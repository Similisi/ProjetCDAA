#include "./contact.h"


Contact::~Contact()
{
}

Contact::Contact(Contact* c){
    this->nom = c->getNom();
    this->prenom = c->getPrenom();
    this->entreprise = c->getEntreprise();
    this->mail = c->getMail();
    this->telephone = c->getTelephone();
    this->photo = c->getPhoto();
    this->dateCreation = c->getDateCreation();
}

Contact::Contact(std::string nom,std::string prenom,std::string entreprise,std::string mail,std::string telephone,std::string photo,Date dateCreation){

    this->nom = nom;
    this->prenom = prenom;
    this->entreprise = entreprise;
    this->mail = mail;
    this->telephone = telephone;
    this->photo = photo;
    this->dateCreation = dateCreation;

}

std::ostream& operator << (std::ostream&o, const Contact&c){
    o << "Nom : " << c.getNom();
    o << std::endl;
    o << "Prenom : " << c.getPrenom();
    o << std::endl;
    o << "Entreprise : " << c.getEntreprise();
    o << std::endl;
    o << "Mail : " << c.getMail();
    o << std::endl;
    o << "Telephone : " << c.getTelephone();
    o << std::endl;
    o << "Photo : " << c.getPhoto();
    o << std::endl;
    o << "Date de Creation : " << c.getDateCreation().jour << "/" << c.getDateCreation().mois << "/" <<c.getDateCreation().annee;
    return o;
}

bool Contact::operator == (const Contact&c){
    bool resultat = false;
    if(this->getNom() == c.getNom() && this->getPrenom() == c.getPrenom() && this->getEntreprise() == c.getEntreprise() && this->getMail() == c.getMail() && this->getTelephone() == c.getTelephone() && this->getPhoto() == c.getPhoto() && this->getDateCreation().jour == c.getDateCreation().jour && this->getDateCreation().mois == c.getDateCreation().mois && this->getDateCreation().annee == c.getDateCreation().annee ){
        //Ajouter aussi le test avec && this->getListeInteraction() == c.getListeInteraction()
        resultat = true;
    }
    return resultat;
}

void Contact::addInteraction(Interaction* interaction){
    Interaction *itemp = new Interaction(interaction->getTitre());
    itemp->setListeTache(interaction->getListeTache());
    itemp->AfficherListeTache();

    this->listeInteraction.push_back(*itemp);
}

std::string Contact::getNom() const{
    return this->nom;
}
std::string Contact::getPrenom() const{
    return this->prenom;
}
std::string Contact::getEntreprise() const{
    return this->entreprise;
}
std::string Contact::getMail() const{
    return this->mail;
}
std::string Contact::getTelephone() const{
    return this->telephone;
}
std::string Contact::getPhoto() const{
    return this->photo;
}
Date Contact::getDateCreation() const{
    return this->dateCreation;
}


std::list<Interaction> Contact::getListeInteraction(){
    return this->listeInteraction;
}

void Contact::setNom(const std::string n){
    this->nom = n;
}
void Contact::setPrenom(const std::string p){
    this->prenom = p;
}
void Contact::setEntreprise(const std::string e){
    this->entreprise = e;
}
void Contact::setMail(const std::string m){
    this->mail = m;

}
void Contact::setTelephone(const std::string t){
    this->telephone = t;

}
void Contact::setPhoto(const std::string p){
    this->photo = p;

}
void Contact::setDateCreation(const Date d){
    this->dateCreation = d;
}
void Contact::setListeInteraction(const std::list<Interaction> l){
    this->listeInteraction = l;

}
