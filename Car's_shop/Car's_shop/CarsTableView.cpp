#include "CarsTableView.h"


CarsTableView::CarsTableView(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	showTable();
}

CarsTableView::~CarsTableView()
{
	
}

void CarsTableView::on_pushButton_clear_clicked()
{
	ui.lineEdit_registration->clear();
	ui.lineEdit_mark->clear();
	ui.lineEdit_model->clear();
	ui.lineEdit_price->clear();
	ui.lineEdit_dateBuy->clear();;
	ui.lineEdit_dateSell->clear();
	ui.lineEdit_numberOfShop->clear();
}

void CarsTableView::showTable() {

	table = new QStandardItemModel;

	int line = 0;
	int col = 0;
	int startPos = 0;
	int endPos = 0;
	QStringList upperHeader;
	upperHeader.append("Registration number");
	upperHeader.append("Mark");
	upperHeader.append("Model");
	upperHeader.append("Price");
	upperHeader.append("Date of buying");
	upperHeader.append("Date of Sell");
	upperHeader.append("Number of shop");
	


	table->setHorizontalHeaderLabels(upperHeader);

	std::ifstream cars;
	std::string file;
	QString output;
	cars.open("Cars.txt");
	cars.seekg(0, cars.end);
	int lenght = cars.tellg();
	cars.seekg(0, cars.beg);
	char * buffer = new char[lenght + 1];
	cars.read(buffer, lenght);
	file = std::string(buffer);

	while (file.find("regnum") != std::string::npos) {

		col = 0;
		table->setItem(line, col, getElementFromFile(7, ':', file));//regnum
		col++;
		table->setItem(line, col, getElementFromFile(5, ':', file));//mark
		col++;
		table->setItem(line, col, getElementFromFile(6, ':', file));//model
		col++;
		table->setItem(line, col, getElementFromFile(6, ':', file));//price
		col++;
		table->setItem(line, col, getElementFromFile(6, ':', file));//date of buying
		col++;
		table->setItem(line, col, getElementFromFile(6, ':', file));//date of selling
		col++;
		table->setItem(line, col, getElementFromFile(8, ';', file));//numshop
		col++;
		line++;
		

	}

	

	ui.tableView_car->setModel(table);

	ui.tableView_car->resizeRowsToContents();
	ui.tableView_car->resizeColumnsToContents();
	cars.close();
}

QStandardItem * CarsTableView::getElementFromFile(int lenght, char endElem, std::string &File)
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

bool CarsTableView::on_pushButton_add_clicked()
{
	QString regnum, mark, model, price, dateB, dateS,  numshop;
	regnum = ui.lineEdit_registration->text();
	mark = ui.lineEdit_mark->text();
	model = ui.lineEdit_model->text();
	price = ui.lineEdit_price->text();
	dateB = ui.lineEdit_dateBuy->text();
	dateS = ui.lineEdit_dateSell->text();
	numshop = ui.lineEdit_numberOfShop->text();
	std::string output, cars_file;
	std::fstream file;
	if (isEmpty(regnum) || !check_regnum(regnum)) {
		showErrorWithText("Invalid Reg number");
		return false;
	}
	file.open("Cars.txt");
	file.seekg(0, file.end);
	int lenght = file.tellg();
	file.seekg(0, file.beg);
	char * buffer = new char[lenght + 1];
	file.read(buffer, lenght);
	cars_file = std::string(buffer);
	file.close();
	if (cars_file.find("regnum:" + regnum.toStdString() + ':') != std::string::npos) {
		showErrorWithText("This Reg number is already in data base");
		return false;
	}

	output += "regnum:" + regnum.toStdString() + ':';
	if (isEmpty(mark)) {
		showErrorWithText("Invalid Mark");
		return false;
	}
	output += "mark:" + mark.toStdString() + ':';
	if (isEmpty(model)) {
		showErrorWithText("Invalid Model");
		return false;
	}
	output += "model:" + model.toStdString() + ':';
	if (isEmpty(price) || !check_price(price)) {
		showErrorWithText("Invalid Price");
		return false;
	}
	output += "price:" + price.toStdString() + ':';
	if (isEmpty(dateB) || !check_date(dateB)) {
		showErrorWithText("Invalid Date of buy");
		return false;
	}
	output += "dateB:" + dateB.toStdString() + ':';
	if (dateS != '-') {
		if (isEmpty(dateS) || !check_selled(dateS)) {
			showErrorWithText("Invalid Date of Sell");
			return false;
		}
	}
	output += "dateS:" + dateS.toStdString() + ':';
	if (isEmpty(numshop) || !check_numshop(numshop)) {
		showErrorWithText("Invalid Shop's number");
		return false;
	}
	output += "numshop:" + numshop.toStdString() + ';';
	file.open("Cars.txt", std::fstream::app | std::fstream::out);
	file << output;
	file.close();
	showTable();
}

bool CarsTableView::check_regnum(QString regnum)
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

bool CarsTableView::check_date(QString date)
{
	std::string check = date.toStdString();

	if (check.length() > 10) {
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

bool CarsTableView::check_numshop(QString numshop)
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

bool CarsTableView::check_price(QString price)
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

bool CarsTableView::check_selled(QString selled)
{
	std::string check = selled.toStdString();
	if (check == "No" || check == "Yes") {
		return true;
	}
	return false;
}

bool CarsTableView::check_name(QString name)
{

	return false;
}

bool CarsTableView::isEmpty(QString check)
{
	if (check == NULL) {
		return true;
	}
	return false;
}

void CarsTableView::showErrorWithText(QString text)
{
	QMessageBox msgBox;
	msgBox.setText(text + '!');
	msgBox.exec();
}

