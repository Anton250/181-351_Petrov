#include "checkPass.h"



checkPass::checkPass()
{
    db = QSqlDatabase::addDatabase("QODBC");
	db.setHostName("localhost");
	db.setDatabaseName("carsshop");
	db.setUserName("root");
	db.setPassword("F2y5n0j9y00");
	bool ok = db.open();
}


checkPass::~checkPass()
{
}

QString checkPass::authorize(QString data)
{
	std::string strData = data.toStdString();
	int pos = strData.find("=");
	std::string login = strData.substr(0, pos);
	strData.erase(0, pos + 1);
	std::string password = strData;


	QSqlQuery querry;

	QString request = "SELECT * FROM users WHERE Login=\'" + QString::fromStdString(login) + "\' AND password=\'" + QString::fromStdString(password) + "\'";

	querry.exec(request);

	if (!querry.next()) {
		return "false$";
	}
	else {
		QString status = querry.value(0).toString();
		QString log = querry.value(1).toString();
		QString pas = querry.value(2).toString();
		return "true$" + status + ':' + log + ':' + pas;
	}

}
