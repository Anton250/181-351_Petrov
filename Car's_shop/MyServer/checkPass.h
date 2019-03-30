#pragma once
#include <string>
#include <fstream>
#include <QString>
#include <qsqldatabase.h>
#include <qsqlquery.h>
#include <QVariant>

class checkPass
{
public:
	checkPass();
	~checkPass();
	QString authorize(QString data);
private:
	QSqlDatabase db;
	std::string info;
};

