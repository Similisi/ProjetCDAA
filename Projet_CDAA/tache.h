#ifndef TACHE_H
#define TACHE_H
/*!
*   \file tache.h
*   \brief Classe création des taches
*   \author Johann Fouchard
*/
#include <string>
#include <iostream>
#include "date.h"
/*!
*   \class Tache
*   \brief Classe création des taches
*   création des taches
*/
class Tache
{
    public:
        /*!
        *   \brief constructeur
        *   \param tache : tache avec les balies
        *   constructeur de tache
        */
        Tache(const std::string);
        Tache(Tache* t);
        virtual ~Tache();
        /*!
        *   \brief constructeur
        *   \return std::string
        */
        std::string getToDo();
        /*!
        *   \brief getDateActiontoString
        *   \return std::string
        */
        std::string getDateActiontoString();

        Date getDateAction();
        /*!
        *   \brief setToDo
        *   \param std::string
        */
        void setToDo(std::string);
        /*!
        *   \brief setDateAction
        *   \param Date
        */
        void setDateAction(Date);
        /*!
        *   \brief operateur ==
        *   \param tache : tache avec les baliese
        */
        bool operator == (Tache&t);
    private:
        std::string toDO;
        Date dateAction;
        void split(std::string, char);
        void splitDate(std::string phrase);
};

#endif // TACHE_H
