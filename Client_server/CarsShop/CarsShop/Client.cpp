#include "Client.h"

Client::Client(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	clientSocket = new QTcpSocket;

	clientSocket->connectToHost("127.0.0.1", 6000);

	connect(clientSocket, &QTcpSocket::readyRead, this, &Client::readFromServer);
	connect(clientSocket, &QTcpSocket::disconnected, this, &Client::disconnect);
	connect(this, &Client::sendSocket, &secondWindow, &SecondWindow::setSocket);
	connect(&secondWindow, &SecondWindow::firstWindow, this, &Client::showBack);
	connect(this, &Client::sendCurUsr, &secondWindow, &SecondWindow::setCurUser);
	ui.frame_reg->close();
}


void Client::readFromServer()
{
	QByteArray answer;
	answer = clientSocket->readAll();
	answer = decrypt(answer);
	/*QByteArray arr;
	arr.append(answer);
	clientSocket->write(arr);*/
	QMessageBox msgBox;
	int pos = answer.toStdString().find("true$");
	if (pos != std::string::npos) {
		std::string info = answer.toStdString();
		info.erase(0, pos + 5);
		
		msgBox.setText("Password is correct.");
		emit sendSocket(clientSocket);
		emit sendCurUsr(QString::fromStdString(info));
		clientSocket->disconnect(clientSocket, &QTcpSocket::readyRead, this, &Client::readFromServer);
		clientSocket->disconnect(clientSocket, &QTcpSocket::disconnected, this, &Client::disconnect);
		connect(secondWindow.clientSocket, &QTcpSocket::readyRead, &secondWindow, &SecondWindow::readFromServer);
		connect(secondWindow.clientSocket, &QTcpSocket::disconnected, &secondWindow, &SecondWindow::disconnect);
		secondWindow.startWindow();
		secondWindow.show();
		int res = msgBox.exec();
		if (res == QMessageBox::Close) {
			close();
		}
		this->close();
	}
	else if (answer.toStdString().find("false$") != std::string::npos){
		
		msgBox.setText("Password is incorrect.");
		msgBox.setInformativeText("Do you want to try again?");
		msgBox.setStandardButtons(QMessageBox::Retry | QMessageBox::Close);
		msgBox.setDefaultButton(QMessageBox::Yes);
		int res = msgBox.exec();
		if (res == QMessageBox::Close) {
			close();
		}
	}
	
	pos = answer.toStdString().find("updateUsersTable$");
	if (pos != std::string::npos) {
		ui.lineEdit_fName->clear();
		ui.lineEdit_lName->clear();
		ui.lineEdit_newLogin->clear();
		ui.lineEdit_newPassword->clear();
		msgBox.setText("Register succesfull!");
		msgBox.exec();
	}
	pos = answer.toStdString().find("error$");
	if (pos != std::string::npos) {
		msgBox.setText("Error! Try again");
		msgBox.exec();
	}
	ui.lineEdit_login->clear();
	ui.lineEdit_password->clear();
}

void Client::disconnect()
{
	clientSocket->close();
}

void Client::showBack()
{
	this->show();
	connect(clientSocket, &QTcpSocket::readyRead, this, &Client::readFromServer);
	connect(clientSocket, &QTcpSocket::disconnected, this, &Client::disconnect);
}

void Client::on_pushButton_register_clicked()
{
	ui.frame_reg->show();
	ui.frame_login->close();
	
}

void Client::on_pushButton_cancel_clicked()
{
	ui.lineEdit_fName->clear();
	ui.lineEdit_lName->clear();
	ui.lineEdit_newLogin->clear();
	ui.lineEdit_newPassword->clear();
	ui.frame_login->show();
	ui.frame_reg->close();
}

bool Client::on_pushButton_startReg_clicked()
{
	QSqlDatabase db;
	db = QSqlDatabase::addDatabase("QODBC");
	db.setHostName("localhost");
	db.setDatabaseName("carsshop");
	db.setUserName("root");
	db.setPassword("F2y5n0j9y00");
	bool ok = db.open();
	QSqlQuery query;
	QMessageBox msgBox;
	QByteArray login;
	login.append(ui.lineEdit_newLogin->text());
	QString fname = ui.lineEdit_fName->text();
	QString lname = ui.lineEdit_lName->text();
	QByteArray password;
	password.append(ui.lineEdit_newPassword->text());
	if (fname.isEmpty()) {
		msgBox.setText("First name is empty!");
		msgBox.exec();
		return false;
	}
	if (lname.isEmpty()) {
		msgBox.setText("Second name is empty!");
		msgBox.exec();
		return false;
	}
	if (password.isEmpty()) {
		msgBox.setText("Password is empty!");
		msgBox.exec();
		return false;
	}
	if (login.isEmpty()) {
		msgBox.setText("Login is empty!");
		msgBox.exec();
		return false;
	}
	QByteArray arr;
	arr.append(login);
	login = QCryptographicHash::hash(arr, QCryptographicHash::Sha1);
	QByteArray tmp_log;
	tmp_log.append(login, login.size());
	int len = tmp_log.size();
	for (int i = 0; i < len; i++) {
		if (tmp_log[i] == '\'' || tmp_log[i] == '\"') {
			tmp_log.insert(i, '\\');
			i++;
			len++;
		}
		if (tmp_log[i] == '\0') {
			tmp_log[i] = '0';
			i++;
			len++;
		}
	}
	QByteArray req = "SELECT * FROM users WHERE Login=\'" + tmp_log + "\'";
	query.exec(req);
	if (query.next()) {
		msgBox.setText("Login is used!");
		msgBox.exec();
		return false;
	}
	req.clear();
	req = "SELECT * FROM users ORDER BY ID ASC";
	query.exec(req);
	query.last();
	int ID = query.value(0).toInt();
	ID++;
	arr.clear();
	arr.append(password);
	password = QCryptographicHash::hash(arr, QCryptographicHash::Sha1);

	req.clear();
	req.append("addUsers$");
	req.append(QString::number(ID));
	QString temp = "$:$" + fname + "$:$" + lname + "$:$";
	req.append(temp);
	req.append(login);
	req.append("$:$");
	req.append(password);
	req.append("$:$user");
	db.close();
	arr.clear();
	arr.append(req);
	arr = encrypt(arr);
	clientSocket->write(arr);
	return true;
}

void Client::on_pushButton_auth_clicked() {

	QByteArray login;
	login.append(ui.lineEdit_login->text());
	QByteArray password;
	password.append(ui.lineEdit_password->text());
	QByteArray arr;
	
	arr.append(login);
	login = QCryptographicHash::hash(arr, QCryptographicHash::Sha1);
	arr.clear();
	arr.append(password);
	password = QCryptographicHash::hash(arr, QCryptographicHash::Sha1);
	QByteArray messageToServer;
	messageToServer.append("login$");
	messageToServer.append(login, login.size());
	messageToServer.append("$=$");
	messageToServer.append(password, password.size());
	qDebug() << messageToServer;
	arr.clear();
	arr.append(messageToServer);
	arr = encrypt(arr);
	clientSocket->write(arr);
}