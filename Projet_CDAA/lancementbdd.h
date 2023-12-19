#ifndef LANCEMENTBDD_H
#define LANCEMENTBDD_H

#include <QObject>
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QtSql/QSqlQuery>
#include "gestioninteraction.h"
#include "gestionnairecontact.h"
#include "gestionhistorique.h"

class Lancementbdd
{
public:
    Lancementbdd();
    void lancementProg();
private:
    QSqlDatabase db;
};

#endif // LANCEMENTBDD_H
