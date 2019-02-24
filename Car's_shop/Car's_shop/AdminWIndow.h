#pragma once

#include <QWidget>
#include "ui_AdminWindow.h"


class QtGui : public QWidget
{
	Q_OBJECT

public:
	QtGui(QWidget *parent = Q_NULLPTR);
	~QtGui();
signals:
	void firstWindow();
private:
	Ui::QtGuiClass ui;
	
private slots:
	void on_pushButton_exit_clicked();
};
