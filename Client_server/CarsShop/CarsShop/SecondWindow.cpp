#include "SecondWindow.h"

SecondWindow::SecondWindow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
	db.setHostName("localhost");
	db.setDatabaseName("carsshop");
	db.setUserName("root");
	db.setPassword("F2y5n0j9y00");
	bool ok = db.open();
	ui.pushButton_addCars->close();
	ui.pushButton_deleteCars->close();
	ui.pushButton_editCars->close();
	ui.pushButton_disableEditCars->close();
	ui.pushButton_addUsers->close();
	ui.pushButton_cancelUsers->close();
	ui.pushButton_deleteUsers->close();
	ui.pushButton_editUsers->close();
	ui.lineEdit_login->close();
	ui.lineEdit_password->close();
	ui.pushButton_confirmNewLogin->close();
	ui.pushButton_cancelNewLogin->close();
	ui.pushButton_confirmNewPassword->close();
	ui.pushButton_cancelNewPassword->close();
	ui.lineEdit_newLogin->close();
	ui.lineEdit_newPassword->close();
	ui.checkBox_dateB->close();
	ui.checkBox_dateS->close();
	
}

SecondWindow::~SecondWindow()
{
}

void SecondWindow::startWindow()
{
	std::string usr = curUser.toStdString();
	if (usr.find("manager:") != std::string::npos) {

		showCarsTable();
		showUsersTable();
		if (ui.tabWidget->count() == 2) {
			QWidget * settings = ui.tabWidget->widget(1);
			ui.tabWidget->insertTab(1, usersData, "Users");
			ui.tabWidget->insertTab(2, settings, "Settings");
		}
	}
	else {

		showCarsTable();
		//ui.tabWidget->tabCloseRequested(1);
		if (ui.tabWidget->count() == 3) {
			usersData = ui.tabWidget->widget(1);
			ui.tabWidget->removeTab(1);
		}
		ui.pushButton_enableEditCars->close();

	}
	std::string user = curUser.toStdString();
	std::string Data[5];
	int pos;
	for (int i = 0; i < 4; i++) {
		pos = user.find(":");
		Data[i] = user.substr(0, pos);
		user.erase(0, pos + 1);
	}
	Data[4] = user;
	ui.status->setText(QString::fromStdString(Data[1]));
	ui.fName->setText(QString::fromStdString(Data[2]));
	ui.lName->setText(QString::fromStdString(Data[3]));
	ui.dateOfR->setText(QString::fromStdString(Data[4]));


}

void SecondWindow::showCarsTable()
{
	



	QSqlTableModel * model = new QSqlTableModel;



	model->setTable("cars");


	
	model->setEditStrategy(QSqlTableModel::OnManualSubmit);
	model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
	model->setHeaderData(1, Qt::Horizontal, QObject::tr("Mark"));
	model->setHeaderData(2, Qt::Horizontal, QObject::tr("Model"));
	model->setHeaderData(3, Qt::Horizontal, QObject::tr("Color"));
	model->setHeaderData(4, Qt::Horizontal, QObject::tr("Price $"));
	model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date of buy"));
	model->setHeaderData(6, Qt::Horizontal, QObject::tr("Date of sell"));
	model->setHeaderData(7, Qt::Horizontal, QObject::tr("Number of shop"));
	bool okey = model->select();

	ui.carsTable->setModel(model);
	ui.carsTable->setColumnHidden(-1, true);
	ui.carsTable->show();
}

void SecondWindow::showUsersTable()
{
	QSqlTableModel * model = new QSqlTableModel;



	model->setTable("users");



	model->setEditStrategy(QSqlTableModel::OnManualSubmit);
	model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
	model->setHeaderData(1, Qt::Horizontal, QObject::tr("Status"));
	model->setHeaderData(2, Qt::Horizontal, QObject::tr("Login"));
	model->setHeaderData(3, Qt::Horizontal, QObject::tr("Password"));
	model->setHeaderData(4, Qt::Horizontal, QObject::tr("First name"));
	model->setHeaderData(5, Qt::Horizontal, QObject::tr("Last name"));
	model->setHeaderData(6, Qt::Horizontal, QObject::tr("Date of regestration"));
	bool okey = model->select();
	ui.usersTable->setModel(model);
	ui.usersTable->hideColumn(2);
	ui.usersTable->hideColumn(3);
	ui.usersTable->show();

}

