#ifndef ADDINTERACTION_H
#define ADDINTERACTION_H

#include <QWidget>
#include "contact.h"
#include <QDebug>
#include <QTextBlock>
#include "gestioninteraction.h"
namespace Ui {
class AddInteraction;
}

class AddInteraction : public QWidget
{
    Q_OBJECT

public:
    explicit AddInteraction(QWidget *parent = nullptr);
    ~AddInteraction();
    void InitInteraction(Contact * c);
    void AjoutInteraction();

private slots:
    void on_valider_btn_clicked();

    void on_annuler_btn_clicked();
signals:
    void AjoutInteractionSign();
private:
    Ui::AddInteraction *ui;
    Contact *contact;
};

#endif // ADDINTERACTION_H
