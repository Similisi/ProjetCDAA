#include "affichageinteraction.h"
#include "ui_affichageinteraction.h"


AffichageInteraction::AffichageInteraction(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AffichageInteraction)
{
    interaction = new Interaction();
    ui->setupUi(this);
    connect(ui->Todo_Liste,SIGNAL(itemSelectionChanged()),this,SLOT(majDate()));
}

AffichageInteraction::~AffichageInteraction()
{
    delete ui;
}

void AffichageInteraction::InfoInteraction(Interaction * interModif){
    this->interaction->setInteraction(interModif);
    ui->Titre_Edit->setText(QString::fromStdString(interModif->getTitre()));
    ui->Todo_Liste->clear();
    ui->dateEdit->setVisible(false);
    for(auto tache : interModif->getListeTache()){
        QListWidgetItem* ql = new QListWidgetItem();
        QString titre = QString::fromStdString(tache.getToDo());
        ui->Todo_Liste->addItem(titre);
    }
}

void AffichageInteraction::on_close_btn_clicked()
{
    this->close();
}

void AffichageInteraction::majDate(){
    if(ui->Todo_Liste->selectedItems().size() != 0){
        for(auto t : this->interaction->getListeTache()){
            if(QString::fromStdString(t.getToDo()) == ui->Todo_Liste->selectedItems().at(0)->text()){
                if(t.getDateAction().jour == 0 && t.getDateAction().mois == 0 &&t.getDateAction().annee == 0){
                    //ui->dateEdit->setEnabled(false);
                    ui->dateEdit->setVisible(false);
                }else{
                    QDate * date = new QDate(t.getDateAction().annee,t.getDateAction().mois,t.getDateAction().jour);
                    ui->dateEdit->setDate(*date);
                    //ui->dateEdit->setEnabled(true);
                    ui->dateEdit->setVisible(true);
                }

            }
        }
    }
}