void SecondWindow::clearLinesUser()
{
	ui.lineEdit_fName->clear();
	ui.lineEdit_lName->clear();
	ui.lineEdit_login->clear();
	ui.lineEdit_password->clear();
	ui.lineEdit_status->clear();
	ui.minDateR->clear();
	ui.maxDateR->clear();
}

void SecondWindow::clearLinesCar()
{
	ui.lineEdit_carId->clear();
	ui.lineEdit_color->clear();
	ui.lineEdit_mark->clear();
	ui.lineEdit_maxPrice->clear();
	ui.lineEdit_minPrice->clear();
	ui.lineEdit_model->clear();
	ui.lineEdit_numShop->clear();
	ui.maxDateB->clear();
	ui.minDateB->clear();
	ui.maxDateS->clear();
	ui.minDateS->clear();
	ui.checkBox_dateB->setChecked(true);
	ui.checkBox_dateS->setChecked(true);
	ui.checkBox_maxDateB->setChecked(false);
	ui.checkBox_maxDateS->setChecked(false);
	ui.checkBox_minDateB->setChecked(false);
	ui.checkBox_minDateS->setChecked(false);
}

void SecondWindow::showErrorMsg(QString message)
{
	QMessageBox msgBox;
	msgBox.setText(message);
	msgBox.exec();
	
}

QString SecondWindow::setMessageForServer(QString id, QString mark, QString model, QString color, QString price, QString dateB, QString dateS, QString numshop)
{
	QString answer =  id + "$:$";
	if (mark.isEmpty()) {
		answer += "-$:$";
	}
	else {
		answer += mark + "$:$";
	}
	if (model.isEmpty()) {
		answer += "-$:$";
	}
	else {
		answer += model + "$:$";
	}
	if (color.isEmpty()) {
		answer += "-$:$";
	}
	else {
		answer += color + "$:$";
	}
	if (price.isEmpty()) {
		answer += "-$:$";
	}
	else {
		answer += price + "$:$";
	}
	if (dateB.isEmpty()) {
		answer += "-$:$";
	}
	else {
		answer += dateB + "$:$";
	}
	if (dateS.isEmpty()) {
		answer += "-$:$";
	}
	else {
		answer += dateS + "$:$";
	}
	if (numshop.isEmpty()) {
		answer += "-";
	}
	else {
		answer += numshop;
	}
	

	return answer;
}

QByteArray SecondWindow::setMessageForServerUser(QString id, QString fname, QString lname, QByteArray login, QByteArray password, QString status)
{
	QByteArray answer;
	answer.append(id);
	answer.append("$:$");
	if (fname.isEmpty()) {
		answer.append("-$:$");
	}
	else {
		answer.append(fname);
		answer.append("$:$");
	}
	if (lname.isEmpty()) {
		answer.append("-$:$");
	}
	else {
		answer.append(lname);
		answer.append("$:$");
	}
	if (login.isEmpty()) {
		answer += "-$:$";
	}
	else {
		answer.append(login, login.size());
		answer.append("$:$");
	}
	if (password.isEmpty()) {
		answer += "-$:$";
	}
	else {
		answer.append(password, password.size());
		answer.append("$:$");
	}
	if (status.isEmpty()) {
		answer += "-";
	}
	else {
		answer += status;
	}


	return answer;
}

void SecondWindow::setCurUser(QString CurUser)
{
	curUser = CurUser;
}

void SecondWindow::on_pushButton_enableEditUsers_clicked()
{
	ui.pushButton_enableEditUsers->close();
	ui.pushButton_searchUsers->close();
	ui.maxDateR->close();
	ui.minDateR->close();
	ui.label_maxDateR->close();
	ui.label_minDateR->close();
	ui.pushButton_addUsers->show();
	ui.pushButton_cancelUsers->show();
	ui.pushButton_deleteUsers->show();
	ui.pushButton_editUsers->show();
	ui.lineEdit_login->show();
	ui.lineEdit_password->show();
	ui.checkBox_maxDateR->close();
	ui.checkBox_minDateR->close();

}

