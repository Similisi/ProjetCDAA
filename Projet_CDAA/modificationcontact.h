#ifndef MODIFICATIONCONTACT_H
#define MODIFICATIONCONTACT_H

#include <QWidget>
#include "contact.h"
#include "gestioninteraction.h"

namespace Ui {
class ModificationContact;
}

class ModificationContact : public QWidget
{
    Q_OBJECT

public:
    explicit ModificationContact(QWidget *parent = nullptr);
    ~ModificationContact();
    void ModifContact(Contact * c);
private slots:

    void on_AnnulerBTN_clicked();

    void on_ModifBTN_clicked();
signals:
    void ModifCont();
private:
    Ui::ModificationContact *ui;
    std::string ancienNom ;
    std::string ancienPrenom;
};

#endif // MODIFICATIONCONTACT_H
