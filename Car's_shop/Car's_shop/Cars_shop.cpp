#include "Cars_shop.h"
#include <QMessageBox> 
#include <fstream>
int authorize(std::string login, std::string password) {
	std::ifstream log_pas;
	std::string file, login_str;
	log_pas.open("Logins.txt");
	log_pas.seekg(0, log_pas.end);
	int lenght = log_pas.tellg();
	log_pas.seekg(0, log_pas.beg);
	char * buffer = new char[lenght + 1];
	log_pas.read(buffer, lenght);
	file = std::string(buffer);
	if (login == "admin") {
		if (file.find(login + ":" + password + ";") != std::string::npos) {
			return 1;
		}
		else {
			return -2;
		}
	}
	if (login == "manager") {
		if (file.find(login + ":" + password + ";") != std::string::npos) {
			return 2;
		}
		else {
			return -2;
		}
	}
	if (file.find(login + ":" + password + ";") != std::string::npos) {
		return 0;
	}
	else {
		return -2;
	}
}

Cars_shop::Cars_shop(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	
	connect(&adminWindow, &QtGui::firstWindow, this, &Cars_shop::show);
	connect(&managerWindow, &ManagerWIndow::firstWindow, this, &Cars_shop::show);
	connect(&userWindow, &UserWindow::firstWindow, this, &Cars_shop::show);
}
void Cars_shop::on_pushButton_auth_clicked() {
	//Read lineEdits
	std::string login = ui.lineEdit_login->text().toStdString();
	std::string password = ui.lineEdit_password->text().toStdString();

	QMessageBox msgBox;
	if (authorize(login, password) == 0) {
		std::string message = "Hello, user " + login + "!";
		msgBox.setText(QString::fromStdString(message));
		userWindow.show();
		this->close();
	}
	else if (authorize(login, password) == 1) {
		msgBox.setText("Hello, Admin!");
		adminWindow.show();
		this->close();
	}
	else if (authorize(login, password) == 2) {
		msgBox.setText("Hello, Manager!");
		managerWindow.show();
		this->close();
	}
	else {
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
