#include "CarsTableView.h"


CarsTableView::CarsTableView(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	createDB("Cars.txt");
	showTable(db);
}

CarsTableView::~CarsTableView()
{
	if (isEdited) {
		writeToFile("Cars.txt");
	}
}

void CarsTableView::closeForUser()
{
	ui.pushButton_add->close();
	ui.pushButton_delete->close();
	ui.pushButton_edit->close();
}

void CarsTableView::on_pushButton_clear_clicked()
{
	ui.lineEdit_registration->clear();
	ui.lineEdit_mark->clear();
	ui.lineEdit_model->clear();
	ui.lineEdit_color->clear();
	ui.lineEdit_price->clear();
	ui.lineEdit_dateBuy->clear();;
	ui.lineEdit_dateSell->clear();
	ui.lineEdit_numberOfShop->clear();
	searchedDB.clear();
	showTable(db);
}

bool CarsTableView::on_pushButton_search_clicked()
{
	QString regnum, mark, model, color, price, dateB, dateS, numshop;
	regnum = ui.lineEdit_registration->text();
	mark = ui.lineEdit_mark->text();
	model = ui.lineEdit_model->text();
	color = ui.lineEdit_color->text();
	price = ui.lineEdit_price->text();
	dateB = ui.lineEdit_dateBuy->text();
	dateS = ui.lineEdit_dateSell->text();
	numshop = ui.lineEdit_numberOfShop->text();
	bool isFinded = false;
	if (!isEmpty(regnum)) {
		if (checkRegnum(regnum)) {
			if (findElements(1, regnum.toStdString(), db)) {
				showTable(searchedDB);
				return true;
			}
			else {
				showErrorWithText("There is no such cars");
				return false;
			}
		}
		else {
			showErrorWithText("Invalid regnum");
			return false;
		}
	}

	if (!isEmpty(mark)) {
		if (searchedDB.size() != 0) {
			isFinded = findElements(2, mark.toStdString(), searchedDB);
		}
		else {
			isFinded = findElements(2, mark.toStdString(), db);
		}
	}
	if (!isEmpty(model)) {
		if (searchedDB.size() != 0) {
			isFinded = findElements(3, model.toStdString(), searchedDB);
		}
		else {
			isFinded = findElements(3, model.toStdString(), db);
		}
	}
	if (!isEmpty(color)) {
		if (searchedDB.size() != 0) {
			isFinded = findElements(4, color.toStdString(), searchedDB);
		}
		else {
			isFinded = findElements(4, color.toStdString(), db);
		}
	}
	if (!isEmpty(price)) {
		if (checkPrice(price)) {
			if (searchedDB.size() != 0) {
				isFinded = findElements(5, price.toStdString(), searchedDB);
			}
			else {
				isFinded = findElements(5, price.toStdString(), db);
			}
		}
		else {
			showErrorWithText("Invalid price");
			return false;
		}
	}
	if (!isEmpty(dateB)) {
		if (checkDate(dateB)) {
			if (searchedDB.size() != 0) {
				isFinded = findElements(6, dateB.toStdString(), searchedDB);
			}
			else {
				isFinded = findElements(6, dateB.toStdString(), db);
			}
		}
		else {
			showErrorWithText("Invalid date");
			return false;
		}
	}
	if (!isEmpty(dateS)) {
		if (checkDate(dateS) || dateS == "-") {
			if (searchedDB.size() != 0) {
				isFinded = findElements(7, dateS.toStdString(), searchedDB);
			}
			else {
				isFinded = findElements(7, dateS.toStdString(), db);
			}
		}
		else {
			showErrorWithText("Invalid date");
			return false;
		}
	}
	if (!isEmpty(numshop)) {
		if (checkNumshop(numshop)) {
			if (searchedDB.size() != 0) {
				isFinded = findElements(8, numshop.toStdString(), searchedDB);
			}
			else {
				isFinded = findElements(8, numshop.toStdString(), db);
			}
		}
		else {
			showErrorWithText("Invalid numshop");
			return false;
		}
	}
	if (isFinded) {
		showTable(searchedDB);
		searchedDB.clear();
		return true;
	}
	else {
		showErrorWithText("There is no such cars");
		return false;
	}
	
}

bool CarsTableView::on_pushButton_delete_clicked()
{
	QString regnum;
	int i;
	regnum = ui.lineEdit_registration->text();

	if (isEmpty(regnum)) {
		showErrorWithText("You need to write Reg number to delete text");
		return false;
	}
	if (!checkRegnum(regnum)) {
		showErrorWithText("Invalid Reg number");
		return false;
	}
	if (!findElemToEditOrDelete(i, regnum.toStdString(), db)) {
		showErrorWithText("There is no such car");
		return false;
	}
	db.erase(db.begin() + i);
	showTable(db);
	isEdited = true;
	return true;
}

