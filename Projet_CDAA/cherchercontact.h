#ifndef CHERCHERCONTACT_H
#define CHERCHERCONTACT_H

#include <QWidget>
#include "resultatcontact.h"
#include "gestionnairecontact.h"
#include <QDebug>
namespace Ui {
class ChercherContact;
}

class ChercherContact : public QWidget
{
    Q_OBJECT

public:
    explicit ChercherContact(QWidget *parent = nullptr);
    ~ChercherContact();
    QDate conversionDate(Date d);

private slots:
    void on_chercherBTN_clicked();
    void dateAvantEnabled(int i);
    void dateApresEnabled(int i);

private:
    Ui::ChercherContact *ui;
    ResultatContact* rc;
};

#endif // CHERCHERCONTACT_H
