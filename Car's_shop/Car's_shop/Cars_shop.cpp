#include "Cars_shop.h"
#include <QMessageBox> 
#include <fstream>
int Cars_shop::authorize(std::string login, std::string password, std::string &name) {
	std::ifstream log_pas;
	std::string file;
	log_pas.open("Logins.txt");
	log_pas.seekg(0, log_pas.end);
	int lenght = log_pas.tellg();
	log_pas.seekg(0, log_pas.beg);
	char * buffer = new char[lenght + 1];
	log_pas.read(buffer, lenght);
	file = std::string(buffer);
	int pos = file.find("status:manager:login:" + login + ":password:" + password + ':');
	if (pos != std::string::npos) {
		info = file.substr(pos, (file.find(";", pos) + 1) - pos);
		file.erase(0, pos);
		file.erase(0, file.find("name:") + 5);
		name = file.substr(0, file.find(':'));
		return 2;
	}
	pos = file.find("status:admin:login" + login + ":password:" + password + ":");
	if (pos != std::string::npos) {
		info = file.substr(pos, (file.find(";", pos) + 1) - pos);
		return 2;
	}
	pos = file.find("status:user:login:" + login + ":password:" + password + ":");
	if (pos != std::string::npos) {
		info = file.substr(pos, (file.find(";", pos) + 1) - pos);
		file.erase(0, pos);
		file.erase(0, file.find("name:") + 5);
		name = file.substr(0, file.find(':'));
		return 0;
	}
	else {
		return -2;
	}
}

void Cars_shop::readFromServer()
{
	QString answer = clientSocket->readAll();
	int pos = answer.toStdString().find("true$");
	if (pos != std::string::npos) {
		std::string info = answer.toStdString().erase(0, pos+5);
		emit sendCurUsr(info);
		managerWindow.showInfo();
		managerWindow.show();
		this->close();
	}
	else {
		QMessageBox msgBox;
		msgBox.setText("Password is incorrect.");
		msgBox.setInformativeText("Do you want to try again?");
		msgBox.setStandardButtons(QMessageBox::Retry | QMessageBox::Close);
		msgBox.setDefaultButton(QMessageBox::Yes);
		int res = msgBox.exec();
		if (res == QMessageBox::Close) {
			close();
		}
	}
	ui.lineEdit_login->clear();
	ui.lineEdit_password->clear();


}

void Cars_shop::disconnect()
{
	clientSocket->deleteLater();
}

Cars_shop::Cars_shop(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	clientSocket = new QTcpSocket;

	clientSocket->connectToHost("127.0.0.1", 6000);

	connect(clientSocket, &QTcpSocket::readyRead, this, &Cars_shop::readFromServer);
	connect(clientSocket, &QTcpSocket::disconnected, this, &Cars_shop::disconnect);


	connect(&managerWindow, &ManagerWIndow::firstWindow, this, &Cars_shop::show);
	connect(this, &Cars_shop::sendCurUsr, &managerWindow, &ManagerWIndow::writeCurUsr);

}
void Cars_shop::on_pushButton_auth_clicked() {
	//Read lineEdits
	std::string login = ui.lineEdit_login->text().toStdString();
	std::string password = ui.lineEdit_password->text().toStdString();
	std::string name;
	QMessageBox msgBox;
	QString messageToServer = "login$" + QString::fromStdString(login) + "=" + QString::fromStdString(password);
	QByteArray arr;
	arr.append(messageToServer);
	clientSocket->write(arr);
}

