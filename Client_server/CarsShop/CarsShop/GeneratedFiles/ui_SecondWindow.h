/********************************************************************************
** Form generated from reading UI file 'SecondWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECONDWINDOW_H
#define UI_SECONDWINDOW_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
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
    QCheckBox *checkBox_dateB;
    QCheckBox *checkBox_dateS;
    QCheckBox *checkBox_minDateB;
    QCheckBox *checkBox_maxDateB;
    QCheckBox *checkBox_minDateS;
    QCheckBox *checkBox_maxDateS;
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
    QLineEdit *lineEdit_IDUsers;
    QCheckBox *checkBox_minDateR;
    QCheckBox *checkBox_maxDateR;
    QWidget *settings;
    QLabel *label_lName;
    QLabel *lName;
    QLabel *label_status;
    QLabel *status;
    QLabel *label_fName;
    QLabel *fName;
    QPushButton *pushButton_changeLogin;
    QPushButton *pushButton_confirmNewLogin;
    QPushButton *pushButton_changePassword;
    QPushButton *pushButton_confirmNewPassword;
    QLineEdit *lineEdit_newLogin;
    QLineEdit *lineEdit_newPassword;
    QLabel *label_dateOfR;
    QLabel *dateOfR;
    QPushButton *pushButton_cancelNewLogin;
    QPushButton *pushButton_cancelNewPassword;
    QPushButton *pushButton_exit;

    void setupUi(QWidget *SecondWindow)
    {
        if (SecondWindow->objectName().isEmpty())
            SecondWindow->setObjectName(QString::fromUtf8("SecondWindow"));
        SecondWindow->resize(1035, 565);
        tabWidget = new QTabWidget(SecondWindow);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 1041, 571));
        carsTab = new QWidget();
        carsTab->setObjectName(QString::fromUtf8("carsTab"));
        carsTable = new QTableView(carsTab);
        carsTable->setObjectName(QString::fromUtf8("carsTable"));
        carsTable->setGeometry(QRect(0, 100, 1031, 441));
        carsTable->verticalHeader()->setVisible(false);
        lineEdit_carId = new QLineEdit(carsTab);
        lineEdit_carId->setObjectName(QString::fromUtf8("lineEdit_carId"));
        lineEdit_carId->setGeometry(QRect(10, 10, 113, 22));
        lineEdit_carId->setStyleSheet(QString::fromUtf8(""));
        lineEdit_carId->setMaxLength(11);
        lineEdit_minPrice = new QLineEdit(carsTab);
        lineEdit_minPrice->setObjectName(QString::fromUtf8("lineEdit_minPrice"));
        lineEdit_minPrice->setGeometry(QRect(10, 40, 113, 22));
        lineEdit_mark = new QLineEdit(carsTab);
        lineEdit_mark->setObjectName(QString::fromUtf8("lineEdit_mark"));
        lineEdit_mark->setGeometry(QRect(130, 10, 113, 22));
        lineEdit_mark->setMaxLength(20);
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
        minDateB->setCalendarPopup(true);
        maxDateB = new QDateEdit(carsTab);
        maxDateB->setObjectName(QString::fromUtf8("maxDateB"));
        maxDateB->setGeometry(QRect(250, 70, 110, 22));
        maxDateB->setCalendarPopup(true);
        label_minDateB = new QLabel(carsTab);
        label_minDateB->setObjectName(QString::fromUtf8("label_minDateB"));
        label_minDateB->setGeometry(QRect(130, 40, 111, 20));
        label_maxDateB = new QLabel(carsTab);
        label_maxDateB->setObjectName(QString::fromUtf8("label_maxDateB"));
        label_maxDateB->setGeometry(QRect(130, 70, 101, 16));
        minDateS = new QDateEdit(carsTab);
        minDateS->setObjectName(QString::fromUtf8("minDateS"));
        minDateS->setEnabled(true);
        minDateS->setGeometry(QRect(490, 40, 110, 22));
        minDateS->setWrapping(false);
        minDateS->setFrame(true);
        minDateS->setReadOnly(false);
        minDateS->setAccelerated(false);
        minDateS->setCorrectionMode(QAbstractSpinBox::CorrectToPreviousValue);
        minDateS->setKeyboardTracking(true);
        minDateS->setProperty("showGroupSeparator", QVariant(false));
        minDateS->setDateTime(QDateTime(QDate(2000, 1, 1), QTime(0, 0, 0)));
        minDateS->setMinimumDateTime(QDateTime(QDate(1753, 9, 14), QTime(0, 0, 0)));
        minDateS->setCurrentSection(QDateTimeEdit::YearSection);
        minDateS->setCalendarPopup(true);
        minDateS->setCurrentSectionIndex(0);
        minDateS->setDate(QDate(2000, 1, 1));
        maxDateS = new QDateEdit(carsTab);
        maxDateS->setObjectName(QString::fromUtf8("maxDateS"));
        maxDateS->setGeometry(QRect(490, 70, 110, 22));
        maxDateS->setCalendarPopup(true);
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
        checkBox_dateB = new QCheckBox(carsTab);
        checkBox_dateB->setObjectName(QString::fromUtf8("checkBox_dateB"));
        checkBox_dateB->setGeometry(QRect(190, 70, 171, 20));
        checkBox_dateB->setChecked(true);
        checkBox_dateS = new QCheckBox(carsTab);
        checkBox_dateS->setObjectName(QString::fromUtf8("checkBox_dateS"));
        checkBox_dateS->setGeometry(QRect(440, 70, 191, 20));
        checkBox_dateS->setChecked(true);
        checkBox_minDateB = new QCheckBox(carsTab);
        checkBox_minDateB->setObjectName(QString::fromUtf8("checkBox_minDateB"));
        checkBox_minDateB->setGeometry(QRect(230, 40, 16, 20));
        checkBox_maxDateB = new QCheckBox(carsTab);
        checkBox_maxDateB->setObjectName(QString::fromUtf8("checkBox_maxDateB"));
        checkBox_maxDateB->setGeometry(QRect(230, 70, 21, 20));
        checkBox_minDateS = new QCheckBox(carsTab);
        checkBox_minDateS->setObjectName(QString::fromUtf8("checkBox_minDateS"));
        checkBox_minDateS->setGeometry(QRect(470, 40, 16, 20));
        checkBox_maxDateS = new QCheckBox(carsTab);
        checkBox_maxDateS->setObjectName(QString::fromUtf8("checkBox_maxDateS"));
        checkBox_maxDateS->setGeometry(QRect(470, 70, 16, 20));
        tabWidget->addTab(carsTab, QString());
        checkBox_dateS->raise();
        checkBox_dateB->raise();
        carsTable->raise();
        lineEdit_carId->raise();
        lineEdit_minPrice->raise();
        lineEdit_mark->raise();
        lineEdit_model->raise();
        lineEdit_color->raise();
        lineEdit_numShop->raise();
        lineEdit_maxPrice->raise();
        minDateB->raise();
        maxDateB->raise();
        label_minDateB->raise();
        label_maxDateB->raise();
        minDateS->raise();
        maxDateS->raise();
        label_minDateS->raise();
        label_maxDateS->raise();
        pushButton_carsClear->raise();
        pushButton_searchCars->raise();
        pushButton_enableEditCars->raise();
        pushButton_editCars->raise();
        pushButton_deleteCars->raise();
        pushButton_addCars->raise();
        pushButton_disableEditCars->raise();
        checkBox_minDateB->raise();
        checkBox_maxDateB->raise();
        checkBox_minDateS->raise();
        checkBox_maxDateS->raise();
        usersTab = new QWidget();
        usersTab->setObjectName(QString::fromUtf8("usersTab"));
        usersTable = new QTableView(usersTab);
        usersTable->setObjectName(QString::fromUtf8("usersTable"));
        usersTable->setGeometry(QRect(0, 90, 1031, 451));
        lineEdit_status = new QLineEdit(usersTab);
        lineEdit_status->setObjectName(QString::fromUtf8("lineEdit_status"));
        lineEdit_status->setGeometry(QRect(0, 10, 113, 22));
        lineEdit_login = new QLineEdit(usersTab);
        lineEdit_login->setObjectName(QString::fromUtf8("lineEdit_login"));
        lineEdit_login->setGeometry(QRect(120, 50, 113, 22));
        lineEdit_fName = new QLineEdit(usersTab);
        lineEdit_fName->setObjectName(QString::fromUtf8("lineEdit_fName"));
        lineEdit_fName->setGeometry(QRect(120, 10, 113, 22));
        lineEdit_password = new QLineEdit(usersTab);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setGeometry(QRect(240, 50, 113, 22));
        lineEdit_lName = new QLineEdit(usersTab);
        lineEdit_lName->setObjectName(QString::fromUtf8("lineEdit_lName"));
        lineEdit_lName->setGeometry(QRect(240, 10, 113, 22));
        minDateR = new QDateEdit(usersTab);
        minDateR->setObjectName(QString::fromUtf8("minDateR"));
        minDateR->setGeometry(QRect(520, 10, 110, 22));
        maxDateR = new QDateEdit(usersTab);
        maxDateR->setObjectName(QString::fromUtf8("maxDateR"));
        maxDateR->setGeometry(QRect(520, 50, 110, 22));
        label_minDateR = new QLabel(usersTab);
        label_minDateR->setObjectName(QString::fromUtf8("label_minDateR"));
        label_minDateR->setGeometry(QRect(360, 10, 151, 16));
        label_maxDateR = new QLabel(usersTab);
        label_maxDateR->setObjectName(QString::fromUtf8("label_maxDateR"));
        label_maxDateR->setGeometry(QRect(360, 50, 141, 16));
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
        lineEdit_IDUsers = new QLineEdit(usersTab);
        lineEdit_IDUsers->setObjectName(QString::fromUtf8("lineEdit_IDUsers"));
        lineEdit_IDUsers->setGeometry(QRect(0, 50, 113, 22));
        checkBox_minDateR = new QCheckBox(usersTab);
        checkBox_minDateR->setObjectName(QString::fromUtf8("checkBox_minDateR"));
        checkBox_minDateR->setGeometry(QRect(500, 10, 16, 20));
        checkBox_maxDateR = new QCheckBox(usersTab);
        checkBox_maxDateR->setObjectName(QString::fromUtf8("checkBox_maxDateR"));
        checkBox_maxDateR->setGeometry(QRect(500, 50, 20, 20));
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
        lineEdit_IDUsers->raise();
        checkBox_minDateR->raise();
        checkBox_maxDateR->raise();
        settings = new QWidget();
        settings->setObjectName(QString::fromUtf8("settings"));
        label_lName = new QLabel(settings);
        label_lName->setObjectName(QString::fromUtf8("label_lName"));
        label_lName->setGeometry(QRect(270, 130, 71, 20));
        lName = new QLabel(settings);
        lName->setObjectName(QString::fromUtf8("lName"));
        lName->setGeometry(QRect(340, 130, 141, 21));
        label_status = new QLabel(settings);
        label_status->setObjectName(QString::fromUtf8("label_status"));
        label_status->setGeometry(QRect(290, 90, 41, 20));
        status = new QLabel(settings);
        status->setObjectName(QString::fromUtf8("status"));
        status->setGeometry(QRect(340, 90, 101, 21));
        label_fName = new QLabel(settings);
        label_fName->setObjectName(QString::fromUtf8("label_fName"));
        label_fName->setGeometry(QRect(270, 110, 71, 20));
        fName = new QLabel(settings);
        fName->setObjectName(QString::fromUtf8("fName"));
        fName->setGeometry(QRect(340, 110, 141, 21));
        pushButton_changeLogin = new QPushButton(settings);
        pushButton_changeLogin->setObjectName(QString::fromUtf8("pushButton_changeLogin"));
        pushButton_changeLogin->setGeometry(QRect(342, 160, 111, 28));
        pushButton_confirmNewLogin = new QPushButton(settings);
        pushButton_confirmNewLogin->setObjectName(QString::fromUtf8("pushButton_confirmNewLogin"));
        pushButton_confirmNewLogin->setGeometry(QRect(460, 160, 93, 28));
        pushButton_changePassword = new QPushButton(settings);
        pushButton_changePassword->setObjectName(QString::fromUtf8("pushButton_changePassword"));
        pushButton_changePassword->setGeometry(QRect(342, 190, 111, 28));
        pushButton_confirmNewPassword = new QPushButton(settings);
        pushButton_confirmNewPassword->setObjectName(QString::fromUtf8("pushButton_confirmNewPassword"));
        pushButton_confirmNewPassword->setGeometry(QRect(460, 190, 93, 28));
        lineEdit_newLogin = new QLineEdit(settings);
        lineEdit_newLogin->setObjectName(QString::fromUtf8("lineEdit_newLogin"));
        lineEdit_newLogin->setGeometry(QRect(340, 160, 113, 22));
        lineEdit_newPassword = new QLineEdit(settings);
        lineEdit_newPassword->setObjectName(QString::fromUtf8("lineEdit_newPassword"));
        lineEdit_newPassword->setGeometry(QRect(340, 190, 113, 22));
        label_dateOfR = new QLabel(settings);
        label_dateOfR->setObjectName(QString::fromUtf8("label_dateOfR"));
        label_dateOfR->setGeometry(QRect(224, 230, 121, 20));
        dateOfR = new QLabel(settings);
        dateOfR->setObjectName(QString::fromUtf8("dateOfR"));
        dateOfR->setGeometry(QRect(350, 230, 91, 21));
        pushButton_cancelNewLogin = new QPushButton(settings);
        pushButton_cancelNewLogin->setObjectName(QString::fromUtf8("pushButton_cancelNewLogin"));
        pushButton_cancelNewLogin->setGeometry(QRect(560, 160, 93, 28));
        pushButton_cancelNewPassword = new QPushButton(settings);
        pushButton_cancelNewPassword->setObjectName(QString::fromUtf8("pushButton_cancelNewPassword"));
        pushButton_cancelNewPassword->setGeometry(QRect(560, 190, 93, 28));
        tabWidget->addTab(settings, QString());
        label_lName->raise();
        lName->raise();
        label_status->raise();
        status->raise();
        label_fName->raise();
        fName->raise();
        pushButton_confirmNewLogin->raise();
        pushButton_confirmNewPassword->raise();
        lineEdit_newLogin->raise();
        lineEdit_newPassword->raise();
        label_dateOfR->raise();
        dateOfR->raise();
        pushButton_changeLogin->raise();
        pushButton_cancelNewLogin->raise();
        pushButton_changePassword->raise();
        pushButton_cancelNewPassword->raise();
        pushButton_exit = new QPushButton(SecondWindow);
        pushButton_exit->setObjectName(QString::fromUtf8("pushButton_exit"));
        pushButton_exit->setGeometry(QRect(910, 0, 93, 28));

        retranslateUi(SecondWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SecondWindow);
    } // setupUi

    void retranslateUi(QWidget *SecondWindow)
    {
        SecondWindow->setWindowTitle(QApplication::translate("SecondWindow", "SecondWindow", nullptr));
        lineEdit_carId->setInputMask(QApplication::translate("SecondWindow", "D9999999999", nullptr));
        lineEdit_carId->setPlaceholderText(QApplication::translate("SecondWindow", "Reg number", nullptr));
        lineEdit_minPrice->setInputMask(QApplication::translate("SecondWindow", "D999999999", nullptr));
        lineEdit_minPrice->setPlaceholderText(QApplication::translate("SecondWindow", "Min price", nullptr));
        lineEdit_mark->setInputMask(QApplication::translate("SecondWindow", ">A<aaaaaaaaaaaaaaaaaaa", nullptr));
        lineEdit_mark->setPlaceholderText(QApplication::translate("SecondWindow", "Mark", nullptr));
        lineEdit_model->setInputMask(QApplication::translate("SecondWindow", ">N<nnnnnnnnnnnnnnnnnnn", nullptr));
        lineEdit_model->setPlaceholderText(QApplication::translate("SecondWindow", "Model", nullptr));
        lineEdit_color->setInputMask(QApplication::translate("SecondWindow", ">A<aaaaaaaaaaaaaaaaaaa", nullptr));
        lineEdit_color->setPlaceholderText(QApplication::translate("SecondWindow", "Color", nullptr));
        lineEdit_numShop->setInputMask(QApplication::translate("SecondWindow", "D9", nullptr));
        lineEdit_numShop->setText(QString());
        lineEdit_numShop->setPlaceholderText(QApplication::translate("SecondWindow", "Shop number", nullptr));
        lineEdit_maxPrice->setInputMask(QApplication::translate("SecondWindow", "D999999999", nullptr));
        lineEdit_maxPrice->setPlaceholderText(QApplication::translate("SecondWindow", "Max price", nullptr));
        minDateB->setDisplayFormat(QApplication::translate("SecondWindow", "yyyy-MM-dd", nullptr));
        maxDateB->setDisplayFormat(QApplication::translate("SecondWindow", "yyyy-MM-dd", nullptr));
        label_minDateB->setText(QApplication::translate("SecondWindow", "Min date of buy", nullptr));
        label_maxDateB->setText(QApplication::translate("SecondWindow", "Max date of buy", nullptr));
        minDateS->setSpecialValueText(QString());
        minDateS->setDisplayFormat(QApplication::translate("SecondWindow", "yyyy-MM-dd", nullptr));
        maxDateS->setDisplayFormat(QApplication::translate("SecondWindow", "yyyy-MM-dd", nullptr));
        label_minDateS->setText(QApplication::translate("SecondWindow", "Min date of sell", nullptr));
        label_maxDateS->setText(QApplication::translate("SecondWindow", "Max date of sell", nullptr));
        pushButton_carsClear->setText(QApplication::translate("SecondWindow", "Clear", nullptr));
        pushButton_searchCars->setText(QApplication::translate("SecondWindow", "Search", nullptr));
        pushButton_enableEditCars->setText(QApplication::translate("SecondWindow", "Edit", nullptr));
        pushButton_editCars->setText(QApplication::translate("SecondWindow", "Edit", nullptr));
        pushButton_deleteCars->setText(QApplication::translate("SecondWindow", "Delete", nullptr));
        pushButton_addCars->setText(QApplication::translate("SecondWindow", "Add", nullptr));
        pushButton_disableEditCars->setText(QApplication::translate("SecondWindow", "Cancel", nullptr));
        checkBox_dateB->setText(QApplication::translate("SecondWindow", "Don't change date of buy", nullptr));
        checkBox_dateS->setText(QApplication::translate("SecondWindow", "Don't change date of sell", nullptr));
        checkBox_minDateB->setText(QString());
        checkBox_maxDateB->setText(QString());
        checkBox_minDateS->setText(QString());
        checkBox_maxDateS->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(carsTab), QApplication::translate("SecondWindow", "Cars", nullptr));
        lineEdit_status->setInputMask(QApplication::translate("SecondWindow", "aaaaaaaaaa", nullptr));
        lineEdit_status->setPlaceholderText(QApplication::translate("SecondWindow", "Status", nullptr));
        lineEdit_login->setPlaceholderText(QApplication::translate("SecondWindow", "Login", nullptr));
        lineEdit_fName->setInputMask(QApplication::translate("SecondWindow", ">A<AAAaaaaaaaaaaa", nullptr));
        lineEdit_fName->setPlaceholderText(QApplication::translate("SecondWindow", "First name", nullptr));
        lineEdit_password->setPlaceholderText(QApplication::translate("SecondWindow", "Password", nullptr));
        lineEdit_lName->setInputMask(QApplication::translate("SecondWindow", ">A<AAAaaaaaaaaaaa", nullptr));
        lineEdit_lName->setPlaceholderText(QApplication::translate("SecondWindow", "Second name", nullptr));
        minDateR->setDisplayFormat(QApplication::translate("SecondWindow", "dd-MM-yyyy", nullptr));
        maxDateR->setDisplayFormat(QApplication::translate("SecondWindow", "dd-MM-yyyy", nullptr));
        label_minDateR->setText(QApplication::translate("SecondWindow", "Min date of regestration", nullptr));
        label_maxDateR->setText(QApplication::translate("SecondWindow", "Max date of regestration", nullptr));
        pushButton_clearUsers->setText(QApplication::translate("SecondWindow", "Clear", nullptr));
        pushButton_searchUsers->setText(QApplication::translate("SecondWindow", "Search", nullptr));
        pushButton_enableEditUsers->setText(QApplication::translate("SecondWindow", "Edit", nullptr));
        pushButton_addUsers->setText(QApplication::translate("SecondWindow", "Add", nullptr));
        pushButton_deleteUsers->setText(QApplication::translate("SecondWindow", "Delete", nullptr));
        pushButton_editUsers->setText(QApplication::translate("SecondWindow", "Edit", nullptr));
        pushButton_cancelUsers->setText(QApplication::translate("SecondWindow", "Cancel", nullptr));
        lineEdit_IDUsers->setInputMask(QApplication::translate("SecondWindow", "D99999", nullptr));
        lineEdit_IDUsers->setPlaceholderText(QApplication::translate("SecondWindow", "ID", nullptr));
        checkBox_minDateR->setText(QString());
        checkBox_maxDateR->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(usersTab), QApplication::translate("SecondWindow", "Users", nullptr));
        label_lName->setText(QApplication::translate("SecondWindow", "Last name:", nullptr));
        lName->setText(QApplication::translate("SecondWindow", "lname", nullptr));
        label_status->setText(QApplication::translate("SecondWindow", "Status:", nullptr));
        status->setText(QApplication::translate("SecondWindow", "status", nullptr));
        label_fName->setText(QApplication::translate("SecondWindow", "First name:", nullptr));
        fName->setText(QApplication::translate("SecondWindow", "name", nullptr));
        pushButton_changeLogin->setText(QApplication::translate("SecondWindow", "Change login", nullptr));
        pushButton_confirmNewLogin->setText(QApplication::translate("SecondWindow", "Ok", nullptr));
        pushButton_changePassword->setText(QApplication::translate("SecondWindow", "Change password", nullptr));
        pushButton_confirmNewPassword->setText(QApplication::translate("SecondWindow", "Ok", nullptr));
        lineEdit_newLogin->setPlaceholderText(QApplication::translate("SecondWindow", "New login", nullptr));
        lineEdit_newPassword->setPlaceholderText(QApplication::translate("SecondWindow", "New password", nullptr));
        label_dateOfR->setText(QApplication::translate("SecondWindow", "Date of regestration:", nullptr));
        dateOfR->setText(QApplication::translate("SecondWindow", "DateR", nullptr));
        pushButton_cancelNewLogin->setText(QApplication::translate("SecondWindow", "Cancel", nullptr));
        pushButton_cancelNewPassword->setText(QApplication::translate("SecondWindow", "Cancel", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(settings), QApplication::translate("SecondWindow", "Settings", nullptr));
        pushButton_exit->setText(QApplication::translate("SecondWindow", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SecondWindow: public Ui_SecondWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECONDWINDOW_H
