/********************************************************************************
** Form generated from reading UI file 'SecondWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECONDWINDOW_H
#define UI_SECONDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SecondWindow
{
public:
    QTabWidget *tabWidget;
    QWidget *carsTab;
    QTableView *carsTable;
    QLineEdit *lineEdit_carId;
    QLineEdit *lineEdit_minPrice;
    QLineEdit *lineEdit_mark;
    QLineEdit *lineEdit_model;
    QLineEdit *lineEdit_color;
    QLineEdit *lineEdit_numShop;
    QLineEdit *lineEdit_maxPrice;
    QDateEdit *minDateB;
    QDateEdit *maxDateB;
    QLabel *label_minDateB;
    QLabel *label_maxDateB;
    QDateEdit *minDateS;
    QDateEdit *maxDateS;
    QLabel *label_minDateS;
    QLabel *label_maxDateS;
    QPushButton *pushButton_carsClear;
    QPushButton *pushButton_searchCars;
    QPushButton *pushButton_enableEditCars;
    QPushButton *pushButton_editCars;
    QPushButton *pushButton_deleteCars;
    QPushButton *pushButton_addCars;
    QPushButton *pushButton_disableEditCars;
    QWidget *usersTab;
    QTableView *usersTable;
    QLineEdit *lineEdit_status;
    QLineEdit *lineEdit_login;
    QLineEdit *lineEdit_fName;
    QLineEdit *lineEdit_password;
    QLineEdit *lineEdit_lName;
    QDateEdit *minDateR;
    QDateEdit *maxDateR;
    QLabel *label_minDateR;
    QLabel *label_maxDateR;
    QPushButton *pushButton_clearUsers;
    QPushButton *pushButton_searchUsers;
    QPushButton *pushButton_enableEditUsers;
    QPushButton *pushButton_addUsers;
    QPushButton *pushButton_deleteUsers;
    QPushButton *pushButton_editUsers;
    QPushButton *pushButton_cancelUsers;
    QWidget *settings;
    QPushButton *pushButton_exit;

    void setupUi(QWidget *SecondWindow)
    {
        if (SecondWindow->objectName().isEmpty())
            SecondWindow->setObjectName(QString::fromUtf8("SecondWindow"));
        SecondWindow->resize(1003, 567);
        tabWidget = new QTabWidget(SecondWindow);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 1001, 571));
        carsTab = new QWidget();
        carsTab->setObjectName(QString::fromUtf8("carsTab"));
        carsTable = new QTableView(carsTab);
        carsTable->setObjectName(QString::fromUtf8("carsTable"));
        carsTable->setGeometry(QRect(0, 100, 1001, 441));
        lineEdit_carId = new QLineEdit(carsTab);
        lineEdit_carId->setObjectName(QString::fromUtf8("lineEdit_carId"));
        lineEdit_carId->setGeometry(QRect(10, 10, 113, 22));
        lineEdit_minPrice = new QLineEdit(carsTab);
        lineEdit_minPrice->setObjectName(QString::fromUtf8("lineEdit_minPrice"));
        lineEdit_minPrice->setGeometry(QRect(10, 40, 113, 22));
        lineEdit_mark = new QLineEdit(carsTab);
        lineEdit_mark->setObjectName(QString::fromUtf8("lineEdit_mark"));
        lineEdit_mark->setGeometry(QRect(130, 10, 113, 22));
        lineEdit_model = new QLineEdit(carsTab);
        lineEdit_model->setObjectName(QString::fromUtf8("lineEdit_model"));
        lineEdit_model->setGeometry(QRect(250, 10, 113, 22));
        lineEdit_color = new QLineEdit(carsTab);
        lineEdit_color->setObjectName(QString::fromUtf8("lineEdit_color"));
        lineEdit_color->setGeometry(QRect(370, 10, 113, 22));
        lineEdit_numShop = new QLineEdit(carsTab);
        lineEdit_numShop->setObjectName(QString::fromUtf8("lineEdit_numShop"));
        lineEdit_numShop->setGeometry(QRect(490, 10, 113, 22));
        lineEdit_maxPrice = new QLineEdit(carsTab);
        lineEdit_maxPrice->setObjectName(QString::fromUtf8("lineEdit_maxPrice"));
        lineEdit_maxPrice->setGeometry(QRect(10, 70, 113, 22));
        minDateB = new QDateEdit(carsTab);
        minDateB->setObjectName(QString::fromUtf8("minDateB"));
        minDateB->setGeometry(QRect(250, 40, 110, 22));
        maxDateB = new QDateEdit(carsTab);
        maxDateB->setObjectName(QString::fromUtf8("maxDateB"));
        maxDateB->setGeometry(QRect(250, 70, 110, 22));
        label_minDateB = new QLabel(carsTab);
        label_minDateB->setObjectName(QString::fromUtf8("label_minDateB"));
        label_minDateB->setGeometry(QRect(140, 40, 111, 20));
        label_maxDateB = new QLabel(carsTab);
        label_maxDateB->setObjectName(QString::fromUtf8("label_maxDateB"));
        label_maxDateB->setGeometry(QRect(140, 70, 101, 16));
        minDateS = new QDateEdit(carsTab);
        minDateS->setObjectName(QString::fromUtf8("minDateS"));
        minDateS->setGeometry(QRect(490, 40, 110, 22));
        maxDateS = new QDateEdit(carsTab);
        maxDateS->setObjectName(QString::fromUtf8("maxDateS"));
        maxDateS->setGeometry(QRect(490, 70, 110, 22));
        label_minDateS = new QLabel(carsTab);
        label_minDateS->setObjectName(QString::fromUtf8("label_minDateS"));
        label_minDateS->setGeometry(QRect(380, 40, 111, 16));
        label_maxDateS = new QLabel(carsTab);
        label_maxDateS->setObjectName(QString::fromUtf8("label_maxDateS"));
        label_maxDateS->setGeometry(QRect(380, 70, 111, 16));
        pushButton_carsClear = new QPushButton(carsTab);
        pushButton_carsClear->setObjectName(QString::fromUtf8("pushButton_carsClear"));
        pushButton_carsClear->setGeometry(QRect(620, 10, 93, 28));
        pushButton_searchCars = new QPushButton(carsTab);
        pushButton_searchCars->setObjectName(QString::fromUtf8("pushButton_searchCars"));
        pushButton_searchCars->setGeometry(QRect(620, 40, 93, 28));
        pushButton_enableEditCars = new QPushButton(carsTab);
        pushButton_enableEditCars->setObjectName(QString::fromUtf8("pushButton_enableEditCars"));
        pushButton_enableEditCars->setGeometry(QRect(720, 10, 93, 28));
        pushButton_editCars = new QPushButton(carsTab);
        pushButton_editCars->setObjectName(QString::fromUtf8("pushButton_editCars"));
        pushButton_editCars->setGeometry(QRect(620, 70, 93, 28));
        pushButton_deleteCars = new QPushButton(carsTab);
        pushButton_deleteCars->setObjectName(QString::fromUtf8("pushButton_deleteCars"));
        pushButton_deleteCars->setGeometry(QRect(720, 70, 93, 28));
        pushButton_addCars = new QPushButton(carsTab);
        pushButton_addCars->setObjectName(QString::fromUtf8("pushButton_addCars"));
        pushButton_addCars->setGeometry(QRect(620, 40, 93, 28));
        pushButton_disableEditCars = new QPushButton(carsTab);
        pushButton_disableEditCars->setObjectName(QString::fromUtf8("pushButton_disableEditCars"));
        pushButton_disableEditCars->setGeometry(QRect(720, 40, 93, 28));
        tabWidget->addTab(carsTab, QString());
        usersTab = new QWidget();
        usersTab->setObjectName(QString::fromUtf8("usersTab"));
        usersTable = new QTableView(usersTab);
        usersTable->setObjectName(QString::fromUtf8("usersTable"));
        usersTable->setGeometry(QRect(0, 90, 1001, 451));
        lineEdit_status = new QLineEdit(usersTab);
        lineEdit_status->setObjectName(QString::fromUtf8("lineEdit_status"));
        lineEdit_status->setGeometry(QRect(10, 10, 113, 22));
        lineEdit_login = new QLineEdit(usersTab);
        lineEdit_login->setObjectName(QString::fromUtf8("lineEdit_login"));
        lineEdit_login->setGeometry(QRect(10, 50, 113, 22));
        lineEdit_fName = new QLineEdit(usersTab);
        lineEdit_fName->setObjectName(QString::fromUtf8("lineEdit_fName"));
        lineEdit_fName->setGeometry(QRect(130, 10, 113, 22));
        lineEdit_password = new QLineEdit(usersTab);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setGeometry(QRect(130, 50, 113, 22));
        lineEdit_lName = new QLineEdit(usersTab);
        lineEdit_lName->setObjectName(QString::fromUtf8("lineEdit_lName"));
        lineEdit_lName->setGeometry(QRect(250, 10, 113, 22));
        minDateR = new QDateEdit(usersTab);
        minDateR->setObjectName(QString::fromUtf8("minDateR"));
        minDateR->setGeometry(QRect(520, 10, 110, 22));
        maxDateR = new QDateEdit(usersTab);
        maxDateR->setObjectName(QString::fromUtf8("maxDateR"));
        maxDateR->setGeometry(QRect(520, 50, 110, 22));
        label_minDateR = new QLabel(usersTab);
        label_minDateR->setObjectName(QString::fromUtf8("label_minDateR"));
        label_minDateR->setGeometry(QRect(370, 10, 151, 16));
        label_maxDateR = new QLabel(usersTab);
        label_maxDateR->setObjectName(QString::fromUtf8("label_maxDateR"));
        label_maxDateR->setGeometry(QRect(370, 50, 141, 16));
        pushButton_clearUsers = new QPushButton(usersTab);
        pushButton_clearUsers->setObjectName(QString::fromUtf8("pushButton_clearUsers"));
        pushButton_clearUsers->setGeometry(QRect(640, 10, 93, 28));
        pushButton_searchUsers = new QPushButton(usersTab);
        pushButton_searchUsers->setObjectName(QString::fromUtf8("pushButton_searchUsers"));
        pushButton_searchUsers->setGeometry(QRect(640, 50, 93, 28));
        pushButton_enableEditUsers = new QPushButton(usersTab);
        pushButton_enableEditUsers->setObjectName(QString::fromUtf8("pushButton_enableEditUsers"));
        pushButton_enableEditUsers->setGeometry(QRect(740, 10, 93, 28));
        pushButton_addUsers = new QPushButton(usersTab);
        pushButton_addUsers->setObjectName(QString::fromUtf8("pushButton_addUsers"));
        pushButton_addUsers->setGeometry(QRect(640, 50, 93, 28));
        pushButton_deleteUsers = new QPushButton(usersTab);
        pushButton_deleteUsers->setObjectName(QString::fromUtf8("pushButton_deleteUsers"));
        pushButton_deleteUsers->setGeometry(QRect(740, 50, 93, 28));
        pushButton_editUsers = new QPushButton(usersTab);
        pushButton_editUsers->setObjectName(QString::fromUtf8("pushButton_editUsers"));
        pushButton_editUsers->setGeometry(QRect(740, 10, 93, 28));
        pushButton_cancelUsers = new QPushButton(usersTab);
        pushButton_cancelUsers->setObjectName(QString::fromUtf8("pushButton_cancelUsers"));
        pushButton_cancelUsers->setGeometry(QRect(840, 10, 93, 28));
        tabWidget->addTab(usersTab, QString());
        usersTable->raise();
        lineEdit_status->raise();
        lineEdit_login->raise();
        lineEdit_fName->raise();
        lineEdit_password->raise();
        lineEdit_lName->raise();
        minDateR->raise();
        maxDateR->raise();
        label_minDateR->raise();
        label_maxDateR->raise();
        pushButton_clearUsers->raise();
        pushButton_enableEditUsers->raise();
        pushButton_addUsers->raise();
        pushButton_deleteUsers->raise();
        pushButton_editUsers->raise();
        pushButton_searchUsers->raise();
        pushButton_cancelUsers->raise();
        settings = new QWidget();
        settings->setObjectName(QString::fromUtf8("settings"));
        tabWidget->addTab(settings, QString());
        pushButton_exit = new QPushButton(SecondWindow);
        pushButton_exit->setObjectName(QString::fromUtf8("pushButton_exit"));
        pushButton_exit->setGeometry(QRect(910, 0, 93, 28));

        retranslateUi(SecondWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(SecondWindow);
    } // setupUi

    void retranslateUi(QWidget *SecondWindow)
    {
        SecondWindow->setWindowTitle(QApplication::translate("SecondWindow", "SecondWindow", nullptr));
        lineEdit_carId->setPlaceholderText(QApplication::translate("SecondWindow", "Reg number", nullptr));
        lineEdit_minPrice->setPlaceholderText(QApplication::translate("SecondWindow", "Min price", nullptr));
        lineEdit_mark->setPlaceholderText(QApplication::translate("SecondWindow", "Mark", nullptr));
        lineEdit_model->setPlaceholderText(QApplication::translate("SecondWindow", "Model", nullptr));
        lineEdit_color->setPlaceholderText(QApplication::translate("SecondWindow", "Color", nullptr));
        lineEdit_numShop->setPlaceholderText(QApplication::translate("SecondWindow", "Shop number", nullptr));
        lineEdit_maxPrice->setPlaceholderText(QApplication::translate("SecondWindow", "Max price", nullptr));
        label_minDateB->setText(QApplication::translate("SecondWindow", "Min date of buy", nullptr));
        label_maxDateB->setText(QApplication::translate("SecondWindow", "Max date of buy", nullptr));
        label_minDateS->setText(QApplication::translate("SecondWindow", "Min date of sell", nullptr));
        label_maxDateS->setText(QApplication::translate("SecondWindow", "Max date of sell", nullptr));
        pushButton_carsClear->setText(QApplication::translate("SecondWindow", "Clear", nullptr));
        pushButton_searchCars->setText(QApplication::translate("SecondWindow", "Search", nullptr));
        pushButton_enableEditCars->setText(QApplication::translate("SecondWindow", "Edit", nullptr));
        pushButton_editCars->setText(QApplication::translate("SecondWindow", "Edit", nullptr));
        pushButton_deleteCars->setText(QApplication::translate("SecondWindow", "Delete", nullptr));
        pushButton_addCars->setText(QApplication::translate("SecondWindow", "Add", nullptr));
        pushButton_disableEditCars->setText(QApplication::translate("SecondWindow", "Cancel", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(carsTab), QApplication::translate("SecondWindow", "Cars", nullptr));
        lineEdit_status->setPlaceholderText(QApplication::translate("SecondWindow", "Status", nullptr));
        lineEdit_login->setPlaceholderText(QApplication::translate("SecondWindow", "Login", nullptr));
        lineEdit_fName->setPlaceholderText(QApplication::translate("SecondWindow", "First name", nullptr));
        lineEdit_password->setPlaceholderText(QApplication::translate("SecondWindow", "Password", nullptr));
        lineEdit_lName->setPlaceholderText(QApplication::translate("SecondWindow", "Second name", nullptr));
        label_minDateR->setText(QApplication::translate("SecondWindow", "Min date of regestration", nullptr));
        label_maxDateR->setText(QApplication::translate("SecondWindow", "Max date of regestration", nullptr));
        pushButton_clearUsers->setText(QApplication::translate("SecondWindow", "Clear", nullptr));
        pushButton_searchUsers->setText(QApplication::translate("SecondWindow", "Search", nullptr));
        pushButton_enableEditUsers->setText(QApplication::translate("SecondWindow", "Edit", nullptr));
        pushButton_addUsers->setText(QApplication::translate("SecondWindow", "Add", nullptr));
        pushButton_deleteUsers->setText(QApplication::translate("SecondWindow", "Delete", nullptr));
        pushButton_editUsers->setText(QApplication::translate("SecondWindow", "Edit", nullptr));
        pushButton_cancelUsers->setText(QApplication::translate("SecondWindow", "Cancel", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(usersTab), QApplication::translate("SecondWindow", "Users", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(settings), QApplication::translate("SecondWindow", "Settings", nullptr));
        pushButton_exit->setText(QApplication::translate("SecondWindow", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SecondWindow: public Ui_SecondWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECONDWINDOW_H
