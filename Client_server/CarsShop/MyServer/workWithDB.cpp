#include "workWithDB.h"



workWithDB::workWithDB()
{
    db = QSqlDatabase::addDatabase("QODBC");
	db.setHostName("localhost");
	db.setDatabaseName("carsshop");
	db.setUserName("root");
	db.setPassword("F2y5n0j9y00");
	bool ok = db.open();
}


workWithDB::~workWithDB()
{
}

bool workWithDB::isEmpty(QByteArray str) {

	if (str == "-") {
		return true;
	}
	else {
		return false;
	}


}
bool workWithDB::isEmpty(std::string str) {

	if (str == "-") {
		return true;
	}
	else {
		return false;
	}


}

QString workWithDB::prepareReq(std::string Data[8])
{
	QString request;
	if (!isEmpty(Data[1])) {
		request += ", Mark=\'" + QString::fromStdString(Data[1]) + "\'";
	}
	if (!isEmpty(Data[2])) {
		request += ", Model=\'" + QString::fromStdString(Data[2]) + "\'";
	}
	if (!isEmpty(Data[3])) {
		request += ", Color=\'" + QString::fromStdString(Data[3]) + "\'";
	}
	if (!isEmpty(Data[4])) {
		request += ", Price=\'" + QString::fromStdString(Data[4]) + "\'";
	}
	if (!isEmpty(Data[5])) {
		request += ", Date_of_buy=date(\'" + QString::fromStdString(Data[5]) + "\')";
	}
	if (!isEmpty(Data[6])) {
		request += ", Date_of_sell=date(\'" + QString::fromStdString(Data[6]) + "\')";
	}
	if (!isEmpty(Data[7])) {
		request += ", Number_of_shop=\'" + QString::fromStdString(Data[7]) + "\'";
	}
	return request;
}

QByteArray workWithDB::prepareReqUsers(QByteArray Data[6])
{
	QByteArray request;
	if (!isEmpty(Data[1])) {
		request += ", First_name=\'" + Data[1] + "\'";
	}
	if (!isEmpty(Data[2])) {
		request += ", Last_name=\'" + Data[2] + "\'";
	}
	if (!isEmpty(Data[3])) {
		
		int len = Data[3].size();
		for (int i = 0; i < len; i++) {
			if (Data[3][i] == '\'' || Data[3][i] == '\"') {
				Data[3].insert(i, '\\');
				i++;
				len++;
			}
			if (Data[3][i] == '\0') {
				Data[3][i] = '0';
				i++;
				len++;
			}
			}
		request += ", Login=\'";
		request.append(Data[3], Data[3].size());
		request += "\'";
	}
	if (!isEmpty(Data[4])) {
		
		int len = Data[4].size();
		for (int i = 0; i < len; i++) {
			if (Data[4][i] == '\'' || Data[4][i] == '\"') {
				Data[4].insert(i, '\\');
				i++;
				len++;
			}
			if (Data[4][i] == '\0') {
				Data[4][i] = '0';
				i++;
				len++;
			}
		}
		request += ", Password=\'";
		request.append(Data[4], Data[4].size());
		request += "\'";
	}
	if (!isEmpty(Data[5])) {
		request += ", Status=\'" + Data[5] + "\'";
	}
	
	return request;
}

QByteArray workWithDB::authorize(QByteArray data)
{
	QByteArray strData = data;
	QByteArray Data[2];
	int pos = 0;
	for (int i = 0; i < 2; i++) {
		while (pos < strData.size())
		{

			if (strData[pos] == '$' && strData[pos + 1] == '=' && strData[pos + 2] == '$') {
				pos += 3;
				break;
			}

			Data[i].append(strData[pos]);

			pos++;
		}

	}
	
	
	int len = Data[0].size();
	for (int i = 0; i < len; i++) {
		if (Data[0][i] == '\'' || Data[0][i] == '\"') {
			Data[0].insert(i, '\\');
			i++;
			len++;
		}
		if (Data[0][i] == '\0') {
			Data[0][i] = '0';
			i++;
			len++;
		}
	}
	len = Data[1].size();
	for (int i = 0; i < len; i++) {
		if (Data[1][i] == '\'' || Data[1][i] == '\"') {
			Data[1].insert(i, '\\');
			i++;
			len++;
		}
		if (Data[1][i] == '\0') {
			Data[1][i] = '0';
			i++;
			len++;
		}
	}
	

	QSqlQuery querry;

	QByteArray request = "SELECT * FROM users WHERE Login=\'";
	request.append(Data[0], Data[0].size());
	request.append("\' AND password=\'");
	request.append(Data[1], Data[1].size());
	request.append("\'");

	bool ok = querry.exec(request);

	if (!querry.next()) {
		return "false$";
	}
	else {
		QString id = querry.value(0).toString();
		QString status = querry.value(1).toString();
		QString fname = querry.value(4).toString();
		QString lname = querry.value(5).toString();
		QString date = querry.value(6).toString();
		QString result = "true$" + id + ':' + status + ':' + fname + ':' + lname + ':' + date;
		QByteArray arr;
		arr.append(result);
		return arr;
	}

}

