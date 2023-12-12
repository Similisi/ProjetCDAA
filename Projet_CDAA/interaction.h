#ifndef INTERACTION_H
#define INTERACTION_H
/*!
*   \file interaction.h
*   \brief Classe création des interactions
*   \author Johann Fouchard
*/
#include "tache.h"
#include <string>
#include <list>
/*!
*   \class Interaction
*   \brief Classe création des interactions
*   creation de interaction
*/
class Interaction
{
    public:
    /*!
    *   \brief constructeur
    *   constructeur de interaction
    *   \param titre de l'interaction
    */
        Interaction(const std::string);
        virtual ~Interaction();

        Interaction();

        void setInteraction(Interaction * i);
    /*!
    *   \brief addTache
    *   \param tache
    */
        void addTache(Tache*);
    /*!
    *   \brief getTitre
    *   \return titre
    */
        std::string getTitre();
    /*!
    *   \brief operateur ==
    *   \param interaction
    */
        bool operator== (Interaction&i);
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
    *   \brief setTitreInteraction
    *   \param std::string
    */
        void setTitreInteraction(std::string);

        void setListeTache(std::list<Tache> listeTache);


    private:
        std::string titreInteraction;
        std::list<Tache> listeTache;


};

#endif // INTERACTION_H
