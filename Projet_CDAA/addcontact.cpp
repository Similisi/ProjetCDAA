#include "addcontact.h"
#include "ui_addcontact.h"

AddContact::AddContact(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddContact)
{
    ui->setupUi(this);
    QDate datetoday = QDate::currentDate();
    ui->dateEdit->dateChanged(datetoday);
    //ui->dateEdit->date().setDate(datetoday.year(),datetoday.month(),datetoday.day());
}

AddContact::~AddContact()
{
    delete ui;
}

void AddContact::on_AJoutBTN_clicked()
{
    qDebug() << "Bouton Accepté Ajout Contact";
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

    ContactBDD *cb = new ContactBDD();
    GestionnaireContact* gs;

    gs->GetInstance()->addContact(c);

    cb->AddContact(c);
    emit ajoutCont();
    ui->NomEdit->clear();
    ui->PrenomEdit->clear();
    ui->EntrepriseEdit->clear();
    ui->MailEdit->clear();
    ui->TelEdit->clear();
    ui->PhotoEdit->clear();
    ui->dateEdit->clear();
    this->close();
    }

}




void AddContact::on_AnnulerBTN_clicked()
{
    qDebug() << "Bouton Refuser Ajout Contact";
    this->close();
}

