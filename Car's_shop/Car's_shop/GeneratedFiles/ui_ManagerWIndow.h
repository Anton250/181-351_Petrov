/********************************************************************************
** Form generated from reading UI file 'ManagerWIndow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGERWINDOW_H
#define UI_MANAGERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ManagerWIndow
{
public:
    QPushButton *pushButton_exit;
    QPushButton *pushButton_showCars;
    QPushButton *pushButton_userData;
    QLabel *label_lStatus;
    QLabel *label_LLogin;
    QLabel *label_LPassword;
    QLabel *label_LFstName;
    QLabel *label_LScndName;
    QLabel *label_LDateOfReg;
    QLabel *label_Status;
    QLabel *label_Login;
    QLabel *label_Password;
    QLabel *label_FirstName;
    QLabel *label_ScndName;
    QLabel *label_DateOfReg;

    void setupUi(QWidget *ManagerWIndow)
    {
        if (ManagerWIndow->objectName().isEmpty())
            ManagerWIndow->setObjectName(QString::fromUtf8("ManagerWIndow"));
        ManagerWIndow->resize(711, 645);
        QFont font;
        font.setPointSize(13);
        ManagerWIndow->setFont(font);
        pushButton_exit = new QPushButton(ManagerWIndow);
        pushButton_exit->setObjectName(QString::fromUtf8("pushButton_exit"));
        pushButton_exit->setGeometry(QRect(610, 0, 101, 31));
        pushButton_showCars = new QPushButton(ManagerWIndow);
        pushButton_showCars->setObjectName(QString::fromUtf8("pushButton_showCars"));
        pushButton_showCars->setGeometry(QRect(240, 340, 191, 61));
        pushButton_userData = new QPushButton(ManagerWIndow);
        pushButton_userData->setObjectName(QString::fromUtf8("pushButton_userData"));
        pushButton_userData->setGeometry(QRect(240, 400, 191, 61));
        label_lStatus = new QLabel(ManagerWIndow);
        label_lStatus->setObjectName(QString::fromUtf8("label_lStatus"));
        label_lStatus->setGeometry(QRect(180, 49, 71, 31));
        label_LLogin = new QLabel(ManagerWIndow);
        label_LLogin->setObjectName(QString::fromUtf8("label_LLogin"));
        label_LLogin->setGeometry(QRect(190, 80, 61, 31));
        label_LPassword = new QLabel(ManagerWIndow);
        label_LPassword->setObjectName(QString::fromUtf8("label_LPassword"));
        label_LPassword->setGeometry(QRect(150, 110, 101, 31));
        label_LFstName = new QLabel(ManagerWIndow);
        label_LFstName->setObjectName(QString::fromUtf8("label_LFstName"));
        label_LFstName->setGeometry(QRect(140, 140, 111, 31));
        label_LScndName = new QLabel(ManagerWIndow);
        label_LScndName->setObjectName(QString::fromUtf8("label_LScndName"));
        label_LScndName->setGeometry(QRect(110, 170, 141, 31));
        label_LDateOfReg = new QLabel(ManagerWIndow);
        label_LDateOfReg->setObjectName(QString::fromUtf8("label_LDateOfReg"));
        label_LDateOfReg->setGeometry(QRect(50, 200, 201, 31));
        label_Status = new QLabel(ManagerWIndow);
        label_Status->setObjectName(QString::fromUtf8("label_Status"));
        label_Status->setGeometry(QRect(260, 50, 131, 31));
        label_Login = new QLabel(ManagerWIndow);
        label_Login->setObjectName(QString::fromUtf8("label_Login"));
        label_Login->setGeometry(QRect(260, 80, 111, 31));
        label_Password = new QLabel(ManagerWIndow);
        label_Password->setObjectName(QString::fromUtf8("label_Password"));
        label_Password->setGeometry(QRect(260, 110, 111, 31));
        label_FirstName = new QLabel(ManagerWIndow);
        label_FirstName->setObjectName(QString::fromUtf8("label_FirstName"));
        label_FirstName->setGeometry(QRect(260, 140, 131, 31));
        label_ScndName = new QLabel(ManagerWIndow);
        label_ScndName->setObjectName(QString::fromUtf8("label_ScndName"));
        label_ScndName->setGeometry(QRect(260, 170, 151, 31));
        label_DateOfReg = new QLabel(ManagerWIndow);
        label_DateOfReg->setObjectName(QString::fromUtf8("label_DateOfReg"));
        label_DateOfReg->setGeometry(QRect(260, 200, 211, 31));

        retranslateUi(ManagerWIndow);

        QMetaObject::connectSlotsByName(ManagerWIndow);
    } // setupUi

    void retranslateUi(QWidget *ManagerWIndow)
    {
        ManagerWIndow->setWindowTitle(QApplication::translate("ManagerWIndow", "ManagerWIndow", nullptr));
        pushButton_exit->setText(QApplication::translate("ManagerWIndow", "Exit", nullptr));
        pushButton_showCars->setText(QApplication::translate("ManagerWIndow", "Cars Data", nullptr));
        pushButton_userData->setText(QApplication::translate("ManagerWIndow", "Users Data", nullptr));
        label_lStatus->setText(QApplication::translate("ManagerWIndow", "Status:", nullptr));
        label_LLogin->setText(QApplication::translate("ManagerWIndow", "Login:", nullptr));
        label_LPassword->setText(QApplication::translate("ManagerWIndow", "Password:", nullptr));
        label_LFstName->setText(QApplication::translate("ManagerWIndow", "First name:", nullptr));
        label_LScndName->setText(QApplication::translate("ManagerWIndow", "Second name:", nullptr));
        label_LDateOfReg->setText(QApplication::translate("ManagerWIndow", "Date of regestrstion:", nullptr));
        label_Status->setText(QApplication::translate("ManagerWIndow", "Status", nullptr));
        label_Login->setText(QApplication::translate("ManagerWIndow", "Login", nullptr));
        label_Password->setText(QApplication::translate("ManagerWIndow", "Password", nullptr));
        label_FirstName->setText(QApplication::translate("ManagerWIndow", "First Name", nullptr));
        label_ScndName->setText(QApplication::translate("ManagerWIndow", "Second Name", nullptr));
        label_DateOfReg->setText(QApplication::translate("ManagerWIndow", "Date of Regestration", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ManagerWIndow: public Ui_ManagerWIndow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGERWINDOW_H
