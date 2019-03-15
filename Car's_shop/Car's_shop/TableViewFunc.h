#pragma once
#include <QWidget>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QTableView>
#include <QAbstractItemModel>
#include <QMessageBox>
#include <fstream>
class TableViewFunc
{
public:
	TableViewFunc();
	~TableViewFunc();
	QStandardItem * getElementFromFile(int lenght, char endElem, std::string &File);
	std::string getStringElementFromFile(int lenght, char endElem, std::string &File);
	bool isEmpty(QString check);
	void showErrorWithText(QString text);
	bool openFile(std::string path, std::string &destanation);
	bool searchInStr(std::string firstWord, std::string info, int positionDel, std::string &src);
	QStandardItem * fromStdString(std::string str);
};

