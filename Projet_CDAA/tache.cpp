#include "tache.h"

Tache::~Tache()
{
    //dtor
}

Tache::Tache(const std::string interaction){
    //split(interaction+" ",' ');
}

Tache::Tache(Tache* t){
    this->toDO = t->getToDo();
    this->dateAction.jour = t->dateAction.jour;
    this->dateAction.mois = t->dateAction.mois;
    this->dateAction.annee = t->dateAction.annee;
}

void Tache::split(std::string phrase, char separateur){
    int fin = phrase.find(separateur);
    bool isTodo = false,isDate = false;
    while (fin != -1){
        if (isDate){
            splitDate(phrase.substr(0,fin));
        }else{
            this->dateAction.jour = 0;
            this->dateAction.mois = 0;
            this->dateAction.annee = 0;
        }
        if(isTodo && phrase.substr(0,fin) != "@date"){
            this->toDO.append(phrase.substr(0,fin));
            this->toDO.append(" ");
        }
        if(phrase.substr(0,fin) == "@todo"){
            isTodo = true;
            isDate = false;
        }else if (phrase.substr(0,fin) == "@date"){
            isDate = true;
            isTodo = false;
        }


        phrase.erase(phrase.begin(),phrase.begin() + fin + 1);
        fin = phrase.find(separateur);
    }


}


void Tache::splitDate(std::string phrase){
    if(phrase != "" || phrase != " "){
        char separateur = '/';
        int fin = phrase.find(separateur);
        int index = 0;
        while (fin != -1){
            if(index == 0){
                this->dateAction.jour = std::stoi(phrase.substr(0,fin));
            }else if(index == 1){
                this->dateAction.mois = std::stoi(phrase.substr(0,fin));
            }
            index++;

            phrase.erase(phrase.begin(),phrase.begin() + fin + 1);
            fin = phrase.find(separateur);
        }
        this->dateAction.annee = std::stoi(phrase.substr(0,fin));
    }

}

std::string Tache::getToDo(){
    return this->toDO;
}

 std::string Tache::getDateActiontoString(){
    std::string res = "";
    res += std::to_string(this->dateAction.jour);
    res += "/";
    res += std::to_string(this->dateAction.mois);
    res += "/";
    res += std::to_string(this->dateAction.annee);
    return res;
 }

 bool Tache::operator == (Tache&t){
    bool resultat = false;
    if(this->getToDo() == t.getToDo() && this->getDateActiontoString() == t.getDateActiontoString()){
        resultat = true;
    }
    return resultat;
}

 Date Tache::getDateAction(){
    return this->dateAction;
 }

void Tache::setToDo(std::string toDo){
    this->toDO = toDo;

}
void Tache::setDateAction(Date d){
    this->dateAction = d;
}
