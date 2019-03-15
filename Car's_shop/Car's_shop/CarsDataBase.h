#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <QString>

struct dataBase {
	std::string regnum;
	std::string mark;
	std::string model;
	std::string color;
	std::string	price;
	std::string dateB;
	std::string dateS;
	std::string numshop;
};

class CarsDataBase
{
public:
	CarsDataBase();
	CarsDataBase(std::string * tmp);
	~CarsDataBase();
	bool createDB(std::string fileName);
	bool add_line(dataBase tmp_data);
	bool findElements(int critery, std::string strToFind, std::vector<dataBase> dBase);
	bool findElemToEditOrDelete(int &itertor, std::string toFind, std::vector<dataBase> db);
	bool checkRegnum(QString regnum);
	bool checkRegnumAdd(QString regnum);
	bool checkDate(QString date);
	bool checkNumshop(QString numshop);
	bool checkPrice(QString price);
	bool writeToFile(std::string fileName);
	bool isEdited = false;
	std::string getElement(std::string name, std::string line);
	std::vector<dataBase> db;
	std::vector<dataBase> searchedDB;
private:
	dataBase parsing(std::string line);
};

