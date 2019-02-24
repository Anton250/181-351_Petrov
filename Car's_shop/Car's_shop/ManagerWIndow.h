#pragma once

#include <QWidget>
#include <QStandardItemModel>
#include <QStandardItem>
#include "ui_ManagerWIndow.h"
#include "CarsTableView.h"


class ManagerWIndow : public QWidget
{
	Q_OBJECT

public:
	ManagerWIndow(QWidget *parent = Q_NULLPTR);
	~ManagerWIndow();
signals:
	void firstWindow();
private slots:
	void on_pushButton_exit_clicked();
	void on_pushButton_showCars_clicked();
private:
	Ui::ManagerWIndow ui;
	CarsTableView carsTableWindow;
};
