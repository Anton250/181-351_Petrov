#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <QString>

struct dataBaseU {
	std::string status;
	std::string login;
	std::string password;
	std::string fstName;
	std::string	scndName;
	std::string dateR;
};

class UsersDataBase
{
public:
	UsersDataBase();
	~UsersDataBase();
	bool createDB(std::string fileName);
	bool add_line(dataBaseU tmp_data);
	bool findElements(int critery, std::string strToFind, std::vector<dataBaseU> dBase);
	bool findElemToEditOrDelete(int &iterator, std::string toFind, std::vector<dataBaseU> db);
	bool writeToFile(std::string fileName);
	bool checkStatus(QString status);
	bool checkPassword(QString password, QString login);
	bool isEdited = false;
	std::string getElement(std::string name, std::string line, char endChar);
	std::vector<dataBaseU> db;
	std::vector<dataBaseU> searchedDB;
private:
	dataBaseU parsing(std::string line);
};

