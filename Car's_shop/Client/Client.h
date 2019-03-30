#pragma once

#include <QtWidgets/QMainWindow>
#include<qsqldatabase.h>
#include<qtableview.h>
#include <QString>
#include <qmessagebox.h>
#include<qsqlquery.h>
#include <QTcpSocket>
#include <qsqltablemodel.h>
#include <SecondWindow.h>
#include "ui_Client.h"

class Client : public QMainWindow
{
	Q_OBJECT


signals:
	void sendCurUsr(QString);
	void sendSocket(QTcpSocket *);
public:
	Client(QWidget *parent = Q_NULLPTR);
	void ShowTable();
	QTcpSocket * clientSocket;
	
private:
	Ui::ClientClass ui;
	SecondWindow secondWindow;
private slots:
	void on_pushButton_auth_clicked();
	void readFromServer();
	void disconnect();
	void showBack();
};
