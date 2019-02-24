#include "ManagerWIndow.h"

ManagerWIndow::ManagerWIndow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

ManagerWIndow::~ManagerWIndow()
{
}

void ManagerWIndow::on_pushButton_showCars_clicked()
{
	
	carsTableWindow.show();
}

void ManagerWIndow::on_pushButton_exit_clicked() {
	this->close();
	emit firstWindow();
}

