#include "modificationcontact.h"
#include "ui_modificationcontact.h"
#include <QMessageBox>
#include <QDebug>
#include "gestionnairecontact.h"
#include "contactbdd.h"
ModificationContact::ModificationContact(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModificationContact)
{
    ui->setupUi(this);
}

ModificationContact::~ModificationContact()
{
    delete ui;
}

void ModificationContact::ModifContact(Contact * c){
    ancienNom = c->getNom();
    ancienPrenom = c->getPrenom();
    ui->NomEdit->setText(QString::fromStdString(c->getNom()));
    ui->PrenomEdit->setText(QString::fromStdString(c->getPrenom()));
    ui->EntrepriseEdit->setText(QString::fromStdString(c->getEntreprise()));
    ui->MailEdit->setText(QString::fromStdString(c->getMail()));
    ui->TelEdit->setText(QString::fromStdString(c->getTelephone()));
    ui->PhotoEdit->setText(QString::fromStdString(c->getPhoto()));
    QDate* date = new QDate();
    date->setDate(c->getDateCreation().annee,c->getDateCreation().mois,c->getDateCreation().jour);
    ui->dateEdit->setDate(*date);
    this->close();
}


void ModificationContact::on_AnnulerBTN_clicked()
{
    this->close();

}


void ModificationContact::on_ModifBTN_clicked()
{
    qDebug() << "Bouton Accepté Modif Contact";
    if(ui->NomEdit->text() == "" || ui->PrenomEdit->text() == "" || ui->EntrepriseEdit->text() == "" || ui->MailEdit->text() == "" ||
            ui->TelEdit->text() == "" || ui->PhotoEdit->text() == ""){
        QMessageBox msgBox;
        msgBox.setText("Tout les champs ne sont pas renseigné");
        msgBox.exec();
    }else{
    //std::string nom,std::string prenom,std::string entreprise,std::string mail,std::string telephone,std::string photo,Date dateCreation
    std::string nomContact = ui->NomEdit->text().toStdString();
    std::string prenomContact = ui->PrenomEdit->text().toStdString();
    std::string entrepriseContact = ui->EntrepriseEdit->text().toStdString();
    std::string mailContact = ui->MailEdit->text().toStdString();
    std::string telContact = ui->TelEdit->text().toStdString();
    std::string photoContact = ui->PhotoEdit->text().toStdString();
    Date *dateContact = new Date();
    dateContact->jour = ui->dateEdit->date().day();
    dateContact->mois = ui->dateEdit->date().month();
    dateContact->annee = ui->dateEdit->date().year();
    Contact *c = new Contact(nomContact,prenomContact,entrepriseContact,mailContact,telContact,photoContact,*dateContact);
    GestionnaireContact* gs;
    GestionInteraction* gi;
    //@todo mettre par rapport a la date du jour et non datecontact
    gs->GetInstance()->modificationContact(this->ancienNom,this->ancienPrenom,c,*dateContact);
    for(auto l :gi->GetInstance()->getListeLien()){
        if(l.getContact()->getNom() == this->ancienNom && l.getContact()->getPrenom() == this->ancienPrenom){
            l.getContact()->setPrenom(c->getPrenom());
            l.getContact()->setNom(c->getNom());
        }
    }
    emit ModifCont();
    ContactBDD* cb = new ContactBDD();
    cb->ModifierContact(QString::fromStdString(this->ancienNom),QString::fromStdString(this->ancienPrenom),c);
    this->close();
    }

}

