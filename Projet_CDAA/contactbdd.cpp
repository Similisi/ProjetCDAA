#include "contactbdd.h"
#include "historiquebdd.h"
#include <QDate>
#include <QSqlError>
ContactBDD::ContactBDD()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    //attention à avoir placer le fichier dans le répertoire /tmp
    db.setDatabaseName("../baseProjet.sqlite");
}

void ContactBDD::AddContact(Contact * c){
    if(!db.open())
          {
              qDebug() << "Pas de connexion BDD ! Contact";
          }
          else
          {

              qDebug() << "Connexion BDD ok";
              QSqlQuery query;


              query.prepare("INSERT INTO Contact (nom,prenom,entreprise,telephone,email,photo,date) VALUES (:n,:p,:e,:t,:m,:ph,:d)");
              query.bindValue(":n", QString::fromStdString(c->getNom()));
              query.bindValue(":p", QString::fromStdString(c->getPrenom()));
              query.bindValue(":e", QString::fromStdString(c->getEntreprise())) ;
              query.bindValue(":t", QString::fromStdString(c->getTelephone()));
              query.bindValue(":m", QString::fromStdString(c->getMail()));
              query.bindValue(":ph", QString::fromStdString(c->getPhoto())) ;
              QString date = "";

              date+=QString::number(c->getDateCreation().jour);
              date+="/";
              date+=QString::number(c->getDateCreation().mois);
              date+="/";
              date+=QString::number(c->getDateCreation().annee);
              qDebug() << "date bdd :"<<date;
              query.bindValue(":d", date);
              query.exec () ;
              //qDebug() << "id " << query.value(0).toString();
          }
    HistoriqueBDD *hb = new HistoriqueBDD();
    Historique* historique = new Historique("Ajout contact : "+c->getNom(),c->getDateCreation());
    hb->AddHistorique(historique);
    }
void ContactBDD::ModifierContact(QString anciennom,QString ancienprenom,Contact*c){
    if(!db.open())
          {
              qDebug() << "Pas de connexion BDD !";
          }
          else
          {

              qDebug() << "Connexion BDD ok";
              QSqlQuery query;
              qDebug() << QString::fromStdString(c->getNom());
              qDebug() << QString::fromStdString(c->getNom());
              qDebug() << QString::fromStdString(c->getPrenom());
              qDebug() << QString::fromStdString(c->getEntreprise()) ;
              qDebug() <<  QString::fromStdString(c->getTelephone());
              qDebug() <<  QString::fromStdString(c->getMail());
              qDebug() <<  QString::fromStdString(c->getPhoto()) ;
              //qDebug() << QString::fromStdString(c->getDateCreation());
              qDebug() << anciennom;
              qDebug() <<ancienprenom;

              query.prepare("UPDATE Contact SET nom=:n,prenom=:p,entreprise=:e,telephone=:t,email=:m,photo=:ph where nom=:an and prenom=:ap");
              query.bindValue(":n", QString::fromStdString(c->getNom()));
              query.bindValue(":p", QString::fromStdString(c->getPrenom()));
              query.bindValue(":e", QString::fromStdString(c->getEntreprise())) ;
              query.bindValue(":t", QString::fromStdString(c->getTelephone()));
              query.bindValue(":m", QString::fromStdString(c->getMail()));
              query.bindValue(":ph", QString::fromStdString(c->getPhoto())) ;
              query.bindValue(":an", anciennom);
              query.bindValue(":ap", ancienprenom);
              if(!query.exec ()){
                qDebug() << "Impossible d'exécuter la requête !" << query.lastError().text();
              }
          }
    HistoriqueBDD *hb = new HistoriqueBDD();
    QDate datecourrant = QDate::currentDate();
    Date *d = new Date();
    d->jour = datecourrant.day();
    d->mois = datecourrant.month();
    d->annee = datecourrant.year();
    QString action = "Modification de ";
    action += anciennom;
    action +="->";
    action += QString::fromStdString(c->getNom());
    Historique* historique = new Historique(action.toStdString(),*d);
    hb->AddHistorique(historique);

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

int ContactBDD::getLastId(){
    int res = 0;
    if(!db.open())
    {
        qDebug() << "Pas de connexion BDD !";
    }else
    {
        qDebug() << "Connexion BDD ok";
        QSqlQuery query("SELECT count(*) from Contact");
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
              qDebug() << "count : " << query.value(0).toString();
              res = query.value(0).toInt();
          }
        }
    }
    return res;
}

int ContactBDD::getidContact(Contact *c ){
    int res = 0;
    if(!db.open())
    {
        qDebug() << "Pas de connexion BDD !";
    }else
    {
        qDebug() << "Connexion BDD ok";
        QSqlQuery query;
        query.prepare("SELECT id from Contact where nom=:n and prenom=:p and entreprise=:e and telephone=:t and email=:em and photo=:ph and date=:d");
        query.bindValue(":n", QString::fromStdString(c->getNom()));
        query.bindValue(":p", QString::fromStdString(c->getPrenom()));
        query.bindValue(":e", QString::fromStdString(c->getEntreprise())) ;
        query.bindValue(":t", QString::fromStdString(c->getTelephone()));
        query.bindValue(":em", QString::fromStdString(c->getMail()));
        query.bindValue(":ph", QString::fromStdString(c->getPhoto()));
        QString date = "";

        date+=QString::number(c->getDateCreation().jour);
        date+="/";
        date+=QString::number(c->getDateCreation().mois);
        date+="/";
        date+=QString::number(c->getDateCreation().annee);
        qDebug() << "date bdd :"<<date;
        query.bindValue(":d", date);

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
              qDebug() << "id : " << query.value(0).toString();
              res = query.value(0).toInt();
          }
        }
    }
    return res;
}
