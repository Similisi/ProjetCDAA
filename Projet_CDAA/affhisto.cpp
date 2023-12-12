#include "affhisto.h"
#include "ui_affhisto.h"
#include <QDebug>

AffHisto::AffHisto(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AffHisto)
{
    ui->setupUi(this);
}

AffHisto::~AffHisto()
{
    delete ui;
}

void AffHisto::MajHisto(){
    GestionInteraction gi;
    ui->list_histo->clear();
    for(auto i : gi.GetInstance()->getListeHistorique()){
        qDebug()<< QString::fromStdString(i.getAction());
        QListWidgetItem* li = new QListWidgetItem(QString::fromStdString(i.getAction()));
        ui->list_histo->addItem(li);
    }
    GestionnaireContact gc;
    for(auto c : gc.GetInstance()->getListeHistorique()){
        qDebug()<< QString::fromStdString(c.getAction());
        QListWidgetItem* li = new QListWidgetItem(QString::fromStdString(c.getAction()));
        ui->list_histo->addItem(li);
    }
}

void AffHisto::on_pushButton_clicked()
{
    this->close();
}

