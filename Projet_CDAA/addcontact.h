#ifndef ADDCONTACT_H
#define ADDCONTACT_H

#include <QDialog>
#include <QMessageBox>
#include <QDebug>
#include <QDate>
#include "contact.h"
#include "date.h"
#include "gestionnairecontact.h"
#include "contactbdd.h"
namespace Ui {
class AddContact;
}

class AddContact : public QDialog
{
    Q_OBJECT

public:
    explicit AddContact(QWidget *parent = nullptr);
    ~AddContact();

private slots:
    void on_AJoutBTN_clicked();

    void on_AnnulerBTN_clicked();

signals:
    void ajoutCont();
private:
    Ui::AddContact *ui;
};

#endif // ADDCONTACT_H
