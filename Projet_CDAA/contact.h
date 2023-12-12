#ifndef CONTACT_H
#define CONTACT_H

/*!
*   \file contact.h
*   \brief Classe creation de contact
*   \author Johann Fouchard
*/

#include <string>
#include <list>
#include <iostream>

#include "./date.h"
#include "interaction.h"

/*!
*   \class Contact
*   \brief Classe creation de contact
*   creation de contact
*/

class Contact
{
private:
    std::string nom;
    std::string prenom;
    std::string entreprise;
    std::string mail;
    std::string telephone;
    std::string photo;
    Date dateCreation;
    std::list<Interaction> listeInteraction;
public:
/*!
*   \brief constructeur
*   \param nom : nom du contact
*   \param prenom : prenom du contact
*   \param entreprise : entreprise du contact
*   \param mail : mail du contact
*   \param telephone : telephone du contact
*   \param photo : photo du contact
*   \param dateCreation : dateCreation du contact
*   constructeur de contact
*/
    Contact(std::string nom,std::string prenom,std::string entreprise,std::string mail,std::string telephone,std::string photo,Date dateCreation);
    Contact(Contact *);
/*!
*   \brief destructeur
*   destructeur de contact
*/
    ~Contact();
/*!
*   \brief surcharge <<
*/
    friend std::ostream& operator<< (std::ostream &o, const Contact&c);
/*!
*   \brief surcharge ==
*/
    bool operator== (const Contact&c);
/*!
*   \brief getteur nom
*   \return nom
*/
    std::string getNom() const;
/*!
*   \brief getteur Prenom
*   \return Prenom
*/
    std::string getPrenom() const;
/*!
*   \brief getteur Entreprise
*   \return Entreprise
*/
    std::string getEntreprise() const;
/*!
*   \brief getteur Mail
*   \return Mail
*/
    std::string getMail() const;
/*!
*   \brief getteur Telephone
*   \return Telephone
*/
    std::string getTelephone() const;
/*!
*   \brief getteur Photo
*   \return Photo
*/
    std::string getPhoto() const;
/*!
*   \brief getteur DateCreation
*   \return DateCreation
*/
    Date getDateCreation() const;
/*!
*   \brief getteur ListeInteraction
*   \return ListeInteraction
*/
    std::list<Interaction> getListeInteraction();
/*!
*   \brief setteur Nom
*   \param string
*/
    void setNom(const std::string);
/*!
*   \brief setteur Prenom
*   \param string
*/
    void setPrenom(const std::string);
/*!
*   \brief setteur Entreprise
*   \param string
*/
    void setEntreprise(const std::string);
/*!
*   \brief setteur Mail
*   \param string
*/
    void setMail(const std::string);
/*!
*   \brief setteur Telephone
*   \param string
*/
    void setTelephone(const std::string);
/*!
*   \brief setteur Photo
*   \param string
*/
    void setPhoto(const std::string);
/*!
*   \brief setteur DateCreation
*   \param Date
*/
    void setDateCreation(const Date);
/*!
*   \brief setteur ListeInteraction
*   \param list<Interaction>
*/
    void setListeInteraction(const std::list<Interaction>);
    void addInteraction(Interaction*);
};

#endif
