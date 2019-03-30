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
}


void Client::readFromServer()
{
	QString answer;
	answer = clientSocket->readAll();
	
	QMessageBox msgBox;
	int pos = answer.toStdString().find("true$");
	if (pos != std::string::npos) {
		std::string info = answer.toStdString().erase(0, pos + 5);
		
		msgBox.setText("Password is correct.");
		emit sendSocket(clientSocket);
		emit sendCurUsr(QString::fromStdString(info));
		clientSocket->disconnect(clientSocket, &QTcpSocket::readyRead, this, &Client::readFromServer);
		clientSocket->disconnect(clientSocket, &QTcpSocket::disconnected, this, &Client::disconnect);
		connect(secondWindow.clientSocket, &QTcpSocket::readyRead, &secondWindow, &SecondWindow::readFromServer);
		connect(secondWindow.clientSocket, &QTcpSocket::disconnected, &secondWindow, &SecondWindow::disconnect);
		secondWindow.startWindow();
		secondWindow.show();
		this->close();
	}
	else if (answer.toStdString().find("false$") != std::string::npos){
		
		msgBox.setText("Password is incorrect.");
		msgBox.setInformativeText("Do you want to try again?");
		msgBox.setStandardButtons(QMessageBox::Retry | QMessageBox::Close);
		msgBox.setDefaultButton(QMessageBox::Yes);
	}
	int res = msgBox.exec();
	if (res == QMessageBox::Close) {
		close();
	}
	ui.lineEdit_login->clear();
	ui.lineEdit_password->clear();
}

void Client::disconnect()
{
	clientSocket->deleteLater();
}

void Client::showBack()
{
	this->show();
	connect(clientSocket, &QTcpSocket::readyRead, this, &Client::readFromServer);
	connect(clientSocket, &QTcpSocket::disconnected, this, &Client::disconnect);
}

void Client::on_pushButton_auth_clicked() {

	QString login = ui.lineEdit_login->text();
	QString password = ui.lineEdit_password->text();
	std::string name;
	QString messageToServer = "login$" + login + "=" + password;
	QByteArray arr;
	arr.append(messageToServer);
	clientSocket->write(arr);
}