void SecondWindow::on_pushButton_disableEditCars_clicked()
{
	ui.pushButton_addCars->close();
	ui.pushButton_deleteCars->close();
	ui.pushButton_editCars->close();
	ui.pushButton_disableEditCars->close();
	ui.pushButton_searchCars->show();
	ui.pushButton_enableEditCars->show();
	ui.lineEdit_maxPrice->show();
	ui.lineEdit_minPrice->setPlaceholderText("Min price");
	ui.maxDateB->show();
	ui.maxDateS->show();
	ui.label_maxDateB->show();
	ui.label_maxDateS->show();
	ui.label_minDateB->setText("Min date of buy:");
	ui.label_minDateS->setText("Min date of sell:"); 
	ui.checkBox_dateB->close();
	ui.checkBox_dateS->close();
	ui.checkBox_maxDateB->show();
	ui.checkBox_maxDateS->show();
	ui.checkBox_minDateB->show();
	ui.checkBox_minDateS->show();
}

void SecondWindow::on_pushButton_cancelUsers_clicked()
{
	ui.pushButton_enableEditUsers->show();
	ui.pushButton_searchUsers->show();
	ui.maxDateR->show();
	ui.minDateR->show();
	ui.label_maxDateR->show();
	ui.label_minDateR->show();
	ui.pushButton_addUsers->close();
	ui.pushButton_cancelUsers->close();
	ui.pushButton_deleteUsers->close();
	ui.pushButton_editUsers->close();
	ui.lineEdit_login->close();
	ui.lineEdit_password->close();
	ui.checkBox_maxDateR->show();
	ui.checkBox_minDateR->show();
}

void SecondWindow::on_pushButton_exit_clicked()
{
	clientSocket->disconnect(clientSocket, &QTcpSocket::readyRead, this, &SecondWindow::readFromServer);
	clientSocket->disconnect(clientSocket, &QTcpSocket::disconnected, this, &SecondWindow::disconnect);
	emit firstWindow();
	this->close();
}

void SecondWindow::on_pushButton_carsClear_clicked()
{
	clearLinesCar();
	showCarsTable();
}

void SecondWindow::on_pushButton_clearUsers_clicked()
{
	clearLinesUser();
	showUsersTable();
}

void SecondWindow::on_pushButton_changeLogin_clicked()
{
	ui.pushButton_changeLogin->close();
	ui.pushButton_confirmNewLogin->show();
	ui.pushButton_cancelNewLogin->show();
	ui.lineEdit_newLogin->show();
	
	
}

void SecondWindow::on_pushButton_cancelNewLogin_clicked()
{
	ui.pushButton_changeLogin->show();
	ui.lineEdit_newLogin->clear();
	ui.pushButton_confirmNewLogin->close();
	ui.pushButton_cancelNewLogin->close();
	ui.lineEdit_newLogin->close();
}

void SecondWindow::on_pushButton_changePassword_clicked()
{
	ui.pushButton_changePassword->close();
	ui.pushButton_confirmNewPassword->show();
	ui.pushButton_cancelNewPassword->show();
	ui.lineEdit_newPassword->show();
}

void SecondWindow::on_pushButton_cancelNewPassword_clicked()
{
	ui.pushButton_changePassword->show();
	ui.lineEdit_newPassword->clear();
	ui.pushButton_confirmNewPassword->close();
	ui.pushButton_cancelNewPassword->close();
	ui.lineEdit_newPassword->close();
}

bool SecondWindow::on_pushButton_addCars_clicked()
{
	QSqlQuery check;
	QString id = ui.lineEdit_carId->text();
	if (id.isEmpty()) {
		
		showErrorMsg("Reg number is empty!");
		return false;
	}

	QString request = "SELECT * FROM cars WHERE idCars=" + id;
	check.exec(request);
	if (check.next()) {
		showErrorMsg("This reg number is already in data base!");
		return false;
	}

	QString mark = ui.lineEdit_mark->text();
	QString model = ui.lineEdit_model->text();
	QString color = ui.lineEdit_color->text();
	QString price = ui.lineEdit_minPrice->text();
	QString dateB = ui.minDateB->text();
	QString dateS;
	QString numShop = ui.lineEdit_numShop->text();


	if (ui.minDateS->text() >= dateB) {
		dateS = ui.minDateS->text();
	}

	if (mark.isEmpty()) {
		showErrorMsg("Mark is empty!");
		return false;
	}
	if (model.isEmpty()) {
		showErrorMsg("Model is empty!");
		return false;
	}
	if (color.isEmpty()) {
		showErrorMsg("Color is empty!");
		return false;
	}
	if (price.isEmpty()) {
		showErrorMsg("Price is empty!");
		return false;
	}
	if (numShop.isEmpty()) {
		showErrorMsg("Shop number is empty!");
		return false;
	}

	QByteArray arr;
	QString req = "addCars$" + setMessageForServer(id, mark, model, color, price, dateB, dateS, numShop);
	arr.append(req);
	arr = encrypt(arr);
	clientSocket->write(arr);


}

