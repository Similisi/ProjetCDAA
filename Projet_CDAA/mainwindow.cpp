#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "contactbdd.h"
#include "lancementbdd.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Lancementbdd* lb = new Lancementbdd();

    lb->lancementProg();
    this->majListeDebut();
    ad = new AddContact();

    mc = new ModificationContact();
    ai = new AddInteraction();
    Affi = new AffichageInteraction();
    cc = new ChercherContact();
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
                mc->ModifContact(contactModif);
            }
        }

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
                qDebug() << QString::fromStdString(cont.getPrenom()) << " " << QString::fromStdString(cont.getNom());
                contactModif = &cont;
                ai->InitInteraction(contactModif);
            }
        }

        ai->show();
    }else{
        QMessageBox msgBox;
        msgBox.setText("Il vous faut séléctionner un contact");
        msgBox.exec();
    }

}

void MainWindow::majListInteraction(){
    if(ui->ListeContactWidg->selectedItems().size() != 0){
        qDebug() << "maj";
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
            qDebug() << "boucle :"<< cont.getListeTache().size() ;
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


void MainWindow::on_actionChercher_contact_triggered()
{
    cc->show();
}


void MainWindow::on_pushButton_4_clicked()
{
    //export JSON
    GestionInteraction* gi;
    GestionnaireContact* gc;
    QByteArray jsonData;
    for(auto contact : gc->GetInstance()->getListeContact()){
        QJsonObject jsonObject;
        jsonObject["nom"] = QString::fromStdString(contact.getNom());
        jsonObject["prenom"] = QString::fromStdString(contact.getPrenom());
        jsonObject["entreprise"] = QString::fromStdString(contact.getEntreprise());
        jsonObject["mail"] = QString::fromStdString(contact.getMail());
        jsonObject["photo"] = QString::fromStdString(contact.getPhoto());
        jsonObject["telephone"] = QString::fromStdString(contact.getTelephone());
        QString date = contact.getDateCreation().jour + "/" + contact.getDateCreation().mois;
        date += "/"+ contact.getDateCreation().annee;
        jsonObject["date"] = date;
        QJsonDocument jsonDoc(jsonObject);
        jsonData.push_back(jsonDoc.toJson(QJsonDocument::Indented));
    }
    for(auto lien : gi->GetInstance()->getListeLien()){
        QJsonObject jsonObject;
        jsonObject["titre"] = QString::fromStdString(lien.getInteraction()->getTitre());
        QJsonArray jsonarr;
        for(auto t : lien.getInteraction()->getListeTache()){

            std::string res = "";
            res += '"';
            res +="todo";
            res += '"';
            res += ": "+t.getToDo();
            res += '"';
            res += ",";
            res += '"';
            res +="date";
            res += '"';
            res += ": "+t.getDateActiontoString();
            res += '"';
            res += ",";
            jsonarr.append(QString::fromStdString(res));
        }
        jsonObject["tache"] = jsonarr;
        QJsonDocument jsonDoc(jsonObject);
        jsonData.push_back(jsonDoc.toJson(QJsonDocument::Indented));
    }
        // Sauvegarder la chaîne JSON dans un fichier
        QFile file("../ExportJSON.json");
        if (file.open(QIODevice::WriteOnly)) {
            file.write(jsonData);
            file.close();
            QMessageBox msgBox;
            msgBox.setText("votre JSON a bien été crée dans le dossier avant la racine du projet");
            msgBox.exec();
        } else {

            QMessageBox msgBox;
            msgBox.setText("Erreur lors de l'ouverture du fichier.");
            msgBox.exec();
        }
}

void MainWindow::majListeDebut(){
    GestionnaireContact* gc;
    qDebug() << "size : " << gc->GetInstance()->getListeContact().size();
    for(auto c: gc->GetInstance()->getListeContact()){
        QListWidgetItem* ql = new QListWidgetItem();
        QString titre = QString::fromStdString(c.getNom());
        titre += " ";
        titre += QString::fromStdString(c.getPrenom());
        ql->setText(titre);
        ui->ListeContactWidg->addItem(ql);
    }
}

void MainWindow::on_Chercher_btn_clicked()
{
    cc->show();
}


void MainWindow::on_actionExport_JSON_triggered()
{
    //export JSON
    GestionInteraction* gi;
    GestionnaireContact* gc;
    QByteArray jsonData;
    for(auto contact : gc->GetInstance()->getListeContact()){
        QJsonObject jsonObject;
        jsonObject["nom"] = QString::fromStdString(contact.getNom());
        jsonObject["prenom"] = QString::fromStdString(contact.getPrenom());
        jsonObject["entreprise"] = QString::fromStdString(contact.getEntreprise());
        jsonObject["mail"] = QString::fromStdString(contact.getMail());
        jsonObject["photo"] = QString::fromStdString(contact.getPhoto());
        jsonObject["telephone"] = QString::fromStdString(contact.getTelephone());
        QString date = contact.getDateCreation().jour + "/" + contact.getDateCreation().mois;
        date += "/"+ contact.getDateCreation().annee;
        jsonObject["date"] = date;
        QJsonDocument jsonDoc(jsonObject);
        jsonData.push_back(jsonDoc.toJson(QJsonDocument::Indented));
    }
    for(auto lien : gi->GetInstance()->getListeLien()){
        QJsonObject jsonObject;
        jsonObject["titre"] = QString::fromStdString(lien.getInteraction()->getTitre());
        QJsonArray jsonarr;
        for(auto t : lien.getInteraction()->getListeTache()){

            std::string res = "";
            res += '"';
            res +="todo";
            res += '"';
            res += ": "+t.getToDo();
            res += '"';
            res += ",";
            res += '"';
            res +="date";
            res += '"';
            res += ": "+t.getDateActiontoString();
            res += '"';
            res += ",";
            jsonarr.append(QString::fromStdString(res));
        }
        jsonObject["tache"] = jsonarr;
        QJsonDocument jsonDoc(jsonObject);
        jsonData.push_back(jsonDoc.toJson(QJsonDocument::Indented));
    }
        // Sauvegarder la chaîne JSON dans un fichier
        QFile file("../ExportJSON.json");
        if (file.open(QIODevice::WriteOnly)) {
            file.write(jsonData);
            file.close();
            QMessageBox msgBox;
            msgBox.setText("votre JSON a bien été crée dans le dossier avant la racine du projet");
            msgBox.exec();
        } else {

            QMessageBox msgBox;
            msgBox.setText("Erreur lors de l'ouverture du fichier.");
            msgBox.exec();
        }

}

