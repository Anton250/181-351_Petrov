#pragma once
#include <string>
#include <fstream>
#include <QString>
#include <qsqldatabase.h>
#include <qsqlquery.h>
#include <QVariant>

class workWithDB
{
public:
	workWithDB();
	~workWithDB();
	
	QByteArray authorize(QByteArray data);
	QByteArray addCar(QString data);
	QByteArray editCar(QString data);
	QByteArray deleteCar(QString data);
	QByteArray addUser(QByteArray data);
	QByteArray editUser(QByteArray data);
	QByteArray deleteUser(QString data);
	int find(QByteArray data, QByteArray arr);
	QByteArray erase(QByteArray arr, int Where, int count);
private:
	QSqlDatabase db;
	std::string info;
	bool isEmpty(QByteArray str);
	bool isEmpty(std::string str);
	QString prepareReq(std::string data[8]);
	QByteArray prepareReqUsers(QByteArray Data[6]);
};

