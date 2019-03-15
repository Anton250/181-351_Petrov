/********************************************************************************
** Form generated from reading UI file 'UsersTabView.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERSTABVIEW_H
#define UI_USERSTABVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UsersTabView
{
public:
    QTableView *tableView_userData;
    QLabel *label_Status;
    QLabel *label_Login;
    QLabel *label_Password;
    QLabel *label_FstName;
    QLabel *label_ScndName;
    QLabel *label_DateOfReg;
    QLineEdit *lineEdit_Status;
    QLineEdit *lineEdit_Login;
    QLineEdit *lineEdit_Password;
    QLineEdit *lineEdit_FirstName;
    QLineEdit *lineEdit_ScndName;
    QLineEdit *lineEdit_DateOfReg;
    QPushButton *pushButton_add;
    QPushButton *pushButton_clear;
    QPushButton *pushButton_search;
    QPushButton *pushButton_edit;
    QPushButton *pushButton_delete;

    void setupUi(QWidget *UsersTabView)
    {
        if (UsersTabView->objectName().isEmpty())
            UsersTabView->setObjectName(QString::fromUtf8("UsersTabView"));
        UsersTabView->resize(807, 544);
        QFont font;
        font.setPointSize(12);
        UsersTabView->setFont(font);
        tableView_userData = new QTableView(UsersTabView);
        tableView_userData->setObjectName(QString::fromUtf8("tableView_userData"));
        tableView_userData->setGeometry(QRect(0, 0, 811, 431));
        label_Status = new QLabel(UsersTabView);
        label_Status->setObjectName(QString::fromUtf8("label_Status"));
        label_Status->setGeometry(QRect(30, 440, 61, 16));
        label_Login = new QLabel(UsersTabView);
        label_Login->setObjectName(QString::fromUtf8("label_Login"));
        label_Login->setGeometry(QRect(40, 460, 51, 31));
        label_Password = new QLabel(UsersTabView);
        label_Password->setObjectName(QString::fromUtf8("label_Password"));
        label_Password->setGeometry(QRect(0, 500, 91, 16));
        label_FstName = new QLabel(UsersTabView);
        label_FstName->setObjectName(QString::fromUtf8("label_FstName"));
        label_FstName->setGeometry(QRect(300, 440, 101, 21));
        label_ScndName = new QLabel(UsersTabView);
        label_ScndName->setObjectName(QString::fromUtf8("label_ScndName"));
        label_ScndName->setGeometry(QRect(280, 470, 121, 16));
        label_DateOfReg = new QLabel(UsersTabView);
        label_DateOfReg->setObjectName(QString::fromUtf8("label_DateOfReg"));
        label_DateOfReg->setGeometry(QRect(220, 490, 201, 31));
        lineEdit_Status = new QLineEdit(UsersTabView);
        lineEdit_Status->setObjectName(QString::fromUtf8("lineEdit_Status"));
        lineEdit_Status->setGeometry(QRect(100, 440, 113, 22));
        lineEdit_Login = new QLineEdit(UsersTabView);
        lineEdit_Login->setObjectName(QString::fromUtf8("lineEdit_Login"));
        lineEdit_Login->setGeometry(QRect(100, 470, 113, 22));
        lineEdit_Password = new QLineEdit(UsersTabView);
        lineEdit_Password->setObjectName(QString::fromUtf8("lineEdit_Password"));
        lineEdit_Password->setGeometry(QRect(100, 500, 113, 22));
        lineEdit_FirstName = new QLineEdit(UsersTabView);
        lineEdit_FirstName->setObjectName(QString::fromUtf8("lineEdit_FirstName"));
        lineEdit_FirstName->setGeometry(QRect(410, 440, 113, 22));
        lineEdit_ScndName = new QLineEdit(UsersTabView);
        lineEdit_ScndName->setObjectName(QString::fromUtf8("lineEdit_ScndName"));
        lineEdit_ScndName->setGeometry(QRect(410, 470, 113, 22));
        lineEdit_DateOfReg = new QLineEdit(UsersTabView);
        lineEdit_DateOfReg->setObjectName(QString::fromUtf8("lineEdit_DateOfReg"));
        lineEdit_DateOfReg->setGeometry(QRect(410, 500, 113, 22));
        pushButton_add = new QPushButton(UsersTabView);
        pushButton_add->setObjectName(QString::fromUtf8("pushButton_add"));
        pushButton_add->setGeometry(QRect(610, 510, 93, 28));
        pushButton_clear = new QPushButton(UsersTabView);
        pushButton_clear->setObjectName(QString::fromUtf8("pushButton_clear"));
        pushButton_clear->setGeometry(QRect(530, 440, 93, 28));
        pushButton_search = new QPushButton(UsersTabView);
        pushButton_search->setObjectName(QString::fromUtf8("pushButton_search"));
        pushButton_search->setGeometry(QRect(520, 510, 93, 28));
        pushButton_edit = new QPushButton(UsersTabView);
        pushButton_edit->setObjectName(QString::fromUtf8("pushButton_edit"));
        pushButton_edit->setGeometry(QRect(700, 510, 93, 28));
        pushButton_delete = new QPushButton(UsersTabView);
        pushButton_delete->setObjectName(QString::fromUtf8("pushButton_delete"));
        pushButton_delete->setGeometry(QRect(620, 440, 93, 28));

        retranslateUi(UsersTabView);

        QMetaObject::connectSlotsByName(UsersTabView);
    } // setupUi

    void retranslateUi(QWidget *UsersTabView)
    {
        UsersTabView->setWindowTitle(QApplication::translate("UsersTabView", "UsersTabView", nullptr));
        label_Status->setText(QApplication::translate("UsersTabView", "Status", nullptr));
        label_Login->setText(QApplication::translate("UsersTabView", "Login", nullptr));
        label_Password->setText(QApplication::translate("UsersTabView", "Password", nullptr));
        label_FstName->setText(QApplication::translate("UsersTabView", "First Name", nullptr));
        label_ScndName->setText(QApplication::translate("UsersTabView", "Second Name", nullptr));
        label_DateOfReg->setText(QApplication::translate("UsersTabView", "Date Of Regestration", nullptr));
        pushButton_add->setText(QApplication::translate("UsersTabView", "Add", nullptr));
        pushButton_clear->setText(QApplication::translate("UsersTabView", "Clear", nullptr));
        pushButton_search->setText(QApplication::translate("UsersTabView", "Search", nullptr));
        pushButton_edit->setText(QApplication::translate("UsersTabView", "Edit", nullptr));
        pushButton_delete->setText(QApplication::translate("UsersTabView", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UsersTabView: public Ui_UsersTabView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERSTABVIEW_H
