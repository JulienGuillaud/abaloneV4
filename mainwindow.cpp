#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "abalonegrid.h"
#include "boutondirection.h"
#include <QDebug>
#include <QLCDNumber>
#include <QMessageBox>
#include <QTcpServer>
#include <QDialog>
#include <QInputDialog>
#include <QDir>
#include <QPalette>
#include "dialogconnection.h"

class BoutonDirection;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ajout de la grille abalone
    lePlateau=new AbaloneGrid();
    ui->verticalLayout->addLayout(lePlateau);

    //connection des signaux aux slots
    connect(lePlateau,SIGNAL(joueurActifChange(QString)),this, SLOT(changementJoueur(QString)));
    connect(lePlateau, SIGNAL(selectionAChange()),this, SLOT(activeDesactiveBtDirection()));
    //je remplis mon vecteur de BoutonDirection
    ui->pushButtonE->setDx(2);
    ui->pushButtonE->setDy(0);
    vectBoutonRouges.push_back(ui->pushButtonE);
    vectBoutonBleus.push_back(ui->pushButtonE);
    ui->pushButtonO->setDx(-2);
    ui->pushButtonO->setDy(0);
    vectBoutonRouges.push_back(ui->pushButtonO);
    vectBoutonBleus.push_back(ui->pushButtonO);

    ui->pushButtonNE->setDx(1);
    ui->pushButtonNE->setDy(-1);
    vectBoutonRouges.push_back(ui->pushButtonNE);

    ui->pushButtonNO->setDx(-1);
    ui->pushButtonNO->setDy(-1);
    vectBoutonRouges.push_back(ui->pushButtonNO);

    ui->pushButtonSE->setDx(1);
    ui->pushButtonSE->setDy(1);
    vectBoutonBleus.push_back(ui->pushButtonSE);

    ui->pushButtonSO->setDx(-1);
    ui->pushButtonSO->setDy(1);
    vectBoutonBleus.push_back(ui->pushButtonSO);


    foreach( BoutonDirection* leBouton, vectBoutonBleus)
    {
        connect(leBouton, SIGNAL(clicked()), lePlateau, SLOT(deplacerSelection()));
    }
    foreach( BoutonDirection* leBouton, vectBoutonRouges)
    {
        if(!vectBoutonBleus.contains(leBouton))
            connect(leBouton, SIGNAL(clicked()), lePlateau, SLOT(deplacerSelection()));
    }
    connect(lePlateau,SIGNAL(bouleEjectee(QString)),this, SLOT(majScore(QString)));
    changementJoueur("rouge");
    ui->labelMoi->setStyleSheet("color:#F00");
    ui->labelAdversaire->setStyleSheet("color:#00F");
    ui->lcdNumberRouge->setStyleSheet("color:#F00; background-color:#FFF");
    ui->lcdNumberBleu->setStyleSheet("color:#00F; background-color:#FFF");
    monService= new QTcpServer(this);

//    bool ok;
//    QString text = QInputDialog::getText(this, tr("QInputDialog::getText()"),tr("User name:"), QLineEdit::Normal, QDir::home().dirName(), &ok);
//    if (ok && !text.isEmpty())
//        ui->labelMoi->setText(text);

}
MainWindow::~MainWindow()
{
    delete ui;
}

AbaloneGrid *MainWindow::getLePlateau() const
{
    return lePlateau;
}


void MainWindow::afficherGagnant(QString leGagnant)
{
    QMessageBox::information(this,"Abalone","The winner is: "+leGagnant);
}
/**
 * @brief MainWindow::changementJoueur
 * @param nouveauJoueur
 * active et désactive les boutons directionnels
 */
void MainWindow::changementJoueur(QString nouveauJoueur)
{
    qDebug()<<"void MainWindow::changementJoueur(QString nouveauJoueur)";
    //désactivation de tous les boutons de direction
    foreach(BoutonDirection* leBouton, vectBoutonBleus)
    {
        leBouton->setEnabled(false);
    }
    foreach(BoutonDirection* leBouton, vectBoutonRouges)
    {
        leBouton->setEnabled(false);
    }
}
/**
 * @brief MainWindow::activeDesactiveBtDirection
 * ce slot est exécuté lorsque la sélection a changé
 * on doit activer ou désactiver les boutons de direction en fonction de la sélection et du joueur actif
 */
