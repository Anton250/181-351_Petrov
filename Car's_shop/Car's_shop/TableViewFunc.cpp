#include "TableViewFunc.h"



TableViewFunc::TableViewFunc()
{
}


TableViewFunc::~TableViewFunc()
{
}

QStandardItem * TableViewFunc::getElementFromFile(int lenght, char endElem, std::string & File)
{
	QStandardItem * it;
	int endPos = 0;
	File.erase(0, lenght);
	endPos = File.find(endElem);
	QString output;
	it = new QStandardItem(output.fromStdString(File.substr(0, endPos)));
	File.erase(0, endPos + 1);
	return it;
}

std::string TableViewFunc::getStringElementFromFile(int lenght, char endElem, std::string & File)
{
	std::string  it;
	int endPos = 0;
	File.erase(0, lenght);
	endPos = File.find(endElem);
	it = File.substr(0, endPos);
	File.erase(0, endPos + 1);
	return it;
}

bool TableViewFunc::isEmpty(QString check)
{
	if (check == NULL) {
		return true;
	}
	return false;
}

void TableViewFunc::showErrorWithText(QString text)
{
	QMessageBox msgBox;
	msgBox.setText(text + '!');
	msgBox.exec();
}

bool TableViewFunc::openFile(std::string path, std::string & destanation)
{
	std::ifstream file;
	file.open(path);
	file.seekg(0, file.end);
	int lenght = file.tellg();
	file.seekg(0, file.beg);
	char * buffer = new char[lenght + 1];
	file.read(buffer, lenght);
	destanation = std::string(buffer);
	file.close();
	return true;
}

bool TableViewFunc::searchInStr(std::string firstWord, std::string info, int positionDel, std::string & src)
{
	if (src.find(info) != std::string::npos) {
		std::string tmp_str;
		int pos;
		while (src.find(info) != std::string::npos) {
			pos = src.find(info) - positionDel;
			if (pos > 0) {
				src.erase(0, pos);
				src.erase(0, src.find(firstWord));
			}
			tmp_str += src.substr(0, src.find(";")) + ';';
			src.erase(0, src.find(";") + 1);
		}
		src = tmp_str;
		return true;
	}
	else {
		return false;
	}
}

QStandardItem * TableViewFunc::fromStdString(std::string str)
{
	QStandardItem * it;
	it = new QStandardItem(QString::fromStdString(str));
	return it;
}
