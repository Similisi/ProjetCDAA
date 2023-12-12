#include "./gestionnairecontact.h"
#include <QDate>
#include <iostream>

GestionnaireContact* GestionnaireContact::instance = nullptr;

GestionnaireContact::GestionnaireContact(){
}
GestionnaireContact::~GestionnaireContact(){
}

GestionnaireContact* GestionnaireContact::GetInstance(){
    if(!instance)
        instance = new GestionnaireContact();
    return instance;
}


void GestionnaireContact::addContact(const Contact* c){
    this->listeContact.push_back(*c);
    QDate datejour = QDate::currentDate();
    Date* d = new Date();
    d->jour = datejour.day();
    d->mois = datejour.month();
    d->annee = datejour.year();
    Historique *historique = new Historique("Ajout contact : "+c->getNom(),*d);
    this->listeHistorique.push_back(*historique);
}
void GestionnaireContact::modificationContact(const std::string nom,const std::string prenom, Contact* contact,Date date){
    auto it = this->listeContact.begin();
    bool modifapporte = false;

    while (it != this->listeContact.end() && !modifapporte) {
        if (it->getNom() == nom && it->getPrenom() == prenom) {
            it = this->listeContact.erase(it);
            this->listeContact.insert(it,*contact);
            modifapporte = true;
        }

        ++it; // Avancer l'itérateur vers l'élément suivant
    }

    Historique *historique = new Historique("Modification "+nom+" -> "+contact->getNom(),date);
    this->listeHistorique.push_back(*historique);
}

void GestionnaireContact::SupprimerContact(Contact* contact,Date date){
    auto it = this->listeContact.begin();


    while (it != this->listeContact.end()) {
        if (*it == *contact) {
            it = this->listeContact.erase(it);
        }

        ++it; // Avancer l'itérateur vers l'élément suivant
    }

    Historique *historique = new Historique("Suppression de "+contact->getNom(),date);
    this->listeHistorique.push_back(*historique);
}

void GestionnaireContact::AfficherListeContact(){
    std::cout << "Liste des contacts "<< std::endl;
    for(Contact c : this->listeContact){
        std::cout << c.getNom() << " "<< c.getPrenom() << std::endl;
    }
}

std::list<Contact> GestionnaireContact::getListeContact(){
    return this->listeContact;
}
std::list<Historique> GestionnaireContact::getListeHistorique(){
    return this->listeHistorique;
}

