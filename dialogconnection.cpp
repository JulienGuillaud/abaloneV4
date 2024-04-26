#include "dialogconnection.h"
#include "ui_dialogconnection.h"
#include <QDebug>

DialogConnection::DialogConnection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogConnection)
{
    ui->setupUi(this);
}

DialogConnection::~DialogConnection()
{
    delete ui;
}

QString DialogConnection::getPseudo()
{
    return pseudo;
}

QString DialogConnection::getIp()
{
    return ip;
}

void DialogConnection::on_pushButtonOk_clicked()
{
    qDebug()<<"Validation";
    pseudo=ui->lineEditPseudo->text();
    ip=ui->lineEditIp->text();
    accept();
}

void DialogConnection::on_pushButtonLeave_clicked()
{
    qDebug()<<"Annulation";
    reject();
}
