#include "UserWindow.h"

UserWindow::UserWindow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

UserWindow::~UserWindow()
{
}

void UserWindow::on_pushButton_exit_clicked() {
	this->close();
	emit firstWindow();
}
