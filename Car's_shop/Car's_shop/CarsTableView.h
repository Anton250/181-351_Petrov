#pragma once

#include <QWidget>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QTableView>
#include <QAbstractItemModel>
#include <QMessageBox>
#include <fstream>
#include "ui_CarsTableView.h"


class CarsTableView : public QWidget
{
	Q_OBJECT

public:
	CarsTableView(QWidget *parent = Q_NULLPTR);
	~CarsTableView();

signals:
private slots:
	bool on_pushButton_add_clicked();
	void on_pushButton_clear_clicked();
private:
	Ui::CarsTableView ui;
	QStandardItemModel * table;
	QStandardItem * item;
	void showTable();
	QStandardItem * getElementFromFile(int lenght, char endElem, std::string &File);
	bool check_regnum(QString regnum);
	bool check_date(QString date);
	bool check_numshop(QString numshop);
	bool check_price(QString price);
	bool check_selled(QString selled);
	bool check_name(QString name);
	bool isEmpty(QString check);
	void showErrorWithText(QString text);
};
