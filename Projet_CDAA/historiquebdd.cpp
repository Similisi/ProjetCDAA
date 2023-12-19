#include "historiquebdd.h"

HistoriqueBDD::HistoriqueBDD()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    //attention à avoir placer le fichier dans le répertoire /tmp
    db.setDatabaseName("../baseProjet.sqlite");

}

void HistoriqueBDD::AddHistorique(Historique * h){
    if(!db.open())
          {
              qDebug() << "Pas de connexion BDD ! Historique";
          }
          else
          {
              qDebug() << "Connexion BDD ok";
              QSqlQuery query;
              query.prepare("INSERT INTO historique (action,datecreation) VALUES (:a,:d)");
              query.bindValue(":a", QString::fromStdString(h->getAction()));
              QString date = "";
              date+=QString::number(h->getDateCreation().jour);
              date+="/";
              date+=QString::number(h->getDateCreation().mois);
              date+="/";
              date+=QString::number(h->getDateCreation().annee);
              qDebug() << "date bdd :"<<date;
              query.bindValue(":d", date);
              query.exec () ;
              //qDebug() << "id " << query.value(0).toString();
          }
    }
