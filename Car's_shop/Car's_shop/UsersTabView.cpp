#include "UsersTabView.h"
#include "CarsTableView.h"

UsersTabView::UsersTabView(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	createDB("Logins.txt");
	showTable(db);
}

UsersTabView::~UsersTabView()
{
	if (isEdited) {
		writeToFile("Logins.txt");
	}
}

void UsersTabView::on_pushButton_clear_clicked()
{
	ui.lineEdit_Status->clear();
	ui.lineEdit_Login->clear();
	ui.lineEdit_Password->clear();
	ui.lineEdit_FirstName->clear();
	ui.lineEdit_ScndName->clear();
	ui.lineEdit_DateOfReg->clear();
	showTable(db);
}

bool UsersTabView::on_pushButton_search_clicked()
{
	QString status, login, password, fstName, scndName, dateR;
	status = ui.lineEdit_Status->text();
	login = ui.lineEdit_Login->text();
	password = ui.lineEdit_Password->text();
	fstName = ui.lineEdit_FirstName->text();
	scndName = ui.lineEdit_ScndName->text();
	dateR = ui.lineEdit_DateOfReg->text();
	bool isFinded = false;
	if (!isEmpty(login)) {
		
		if (findElements(1, login.toStdString(), db)) {
			showTable(searchedDB);
			return true;
		}
		else {
			showErrorWithText("There is no such users");
			return false;
		}
	}

	if (!isEmpty(status)) {
		if (checkStatus(status)) {
			if (searchedDB.size() != 0) {
				isFinded = findElements(2, status.toStdString(), searchedDB);
			}
			else {
				isFinded = findElements(2, status.toStdString(), db);
			}
		}
		else {
			showErrorWithText("Invalid status");
			return false;
		}
	}
	if (!isEmpty(password)) {
		if (searchedDB.size() != 0) {
			isFinded = findElements(3, password.toStdString(), searchedDB);
		}
		else {
			isFinded = findElements(3, password.toStdString(), db);
		}
	}
	if (!isEmpty(fstName)) {
		if (searchedDB.size() != 0) {
			isFinded = findElements(4, fstName.toStdString(), searchedDB);
		}
		else {
			isFinded = findElements(4, fstName.toStdString(), db);
		}
	}
	if (!isEmpty(scndName)) {
		
		if (searchedDB.size() != 0) {
			isFinded = findElements(5, scndName.toStdString(), searchedDB);
		}
		else {
			isFinded = findElements(5, scndName.toStdString(), db);
		}
	}
	if (!isEmpty(dateR)) {
		
			if (searchedDB.size() != 0) {
				isFinded = findElements(6, dateR.toStdString(), searchedDB);
			}
			else {
				isFinded = findElements(6, dateR.toStdString(), db);
			}
	}
	
	if (isFinded) {
		showTable(searchedDB);
		searchedDB.clear();
		return true;
	}
	else {
		showErrorWithText("There is no such users");
		return false;
	}
}

bool UsersTabView::on_pushButton_delete_clicked()
{
	QString login;
	int i;
	login = ui.lineEdit_Login->text();

	if (isEmpty(login)) {
		showErrorWithText("You need to write login to delete text");
		return false;
	}
	if (!findElemToEditOrDelete(i, login.toStdString(), db)) {
		showErrorWithText("There is no such user");
		return false;
	}
	db.erase(db.begin() + i);
	showTable(db);
	isEdited = true;
	return true;
}

