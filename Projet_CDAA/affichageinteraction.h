#ifndef AFFICHAGEINTERACTION_H
#define AFFICHAGEINTERACTION_H

#include <QWidget>
#include "interaction.h"

namespace Ui {
class AffichageInteraction;
}

class AffichageInteraction : public QWidget
{
    Q_OBJECT

public:
    explicit AffichageInteraction(QWidget *parent = nullptr);
    ~AffichageInteraction();
    void InfoInteraction(Interaction *);

private slots:
    void on_close_btn_clicked();
    void majDate();

private:
    Ui::AffichageInteraction *ui;
    Interaction * interaction;
};

#endif // AFFICHAGEINTERACTION_H
