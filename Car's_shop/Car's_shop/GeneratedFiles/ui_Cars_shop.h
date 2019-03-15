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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Cars_shopClass
{
public:
    QAction *actionClose;
    QAction *actionAbout;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_login;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *lineEdit_login;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_password;
    QLineEdit *lineEdit_password;
    QPushButton *pushButton_auth;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Cars_shopClass)
    {
        if (Cars_shopClass->objectName().isEmpty())
            Cars_shopClass->setObjectName(QString::fromUtf8("Cars_shopClass"));
        Cars_shopClass->resize(500, 326);
        actionClose = new QAction(Cars_shopClass);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionAbout = new QAction(Cars_shopClass);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        centralWidget = new QWidget(Cars_shopClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_login = new QLabel(centralWidget);
        label_login->setObjectName(QString::fromUtf8("label_login"));

        horizontalLayout->addWidget(label_login);

        horizontalSpacer_3 = new QSpacerItem(25, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        lineEdit_login = new QLineEdit(centralWidget);
        lineEdit_login->setObjectName(QString::fromUtf8("lineEdit_login"));

        horizontalLayout->addWidget(lineEdit_login);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_password = new QLabel(centralWidget);
        label_password->setObjectName(QString::fromUtf8("label_password"));

        horizontalLayout_2->addWidget(label_password);

        lineEdit_password = new QLineEdit(centralWidget);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));

        horizontalLayout_2->addWidget(lineEdit_password);


        verticalLayout->addLayout(horizontalLayout_2);

        pushButton_auth = new QPushButton(centralWidget);
        pushButton_auth->setObjectName(QString::fromUtf8("pushButton_auth"));
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

        verticalLayout->addWidget(pushButton_auth);


        gridLayout->addLayout(verticalLayout, 1, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 66, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(122, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(121, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 55, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        Cars_shopClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Cars_shopClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 500, 26));
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
