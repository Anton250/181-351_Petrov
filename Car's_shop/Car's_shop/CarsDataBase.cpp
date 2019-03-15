#include "CarsDataBase.h"



CarsDataBase::CarsDataBase()
{
}


CarsDataBase::~CarsDataBase()
{
}

dataBase CarsDataBase::parsing(std::string line)
{
	dataBase tmp;
	tmp.regnum = getElement("regnum:", line);
	tmp.mark = getElement("mark:", line);
	tmp.model = getElement("model:", line);
	tmp.color = getElement("clr:", line);
	tmp.price = getElement("price:", line);
	tmp.dateB = getElement("dateB:", line);
	tmp.dateS = getElement("dateS:", line);
	tmp.numshop = getElement("numshop:", line);

	return tmp;
}

bool CarsDataBase::createDB(std::string fileName)
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

bool CarsDataBase::add_line(dataBase tmp_data)
{
	db.push_back(tmp_data);
	return false;
}

bool CarsDataBase::findElements(int critery, std::string strToFind, std::vector<dataBase> dBase)
{
	std::vector<dataBase> tmp_DB;
	if (critery == 1) {
		for (int i = 0; i < dBase.size(); i++) {
			if (dBase[i].regnum == strToFind) {
				searchedDB.push_back(dBase[i]);
				return true;
			}
		}
	}
	if (critery == 2) {
		for (int i = 0; i < dBase.size(); i++) {
			if (dBase[i].mark == strToFind) {
				tmp_DB.push_back(dBase[i]);
			}
		}
	}
	if (critery == 3) {
		for (int i = 0; i < dBase.size(); i++) {
			if (dBase[i].model == strToFind) {
				tmp_DB.push_back(dBase[i]);
			}
		}
	}
	if (critery == 4) {
		for (int i = 0; i < dBase.size(); i++) {
			if (dBase[i].color == strToFind) {
				tmp_DB.push_back(dBase[i]);
			}
		}
	}
	if (critery == 5) {
		for (int i = 0; i < dBase.size(); i++) {
			if (dBase[i].price == strToFind) {
				tmp_DB.push_back(dBase[i]);
			}
		}
	}
	if (critery == 6) {
		for (int i = 0; i < dBase.size(); i++) {
			if (dBase[i].dateB == strToFind) {
				tmp_DB.push_back(dBase[i]);
			}
		}
	}
	if (critery == 7) {
		for (int i = 0; i < dBase.size(); i++) {
			if (dBase[i].dateS == strToFind) {
				tmp_DB.push_back(dBase[i]);
			}
		}
	}
	if (critery == 8) {
		for (int i = 0; i < dBase.size(); i++) {
			if (dBase[i].numshop == strToFind) {
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

bool CarsDataBase::findElemToEditOrDelete(int & iterator, std::string toFind, std::vector<dataBase> db)
{
	
	
		for (int i = 0; i < db.size(); i++) {
			if (db[i].regnum == toFind) {
				iterator = i;
				return true;
			}
		}
	
	return false;
}

bool CarsDataBase::checkRegnum(QString regnum)
{
	std::string check = regnum.toStdString();
	if (check.length() > 5) {
		return false;
	}
	for (int i = 0; i < 5; i++) {
		if (check[i] < '0' || check[i] > '9') {
			return false;
		}
	}
	return true;
}

bool CarsDataBase::checkRegnumAdd(QString regnum)
{
	std::string check = regnum.toStdString();
	if (check.length() > 5) {
		return false;
	}
	for (int i = 0; i < 5; i++) {
		if (check[i] < '0' || check[i] > '9') {
			return false;
		}
	}
	
		for (int i = 0; i < db.size(); i++) {
			if (db[i].regnum == check) {
				return false;
			}
		}
	
	return true;
}

bool CarsDataBase::checkDate(QString date)
{
	std::string check = date.toStdString();

	if (check.length() != 10) {
		return false;
	}

	if (check[2] != '.' || check[5] != '.') {
		return false;
	}

	if (check[0] > '3') {
		return false;
	}

	if (check[0] == '0' && check[1] == '0') {
		return false;
	}

	switch (check[3]) {
	case '0':
		if (check[4] == '0') return false;
		if (check[4] == '1' || check[4] == '3' || check[4] == '5' || check[4] == '7' || check[4] == '8') {
			if (check[0] == '3') {
				if (check[1] > '1') {
					return false;
				}
			}
		}
		if (check[4] == '2' || check[4] == '4' || check[4] == '6' || check[4] == '9') {
			if (check[0] == '3') {
				if (check[1] > '0') {
					return false;
				}
			}
		}
		break;
	case '1':
		if (check[4] == '1') {
			if (check[0] == '3') {
				if (check[1] > '0') {
					return false;
				}
			}
		}
		if (check[4] == '0' || check[4] == '2') {
			if (check[0] == '3') {
				if (check[1] > '1') {
					return false;
				}
			}
		}
		if (check[4] > '2') {
			return false;
		}
		break;
	default:
		return false;
	}

	return true;
}

bool CarsDataBase::checkNumshop(QString numshop)
{
	std::string check = numshop.toStdString();
	if (check.length() > 2) {
		return false;
	}
	for (int i = 0; i < check.length(); i++) {
		if (check[i] < '0' || check[i] > '9') {
			return false;
		}
	}
	return true;
}

bool CarsDataBase::checkPrice(QString price)
{
	std::string check = price.toStdString();
	for (int i = 0; i < check.length() - 1; i++) {
		if (check[i] < '0' || check[i] > '9') {
			return false;
		}
	}
	if (check[check.length() - 1] != '$') {
		return false;
	}
	return true;
}

bool CarsDataBase::writeToFile(std::string fileName)
{
	std::ofstream file;
	file.open(fileName);
	for (int i = 0; i < db.size() - 1; i++) {
		file << "regnum:" << db[i].regnum; 
		file << ":mark:" << db[i].mark;
		file << ":model:" << db[i].model;
		file << ":clr:" << db[i].color;
		file << ":price:" << db[i].price;
		file << ":dateB:" << db[i].dateB;
		file << ":dateS:" << db[i].dateS;
		file << ":numshop:" << db[i].numshop << ":\n";
	}
	int size = db.size() - 1;
	file << "regnum:" << db[size].regnum;
	file << ":mark:" << db[size].mark;
	file << ":model:" << db[size].model;
	file << ":clr:" << db[size].color;
	file << ":price:" << db[size].price;
	file << ":dateB:" << db[size].dateB;
	file << ":dateS:" << db[size].dateS;
	file << ":numshop:" << db[size].numshop << ":";
	return true;
}

std::string CarsDataBase::getElement(std::string name, std::string line)
{
	int pos, endPos;
	pos = line.find(name);
	std::string tmp_str;
	if (pos != std::string::npos) {
		line.erase(0, pos + name.length());
		endPos = line.find(':');
		tmp_str = line.substr(0, endPos);
		line.erase(0, endPos + 1);
		return tmp_str;
	}
	else {
		return "-";
	}
}