bool UsersTabView::on_pushButton_edit_clicked()
{
	QString login;
	int i;
	login = ui.lineEdit_Login->text();
	
	dataBaseU tmp_line;

	if (isEmpty(login)) {
		showErrorWithText("You need to write login to edit text");
		return false;
	}
	if (!findElemToEditOrDelete(i, login.toStdString(), db)) {
		showErrorWithText("There is no such user");
		return false;
	}
	tmp_line.login = login.toStdString();
	QString status, password, fstName, scndName, dateR;
	status = ui.lineEdit_Status->text();
	password = ui.lineEdit_Password->text();
	fstName = ui.lineEdit_FirstName->text();
	scndName = ui.lineEdit_ScndName->text();
	dateR = ui.lineEdit_DateOfReg->text();

	if (!isEmpty(status)) {
		if (checkStatus(status)) {
			tmp_line.status = status.toStdString();
		}
		else {
			showErrorWithText("Invalid status");
		}
	}
	else {
		tmp_line.status = db[i].status;
	}
	if (!isEmpty(password)) {
		tmp_line.password = password.toStdString();
	}
	else {
		tmp_line.password = db[i].password;
	}
	if (!isEmpty(fstName)) {
		tmp_line.fstName = fstName.toStdString();
	}
	else {
		tmp_line.fstName = db[i].fstName;
	}
	if (!isEmpty(scndName)) {
		tmp_line.scndName = scndName.toStdString();
	}
	else {
		tmp_line.scndName = db[i].scndName;
	}
	if (!isEmpty(dateR)) {
		
		tmp_line.dateR = dateR.toStdString();
	}
	else {
		tmp_line.dateR = db[i].dateR;
	}
	db[i] = tmp_line;
	showTable(db);
	isEdited = true;
	return true;
}

void UsersTabView::showTable(std::vector <dataBaseU> DataBase)
{
	table = new QStandardItemModel;

	int line = 0;
	int col = 0;
	QStringList upperHeader;
	upperHeader.append("Status");
	upperHeader.append("Login");
	upperHeader.append("Password");
	upperHeader.append("First Name");
	upperHeader.append("Second Name");
	upperHeader.append("Date of regestration");



	table->setHorizontalHeaderLabels(upperHeader);

	dataBaseU tmp_data;

	for (int i = 0; i < DataBase.size(); i++) {

		tmp_data = DataBase[i];
		col = 0;
		table->setItem(line, col, fromStdString(tmp_data.status));//status
		col++;
		table->setItem(line, col, fromStdString(tmp_data.login));//login
		col++;
		table->setItem(line, col, fromStdString(tmp_data.password));//password
		col++;
		table->setItem(line, col, fromStdString(tmp_data.fstName));//1 name
		col++;
		table->setItem(line, col, fromStdString(tmp_data.scndName));//2 name
		col++;
		table->setItem(line, col, fromStdString(tmp_data.dateR));//date of reg
		col++;
		line++;


	}



	ui.tableView_userData->setModel(table);

	ui.tableView_userData->resizeRowsToContents();
	ui.tableView_userData->resizeColumnsToContents();
}



bool UsersTabView::checkStatus(QString status)
{
	if (status == "manager" || status == "admin" || status == "user") {
		return true;
	}
	return false;
}

bool UsersTabView::checkPassword(QString password, QString login)
{
	std::string pass = password.toStdString();
	if (pass.find(login.toStdString()) != std::string::npos) {
		return false;
	}
	return true;
}

bool UsersTabView::on_pushButton_add_clicked() {

	QString status, login, password, fstName, scndName;
	status = ui.lineEdit_Status->text();
	login = ui.lineEdit_Login->text();
	password = ui.lineEdit_Password->text();
	fstName = ui.lineEdit_FirstName->text();
	scndName = ui.lineEdit_ScndName->text();
	dataBaseU tmp_db;
	time_t t;
	t = time(NULL);
	if (isEmpty(status) || !checkStatus(status)) {
		showErrorWithText("Invalid Status");
		return false;
	}
	if (isEmpty(login)) {
		showErrorWithText("Invalid Login");
		return false;
	}
	if (findElements(1, login.toStdString(), db)) {
		showErrorWithText("This login is already in data base");
		searchedDB.clear();
		return false;
	}
	if (isEmpty(password) || !checkPassword(password, login)) {
		showErrorWithText("Invalid password");
		return false;
	}
	if (isEmpty(fstName)) {
		showErrorWithText("Invalid first name");
		return false;
	}
	if (isEmpty(scndName)) {
		showErrorWithText("Invalid second name");
		return false;
	}
	
	tmp_db.status = status.toStdString();
	tmp_db.login = login.toStdString();
	tmp_db.password = password.toStdString();
	tmp_db.fstName = fstName.toStdString();
	tmp_db.scndName = scndName.toStdString();
	tmp_db.dateR = std::string(ctime(&t));

	tmp_db.dateR.resize(tmp_db.dateR.length() - 1);
	
	db.push_back(tmp_db);

	showTable(db);
}



