/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "boutondirection.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionRejoindre;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *labelAdversaire;
    QLCDNumber *lcdNumberBleu;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout;
    BoutonDirection *pushButtonSE;
    BoutonDirection *pushButtonE;
    BoutonDirection *pushButtonSO;
    BoutonDirection *pushButtonNE;
    BoutonDirection *pushButtonO;
    BoutonDirection *pushButtonNO;
    QSpacerItem *horizontalSpacer_2;
    QLabel *labelMoi;
    QLCDNumber *lcdNumberRouge;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QMenu *menuServer;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionRejoindre = new QAction(MainWindow);
        actionRejoindre->setObjectName(QString::fromUtf8("actionRejoindre"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelAdversaire = new QLabel(centralwidget);
        labelAdversaire->setObjectName(QString::fromUtf8("labelAdversaire"));

        horizontalLayout->addWidget(labelAdversaire);

        lcdNumberBleu = new QLCDNumber(centralwidget);
        lcdNumberBleu->setObjectName(QString::fromUtf8("lcdNumberBleu"));

        horizontalLayout->addWidget(lcdNumberBleu);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButtonSE = new BoutonDirection(centralwidget);
        pushButtonSE->setObjectName(QString::fromUtf8("pushButtonSE"));

        gridLayout->addWidget(pushButtonSE, 2, 1, 1, 1);

        pushButtonE = new BoutonDirection(centralwidget);
        pushButtonE->setObjectName(QString::fromUtf8("pushButtonE"));

        gridLayout->addWidget(pushButtonE, 1, 1, 1, 1);

        pushButtonSO = new BoutonDirection(centralwidget);
        pushButtonSO->setObjectName(QString::fromUtf8("pushButtonSO"));

        gridLayout->addWidget(pushButtonSO, 2, 0, 1, 1);

        pushButtonNE = new BoutonDirection(centralwidget);
        pushButtonNE->setObjectName(QString::fromUtf8("pushButtonNE"));

        gridLayout->addWidget(pushButtonNE, 0, 1, 1, 1);

        pushButtonO = new BoutonDirection(centralwidget);
        pushButtonO->setObjectName(QString::fromUtf8("pushButtonO"));

        gridLayout->addWidget(pushButtonO, 1, 0, 1, 1);

        pushButtonNO = new BoutonDirection(centralwidget);
        pushButtonNO->setObjectName(QString::fromUtf8("pushButtonNO"));

        gridLayout->addWidget(pushButtonNO, 0, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        labelMoi = new QLabel(centralwidget);
        labelMoi->setObjectName(QString::fromUtf8("labelMoi"));

        horizontalLayout->addWidget(labelMoi);

        lcdNumberRouge = new QLCDNumber(centralwidget);
        lcdNumberRouge->setObjectName(QString::fromUtf8("lcdNumberRouge"));

        horizontalLayout->addWidget(lcdNumberRouge);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        verticalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        menuServer = new QMenu(menubar);
        menuServer->setObjectName(QString::fromUtf8("menuServer"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuServer->menuAction());
        menuServer->addAction(actionOpen);
        menuServer->addAction(actionRejoindre);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Abalone", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Heberger", nullptr));
        actionRejoindre->setText(QCoreApplication::translate("MainWindow", "Rejoindre", nullptr));
        labelAdversaire->setText(QCoreApplication::translate("MainWindow", "Bleus", nullptr));
        pushButtonSE->setText(QCoreApplication::translate("MainWindow", "SudEst", nullptr));
        pushButtonE->setText(QCoreApplication::translate("MainWindow", "Est", nullptr));
        pushButtonSO->setText(QCoreApplication::translate("MainWindow", "SudOuest", nullptr));
        pushButtonNE->setText(QCoreApplication::translate("MainWindow", "NordEst", nullptr));
        pushButtonO->setText(QCoreApplication::translate("MainWindow", "Ouest", nullptr));
        pushButtonNO->setText(QCoreApplication::translate("MainWindow", "NordOuest", nullptr));
        labelMoi->setText(QCoreApplication::translate("MainWindow", "Rouges", nullptr));
        menuServer->setTitle(QCoreApplication::translate("MainWindow", "Server", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
