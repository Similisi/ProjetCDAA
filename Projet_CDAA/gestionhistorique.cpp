#include "gestionhistorique.h"
GestionHistorique* GestionHistorique::instance = nullptr;
GestionHistorique::GestionHistorique()
{

}

GestionHistorique* GestionHistorique::GetInstance(){
    if(!instance)
        instance = new GestionHistorique();
    return instance;
}

void GestionHistorique::addHistorique(Historique* historique){
    this->listeHistorique.push_back(*historique);
}

std::list<Historique> GestionHistorique::getListeHistorique(){
    return this->listeHistorique;
}
