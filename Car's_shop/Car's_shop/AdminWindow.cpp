#include "AdminWIndow.h"

QtGui::QtGui(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

QtGui::~QtGui()
{
}
void QtGui::on_pushButton_exit_clicked() {
	this->close();
	emit firstWindow();
}
