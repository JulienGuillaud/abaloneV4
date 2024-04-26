/********************************************************************************
** Form generated from reading UI file 'dialogconnection.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCONNECTION_H
#define UI_DIALOGCONNECTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DialogConnection
{
public:
    QPushButton *pushButtonLeave;
    QPushButton *pushButtonOk;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEditPseudo;
    QLineEdit *lineEditIp;

    void setupUi(QDialog *DialogConnection)
    {
        if (DialogConnection->objectName().isEmpty())
            DialogConnection->setObjectName(QString::fromUtf8("DialogConnection"));
        DialogConnection->resize(400, 300);
        pushButtonLeave = new QPushButton(DialogConnection);
        pushButtonLeave->setObjectName(QString::fromUtf8("pushButtonLeave"));
        pushButtonLeave->setGeometry(QRect(290, 260, 80, 21));
        pushButtonOk = new QPushButton(DialogConnection);
        pushButtonOk->setObjectName(QString::fromUtf8("pushButtonOk"));
        pushButtonOk->setGeometry(QRect(199, 260, 81, 21));
        label = new QLabel(DialogConnection);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 60, 47, 13));
        label_2 = new QLabel(DialogConnection);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(110, 130, 47, 13));
        lineEditPseudo = new QLineEdit(DialogConnection);
        lineEditPseudo->setObjectName(QString::fromUtf8("lineEditPseudo"));
        lineEditPseudo->setGeometry(QRect(100, 90, 113, 21));
        lineEditIp = new QLineEdit(DialogConnection);
        lineEditIp->setObjectName(QString::fromUtf8("lineEditIp"));
        lineEditIp->setGeometry(QRect(100, 160, 113, 21));

        retranslateUi(DialogConnection);

        QMetaObject::connectSlotsByName(DialogConnection);
    } // setupUi

    void retranslateUi(QDialog *DialogConnection)
    {
        DialogConnection->setWindowTitle(QCoreApplication::translate("DialogConnection", "Dialog", nullptr));
        pushButtonLeave->setText(QCoreApplication::translate("DialogConnection", "Annuler", nullptr));
        pushButtonOk->setText(QCoreApplication::translate("DialogConnection", "Ok", nullptr));
        label->setText(QCoreApplication::translate("DialogConnection", "Pseudo", nullptr));
        label_2->setText(QCoreApplication::translate("DialogConnection", "Ip", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogConnection: public Ui_DialogConnection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCONNECTION_H
