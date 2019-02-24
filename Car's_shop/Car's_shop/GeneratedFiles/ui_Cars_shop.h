/********************************************************************************
** Form generated from reading UI file 'Cars_shop.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARS_SHOP_H
#define UI_CARS_SHOP_H

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

class Ui_Cars_shopClass
{
public:
    QAction *actionClose;
    QAction *actionAbout;
    QWidget *centralWidget;
    QLineEdit *lineEdit_login;
    QLineEdit *lineEdit_password;
    QLabel *label_login;
    QLabel *label_password;
    QPushButton *pushButton_auth;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Cars_shopClass)
    {
        if (Cars_shopClass->objectName().isEmpty())
            Cars_shopClass->setObjectName(QString::fromUtf8("Cars_shopClass"));
        Cars_shopClass->resize(600, 400);
        actionClose = new QAction(Cars_shopClass);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionAbout = new QAction(Cars_shopClass);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        centralWidget = new QWidget(Cars_shopClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        lineEdit_login = new QLineEdit(centralWidget);
        lineEdit_login->setObjectName(QString::fromUtf8("lineEdit_login"));
        lineEdit_login->setGeometry(QRect(240, 90, 113, 22));
        lineEdit_password = new QLineEdit(centralWidget);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setGeometry(QRect(240, 140, 113, 22));
        label_login = new QLabel(centralWidget);
        label_login->setObjectName(QString::fromUtf8("label_login"));
        label_login->setGeometry(QRect(200, 90, 41, 16));
        label_password = new QLabel(centralWidget);
        label_password->setObjectName(QString::fromUtf8("label_password"));
        label_password->setGeometry(QRect(174, 140, 61, 20));
        pushButton_auth = new QPushButton(centralWidget);
        pushButton_auth->setObjectName(QString::fromUtf8("pushButton_auth"));
        pushButton_auth->setGeometry(QRect(240, 190, 93, 28));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        pushButton_auth->setPalette(palette);
        QFont font;
        font.setPointSize(10);
        pushButton_auth->setFont(font);
        pushButton_auth->setAutoFillBackground(true);
        Cars_shopClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Cars_shopClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 26));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        Cars_shopClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Cars_shopClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Cars_shopClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Cars_shopClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Cars_shopClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionClose);
        menuHelp->addAction(actionAbout);

        retranslateUi(Cars_shopClass);
        QObject::connect(actionClose, SIGNAL(triggered()), Cars_shopClass, SLOT(close()));

        QMetaObject::connectSlotsByName(Cars_shopClass);
    } // setupUi

    void retranslateUi(QMainWindow *Cars_shopClass)
    {
        Cars_shopClass->setWindowTitle(QApplication::translate("Cars_shopClass", "Cars_shop", nullptr));
        actionClose->setText(QApplication::translate("Cars_shopClass", "Close", nullptr));
        actionAbout->setText(QApplication::translate("Cars_shopClass", "About", nullptr));
        label_login->setText(QApplication::translate("Cars_shopClass", "Login:", nullptr));
        label_password->setText(QApplication::translate("Cars_shopClass", "Password:", nullptr));
        pushButton_auth->setText(QApplication::translate("Cars_shopClass", "LOGIN", nullptr));
        menuFile->setTitle(QApplication::translate("Cars_shopClass", "File", nullptr));
        menuHelp->setTitle(QApplication::translate("Cars_shopClass", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Cars_shopClass: public Ui_Cars_shopClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARS_SHOP_H
