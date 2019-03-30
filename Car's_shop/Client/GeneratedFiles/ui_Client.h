/********************************************************************************
** Form generated from reading UI file 'Client.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientClass
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton_auth;
    QLabel *label_login;
    QLabel *label_password;
    QLineEdit *lineEdit_login;
    QLineEdit *lineEdit_password;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuAbout;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ClientClass)
    {
        if (ClientClass->objectName().isEmpty())
            ClientClass->setObjectName(QString::fromUtf8("ClientClass"));
        ClientClass->resize(888, 612);
        centralWidget = new QWidget(ClientClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton_auth = new QPushButton(centralWidget);
        pushButton_auth->setObjectName(QString::fromUtf8("pushButton_auth"));
        pushButton_auth->setGeometry(QRect(380, 320, 93, 28));
        label_login = new QLabel(centralWidget);
        label_login->setObjectName(QString::fromUtf8("label_login"));
        label_login->setGeometry(QRect(290, 220, 55, 16));
        label_password = new QLabel(centralWidget);
        label_password->setObjectName(QString::fromUtf8("label_password"));
        label_password->setGeometry(QRect(274, 270, 71, 20));
        lineEdit_login = new QLineEdit(centralWidget);
        lineEdit_login->setObjectName(QString::fromUtf8("lineEdit_login"));
        lineEdit_login->setGeometry(QRect(370, 220, 113, 22));
        lineEdit_password = new QLineEdit(centralWidget);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setGeometry(QRect(370, 260, 113, 22));
        ClientClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ClientClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 888, 26));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        ClientClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ClientClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ClientClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ClientClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ClientClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuAbout->menuAction());

        retranslateUi(ClientClass);

        QMetaObject::connectSlotsByName(ClientClass);
    } // setupUi

    void retranslateUi(QMainWindow *ClientClass)
    {
        ClientClass->setWindowTitle(QApplication::translate("ClientClass", "Client", nullptr));
        pushButton_auth->setText(QApplication::translate("ClientClass", "Login", nullptr));
        label_login->setText(QApplication::translate("ClientClass", "Login", nullptr));
        label_password->setText(QApplication::translate("ClientClass", "Password", nullptr));
        menuFile->setTitle(QApplication::translate("ClientClass", "File", nullptr));
        menuAbout->setTitle(QApplication::translate("ClientClass", "About", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientClass: public Ui_ClientClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
