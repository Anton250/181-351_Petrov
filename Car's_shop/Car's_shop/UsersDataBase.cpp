#include "UsersDataBase.h"



UsersDataBase::UsersDataBase()
{
}


UsersDataBase::~UsersDataBase()
{
}

bool UsersDataBase::createDB(std::string fileName)
{
	std::ifstream file;
	file.open(fileName);
	if (!file) {
		return false;
	}
	std::string tmp_str;
	while (!file.eof()) {
		std::getline(file, tmp_str);
		db.push_back(parsing(tmp_str));
	}
	file.close();
	return true;
}

bool UsersDataBase::add_line(dataBaseU tmp_data)
{
	db.push_back(tmp_data);
	return false;
}

bool UsersDataBase::findElements(int critery, std::string strToFind, std::vector<dataBaseU> dBase)
{
	std::vector<dataBaseU> tmp_DB;
	if (critery == 1) {
		for (int i = 0; i < dBase.size(); i++) {
			if (dBase[i].login == strToFind) {
				searchedDB.push_back(dBase[i]);
				return true;
			}
		}
	}
	if (critery == 2) {
		for (int i = 0; i < dBase.size(); i++) {
			if (dBase[i].status == strToFind) {
				tmp_DB.push_back(dBase[i]);
			}
		}
	}
	if (critery == 3) {
		for (int i = 0; i < dBase.size(); i++) {
			if (dBase[i].password == strToFind) {
				tmp_DB.push_back(dBase[i]);
			}
		}
	}
	if (critery == 4) {
		for (int i = 0; i < dBase.size(); i++) {
			if (dBase[i].fstName == strToFind) {
				tmp_DB.push_back(dBase[i]);
			}
		}
	}
	if (critery == 5) {
		for (int i = 0; i < dBase.size(); i++) {
			if (dBase[i].scndName == strToFind) {
				tmp_DB.push_back(dBase[i]);
			}
		}
	}
	if (critery == 6) {
		for (int i = 0; i < dBase.size(); i++) {
			if (dBase[i].dateR == strToFind) {
				tmp_DB.push_back(dBase[i]);
			}
		}
	}
	if (!tmp_DB.empty()) {
		searchedDB.clear();
		searchedDB = tmp_DB;
		return true;
	}
	else {
		return false;
	}
}

bool UsersDataBase::findElemToEditOrDelete(int & iterator, std::string toFind, std::vector<dataBaseU> db)
{
	for (int i = 0; i < db.size(); i++) {
		if (db[i].login == toFind) {
			iterator = i;
			return true;
		}
	}

	return false;
}

bool UsersDataBase::writeToFile(std::string fileName)
{
	std::ofstream file;
	file.open(fileName);
	for (int i = 0; i < db.size() - 1; i++) {
		file << "status:" << db[i].status;
		file << ":login:" << db[i].login;
		file << ":password:" << db[i].password;
		file << ":fstname:" << db[i].fstName;
		file << ":scndname:" << db[i].scndName;
		file << ":dateR:" << db[i].dateR << ";\n";
	}
	int size = db.size() - 1;
	file << "status:" << db[size].status;
	file << ":login:" << db[size].login;
	file << ":password:" << db[size].password;
	file << ":fstname:" << db[size].fstName;
	file << ":scndname:" << db[size].scndName;
	file << ":dateR:" << db[size].dateR << ";";
	return true;
}

bool UsersDataBase::checkStatus(QString status)
{
	if (status == "manager" || status == "admin" || status == "user") {
		return true;
	}
	return false;
}

bool UsersDataBase::checkPassword(QString password, QString login)
{
	std::string pass = password.toStdString();
	if (pass.find(login.toStdString()) != std::string::npos) {
		return false;
	}
	return true;
}

std::string UsersDataBase::getElement(std::string name, std::string line, char endChar)
{
	int pos, endPos;
	pos = line.find(name);
	std::string tmp_str;
	if (pos != std::string::npos) {
		line.erase(0, pos + name.length());
		endPos = line.find(endChar);
		tmp_str = line.substr(0, endPos);
		line.erase(0, endPos + 1);
		return tmp_str;
	}
	else {
		return "-";
	}
}

dataBaseU UsersDataBase::parsing(std::string line)
{
	dataBaseU tmp;
	tmp.status = getElement("status:", line, ':');
	tmp.login = getElement("login:", line, ':');
	tmp.password = getElement("password:", line, ':');
	tmp.fstName = getElement("fstname:", line, ':');
	tmp.scndName = getElement("scndname:", line, ':');
	tmp.dateR = getElement("dateR:", line, ';');
	return tmp;
}
