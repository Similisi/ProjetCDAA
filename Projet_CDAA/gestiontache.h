#ifndef GESTIONTACHE_H
#define GESTIONTACHE_H
/*!
*   \file gestionTache.h
*   \brief Classe Gestion des taches
*   \author Johann Fouchard
*/
#include "tache.h"
#include <list>
#include <string>
#include "historique.h"
#include "date.h"
/*!
*   \class GestionTache
*   \brief Classe Gestion des taches
*   creation de tache
*/

class GestionTache
{
    public:
        /*!
        *   \brief constructeur
        *   constructeur de Gestion des taches
        */
        GestionTache();
        virtual ~GestionTache();
        /*!
        *   \brief addTache
        *   \param tache
        */
        void addTache(const Tache*);
        /*!
        *   \brief modificationTache
        *   \param titre de la tache pour retrouver la cible
        *   \param tache pour la modification
        */
        void modificationTache(const std::string titre, Tache*,Date);
        /*!
        *   \brief SupprimerTache
        *   \param tache pour la suppression
        */
        void SupprimerTache(Tache*,Date);
        /*!
        *   \brief AfficherListeTache
        */
        void AfficherListeTache();
        /*!
        *   \brief getListeTache
        *   \return std::list<Tache>
        */
        std::list<Tache> getListeTache();
        /*!
        *   \brief getListeHistorique
        *   \return std::list<Historique>
        */
        std::list<Historique> getListeHistorique();

    private:
        std::list<Tache> listeTache;
        std::list<Historique> listeHistorique;
};

#endif // GESTIONTACHE_H
