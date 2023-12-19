#ifndef CONTACTBDD_H
#define CONTACTBDD_H

#include <QObject>
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QtSql/QSqlQuery>
#include "contact.h"

class ContactBDD
{
public:
    ContactBDD();
    void AddContact(Contact *);
    void ModifierContact(QString anciennom,QString ancienprenom,Contact*);
    std::list<Contact> SelectAllContact();
    int getLastId();
    int getidContact(Contact *c );
private:
    QSqlDatabase db;
};

#endif // CONTACTBDD_H
