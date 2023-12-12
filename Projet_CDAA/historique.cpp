#include "./historique.h"

Historique::Historique(std::string action,Date date)
{
    this->action = action;
    this->dateCreation = date;
    //ctor
}

Historique::Historique(std::string action){
    this->action = action;
}

Historique::~Historique()
{
    //dtor
}

std::ostream& operator << (std::ostream&o, const Historique&h){
    o << "Action : " << h.getAction();
    o << std::endl;
    o << "Date de Creation : " << h.getDateCreation().jour << "/" << h.getDateCreation().mois << "/" <<h.getDateCreation().annee;
    return o;
}

std::string Historique::getAction() const{
    return this->action;
}

Date Historique::getDateCreation() const{
    return this->dateCreation;
}

void Historique::setAction(std::string action) {
    this->action = action;
}

void Historique::setDateCreation(Date d){
    this->dateCreation = d;
}
