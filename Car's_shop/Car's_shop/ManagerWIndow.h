#pragma once

#include <QWidget>
#include <QStandardItemModel>
#include <QStandardItem>
#include <TableViewFunc.h>
#include "ui_ManagerWIndow.h"
#include "CarsTableView.h"
#include "UsersTabView.h"


class ManagerWIndow : public QWidget, TableViewFunc
{
	Q_OBJECT

public:
	ManagerWIndow(QWidget *parent = Q_NULLPTR);
	~ManagerWIndow();
	std::string curUsr;
signals:
	void firstWindow();
public slots:
	void writeCurUsr(std::string curentUsr);
	void showInfo();
private slots:
	void on_pushButton_exit_clicked();
	void on_pushButton_showCars_clicked();
	void on_pushButton_userData_clicked();
private:
	Ui::ManagerWIndow ui;
	CarsTableView carsTableWindow;
	UsersTabView userTableWindow;
};