bool CarsTableView::on_pushButton_edit_clicked()
{
	QString regnum;
	dataBase tmp_line;
	int i;
	regnum = ui.lineEdit_registration->text();

	if (isEmpty(regnum)) {
		showErrorWithText("You need to write Reg number to edit text");
		return false;
	}
	if (!checkRegnum(regnum)) {
		showErrorWithText("Invalid Reg number");
		return false;
	}
	if (!findElemToEditOrDelete(i, regnum.toStdString(), db)) {
		showErrorWithText("There is no such car");
		return false;
	}
	tmp_line.regnum = regnum.toStdString();
	QString mark, model, color, price, dateB, dateS, numshop;
	mark = ui.lineEdit_mark->text();
	model = ui.lineEdit_model->text();
	color = ui.lineEdit_color->text();
	price = ui.lineEdit_price->text();
	dateB = ui.lineEdit_dateBuy->text();
	dateS = ui.lineEdit_dateSell->text();
	numshop = ui.lineEdit_numberOfShop->text();

	if (!isEmpty(mark)) {
		tmp_line.mark = mark.toStdString();
	}
	else {
		tmp_line.mark = db[i].mark;
	}
	if (!isEmpty(model)) {
		tmp_line.model = model.toStdString();
	}
	else {
		tmp_line.model = db[i].model;
	}
	if (!isEmpty(color)) {
		tmp_line.color = color.toStdString();
	}
	else {
		tmp_line.color = db[i].color;
	}
	if (!isEmpty(price)) {
		if (!checkPrice(price)) {
			showErrorWithText("Invalid price");
			return false;
		}
		tmp_line.price = price.toStdString();
	}
	else {
		tmp_line.price = db[i].price;
	}
	if (!isEmpty(dateB)) {
		if (!checkDate(dateB)) {
			showErrorWithText("Invalid Date buy");
			return false;
		}
		tmp_line.dateB = dateB.toStdString();
	}
	else {
		tmp_line.dateB = db[i].dateB;
	}
	if (!isEmpty(dateS)) {
		if (dateS != '-'){
			if (!checkDate(dateS)) {
				showErrorWithText("Invalid Date Sell");
				return false;
			}
		}
		
		tmp_line.dateS = dateS.toStdString();
		
	}
	else {
		tmp_line.dateS = db[i].dateS;
	}
	if (!isEmpty(numshop)) {
		if (!checkNumshop(numshop)) {
			showErrorWithText("Invalid number of shop");
			return false;
		}
		tmp_line.numshop = numshop.toStdString();
	}
	else {
		tmp_line.numshop = db[i].numshop;
	}
	db[i] = tmp_line;
	showTable(db);
	isEdited = true;
	return true;

}

void CarsTableView::showTable(std::vector <dataBase> DataBase) {

	table = new QStandardItemModel;

	int line = 0;
	int col = 0;
	QStringList upperHeader;
	upperHeader.append("Registration number");
	upperHeader.append("Mark");
	upperHeader.append("Model");
	upperHeader.append("Color");
	upperHeader.append("Price");
	upperHeader.append("Date of buying");
	upperHeader.append("Date of Sell");
	upperHeader.append("Number of shop");
	
	table->setHorizontalHeaderLabels(upperHeader);

	dataBase tmp_data;

	for (int i = 0; i < DataBase.size(); i++) {
		tmp_data = DataBase[i];
		col = 0;
		table->setItem(line, col, fromStdString(tmp_data.regnum));//regnum
		col++;
		table->setItem(line, col, fromStdString(tmp_data.mark));//mark
		col++;
		table->setItem(line, col, fromStdString(tmp_data.model));//model
		col++;
		table->setItem(line, col, fromStdString(tmp_data.color));//color
		col++;
		table->setItem(line, col, fromStdString(tmp_data.price));//price
		col++;
		table->setItem(line, col, fromStdString(tmp_data.dateB));//date of buying
		col++;
		table->setItem(line, col, fromStdString(tmp_data.dateS));//date of selling
		col++;
		table->setItem(line, col, fromStdString(tmp_data.numshop));//numshop
		col++;
		line++;
	}

	ui.tableView_car->setModel(table);

	ui.tableView_car->resizeRowsToContents();
	ui.tableView_car->resizeColumnsToContents();
}



bool CarsTableView::on_pushButton_add_clicked()
{
	QString regnum, mark, model, color, price, dateB, dateS, numshop;
	regnum = ui.lineEdit_registration->text();
	mark = ui.lineEdit_mark->text();
	model = ui.lineEdit_model->text();
	color = ui.lineEdit_color->text();
	price = ui.lineEdit_price->text();
	dateB = ui.lineEdit_dateBuy->text();
	dateS = ui.lineEdit_dateSell->text();
	numshop = ui.lineEdit_numberOfShop->text();
	std::string output, cars_file;
	dataBase tmp_data;
	if (isEmpty(regnum) || !checkRegnumAdd(regnum)) {
		showErrorWithText("Invalid reg number or this reg number is already in data base");
		return false;
	}
	tmp_data.regnum = regnum.toStdString();
	if (isEmpty(mark)) {
		showErrorWithText("Invalid mark");
		return false;
	}
	
	tmp_data.mark = mark.toStdString();
	
	if (isEmpty(model)) {
		showErrorWithText("Invalid model");
		return false;
	}
	tmp_data.model = model.toStdString();
	if (isEmpty(color)) {
		tmp_data.color = "-";
	}
	else {
		tmp_data.color = color.toStdString();
	}
	if (!checkPrice(price)) {
		showErrorWithText("Invalid Price");
		return false;
	} 
	if (isEmpty(price)) {
		tmp_data.price = "-";
	} else {
		tmp_data.price = price.toStdString();
	}
	if (isEmpty(dateB) || !checkDate(dateB)) {
		showErrorWithText("Invalid Date of buy");
		return false;
	}
	tmp_data.dateB = dateB.toStdString();
	
	if (!checkDate(dateS)) {
		showErrorWithText("Invalid Date of Sell");
		return false;
	}
	if (isEmpty(dateS)) {
		tmp_data.dateS = "-";
	}
	else {
		tmp_data.dateS = dateS.toStdString();
	}
	
	if (isEmpty(numshop) || !checkNumshop(numshop)) {
		showErrorWithText("Invalid Shop's number");
		return false;
	}
	tmp_data.numshop = numshop.toStdString();
	add_line(tmp_data);
	
	showTable(db);
	isEdited = true;
	return true;
}

