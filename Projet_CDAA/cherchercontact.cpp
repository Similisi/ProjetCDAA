#include "cherchercontact.h"
#include "ui_cherchercontact.h"

ChercherContact::ChercherContact(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChercherContact)
{
    rc = new ResultatContact();
    ui->setupUi(this);
    connect(ui->CheckAvant,SIGNAL(stateChanged(int)),this,SLOT(dateAvantEnabled(int)));
    connect(ui->checkapres,SIGNAL(stateChanged(int)),this,SLOT(dateApresEnabled(int)));
}

void ChercherContact::dateAvantEnabled(int i){
    qDebug() << i;
    if(i != 0){
        ui->dateavant_Edit->setEnabled(true);
    }else{
        ui->dateavant_Edit->setEnabled(false);
    }
}

void ChercherContact::dateApresEnabled(int i){
    qDebug() << i;
    if(i != 0){
        ui->dateapres_edit->setEnabled(true);
    }else{
        ui->dateapres_edit->setEnabled(false);
    }
}

ChercherContact::~ChercherContact()
{
    delete ui;
}

void ChercherContact::on_chercherBTN_clicked()
{
    std::list<Contact> listeRecherche;
    GestionnaireContact gc;
    for(auto i : gc.GetInstance()->getListeContact()){
        QDate datecreation = conversionDate(i.getDateCreation());
        if((ui->entrprise_edit->text() == "" || i.getEntreprise() == ui->entrprise_edit->text().toStdString())
          && (ui->nom_edit->text() == "" || i.getNom() == ui->nom_edit->text().toStdString())
          && (ui->prenom_edit->text() == "" || i.getPrenom() == ui->prenom_edit->text().toStdString())
          && (!ui->CheckAvant->isChecked() || datecreation < ui->dateavant_Edit->date())
          && (!ui->checkapres->isChecked() || datecreation > ui->dateapres_edit->date())){
            listeRecherche.push_back(i);
        }
    }
    rc->AjoutListe(listeRecherche);
    rc->show();
}

QDate ChercherContact::conversionDate(Date d){
    QDate res;
    res.setDate(d.annee,d.mois,d.jour);
    return res;
}

