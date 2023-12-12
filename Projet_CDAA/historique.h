#ifndef HISTORIQUE_H
#define HISTORIQUE_H

/*!
*   \file historique.h
*   \brief Classe creation des historique
*   \author Johann Fouchard
*/
#include <string>
#include <iostream>

#include "date.h"
/*!
*   \class Historique
*   \brief Classe creation des historiques
*   creation de historique
*/
class Historique
{
    public:
        /*!
        *   \brief constructeur
        *   \param action : nom en string de l'action présent dans l'historique
        *   \param datecreation : date de création de l'historique
        *   constructeur de historique
        */
        Historique(std::string,Date);
        /*!
        *   \brief constructeur
        *   \param action : nom en string de l'action présent dans l'historique
        *   constructeur de historique
        */
        Historique(std::string);
        virtual ~Historique();
        /*!
        *   \brief surcharge de l'operateur <<
        *   \param O : sortie dans lequellee sera retrourner le résultat de l'operateur
        *   \param Historique : historique utiliser pour traiter les information
        *   constructeur de historique
        */
        friend std::ostream& operator<< (std::ostream &o, const Historique&h);
        /*!
        *   \brief getAction
        *   \return action
        */
        std::string getAction() const;
        /*!
        *   \brief getDateCreation
        *   \return date de creation
        */
        Date getDateCreation() const;
        /*!
        *   \brief setAction
        *   \param action
        */
        void setAction(std::string);
        /*!
        *   \brief setDateCreation
        *   \param date de creation
        */
        void setDateCreation(Date);

    private:
        std::string action;
        Date dateCreation;
};

#endif // HISTORIQUE_H
