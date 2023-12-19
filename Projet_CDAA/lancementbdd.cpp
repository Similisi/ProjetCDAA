#include "lancementbdd.h"
#include <QSqlError>
Lancementbdd::Lancementbdd()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    //attention à avoir placer le fichier dans le répertoire /tmp
    db.setDatabaseName("../baseProjet.sqlite");
}

void Lancementbdd::lancementProg(){
    if(!db.open())
          {
              qDebug() << "Pas de connexion BDD !";
          }
  else
  {
        GestionnaireContact * gc;
        GestionInteraction *gi;
        qDebug() << "Connexion BDD ok";
        //creation des contact
        QSqlQuery query("SELECT nom,prenom,entreprise,photo,email,Contact.date,telephone from Contact");
        if(!query.exec()){
            qDebug() << "Impossible d'exécuter la requête !" << query.lastError().text();
        }else{
            while(query.next()){
            qDebug() << "nom : " << query.value(0).toString();
            qDebug() << "prenom : " << query.value(1).toString();
            qDebug() << "entreprise : " << query.value(2).toString();
            qDebug() << "photo : " << query.value(3).toString();
            qDebug() << "email : " << query.value(4).toString();
            qDebug() << "Contact.date : " << query.value(5).toString();
            qDebug() << "telephone : " << query.value(6).toString();
            QString nom =query.value(0).toString();
            QString prenom = query.value(1).toString();
            QString entreprise = query.value(2).toString();
            QString photo = query.value(3).toString();
            QString email = query.value(4).toString();
            QString dateC = query.value(5).toString();
            QString telephone = query.value(6).toString();
            Date* d = new Date();
            d->jour = dateC.split("/").at(0).toInt();
            d->mois = dateC.split("/").at(1).toInt();
            d->annee = dateC.split("/").at(2).toInt();

            Contact *c = new Contact(nom.toStdString(),prenom.toStdString(),entreprise.toStdString(),email.toStdString(),telephone.toStdString(),photo.toStdString(),*d);
            gc->GetInstance()->addContact(c);
            }
        }
        QSqlQuery query2("Select * from Interaction,Tache where Interaction.idInteraction = Tache.idInteraction");
        Interaction *i;
        int idContactpourinteraction = -1;
        int idInteractionpourinteraction = -1;
        bool pasinteraction = true;
        if(!query2.exec()){
            qDebug() << "Impossible d'exécuter la requête !" << query2.lastError().text();
        }else{
            while(query2.next()){
                pasinteraction = false;
                qDebug() << "idInteraction : " << query2.value(0).toString();
                qDebug() << "idContact : " << query2.value(1).toString();
                qDebug() << "titre : " << query2.value(2).toString();
                qDebug() << "idTache : " << query2.value(3).toString();
                qDebug() << "todo : " << query2.value(4).toString();
                qDebug() << "Tache.date : " << query2.value(5).toString();
                qDebug() << "idInteraction : " << query2.value(6).toString();
                QString idInteraction =query2.value(0).toString();
                QString idContact = query2.value(1).toString();
                QString titre = query2.value(2).toString();
                QString idTache = query2.value(3).toString();
                QString todo = query2.value(4).toString();
                QString dateT = query2.value(5).toString();
                Date* d2 = new Date();
                d2->jour = dateT.split("/").at(0).toInt();
                d2->mois = dateT.split("/").at(1).toInt();
                d2->annee = dateT.split("/").at(2).toInt();
                //premiere boucle
                if(idContactpourinteraction == -1 && idInteractionpourinteraction == -1){
                   idContactpourinteraction = idContact.toInt();
                   idInteractionpourinteraction = idInteraction.toInt();
                   i =new Interaction(titre.toStdString());
                   Tache *t = new Tache("");
                   t->setToDo(todo.toStdString());
                   t->setDateAction(*d2);
                   i->addTache(t);
                }else if(idContactpourinteraction == idContact.toInt() && idInteractionpourinteraction == idInteraction.toInt()){
                    //on a une nouvelle tache mais meme interaction
                    Tache *t = new Tache("");
                    t->setToDo(todo.toStdString());
                    t->setDateAction(*d2);
                    i->addTache(t);
                }else if(idContactpourinteraction == idContact.toInt() && idInteractionpourinteraction != idInteraction.toInt()){
                    //nouvelle interaction pour le meme contact
                    //on enregistre déjà l'ancienne interaction
                    gi->GetInstance()->addInteraction(i);
                    int pos = 1;
                    for(auto c: gc->GetInstance()->getListeContact()){
                        if(pos == idContactpourinteraction){
                            Contact *copie = new Contact(c);
                             gi->GetInstance()->addLienContactInteraction(i,copie);
                        }
                        pos++;
                    }
                    //on fait un nouvelle interaction
                    idInteractionpourinteraction = idInteraction.toInt();
                    i =new Interaction(titre.toStdString());
                    Tache *t = new Tache("");
                    t->setToDo(todo.toStdString());
                    t->setDateAction(*d2);
                    i->addTache(t);


                }else if(idContactpourinteraction != idContact.toInt() && idInteractionpourinteraction != idInteraction.toInt()){
                    //nouvelle interaction pour un contact different
                    //on enregistre déjà l'ancienne interaction
                    gi->GetInstance()->addInteraction(i);
                    int pos = 1;
                    for(auto c: gc->GetInstance()->getListeContact()){
                        if(pos == idContactpourinteraction){
                            Contact *copie = new Contact(c);
                             gi->GetInstance()->addLienContactInteraction(i,copie);
                        }
                        pos++;
                    }
                    //on fait un nouvelle interaction
                    idContactpourinteraction = idContact.toInt();
                    idInteractionpourinteraction = idInteraction.toInt();
                    i =new Interaction(titre.toStdString());
                    Tache *t = new Tache("");
                    t->setToDo(todo.toStdString());
                    t->setDateAction(*d2);
                    i->addTache(t);
                }
            }
            if(!pasinteraction){
                //on a fini don on enregistre tout
                //on enregistre déjà l'ancienne interaction
                gi->GetInstance()->addInteraction(i);
                int pos = 1;
                for(auto c: gc->GetInstance()->getListeContact()){
                    if(pos == idContactpourinteraction){
                        Contact *copie = new Contact(c);
                         gi->GetInstance()->addLienContactInteraction(i,copie);
                    }
                    pos++;
                }
            }
        }
        QSqlQuery query3("Select action,datecreation from historique");
        GestionHistorique gh;
        if(!query3.exec()){
            qDebug() << "Impossible d'exécuter la requête !" << query3.lastError().text();
        }else{
            while(query3.next()){
                qDebug() << "action : " << query3.value(0).toString();
                qDebug() << "datecreation : " << query3.value(1).toString();
                Date* d3 = new Date();
                d3->jour = query3.value(1).toString().split("/").at(0).toInt();
                d3->mois = query3.value(1).toString().split("/").at(1).toInt();
                d3->annee = query3.value(1).toString().split("/").at(2).toInt();
                Historique *h = new Historique("");
                h->setAction(query3.value(0).toString().toStdString());
                h->setDateCreation(*d3);
                gh.GetInstance()->addHistorique(h);
            }
        }
    }
}
