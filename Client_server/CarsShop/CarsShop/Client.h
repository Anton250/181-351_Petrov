#pragma once

#include <QtWidgets/QMainWindow>
#include <qsqldatabase.h>
#include <qtableview.h>
#include <QString>
#include <qmessagebox.h>
#include <qdebug.h>
#include <qsqlquery.h>
#include <QTcpSocket>
#include <qsqltablemodel.h>
#include <SecondWindow.h>
#include <qcryptographichash.h>
#include <crypto.h>
#include "ui_Client.h"

class Client : public QMainWindow, public crypto
{
	Q_OBJECT


signals:
	void sendCurUsr(QString);
	void sendSocket(QTcpSocket *);
public:
	Client(QWidget *parent = Q_NULLPTR);
	
	QTcpSocket * clientSocket;
	
private:
	Ui::ClientClass ui;
	SecondWindow secondWindow;
private slots:
	void on_pushButton_auth_clicked();
	void readFromServer();
	void disconnect();
	void showBack();
	void on_pushButton_register_clicked();
	void on_pushButton_cancel_clicked();
	bool on_pushButton_startReg_clicked();
};
