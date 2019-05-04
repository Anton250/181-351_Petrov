#pragma once

#include <QWidget>
#include <qsqldatabase.h>
#include <qtableview.h>
#include <QString>
#include <qmessagebox.h>
#include <qsqlquery.h>
#include <QTcpSocket>
#include <qsqltablemodel.h>
#include <qcryptographichash.h>
#include <crypto.h>
#include "ui_SecondWindow.h"

class SecondWindow : public QWidget, public crypto
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
	void on_pushButton_changeLogin_clicked();
	void on_pushButton_cancelNewLogin_clicked();
	void on_pushButton_changePassword_clicked();
	void on_pushButton_cancelNewPassword_clicked();
	bool on_pushButton_addCars_clicked();
	bool on_pushButton_editCars_clicked();
	bool on_pushButton_deleteCars_clicked();
	bool on_pushButton_searchCars_clicked();
	bool on_pushButton_editUsers_clicked();
	bool on_pushButton_deleteUsers_clicked();
	bool on_pushButton_addUsers_clicked();
	bool on_pushButton_searchUsers_clicked();
	bool on_pushButton_confirmNewLogin_clicked();
	bool on_pushButton_confirmNewPassword_clicked();
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
	QWidget * usersData;
	void showErrorMsg(QString message);
	QString setMessageForServer(QString id, QString mark, QString model, QString color,
		QString price, QString dateB, QString dateS, QString numshop);
	QByteArray setMessageForServerUser(QString id, QString fname, QString lname, QByteArray login, QByteArray password, QString status);
};
