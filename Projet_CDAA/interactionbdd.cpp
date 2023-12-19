#include "interactionbdd.h"
#include <QSqlError>
#include "historiquebdd.h"
#include <QDate>
InteractionBdd::InteractionBdd()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    //attention à avoir placer le fichier dans le répertoire /tmp
    db.setDatabaseName("../baseProjet.sqlite");
}

void InteractionBdd::AddInteraction(Interaction * i,Contact * c){
    if(!db.open())
          {
              qDebug() << "Pas de connexion BDD ! Interaction";
          }
          else
          {
              ContactBDD* cb =new ContactBDD();
              int idcontact = cb->getidContact(c);
              qDebug() << "Connexion BDD ok " << idcontact << " : " <<QString::fromStdString(i->getTitre()) ;
              QSqlQuery query;
              QSqlQuery query2;
              query.prepare("INSERT INTO Interaction (idContact,titre) VALUES (:i,:t)");
              query.bindValue(":i", idcontact);
              query.bindValue(":t", QString::fromStdString(i->getTitre()));
              query.exec();
              query.prepare("SELECT idInteraction from Interaction where titre = :t and idContact = :id");
              query.bindValue(":t", QString::fromStdString(i->getTitre()));
              query.bindValue(":id",idcontact);
              if(!query.exec())
              {
                  qDebug() << "Impossible d'exécuter la requête !";
              }
              else
              {
                  qDebug() << "Requête exécutée";
                  while(query.next())
                  {
                      //le value(0) est l'idPersonne
                      QString id = query.value(0).toString();
                      qDebug() << "idInteraction : " << query.value(0).toString();
                      qDebug() << "taille : " << i->getListeTache().size();
                      for(auto t : i->getListeTache()){
                        query2.prepare("INSERT INTO Tache (todo,date,idInteraction) VALUES(:t,:d,:i)");
                        query2.bindValue(":t", QString::fromStdString(t.getToDo()));
                        query2.bindValue(":d", QString::fromStdString(t.getDateActiontoString()));
                        query2.bindValue(":i", id);
                        if(!query2.exec())
                        {
                            qDebug() << "Impossible d'exécuter la requête !" << query2.lastError().text();
                        }
                      }
                  }
              }

          }
    HistoriqueBDD *hb = new HistoriqueBDD();
    QDate datecourrant = QDate::currentDate();
    Date *d = new Date();
    d->jour = datecourrant.day();
    d->mois = datecourrant.month();
    d->annee = datecourrant.year();
    Historique* historique = new Historique("Ajout interaction "+i->getTitre() +" pour "+c->getNom(),*d);
    hb->AddHistorique(historique);
}

std::list<Interaction> InteractionBdd::SelectAllInteraction(){
    if(!db.open())
          {
              qDebug() << "Pas de connexion BDD !";
          }
          else
          {

              qDebug() << "Connexion BDD ok";
              QSqlQuery query("SELECT titre,todo,dateAction from Interaction,Tache WHERE Interaction.idInteraction = Tache.idInteraction");
              if(!query.exec())
              {
                  qDebug() << "Impossible d'exécuter la requête !";
              }
              else
              {
                  qDebug() << "Requête exécutée";
                  while(query.next())
                  {
                      //le value(0) est l'idPersonne
                      qDebug() << "titre : " << query.value(1).toString();
                      qDebug() << "todo : " << query.value(2).toString();
                      qDebug() << "dateAction : " << query.value(3).toString();
                  }
              }
          }
}

