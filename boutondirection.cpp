#include "boutondirection.h"
#include "abalonegrid.h"
#include "mainwindow.h"
int BoutonDirection::getDx() const
{
    return dx;
}

int BoutonDirection::getDy() const
{
    return dy;
}

void BoutonDirection::setDx(int value)
{
    dx = value;
}

void BoutonDirection::setDy(int value)
{
    dy = value;
}

BoutonDirection::BoutonDirection(QWidget* parent):QPushButton(parent)
{

}