void MainWindow::activeDesactiveBtDirection()
{
    qDebug()<<"void MainWindow::activeDesactiveBtDirection()";
    //si aucune sélection n'a été faite on désactive tous les boutons
    if(lePlateau->selectionEmpty())
    {
        //On commence par les rouges
        foreach (BoutonDirection* leBouton, vectBoutonRouges)
        {
            leBouton->setEnabled(false);
        }
        //on fini par les bleus
        foreach (BoutonDirection* leBouton, vectBoutonBleus)
        {
            leBouton->setEnabled(false);
        }
    }
    else //il y a une sélection
    {
        //parcours des boutons de direction et test si dans la direction des boutons le déplacement est possible
        QVector<BoutonDirection*>vectBoutonDirectionActivables, vectBoutonsADesactiver;
        if(lePlateau->getJoueurActif()=="rouge")
        {
            vectBoutonDirectionActivables=vectBoutonRouges;
            vectBoutonsADesactiver=vectBoutonBleus;
        }
        else
        {
            vectBoutonDirectionActivables=vectBoutonBleus;
            vectBoutonsADesactiver=vectBoutonRouges;
        }
        //désactivation des autres boutons
        foreach (BoutonDirection* leBouton, vectBoutonsADesactiver)
        {
            leBouton->setEnabled(false);
        }
        //activation éventuelle des boutons propres au joueur actif
        foreach (BoutonDirection* leBouton, vectBoutonDirectionActivables)
        {
            //j'obtiens de dx et dy du bouton
            int dx=leBouton->getDx();
            int dy=leBouton->getDy();
            //obtention poids de la sélection et résistance

            int lePoids=lePlateau->poidsSelection(dx,dy);
            int laResistance=lePlateau->resistanceSelection(dx,dy);
            //pour debugger
            qDebug()<<"dans la direction"<<leBouton->text()<<" le poids est de: "<<lePoids<<" et la résistance est de: "<<laResistance;
            //activation si les conditions sont réunies
            leBouton->setEnabled(lePoids>laResistance);
        }
    }
}
/**
 * @brief MainWindow::majScore
 * @param joueurActif
 * met à jour les scores des joueurs et eventuellement affiche le gagnant
 */
void MainWindow::majScore(QString joueurActif)
{
    qDebug()<<"void MainWindow::majScore(QString joueurActif)";
    QLCDNumber * leLCDNumber;
    QLCDNumber * lAutreLCDNumber;
    if(joueurActif=="rouge")
    {
        leLCDNumber=ui->lcdNumberRouge;
        lAutreLCDNumber=ui->lcdNumberBleu;
    }
    else
    {
        leLCDNumber=ui->lcdNumberBleu;
        lAutreLCDNumber=ui->lcdNumberRouge;
    }
    leLCDNumber->display(leLCDNumber->value()+1);
    if(leLCDNumber->value()==6 ||leLCDNumber->value()-lAutreLCDNumber->value()==2 )
    {
        afficherGagnant(joueurActif);
        //fermer l'application
        close();
    }

}

void MainWindow::connexionATraiter()
{
    //je gère la connexion
    qDebug()<<"Traitement de la connection";
    laSocketDeCom=monService->nextPendingConnection();
    laSocketDeCom->write("WELCOME\r\n\r\n");
    connect(laSocketDeCom, SIGNAL(readyRead()),this, SLOT(traiteMessageRecu()));
}

void MainWindow::traiteMessageRecu()
{

    QString message=laSocketDeCom->readAll();
    qDebug()<<"Message = "<<message;
    QStringList listeDesMotsDuMessage=message.split(" ");
    if(listeDesMotsDuMessage.size()<2)
    {
        qDebug()<<"Erreur, message non valide";
    }
    else
    {
        QString laCommande=listeDesMotsDuMessage[0];
        QString leReste=listeDesMotsDuMessage[1];
        if(laCommande=="PSEUDO")
        {
            ui->labelAdversaire->setText(leReste);
        }
        else if(laCommande=="CLIC")
        {
            //c'est un clic il faut que je répercute ça sur mon plateau
            //J'attends vos propositions
            //extraire les coordonnées du message
            QString lesCoordo=leReste.split("\r")[0];
            QStringList listeCoordo=lesCoordo.split(",");
            int abcisse=listeCoordo[0].toInt();
            int ordonnee=listeCoordo[1].toInt();
            //chopper la bille correspondante
            Emplacement * lEmplacement=lePlateau->getEmplacement(abcisse,ordonnee);
            //lui faire émettre le signal clicked
            lEmplacement->click();
        }
        else
        {
            if(laCommande=="BOUTON")
            {
                BoutonDirection* boutonConcerne=nullptr;
                if(leReste.left(2)=="NO")
                {
                    boutonConcerne=ui->pushButtonNO;
                }
                else if(leReste.left(2)=="NE")
                {
                    boutonConcerne=ui->pushButtonNE;
                }
                else if(leReste.left(2)=="SE")
                {
                    boutonConcerne=ui->pushButtonSE;
                }
                else if(leReste.left(2)=="SO")
                {
                    boutonConcerne=ui->pushButtonSO;
                }
                else if(leReste.left(1)=="O")
                {
                    boutonConcerne=ui->pushButtonO;
                }
                else if(leReste.left(1)=="E")
                {
                    boutonConcerne=ui->pushButtonE;
                }
                if(boutonConcerne!=nullptr)
                    boutonConcerne->click();            }
        }
    }
}


void MainWindow::on_actionOpen_triggered()
{
    qDebug()<<"Server open";
    connect(monService,SIGNAL(newConnection()), this, SLOT(connexionATraiter()));
    monService->listen(QHostAddress::Any,11111);
    monService->waitForNewConnection();
}


void MainWindow::on_actionRejoindre_triggered()
{
    DialogConnection theDialog;
    theDialog.exec();
    QString pseudo=theDialog.getPseudo();
    QString ip=theDialog.getIp();
    qDebug()<<"Pseudo : "<<pseudo<<" | ip : "<<ip;

//    monService->connect(ip,11111);
    laSocketDeCom->connectToHost(ip, 11111);

    laSocketDeCom->write("PSEUDO Mechant");
}
