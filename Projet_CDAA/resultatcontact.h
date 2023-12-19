#ifndef RESULTATCONTACT_H
#define RESULTATCONTACT_H

#include <QWidget>
#include "contact.h"
namespace Ui {
class ResultatContact;
}

class ResultatContact : public QWidget
{
    Q_OBJECT

public:
    explicit ResultatContact(QWidget *parent = nullptr);
    ~ResultatContact();
    void AjoutListe(std::list<Contact> liste);

private:
    Ui::ResultatContact *ui;
    std::list<Contact> listeContact;
};

#endif // RESULTATCONTACT_H
