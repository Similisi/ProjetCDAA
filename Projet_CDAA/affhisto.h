#ifndef AFFHISTO_H
#define AFFHISTO_H

#include <QWidget>
#include "gestioninteraction.h"
#include "gestionnairecontact.h"
#include "gestionhistorique.h"
#include <QDebug>
namespace Ui {
class AffHisto;
}

class AffHisto : public QWidget
{
    Q_OBJECT

public:
    explicit AffHisto(QWidget *parent = nullptr);
    ~AffHisto();
    void MajHisto();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AffHisto *ui;
};

#endif // AFFHISTO_H
