#include "resultatcontact.h"
#include "ui_resultatcontact.h"

ResultatContact::ResultatContact(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ResultatContact)
{
    ui->setupUi(this);
}

ResultatContact::~ResultatContact()
{
    delete ui;
}

void ResultatContact::AjoutListe(std::list<Contact> liste){
    this->listeContact.clear();
    ui->listWidget->clear();
    for(auto c : liste){
        this->listeContact.push_back(c);
        QString titre = QString::fromStdString(c.getPrenom()) + " ";
        titre += QString::fromStdString(c.getNom());
        QListWidgetItem* li = new QListWidgetItem(titre);
        ui->listWidget->addItem(li);
    }
}
