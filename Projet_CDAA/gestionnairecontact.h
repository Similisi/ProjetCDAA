#ifndef GESTIONNAIRECONTACT_H
#define GESTIONNAIRECONTACT_H
/*!
*   \file gestionnaireContact.h
*   \brief Classe gestionnaire de contact
*   \author Johann Fouchard
*/
#include <list>

#include "contact.h"
#include "historique.h"
/*!
*   \class GestionnaireContact
*   \brief Classe gestionnaire de contact
*   creation de gestionnaire de contact
*/
class GestionnaireContact
{
    public:
        /*!
        *   \brief constructeur
        *   constructeur du gestionnaire de contact
        */
        GestionnaireContact();
        virtual ~GestionnaireContact();
        /*!
        *   \brief addContact
        *   \param contact
        */
        void addContact(const Contact*);
        /*!
        *   \brief modificationContact
        *   \param nom pour la reconnaissance
        *   \param prenom pour la reconnaissance
        *   \param contact pour la modification
        *   \param date pour l'historique
        */
        void modificationContact(const std::string nom,const std::string prenom, Contact* contact,Date);
        /*!
        *   \brief SupprimerContact
        *   \param contact pour la suppression
        *   \param date pour l'historique
        */
        void SupprimerContact(Contact* contact,Date date);
        /*!
        *   \brief AfficherListeContact
        */
        void AfficherListeContact();
        /*!
        *   \brief getListeContact
        *   \return std::list<Contact>
        */
        std::list<Contact> getListeContact();
        /*!
        *   \brief getListeHistorique
        *   \return std::list<Historique>
        */
        std::list<Historique> getListeHistorique();
        /*!
        *   \brief GetInstance
        *   \return GestionnaireContact
        *   singleton de la classe GestionnaireContact
        */
        GestionnaireContact* GetInstance();
    private:

        std::list<Contact> listeContact;
        std::list<Historique> listeHistorique;
    protected:
        static GestionnaireContact * instance;

};

#endif // GESTIONNAIRECONTACT_H
