#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ad = new AddContact();

    mc = new ModificationContact();
    ai = new AddInteraction();
    Affi = new AffichageInteraction();
    connect(ad,SIGNAL(ajoutCont()),this,SLOT(majListContact()));
    connect(mc,SIGNAL(ModifCont()),this,SLOT(majListContact()));
    connect(ai,SIGNAL(AjoutInteractionSign()),this,SLOT(majListInteraction()));
    connect(ui->ListeContactWidg,SIGNAL(itemSelectionChanged()),this,SLOT(majListInteraction()));
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_AjoutContact_BTN_clicked()
{
    qDebug() << "Bouton Ajout Contact";
    ad->show();
}

void MainWindow::majListContact(){
    qDebug() << "Ajout a la liste";
    GestionnaireContact* gs;
    ui->ListeContactWidg->clear();
    for(auto cont : gs->GetInstance()->getListeContact()){
        QListWidgetItem* ql = new QListWidgetItem();
        QString titre = QString::fromStdString(cont.getNom());
        titre += " ";
        titre += QString::fromStdString(cont.getPrenom());
        ql->setText(titre);
        ui->ListeContactWidg->addItem(ql);
    }
}


void MainWindow::on_ModifContact_BTN_clicked()
{
    qDebug() << "Bouton Modif Contact";
    if(ui->ListeContactWidg->selectedItems().size() != 0){
        GestionnaireContact* gs;
        QString nom = ui->ListeContactWidg->currentItem()->text().split(" ")[0];
        QString prenom = ui->ListeContactWidg->currentItem()->text().split(" ")[1];
        Contact *contactModif;
        for(auto cont : gs->GetInstance()->getListeContact()){
            if(cont.getNom() == nom.toStdString() && cont.getPrenom() == prenom.toStdString()){
                contactModif = &cont;
            }
        }
        mc->ModifContact(contactModif);
        mc->show();
    }else{
        QMessageBox msgBox;
        msgBox.setText("Il vous faut séléctionner un contact");
        msgBox.exec();
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    if(ui->ListeContactWidg->selectedItems().size() != 0){
        GestionnaireContact* gs;
        QString nom = ui->ListeContactWidg->currentItem()->text().split(" ")[0];
        QString prenom = ui->ListeContactWidg->currentItem()->text().split(" ")[1];
        Contact *contactModif;
        for(auto cont : gs->GetInstance()->getListeContact()){
            if(cont.getNom() == nom.toStdString() && cont.getPrenom() == prenom.toStdString()){
                contactModif = &cont;
            }
        }
        ai->InitInteraction(contactModif);
        ai->show();
    }else{
        QMessageBox msgBox;
        msgBox.setText("Il vous faut séléctionner un contact");
        msgBox.exec();
    }

}

void MainWindow::majListInteraction(){
    if(ui->ListeContactWidg->selectedItems().size() != 0){
        QString nom = ui->ListeContactWidg->currentItem()->text().split(" ")[0];
        QString prenom = ui->ListeContactWidg->currentItem()->text().split(" ")[1];
        GestionInteraction* gi;
        std::list<ContactInteraction> listeTemp = gi->GetInstance()->getListeLien();
        ui->ListeInteractionWidg->clear();
        if(listeTemp.size() != 0){
            for(auto i : listeTemp){
                if(i.getContact()->getNom() == nom.toStdString() && i.getContact()->getPrenom() == prenom.toStdString()){
                    QListWidgetItem* ql = new QListWidgetItem();
                    QString titre = QString::fromStdString(i.getInteraction()->getTitre());
                    ql->setText(titre);
                    ui->ListeInteractionWidg->addItem(ql);
                }
            }
        }

    }
}


void MainWindow::on_pushButton_3_clicked()
{
    if(ui->ListeInteractionWidg->selectedItems().size() != 0){
        GestionInteraction* gi;
        QString titre = ui->ListeInteractionWidg->currentItem()->text();
        Interaction *interModif = new Interaction();
        for(auto cont : gi->GetInstance()->getListeInteraction()){
            if(cont.getTitre() == titre.toStdString()){
                interModif->setInteraction(&cont);
            }
        }


        Affi->InfoInteraction(interModif);
        Affi->show();
    }else{
        QMessageBox msgBox;
        msgBox.setText("Il vous faut séléctionner une interaction");
        msgBox.exec();
    }
}


void MainWindow::on_actionHistorique_triggered()
{
    AffHisto* ah = new AffHisto();
    ah->MajHisto();
    ah->show();
}


void MainWindow::on_pushButton_clicked()
{
    AffHisto* ah = new AffHisto();
    ah->MajHisto();
    ah->show();
}