bool SecondWindow::on_pushButton_editCars_clicked()
{
	
	QSqlQuery check;
	QString id = ui.lineEdit_carId->text();
	if (id.isEmpty()) {

		showErrorMsg("Reg number is empty!");
		return false;
	}

	QString request = "SELECT * FROM cars WHERE idCars=" + id;
	check.exec(request);
	if (!check.next()) {
		showErrorMsg("There is no such reg number!");
		return false;
	}

	QString mark = ui.lineEdit_mark->text();
	QString model = ui.lineEdit_model->text();
	QString color = ui.lineEdit_color->text();
	QString price = ui.lineEdit_minPrice->text();
	QString dateB;
	QString dateS;
	QString numShop = ui.lineEdit_numShop->text();


	if (!ui.checkBox_dateB->isChecked()) {
		dateB = ui.minDateB->text();
	}
	if (!ui.checkBox_dateS->isChecked()) {
		if (!ui.checkBox_dateB->isChecked()) {
			if (ui.minDateS->text() >= dateB) {
				dateS = ui.minDateS->text();
			}
			else {
				showErrorMsg("Date of sell can't be lower than date of buy!");
			}
		}
		else {
			request = "SELECT Date_of_buy FROM cars WHERE idCars=" + id;
			check.exec(request);
			check.next();
			if (ui.minDateS->text() >= check.value(0).toString()) {
				dateS = ui.minDateS->text();
			}
			else {
				showErrorMsg("Date of sell can't be lower than date of buy!");
			}
		}
	}
	QByteArray arr;
	QString req = "editCars$" + setMessageForServer(id, mark, model, color, price, dateB, dateS, numShop);
	arr.append(req);
	arr = encrypt(arr);
	clientSocket->write(arr);
	return true;
}

bool SecondWindow::on_pushButton_deleteCars_clicked()
{
	QSqlQuery check;
	QString id = ui.lineEdit_carId->text();
	if (id.isEmpty()) {

		showErrorMsg("Reg number is empty!");
		return false;
	}

	QString request = "SELECT * FROM cars WHERE idCars=" + id;
	check.exec(request);
	if (!check.next()) {
		showErrorMsg("There is no such reg number!");
		return false;
	}

	QByteArray arr;
	QString req = "deleteCars$" + id;
	arr.append(req);
	arr = encrypt(arr);
	clientSocket->write(arr);


	return true;
}

bool SecondWindow::on_pushButton_searchCars_clicked()
{

	QString request;
	std::string req;

	QString id = ui.lineEdit_carId->text();
	QString mark = ui.lineEdit_mark->text();
	QString modelCar = ui.lineEdit_model->text();
	QString color = ui.lineEdit_color->text();
	QString price = ui.lineEdit_minPrice->text();
	QString minDateB = ui.minDateB->text();
	QString minDateS = ui.minDateS->text();
	QString maxDateB = ui.maxDateB->text();
	QString maxDateS = ui.maxDateS->text();
	QString numShop = ui.lineEdit_numShop->text();

	if (!id.isEmpty()) {
		request += " idCars=" + id + " ";
	}
	if (!mark.isEmpty()) {
		request += "AND Mark=\'" + mark + "\' ";
	}
	if (!modelCar.isEmpty()) {
		request += "AND Model=\'" + modelCar + "\' ";
	}
	if (!color.isEmpty()) {
		request += "AND Color=\'" + color + "\' ";
	}
	if (!price.isEmpty()) {
		request += "AND Price=\'" + price + "\' ";
	}
	if (!numShop.isEmpty()) {
		request += "AND Number_of_shop=\'" + numShop + "\' ";
	}
	if (ui.checkBox_minDateB->isChecked()) {
		request += "AND Date_of_buy>=\'" + minDateB + "\' ";
	}
	if (ui.checkBox_maxDateB->isChecked()) {
		request += "AND Date_of_buy<=\'" + maxDateB + "\' ";
	}
	if (ui.checkBox_minDateS->isChecked()) {
		request += "AND Date_of_sell>=\'" + minDateS + "\' ";
	}
	if (ui.checkBox_maxDateS->isChecked()) {
		request += "AND Date_of_sell<=\'" + maxDateS + "\' ";
	}
	req = request.toStdString();

	if (req[0] == 'A') {
		req.erase(0, 3);
		request = QString::fromStdString(req);
	}


	request = "SELECT * FROM cars WHERE" + request + ';';
	QSqlQueryModel * model = new QSqlQueryModel;



	//model->setTable("cars");



	
	model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
	model->setHeaderData(1, Qt::Horizontal, QObject::tr("Mark"));
	model->setHeaderData(2, Qt::Horizontal, QObject::tr("Model"));
	model->setHeaderData(3, Qt::Horizontal, QObject::tr("Color"));
	model->setHeaderData(4, Qt::Horizontal, QObject::tr("Price $"));
	model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date of buy"));
	model->setHeaderData(6, Qt::Horizontal, QObject::tr("Date of sell"));
	model->setHeaderData(7, Qt::Horizontal, QObject::tr("Number of shop"));
	//bool okey = model->select();
	model->setQuery(request);
	//model->setFilter();

	ui.carsTable->setModel(model);
	//ui.carsTable->setColumnHidden(-1, true);
	ui.carsTable->show();
	return false;
}

