#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Cars_shop.h"
#include "AdminWindow.h"
#include "ManagerWindow.h"
#include "UserWindow.h"


class Cars_shop : public QMainWindow
{
	Q_OBJECT

public:
	Cars_shop(QWidget *parent = Q_NULLPTR);

private:
	Ui::Cars_shopClass ui;
	QtGui adminWindow;
	ManagerWIndow managerWindow;
	UserWindow userWindow;
private slots:
	void on_pushButton_auth_clicked();
};
