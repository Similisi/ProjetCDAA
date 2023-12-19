#ifndef GESTIONHISTORIQUE_H
#define GESTIONHISTORIQUE_H

#include "historique.h"
#include "date.h"
#include <list>


class GestionHistorique
{
public:
    GestionHistorique();
    GestionHistorique* GetInstance();
    void addHistorique(Historique* historique);
    std::list<Historique> getListeHistorique();
private:
    std::list<Historique> listeHistorique;

protected:
    static GestionHistorique* instance;
};

#endif // GESTIONHISTORIQUE_H




