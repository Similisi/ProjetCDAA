#include "gestiontache.h"

GestionTache::GestionTache()
{
    //ctor
}

GestionTache::~GestionTache()
{
    //dtor
}


void GestionTache::addTache(const Tache* tache){
    this->listeTache.push_back(*tache);
}
void GestionTache::modificationTache(const std::string titre, Tache* tache,Date d){
    auto it = this->listeTache.begin();
    std::string titre2 = titre + " ";


    while (it != this->listeTache.end()) {
        if (it->getToDo() == titre2) {
            it = this->listeTache.erase(it);
            this->listeTache.insert(it,*tache);
        }

        ++it; // Avancer l'itérateur vers l'élément suivant
    }

    Historique *historique = new Historique("Modification "+titre+" -> "+tache->getToDo(),d);
    this->listeHistorique.push_back(*historique);
}
void GestionTache::SupprimerTache(Tache* tache,Date d){
    auto it = this->listeTache.begin();


    while (it != this->listeTache.end()) {
        if (*it == *tache) {
            it = this->listeTache.erase(it);
        }

        ++it; // Avancer l'itérateur vers l'élément suivant
    }

    Historique *historique = new Historique("Suppression de "+tache->getToDo(),d);
    this->listeHistorique.push_back(*historique);
}

void GestionTache::AfficherListeTache(){
    std::cout << "Liste des Taches "<< std::endl;
    for(Tache t : this->listeTache){
        std::cout << t.getToDo() << " "<< t.getDateActiontoString() << std::endl;
    }
}

std::list<Tache> GestionTache::getListeTache(){
    return this->listeTache;
}
std::list<Historique> GestionTache::getListeHistorique(){
    return this->listeHistorique;
}
