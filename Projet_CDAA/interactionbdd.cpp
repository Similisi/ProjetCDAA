#include "interactionbdd.h"

InteractionBdd::InteractionBdd()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    //attention à avoir placer le fichier dans le répertoire /tmp
    db.setDatabaseName("/tmp/base.sqlite");
}

void InteractionBdd::AddInteraction(Interaction * i){
    if(!db.open())
          {
              qDebug() << "Pas de connexion BDD !";
          }
          else
          {

              qDebug() << "Connexion BDD ok";
              QSqlQuery query;
              QSqlQuery query2;
              query.prepare("INSERT INTO Interaction (titre) VALUES (:t)");
              query.bindValue(":t", QString::fromStdString(i->getTitre()));
              query.exec();
              query.prepare("SELECT idInteraction from Interaction where titre = :t");
              query.bindValue(":t", QString::fromStdString(i->getTitre()));
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
                      QString id = query.value(1).toString();
                      qDebug() << "idInteraction : " << query.value(1).toString();
                      for(auto t : i->getListeTache()){
                        query2.prepare("INSERT INTO Tache (todo,dateAction,idInteraction) VALUES(:t,:d,:i)");
                        query2.bindValue(":t", QString::fromStdString(t.getToDo()));
                        query2.bindValue(":d", QString::fromStdString(t.getDateActiontoString()));
                        query2.bindValue(":i", id);
                      }
                  }
              }

          }
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

