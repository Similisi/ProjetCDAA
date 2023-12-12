#include "./interaction.h"

Interaction::~Interaction()
{
    //dtor
}

Interaction::Interaction(const std::string titre){
    this->titreInteraction = titre;
}

Interaction::Interaction(){

}

void Interaction::setInteraction(Interaction * i){
    this->setTitreInteraction(i->getTitre());
    this->setListeTache(i->getListeTache());
}

void Interaction::addTache(Tache* tache){
    Tache *ntache = new Tache(tache);
    this->listeTache.push_back(*ntache);
}

std::string Interaction::getTitre(){
    return this->titreInteraction;
}

bool Interaction::operator == (Interaction&i){
    bool resultat = false;
    if(this->getTitre() == i.getTitre()){
        //Ajouter aussi le test avec la liste
        resultat = true;
    }
    return resultat;
}

void Interaction::AfficherListeTache(){
    for(Tache t : this->listeTache)
    std::cout << t.getToDo() << std::endl;
}

std::list<Tache> Interaction::getListeTache(){
    return this->listeTache;
}
void Interaction::setTitreInteraction(std::string titre){
    this->titreInteraction = titre;
}

void Interaction::setListeTache(std::list<Tache> listeTache){
    this->listeTache = listeTache;
}