bool SecondWindow::on_pushButton_editUsers_clicked()
{
	QSqlQuery check;
	QString id = ui.lineEdit_IDUsers->text();
	if (id.isEmpty()) {

		showErrorMsg("ID is empty!");
		return false;
	}

	QString request = "SELECT * FROM users WHERE ID=" + id;
	check.exec(request);
	if (!check.next()) {
		showErrorMsg("There is no such ID!");
		return false;
	}

	QString status = ui.lineEdit_status->text();
	QString fname = ui.lineEdit_fName->text();
	QString lname = ui.lineEdit_lName->text();
	QByteArray login;
	login.append(ui.lineEdit_login->text());
	QByteArray arr;
	if (!login.isEmpty()) {
		arr.append(login);
		login = QCryptographicHash::hash(arr, QCryptographicHash::Sha1);
		arr.clear();
	}
	QByteArray password;
	password.append(ui.lineEdit_password->text());
	if (!password.isEmpty()) {
		arr.append(password);
		password = QCryptographicHash::hash(arr, QCryptographicHash::Sha1);
	}
	if (!login.isEmpty()) {
		QByteArray tmp_log;
		tmp_log.append(login, login.size());
		int len = tmp_log.size();
		for (int i = 0; i < len; i++) {
			if (tmp_log[i] == '\'' || tmp_log[i] == '\"') {
				tmp_log.insert(i, "\\");
				i++;
				len++;
			}
			if (tmp_log[i] == '\0') {
				tmp_log[i] = '0';
				i++;
				len++;
			}
		}
		QString request = "SELECT * FROM users WHERE Login=\'" + tmp_log + '\'';
		check.exec(request);
		if (check.next()) {
			showErrorMsg("This login is already in data base!");
			return false;
		}
	}

	
	arr.clear();
	QByteArray req;
	req.append("editUsers$");
	QByteArray mes = setMessageForServerUser(id, fname, lname, login, password, status);
	req.append(mes, mes.size());
	arr.append(req, req.size());
	arr = encrypt(arr);
	clientSocket->write(arr);
	return true;
}

bool SecondWindow::on_pushButton_deleteUsers_clicked()
{
	QSqlQuery check;
	QString id = ui.lineEdit_IDUsers->text();
	if (id.isEmpty()) {

		showErrorMsg("ID is empty!");
		return false;
	}

	QString request = "SELECT * FROM users WHERE ID=" + id;
	check.exec(request);
	if (!check.next()) {
		showErrorMsg("There is no such ID!");
		return false;
	}

	QByteArray arr;
	QString req = "deleteUsers$" + id;
	arr.append(req);
	arr = encrypt(arr);
	clientSocket->write(arr);


	return true;
}

