#ifndef GESTIONINTERACTION_H
#define GESTIONINTERACTION_H

/*!
*   \file gestionInteraction.h
*   \brief Classe Gestion des interactions
*   \author Johann Fouchard
*/
#include "interaction.h"
#include "historique.h"
#include "date.h"
#include "contact.h"
#include <list>
#include "contactinteraction.h"
/*!
*   \class GestionInteraction
*   \brief Classe Gestion des interactions
*   creation de Gestion des interactions
*/

class GestionInteraction
{
    public:
        /*!
        *   \brief constructeur
        *   constructeur gestion des interactions
        */
        GestionInteraction();
        virtual ~GestionInteraction();
        /*!
        *   \brief addInteraction
        *   \param interaction
        */
        void addInteraction(const Interaction*);
        /*!
        *   \brief modificationInteraction
        *   \param titre pour la reconnaissance
        *   \param interaction
        */
        void modificationInteraction(const std::string titre, Interaction*,Date);
        /*!
        *   \brief SupprimerInteraction
        *   \param interaction
        */
        void SupprimerInteraction(Interaction*,Date);
        /*!
        *   \brief AfficherListeInteraction
        */
        void AfficherListeInteraction();
        /*!
        *   \brief getListeInteraction
        *   \return std::list<Interaction>
        */
        std::list<Interaction> getListeInteraction();
        /*!
        *   \brief getListeHistorique
        *   \return std::list<Historique>
        */
        std::list<Historique> getListeHistorique();
        GestionInteraction* GetInstance();
        void addLienContactInteraction( Interaction* interaction, Contact* c);
        std::list<ContactInteraction> getListeLien();
    private:
        std::list<Interaction> listeInteraction;
        std::list<ContactInteraction> listeLienContactInteraction;
        std::list<Historique> listeHistorique;
    protected:
        static GestionInteraction * instance;
};

#endif // GESTIONINTERACTION_H
