#include "gestioninteraction.h"
#include <QDebug>
#include <QDate>
GestionInteraction* GestionInteraction::instance = nullptr;
GestionInteraction::GestionInteraction()
{
    //ctor
}

GestionInteraction::~GestionInteraction()
{
    //dtor
}

GestionInteraction* GestionInteraction::GetInstance(){
    if(!instance)
        instance = new GestionInteraction();
    return instance;
}

void GestionInteraction::addInteraction(const Interaction* interaction){
    this->listeInteraction.push_back(*interaction);
    QDate datejour = QDate::currentDate();
    Date* d = new Date();
    d->jour = datejour.day();
    d->mois = datejour.month();
    d->annee = datejour.year();
    Historique *historique = new Historique("Ajout Interaction ",*d);
    this->listeHistorique.push_back(*historique);
}
void GestionInteraction::addLienContactInteraction( Interaction* interaction, Contact* c){
    ContactInteraction *ci = new ContactInteraction();
    //qDebug() << "nom contact add:" <<QString::fromStdString(c->getNom());
    ci->AddContact(c);
    ci->AddInteraction(interaction);
    this->listeLienContactInteraction.push_back(*ci);
    QDate datejour = QDate::currentDate();
    Date* d = new Date();
    d->jour = datejour.day();
    d->mois = datejour.month();
    d->annee = datejour.year();
    Historique *historique = new Historique("Ajout Interaction "+interaction->getTitre()+" pour "+c->getNom(),*d);
    this->listeHistorique.push_back(*historique);
}

std::list<ContactInteraction> GestionInteraction::getListeLien(){
    return this->listeLienContactInteraction;
}
void GestionInteraction::modificationInteraction(const std::string titre, Interaction* interaction,Date d){
    auto it = this->listeInteraction.begin();


    while (it != this->listeInteraction.end()) {
        if (it->getTitre() == titre) {
            it = this->listeInteraction.erase(it);
            this->listeInteraction.insert(it,*interaction);
        }

        ++it; // Avancer l'itérateur vers l'élément suivant
    }

    Historique *historique = new Historique("Modification "+titre+" -> "+interaction->getTitre(),d);
    this->listeHistorique.push_back(*historique);
    for (Interaction i : this->listeInteraction)
        std::cout << i.getTitre() << std::endl;
}
void GestionInteraction::SupprimerInteraction(Interaction* interaction,Date d){
    auto it = this->listeInteraction.begin();


    while (it != this->listeInteraction.end()) {
        if (*it == *interaction) {
            it = this->listeInteraction.erase(it);
        }

        ++it; // Avancer l'itérateur vers l'élément suivant
    }

    Historique *historique = new Historique("Suppression de "+interaction->getTitre(),d);
    this->listeHistorique.push_back(*historique);
}

void GestionInteraction::AfficherListeInteraction(){

    std::cout << "Liste des Interaction "<< std::endl;
    for(Interaction i : this->listeInteraction){
        std::cout << i.getTitre() << std::endl;
    }
}

std::list<Interaction> GestionInteraction::getListeInteraction(){
    return this->listeInteraction;
}
std::list<Historique> GestionInteraction::getListeHistorique(){
    return this->listeHistorique;
}
