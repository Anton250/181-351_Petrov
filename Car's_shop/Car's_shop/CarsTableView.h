#pragma once

#include <QWidget>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QTableView>
#include <QAbstractItemModel>
#include <QMessageBox>
#include <fstream>
#include <TableViewFunc.h>
#include <CarsDataBase.h>
#include "ui_CarsTableView.h"



class CarsTableView : public QWidget, TableViewFunc, CarsDataBase
{
	Q_OBJECT

public:
	CarsTableView(QWidget *parent = Q_NULLPTR);
	~CarsTableView();
	void closeForUser();
signals:
private slots:
	bool on_pushButton_add_clicked();
	void on_pushButton_clear_clicked();
	bool on_pushButton_search_clicked();
	bool on_pushButton_delete_clicked();
	bool on_pushButton_edit_clicked();
private:
	Ui::CarsTableView ui;
	QStandardItemModel * table;
	QStandardItem * item;
	void showTable(std::vector <dataBase> DataBase);
};
