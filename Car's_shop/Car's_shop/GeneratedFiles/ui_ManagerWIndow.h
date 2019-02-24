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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ManagerWIndow
{
public:
    QPushButton *pushButton_exit;
    QTextBrowser *textBrowser_hello;
    QPushButton *pushButton_showCars;

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
        textBrowser_hello = new QTextBrowser(ManagerWIndow);
        textBrowser_hello->setObjectName(QString::fromUtf8("textBrowser_hello"));
        textBrowser_hello->setGeometry(QRect(0, 0, 611, 111));
        pushButton_showCars = new QPushButton(ManagerWIndow);
        pushButton_showCars->setObjectName(QString::fromUtf8("pushButton_showCars"));
        pushButton_showCars->setGeometry(QRect(250, 110, 191, 51));

        retranslateUi(ManagerWIndow);

        QMetaObject::connectSlotsByName(ManagerWIndow);
    } // setupUi

    void retranslateUi(QWidget *ManagerWIndow)
    {
        ManagerWIndow->setWindowTitle(QApplication::translate("ManagerWIndow", "ManagerWIndow", nullptr));
        pushButton_exit->setText(QApplication::translate("ManagerWIndow", "Exit", nullptr));
        pushButton_showCars->setText(QApplication::translate("ManagerWIndow", "Cars Data", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ManagerWIndow: public Ui_ManagerWIndow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGERWINDOW_H
