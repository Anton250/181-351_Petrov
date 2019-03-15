#include "ManagerWIndow.h"

ManagerWIndow::ManagerWIndow(QWidget *parent)
	: QWidget(parent)
{
	
	ui.setupUi(this);
}

ManagerWIndow::~ManagerWIndow()
{
}

void ManagerWIndow::writeCurUsr(std::string curentUsr)
{
	curUsr = curentUsr;
}

void ManagerWIndow::on_pushButton_showCars_clicked()
{
	carsTableWindow.show();
}

void ManagerWIndow::on_pushButton_userData_clicked()
{
	userTableWindow.show();
}

void ManagerWIndow::showInfo()
{
	if (curUsr.find("status:user:") != std::string::npos) {
		ui.pushButton_userData->close();
		carsTableWindow.closeForUser();
	}
	ui.label_Status->setText(QString::fromStdString(getStringElementFromFile(7, ':', curUsr)));
	ui.label_Login->setText(QString::fromStdString(getStringElementFromFile(6, ':', curUsr)));
	ui.label_Password->setText(QString::fromStdString(getStringElementFromFile(9, ':', curUsr)));
	ui.label_FirstName->setText(QString::fromStdString(getStringElementFromFile(8, ':', curUsr)));
	ui.label_ScndName->setText(QString::fromStdString(getStringElementFromFile(9, ':', curUsr)));
	ui.label_DateOfReg->setText(QString::fromStdString(getStringElementFromFile(5, ';', curUsr)));
}

void ManagerWIndow::on_pushButton_exit_clicked() {
	carsTableWindow.close();
	userTableWindow.close();
	this->close();
	emit firstWindow();
}

