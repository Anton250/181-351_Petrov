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

	}
	else {

		showCarsTable();
		ui.tabWidget->removeTab(1);
		ui.pushButton_enableEditCars->close();

	}
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
	model->setHeaderData(4, Qt::Horizontal, QObject::tr("Price"));
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
	model->setHeaderData(0, Qt::Horizontal, QObject::tr("Status"));
	model->setHeaderData(1, Qt::Horizontal, QObject::tr("Login"));
	model->setHeaderData(2, Qt::Horizontal, QObject::tr("Password"));
	model->setHeaderData(3, Qt::Horizontal, QObject::tr("First name"));
	model->setHeaderData(4, Qt::Horizontal, QObject::tr("Last name"));
	model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date of regestration"));
	bool okey = model->select();

	ui.usersTable->setModel(model);
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

void SecondWindow::readFromServer()
{

	QString answer = clientSocket->readAll();
	QByteArray arr;
	arr.append(answer);
	clientSocket->write(arr);
	std::string strAnswer = answer.toStdString();

	if (strAnswer.find("updateCarsTable$") != std::string::npos) {
		showCarsTable();
	}

	if (strAnswer.find("updateUsersTable$") != std::string::npos) {
		if (curUser.toStdString().find("manager:")) {
			showUsersTable();
		}
	}

}

void SecondWindow::disconnect()
{
	clientSocket->deleteLater();
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
}