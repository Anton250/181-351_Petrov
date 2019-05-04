/********************************************************************************
** Form generated from reading UI file 'Client.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
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
    QFrame *frame_login;
    QPushButton *pushButton_register;
    QLineEdit *lineEdit_login;
    QLineEdit *lineEdit_password;
    QLabel *label_login;
    QPushButton *pushButton_auth;
    QLabel *label_password;
    QFrame *frame_reg;
    QLineEdit *lineEdit_fName;
    QLineEdit *lineEdit_lName;
    QLineEdit *lineEdit_newLogin;
    QLineEdit *lineEdit_newPassword;
    QPushButton *pushButton_startReg;
    QPushButton *pushButton_cancel;
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
        frame_login = new QFrame(centralWidget);
        frame_login->setObjectName(QString::fromUtf8("frame_login"));
        frame_login->setGeometry(QRect(280, 110, 341, 351));
        frame_login->setFrameShape(QFrame::StyledPanel);
        frame_login->setFrameShadow(QFrame::Raised);
        pushButton_register = new QPushButton(frame_login);
        pushButton_register->setObjectName(QString::fromUtf8("pushButton_register"));
        pushButton_register->setGeometry(QRect(140, 250, 93, 28));
        lineEdit_login = new QLineEdit(frame_login);
        lineEdit_login->setObjectName(QString::fromUtf8("lineEdit_login"));
        lineEdit_login->setGeometry(QRect(130, 120, 113, 22));
        lineEdit_password = new QLineEdit(frame_login);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setGeometry(QRect(130, 160, 113, 22));
        lineEdit_password->setEchoMode(QLineEdit::Password);
        label_login = new QLabel(frame_login);
        label_login->setObjectName(QString::fromUtf8("label_login"));
        label_login->setGeometry(QRect(50, 120, 55, 16));
        pushButton_auth = new QPushButton(frame_login);
        pushButton_auth->setObjectName(QString::fromUtf8("pushButton_auth"));
        pushButton_auth->setGeometry(QRect(140, 220, 93, 28));
        label_password = new QLabel(frame_login);
        label_password->setObjectName(QString::fromUtf8("label_password"));
        label_password->setGeometry(QRect(34, 170, 71, 20));
        frame_reg = new QFrame(centralWidget);
        frame_reg->setObjectName(QString::fromUtf8("frame_reg"));
        frame_reg->setGeometry(QRect(290, 170, 341, 351));
        frame_reg->setFrameShape(QFrame::StyledPanel);
        frame_reg->setFrameShadow(QFrame::Raised);
        lineEdit_fName = new QLineEdit(frame_reg);
        lineEdit_fName->setObjectName(QString::fromUtf8("lineEdit_fName"));
        lineEdit_fName->setGeometry(QRect(100, 20, 113, 22));
        lineEdit_lName = new QLineEdit(frame_reg);
        lineEdit_lName->setObjectName(QString::fromUtf8("lineEdit_lName"));
        lineEdit_lName->setGeometry(QRect(100, 50, 113, 22));
        lineEdit_newLogin = new QLineEdit(frame_reg);
        lineEdit_newLogin->setObjectName(QString::fromUtf8("lineEdit_newLogin"));
        lineEdit_newLogin->setGeometry(QRect(100, 80, 113, 22));
        lineEdit_newPassword = new QLineEdit(frame_reg);
        lineEdit_newPassword->setObjectName(QString::fromUtf8("lineEdit_newPassword"));
        lineEdit_newPassword->setGeometry(QRect(100, 110, 113, 22));
        pushButton_startReg = new QPushButton(frame_reg);
        pushButton_startReg->setObjectName(QString::fromUtf8("pushButton_startReg"));
        pushButton_startReg->setGeometry(QRect(110, 150, 93, 28));
        pushButton_cancel = new QPushButton(frame_reg);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(110, 190, 93, 28));
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
        pushButton_register->setText(QApplication::translate("ClientClass", "Register", nullptr));
        label_login->setText(QApplication::translate("ClientClass", "Login", nullptr));
        pushButton_auth->setText(QApplication::translate("ClientClass", "Login", nullptr));
        label_password->setText(QApplication::translate("ClientClass", "Password", nullptr));
        lineEdit_fName->setInputMask(QApplication::translate("ClientClass", ">A<aaaaaaaaaaaaaa", nullptr));
        lineEdit_fName->setPlaceholderText(QApplication::translate("ClientClass", "First name", nullptr));
        lineEdit_lName->setInputMask(QApplication::translate("ClientClass", ">A<aaaaaaaaaaaaaa", nullptr));
        lineEdit_lName->setPlaceholderText(QApplication::translate("ClientClass", "Second name", nullptr));
        lineEdit_newLogin->setPlaceholderText(QApplication::translate("ClientClass", "Login", nullptr));
        lineEdit_newPassword->setPlaceholderText(QApplication::translate("ClientClass", "Password", nullptr));
        pushButton_startReg->setText(QApplication::translate("ClientClass", "Register", nullptr));
        pushButton_cancel->setText(QApplication::translate("ClientClass", "Cancel", nullptr));
        menuFile->setTitle(QApplication::translate("ClientClass", "File", nullptr));
        menuAbout->setTitle(QApplication::translate("ClientClass", "About", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientClass: public Ui_ClientClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
