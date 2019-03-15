#pragma once

#include <QWidget>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QTableView>
#include <QAbstractItemModel>
#include <QMessageBox>
#include <fstream>
#include <TableViewFunc.h>
#include <ctime>
#include <UsersDataBase.h>
#include "ui_UsersTabView.h"

class UsersTabView : public QWidget, TableViewFunc, UsersDataBase
{
	Q_OBJECT

public:
	UsersTabView(QWidget *parent = Q_NULLPTR);
	~UsersTabView();
private slots:
	bool on_pushButton_add_clicked();
	void on_pushButton_clear_clicked();
	bool on_pushButton_search_clicked();
	bool on_pushButton_delete_clicked();
	bool on_pushButton_edit_clicked();
private:
	Ui::UsersTabView ui;
	QStandardItemModel * table;
	QStandardItem * item;
	void showTable(std::vector <dataBaseU> DataBase);
	bool checkStatus(QString status);
	bool checkPassword(QString password, QString login);
};
