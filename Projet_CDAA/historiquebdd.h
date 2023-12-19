#ifndef HISTORIQUEBDD_H
#define HISTORIQUEBDD_H

#include <QObject>
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QtSql/QSqlQuery>
#include "historique.h"

class HistoriqueBDD
{
public:
    HistoriqueBDD();
    void AddHistorique(Historique * h);
private:
    QSqlDatabase db;
};

#endif // HISTORIQUEBDD_H


