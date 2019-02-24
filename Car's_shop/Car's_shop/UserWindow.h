#pragma once

#include <QWidget>
#include "ui_UserWindow.h"

class UserWindow : public QWidget
{
	Q_OBJECT

public:
	UserWindow(QWidget *parent = Q_NULLPTR);
	~UserWindow();

private:
	Ui::UserWindow ui;
signals:
	void firstWindow();
private slots:
	void on_pushButton_exit_clicked();
};
