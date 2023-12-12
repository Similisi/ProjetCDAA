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
    void ModifierContact(Contact*,Contact*);
    std::list<Contact> SelectAllContact();
private:
    QSqlDatabase db;
};

#endif // CONTACTBDD_H