QByteArray workWithDB::addCar(QString data)
{
	std::string strData = data.toStdString();
	std::string Data[8];
	int pos;
	for (int i = 0; i < 7; i++) {
		pos = strData.find("$:$");
		Data[i] = strData.substr(0, pos);
		strData.erase(0, pos + 3);
	}
	Data[7] = strData;

	QString request;

	request = "INSERT INTO cars SET idCars=" + QString::fromStdString(Data[0]);

	
	
	request += prepareReq(Data) + ';';

	QSqlQuery querry;

	bool ok = querry.exec(request);
	QByteArray arr;

	if (ok) {
		arr.append("updateCarsTable$");
		
	}
	else {
		arr.append("error$");
		
	}
	return arr;
}

QByteArray workWithDB::editCar(QString data)
{
	std::string strData = data.toStdString();
	std::string Data[8];
	int pos;
	for (int i = 0; i < 7; i++) {
		pos = strData.find("$:$");
		Data[i] = strData.substr(0, pos);
		strData.erase(0, pos + 3);
	}
	Data[7] = strData;

	QString request;

	

	QString req = prepareReq(Data);
	std::string check = req.toStdString();
	if (check[0] == ',') {
		check.erase(0, 1);
		req = QString::fromStdString(check);
	}
	
	

	request = "UPDATE cars SET" + req + " WHERE idCars=" + QString::fromStdString(Data[0]) + ';';

	QSqlQuery querry;

	bool ok = querry.exec(request);

	QByteArray arr;

	if (ok) {
		arr.append("updateCarsTable$");

	}
	else {
		arr.append("error$");

	}
	return arr;
}

QByteArray workWithDB::deleteCar(QString data)
{
	QSqlQuery querry;

	QString request = "DELETE FROM cars WHERE idCars=" + data + ';';

	bool ok = querry.exec(request);
	QByteArray arr;

	if (ok) {
		arr.append("updateCarsTable$");

	}
	else {
		arr.append("error$");

	}
	return arr;
	
}

QByteArray workWithDB::addUser(QByteArray data)
{
	QByteArray strData = data;
	QByteArray Data[6];
	int pos = 0;
	for (int i = 0; i < 6; i++) {
		while (pos < strData.size())
		{
			
			if (strData[pos] == '$' && strData[pos+1] == ':' && strData[pos+2] == '$') {
				pos += 3;
				break;
			}
			
				Data[i].append(strData[pos]);
			
			pos++;
		}
		
	}
	

	QByteArray request;

	request.append("INSERT INTO users SET ID=");
	request.append(Data[0]);


	QByteArray req = prepareReqUsers(Data);
	request.append(req, req.size());
	request.append(", Date_of_regestration = CURRENT_DATE();");

	QSqlQuery querry;

	bool ok = querry.exec(request);
	QByteArray arr;
	if (ok) {
		arr.append("updateUsersTable$");
		
	}
	else {
		arr.append("error$");
	}
	return arr;
}

QByteArray workWithDB::editUser(QByteArray data)
{
	QByteArray strData = data;
	QByteArray Data[6];
	int pos = 0;
	for (int i = 0; i < 6; i++) {
		while (pos < strData.size())
		{

			if (strData[pos] == '$' && strData[pos + 1] == ':' && strData[pos + 2] == '$') {
				pos += 3;
				break;
			}
			Data[i].append(strData[pos]);
			pos++;
		}

	}

	QByteArray request;



	QByteArray req = prepareReqUsers(Data);
	
	if (req[0] == ',') {
		req[0] = ' ';
		
	}



	request = "UPDATE users SET";
	request.append(req);
	request += " WHERE ID=" + Data[0] + ';';

	QSqlQuery querry;

	bool ok = querry.exec(request);

	QByteArray arr;
	if (ok) {
		arr.append("updateUsersTable$");

	}
	else {
		arr.append("error$");
	}
	return arr;
}

QByteArray workWithDB::deleteUser(QString data)
{
	QSqlQuery querry;

	QString request = "DELETE FROM users WHERE ID=" + data + ';';

	bool ok = querry.exec(request);
	QByteArray arr;
	if (ok) {
		arr.append("updateUsersTable$");

	}
	else {
		arr.append("error$");
	}
	return arr;
}

int workWithDB::find(QByteArray data, QByteArray arr)
{
	int i;
	int result = -1;
	bool found = false;
	int lenght = data.length();
	int len = arr.size();
	for (i = 0; i < len; i++) {

		for (int j = 0; j < lenght; j++) {
			if (data[j] != arr[i + j]) {
				found = false;
				break;
			}
			found = true;
		}
		if (found) {
			result = i;
			break;
		}

	}
	return result;
}

QByteArray workWithDB::erase(QByteArray arr, int Where, int count)
{
	QByteArray newArr;
	for (int i = 0; i < arr.size(); i++) {
		if (i == Where) {
			i += count;
		}
		newArr.append(arr[i]);
	}
	return newArr;
}
