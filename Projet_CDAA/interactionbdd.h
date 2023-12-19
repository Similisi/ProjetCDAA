#ifndef INTERACTIONBDD_H
#define INTERACTIONBDD_H

#include <QObject>
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QtSql/QSqlQuery>
#include "interaction.h"
#include "contact.h"
#include "contactbdd.h"

class InteractionBdd
{
public:
    InteractionBdd();
    void AddInteraction(Interaction *,Contact*);
    void ModifierInteraction(Interaction*,Interaction*);
    std::list<Interaction> SelectAllInteraction();
private:
    QSqlDatabase db;
};

#endif // INTERACTIONBDD_H
