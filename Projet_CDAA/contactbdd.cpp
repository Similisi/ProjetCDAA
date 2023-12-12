#include "contactbdd.h"

ContactBDD::ContactBDD()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    //attention à avoir placer le fichier dans le répertoire /tmp
    db.setDatabaseName("/tmp/base.sqlite");
}

void ContactBDD::AddContact(Contact * c){
    if(!db.open())
          {
              qDebug() << "Pas de connexion BDD !";
          }
          else
          {

              qDebug() << "Connexion BDD ok";
              QSqlQuery query;


              query.prepare("INSERT INTO Contact (nom,prenom,entreprise,telephone,mail,photo,dateCreation) VALUES (:n,:p,:e,:t,:m,:ph,:d)");
              query.bindValue(":n", QString::fromStdString(c->getNom()));
              query.bindValue(":p", QString::fromStdString(c->getPrenom()));
              query.bindValue(":e", QString::fromStdString(c->getEntreprise())) ;
              query.bindValue(":t", QString::fromStdString(c->getTelephone()));
              query.bindValue(":m", QString::fromStdString(c->getMail()));
              query.bindValue(":ph", QString::fromStdString(c->getPhoto())) ;
              QString date = "";
              date+=c->getDateCreation().jour;
              date+="/";
              date+=c->getDateCreation().mois;
              date+="/";
              date+=c->getDateCreation().annee;
              query.bindValue(":d", date);
              query.exec () ;
          }
    }
void ContactBDD::ModifierContact(Contact* anciencontact,Contact*c){
    if(!db.open())
          {
              qDebug() << "Pas de connexion BDD !";
          }
          else
          {

              qDebug() << "Connexion BDD ok";
              QSqlQuery query;


              query.prepare("UPDATE Contact SET nom,prenom,entreprise,telephone,mail,photo,dateCreation where nom,prenom,entreprise,telephone,mail,photo,dateCreation");
              query.bindValue(":nn", QString::fromStdString(c->getNom()));
              query.bindValue(":np", QString::fromStdString(c->getPrenom()));
              query.bindValue(":ne", QString::fromStdString(c->getEntreprise())) ;
              query.bindValue(":nt", QString::fromStdString(c->getTelephone()));
              query.bindValue(":nm", QString::fromStdString(c->getMail()));
              query.bindValue(":nph", QString::fromStdString(c->getPhoto())) ;
              QString date = "";
              date+=c->getDateCreation().jour;
              date+="/";
              date+=c->getDateCreation().mois;
              date+="/";
              date+=c->getDateCreation().annee;
              query.bindValue(":nd", date);
              query.bindValue(":n", QString::fromStdString(anciencontact->getNom()));
              query.bindValue(":p", QString::fromStdString(anciencontact->getPrenom()));
              query.bindValue(":e", QString::fromStdString(anciencontact->getEntreprise())) ;
              query.bindValue(":t", QString::fromStdString(anciencontact->getTelephone()));
              query.bindValue(":m", QString::fromStdString(anciencontact->getMail()));
              query.bindValue(":ph", QString::fromStdString(anciencontact->getPhoto())) ;
              QString date2 = "";
              date2+=anciencontact->getDateCreation().jour;
              date2+="/";
              date2+=anciencontact->getDateCreation().mois;
              date2+="/";
              date2+=anciencontact->getDateCreation().annee;
              query.bindValue(":d", date2);
              query.exec () ;
          }

}

std::list<Contact> ContactBDD::SelectAllContact(){
    if(!db.open())
          {
              qDebug() << "Pas de connexion BDD !";
          }
          else
          {

              qDebug() << "Connexion BDD ok";
              QSqlQuery query("SELECT * from Contact");
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
                      qDebug() << "nom : " << query.value(1).toString();
                      qDebug() << "prenom : " << query.value(2).toString();
                      qDebug() << "age : " << query.value(3).toString();
                  }
              }
          }




}
