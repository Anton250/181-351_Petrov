#pragma once

#include <QWidget>
#include<qsqldatabase.h>
#include<qtableview.h>
#include <QString>
#include <qmessagebox.h>
#include<qsqlquery.h>
#include <QTcpSocket>
#include <qsqltablemodel.h>
#include "ui_SecondWindow.h"

class SecondWindow : public QWidget
{
	Q_OBJECT

public:
	SecondWindow(QWidget *parent = Q_NULLPTR);
	~SecondWindow();
	void startWindow();
	QTcpSocket * clientSocket;

public slots:
	void setSocket(QTcpSocket * socket);
	void setCurUser(QString CurUser);
	void readFromServer();
	void disconnect();

private slots:
	void on_pushButton_enableEditCars_clicked();
	void on_pushButton_enableEditUsers_clicked();
	void on_pushButton_disableEditCars_clicked();
	void on_pushButton_cancelUsers_clicked();
	void on_pushButton_exit_clicked();
	void on_pushButton_carsClear_clicked();
	void on_pushButton_clearUsers_clicked();
signals:
	void firstWindow();

private:
	Ui::SecondWindow ui;
	QSqlDatabase db;
	QString curUser;
	void showCarsTable();
	void showUsersTable();
	void clearLinesUser();
	void clearLinesCar();


};
