#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Cars_shop.h"
#include "ManagerWindow.h"


class Cars_shop : public QMainWindow
{
	Q_OBJECT

public:
	Cars_shop(QWidget *parent = Q_NULLPTR);

signals:
	void sendCurUsr(std::string);
private:
	Ui::Cars_shopClass ui;
	ManagerWIndow managerWindow;
	int authorize(std::string login, std::string password, std::string &name);
	std::string info;
private slots:
	void on_pushButton_auth_clicked();
};
