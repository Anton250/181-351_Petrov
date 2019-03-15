/********************************************************************************
** Form generated from reading UI file 'CarsTableView.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARSTABLEVIEW_H
#define UI_CARSTABLEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CarsTableView
{
public:
    QTableView *tableView_car;
    QLineEdit *lineEdit_registration;
    QLineEdit *lineEdit_mark;
    QLineEdit *lineEdit_model;
    QLineEdit *lineEdit_price;
    QLineEdit *lineEdit_dateSell;
    QLineEdit *lineEdit_numberOfShop;
    QLabel *label_Reg;
    QLabel *label_name;
    QLabel *label_price;
    QLabel *label_date;
    QLabel *label_isSelled;
    QLabel *label_shopNumber;
    QPushButton *pushButton_search;
    QPushButton *pushButton_edit;
    QPushButton *pushButton_add;
    QPushButton *pushButton_clear;
    QLineEdit *lineEdit_dateBuy;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_color;
    QPushButton *pushButton_delete;

    void setupUi(QWidget *CarsTableView)
    {
        if (CarsTableView->objectName().isEmpty())
            CarsTableView->setObjectName(QString::fromUtf8("CarsTableView"));
        CarsTableView->resize(1022, 709);
        tableView_car = new QTableView(CarsTableView);
        tableView_car->setObjectName(QString::fromUtf8("tableView_car"));
        tableView_car->setGeometry(QRect(0, 0, 1021, 571));
        lineEdit_registration = new QLineEdit(CarsTableView);
        lineEdit_registration->setObjectName(QString::fromUtf8("lineEdit_registration"));
        lineEdit_registration->setGeometry(QRect(110, 580, 113, 22));
        lineEdit_mark = new QLineEdit(CarsTableView);
        lineEdit_mark->setObjectName(QString::fromUtf8("lineEdit_mark"));
        lineEdit_mark->setGeometry(QRect(110, 610, 113, 22));
        lineEdit_model = new QLineEdit(CarsTableView);
        lineEdit_model->setObjectName(QString::fromUtf8("lineEdit_model"));
        lineEdit_model->setGeometry(QRect(110, 640, 113, 22));
        lineEdit_price = new QLineEdit(CarsTableView);
        lineEdit_price->setObjectName(QString::fromUtf8("lineEdit_price"));
        lineEdit_price->setGeometry(QRect(380, 580, 113, 22));
        lineEdit_dateSell = new QLineEdit(CarsTableView);
        lineEdit_dateSell->setObjectName(QString::fromUtf8("lineEdit_dateSell"));
        lineEdit_dateSell->setGeometry(QRect(380, 640, 113, 22));
        lineEdit_numberOfShop = new QLineEdit(CarsTableView);
        lineEdit_numberOfShop->setObjectName(QString::fromUtf8("lineEdit_numberOfShop"));
        lineEdit_numberOfShop->setGeometry(QRect(380, 670, 113, 22));
        label_Reg = new QLabel(CarsTableView);
        label_Reg->setObjectName(QString::fromUtf8("label_Reg"));
        label_Reg->setGeometry(QRect(0, 570, 111, 31));
        QFont font;
        font.setPointSize(12);
        label_Reg->setFont(font);
        label_name = new QLabel(CarsTableView);
        label_name->setObjectName(QString::fromUtf8("label_name"));
        label_name->setGeometry(QRect(60, 610, 55, 16));
        label_name->setFont(font);
        label_price = new QLabel(CarsTableView);
        label_price->setObjectName(QString::fromUtf8("label_price"));
        label_price->setGeometry(QRect(320, 580, 55, 16));
        label_price->setFont(font);
        label_date = new QLabel(CarsTableView);
        label_date->setObjectName(QString::fromUtf8("label_date"));
        label_date->setGeometry(QRect(240, 600, 131, 31));
        label_date->setFont(font);
        label_isSelled = new QLabel(CarsTableView);
        label_isSelled->setObjectName(QString::fromUtf8("label_isSelled"));
        label_isSelled->setGeometry(QRect(260, 640, 121, 16));
        label_isSelled->setFont(font);
        label_shopNumber = new QLabel(CarsTableView);
        label_shopNumber->setObjectName(QString::fromUtf8("label_shopNumber"));
        label_shopNumber->setGeometry(QRect(230, 670, 151, 20));
        label_shopNumber->setFont(font);
        pushButton_search = new QPushButton(CarsTableView);
        pushButton_search->setObjectName(QString::fromUtf8("pushButton_search"));
        pushButton_search->setGeometry(QRect(500, 660, 93, 28));
        pushButton_edit = new QPushButton(CarsTableView);
        pushButton_edit->setObjectName(QString::fromUtf8("pushButton_edit"));
        pushButton_edit->setGeometry(QRect(680, 660, 93, 28));
        pushButton_add = new QPushButton(CarsTableView);
        pushButton_add->setObjectName(QString::fromUtf8("pushButton_add"));
        pushButton_add->setGeometry(QRect(590, 660, 93, 28));
        pushButton_clear = new QPushButton(CarsTableView);
        pushButton_clear->setObjectName(QString::fromUtf8("pushButton_clear"));
        pushButton_clear->setGeometry(QRect(500, 580, 93, 28));
        lineEdit_dateBuy = new QLineEdit(CarsTableView);
        lineEdit_dateBuy->setObjectName(QString::fromUtf8("lineEdit_dateBuy"));
        lineEdit_dateBuy->setGeometry(QRect(380, 610, 113, 22));
        label = new QLabel(CarsTableView);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 640, 71, 16));
        label->setFont(font);
        label_2 = new QLabel(CarsTableView);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 670, 55, 16));
        label_2->setFont(font);
        lineEdit_color = new QLineEdit(CarsTableView);
        lineEdit_color->setObjectName(QString::fromUtf8("lineEdit_color"));
        lineEdit_color->setGeometry(QRect(110, 670, 113, 22));
        pushButton_delete = new QPushButton(CarsTableView);
        pushButton_delete->setObjectName(QString::fromUtf8("pushButton_delete"));
        pushButton_delete->setGeometry(QRect(770, 660, 93, 28));

        retranslateUi(CarsTableView);

        QMetaObject::connectSlotsByName(CarsTableView);
    } // setupUi

    void retranslateUi(QWidget *CarsTableView)
    {
        CarsTableView->setWindowTitle(QApplication::translate("CarsTableView", "CarsTableView", nullptr));
        label_Reg->setText(QApplication::translate("CarsTableView", "RegNumber", nullptr));
        label_name->setText(QApplication::translate("CarsTableView", "Mark", nullptr));
        label_price->setText(QApplication::translate("CarsTableView", "Price", nullptr));
        label_date->setText(QApplication::translate("CarsTableView", "Date of buying", nullptr));
        label_isSelled->setText(QApplication::translate("CarsTableView", "Date of Sell", nullptr));
        label_shopNumber->setText(QApplication::translate("CarsTableView", "Number of shop", nullptr));
        pushButton_search->setText(QApplication::translate("CarsTableView", "Search", nullptr));
        pushButton_edit->setText(QApplication::translate("CarsTableView", "Edit", nullptr));
        pushButton_add->setText(QApplication::translate("CarsTableView", "Add", nullptr));
        pushButton_clear->setText(QApplication::translate("CarsTableView", "Clear", nullptr));
        label->setText(QApplication::translate("CarsTableView", "Model", nullptr));
        label_2->setText(QApplication::translate("CarsTableView", "Color", nullptr));
        pushButton_delete->setText(QApplication::translate("CarsTableView", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CarsTableView: public Ui_CarsTableView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARSTABLEVIEW_H