bool SecondWindow::on_pushButton_addUsers_clicked()
{
	QSqlQuery check;
	QString id = ui.lineEdit_IDUsers->text();
	QByteArray login;
	login.append(ui.lineEdit_login->text());
	QByteArray arr;
	if (id.isEmpty()) {

		showErrorMsg("ID is empty!");
		return false;
	}

	QString request = "SELECT * FROM users WHERE ID=" + id;
	check.exec(request);
	if (check.next()) {
		showErrorMsg("This ID is already in data base!");
		return false;
	}
	if (login.isEmpty()) {
		showErrorMsg("Login is empty!");
		return false;
	}
	
	login = QCryptographicHash::hash(login, QCryptographicHash::Sha1);
	QByteArray tmp_log;
	tmp_log.append(login, login.size());
	int len = tmp_log.size();
	for (int i = 0; i < len; i++) {
		if (tmp_log[i] == '\'' || tmp_log[i] == '\"') {
			tmp_log.insert(i, "\\");
			i++;
			len++;
		}
		if (tmp_log[i] == '\0') {
			tmp_log[i] = '0';
			i++;
			len++;
		}
	}
	request = "SELECT * FROM users WHERE Login=\'" + tmp_log + '\'';
	check.exec(request);
	if (check.next()) {
		showErrorMsg("This login is already in data base!");
		return false;
	}
	QString status = ui.lineEdit_status->text();
	QString fname = ui.lineEdit_fName->text();
	QString lname = ui.lineEdit_lName->text();
	
	QByteArray password;
	password.append(ui.lineEdit_password->text());

	
	password = QCryptographicHash::hash(password, QCryptographicHash::Sha1);

	

	if (status.isEmpty()) {
		showErrorMsg("Status is empty!");
		return false;
	}
	if (fname.isEmpty()) {
		showErrorMsg("First name is empty!");
		return false;
	}
	if (lname.isEmpty()) {
		showErrorMsg("Second name is empty!");
		return false;
	}
	
	if (password.isEmpty()) {
		showErrorMsg("Password is empty!");
		return false;
	}

	arr.clear();
	QByteArray req;
	req.append("addUsers$");
	QByteArray mes = setMessageForServerUser(id, fname, lname, login, password, status);
	req.append(mes, mes.size());
	arr.append(req, req.size());
	arr = encrypt(arr);
	clientSocket->write(arr);
}

bool SecondWindow::on_pushButton_searchUsers_clicked()
{
	QString request;
	std::string req;

	QString id = ui.lineEdit_IDUsers->text();
	QString status = ui.lineEdit_status->text();
	QString fname = ui.lineEdit_fName->text();
	QString lname = ui.lineEdit_lName->text();
	QString minDateR = ui.minDateB->text();
	QString maxDateR = ui.maxDateB->text();
	

	if (!id.isEmpty()) {
		request += " ID=" + id + " ";
	}
	if (!status.isEmpty()) {
		request += "AND Status=\'" + status + "\' ";
	}
	if (!fname.isEmpty()) {
		request += "AND First_name=\'" + fname + "\' ";
	}
	if (!lname.isEmpty()) {
		request += "AND Last_name=\'" + lname + "\' ";
	}
	if (ui.checkBox_minDateR->isChecked()) {
		request += "AND Date_of_regestration>=\'" + minDateR + "\' ";
	}
	if (ui.checkBox_maxDateR->isChecked()) {
		request += "AND Date_of_regestration<=\'" + maxDateR + "\' ";
	}
	req = request.toStdString();

	if (req[0] == 'A') {
		req.erase(0, 3);
		request = QString::fromStdString(req);
	}


	request = "SELECT * FROM users WHERE" + request + ';';
	QSqlQueryModel * model = new QSqlQueryModel;



	//model->setTable("cars");




	model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
	model->setHeaderData(1, Qt::Horizontal, QObject::tr("Status"));
	model->setHeaderData(2, Qt::Horizontal, QObject::tr("Login"));
	model->setHeaderData(3, Qt::Horizontal, QObject::tr("Password"));
	model->setHeaderData(4, Qt::Horizontal, QObject::tr("First name"));
	model->setHeaderData(5, Qt::Horizontal, QObject::tr("Second name"));
	model->setHeaderData(6, Qt::Horizontal, QObject::tr("Date of regestration"));
	//bool okey = model->select();
	model->setQuery(request);
	//model->setFilter();

	ui.usersTable->setModel(model);
	ui.usersTable->setColumnHidden(2, true);
	ui.usersTable->setColumnHidden(3, true);
	ui.usersTable->show();
	return false;
}

bool SecondWindow::on_pushButton_confirmNewLogin_clicked()
{
	QByteArray newLogin;
	newLogin.append(ui.lineEdit_newLogin->text());
	QByteArray arr;
	arr.append(newLogin);
	newLogin = QCryptographicHash::hash(arr, QCryptographicHash::Sha1);
	if (newLogin.isEmpty()) {
		showErrorMsg("Login is empty!");
		return false;
	}
	QSqlQuery query;
	QByteArray tmp_log;
	tmp_log.append(newLogin, newLogin.size());
	int len = tmp_log.size();
	for (int i = 0; i < len; i++) {
		if (tmp_log[i] == '\'' || tmp_log[i] == '\"') {
			tmp_log.insert(i, "\\");
			i++;
			len++;
		}
		if (tmp_log[i] == '\0') {
			tmp_log[i] = '0';
			i++;
			len++;
		}
	}
	QString req = "SELECT * FROM users WHERE Login=\'" + tmp_log + '\'';
	query.exec(req);
	if (query.next()) {
		showErrorMsg("This login is used!");
		return false;
	}
	std::string user = curUser.toStdString();
	user = user.substr(0, user.find(':'));
	QString empty;
	QByteArray emptyy;


	QByteArray reqe;
	reqe.append("editUser");
	QByteArray mes = setMessageForServerUser(QString::fromStdString(user), empty, empty, newLogin, emptyy, empty);
	reqe.append(mes, mes.size());
	arr.append(reqe, reqe.size());
	arr.clear();
	arr.append(reqe);
	arr = encrypt(arr);
	clientSocket->write(arr);

	return true;
}

bool SecondWindow::on_pushButton_confirmNewPassword_clicked()
{
	QByteArray newPassword;
	newPassword.append(ui.lineEdit_newPassword->text());
	QByteArray arr;
	if (newPassword.isEmpty()) {
		showErrorMsg("Password is empty!");
		return false;
	}
	arr.append(newPassword);
	newPassword = QCryptographicHash::hash(arr, QCryptographicHash::Sha1);
	
	
	std::string user = curUser.toStdString();
	user = user.substr(0, user.find(':'));
	QString empty;
	QByteArray emptyy;
	arr.clear();
	QByteArray req;
	req.append("editUsers$");
	QByteArray mes = setMessageForServerUser(QString::fromStdString(user), empty, empty, emptyy, newPassword, empty);
	req.append(mes, mes.size());
	arr.append(req, req.size());

	
	
	
	arr = encrypt(arr);
	clientSocket->write(arr);

	return true;
}


void SecondWindow::readFromServer()
{

	QByteArray answer = clientSocket->readAll();
	answer = decrypt(answer);
	std::string strAnswer = answer.toStdString();

	if (strAnswer.find("updateCarsTable$") != std::string::npos) {
		showCarsTable();
	}

	if (strAnswer.find("updateUsersTable$") != std::string::npos) {
		if (curUser.toStdString().find("manager:") != std::string::npos) {
			showUsersTable();
		}
	}
	if (strAnswer.find("updateCorrect") != std::string::npos) {
		showErrorMsg("Update succesfull!");
	}
	if (strAnswer.find("error$") != std::string::npos) {
		showErrorMsg("Error! Try again.");
	}

}

void SecondWindow::disconnect()
{
	clientSocket->close();
}

void SecondWindow::setSocket(QTcpSocket * socket) {

	clientSocket = socket;
}

void SecondWindow::on_pushButton_enableEditCars_clicked() {

	ui.pushButton_addCars->show();
	ui.pushButton_deleteCars->show();
	ui.pushButton_editCars->show();
	ui.pushButton_disableEditCars->show();
	ui.pushButton_searchCars->close();
	ui.pushButton_enableEditCars->close();
	ui.lineEdit_maxPrice->close();
	ui.lineEdit_minPrice->setPlaceholderText("Price");
	ui.maxDateB->close();
	ui.maxDateS->close();
	ui.label_maxDateB->close();
	ui.label_maxDateS->close();
	ui.label_minDateB->setText("Date of buy:");
	ui.label_minDateS->setText("Date of sell:");
	ui.checkBox_dateB->show();
	ui.checkBox_dateS->show();
	ui.checkBox_maxDateB->close();
	ui.checkBox_maxDateS->close();
	ui.checkBox_minDateB->close();
	ui.checkBox_minDateS->close();
}