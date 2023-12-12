#include "addinteraction.h"
#include "ui_addinteraction.h"

AddInteraction::AddInteraction(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddInteraction)
{
    ui->setupUi(this);
}

AddInteraction::~AddInteraction()
{
    delete ui;
}

void AddInteraction::AjoutInteraction(){
    QString titre = ui->titre_edit->text();
    QTextDocument * qdoc = ui->interaction_txt->document();
    Interaction *i = new Interaction(titre.toStdString());
    QTextCursor c(qdoc);
    QTextDocument::FindFlag fcs = (QTextDocument::FindFlag) 0;
    while (!c.isNull()){
        c = qdoc->find("@todo", c.position(), fcs);
        if (!c.isNull()){
            QString todo = "";
            QString date = "";
            QString lignetodo = c.block().text();
            QStringList liste = lignetodo.split("@date");
            //qDebug() << "total : " <<c.block().text();
            if(liste.size() == 2){
                //qDebug() << "taille = 2";
                //qDebug() << "partie todo : " << liste.at(0).split("@todo").at(1);
                //qDebug() << "partie date : " << liste.at(1);
                todo = liste.at(0).split("@todo").at(1);
                date = liste.at(1);
            }else if(liste.size() == 1){
                //qDebug() << "taille = 1";
                //qDebug() << "partie todo : " << liste.at(0).split("@todo").at(1);
                todo = liste.at(0).split("@todo").at(1);
            }
            Tache *t = new Tache("");
            t->setToDo(todo.toStdString());
            QStringList datel = date.split("/");
            Date *d = new Date();
            if(datel.size() != 3){
                qDebug() << "Format de la date incorrecte ( ex : dd/mm/yyyy ).Valeur par défault ajouté.";
                d->jour = 00;
                d->mois = 00;
                d->annee = 0000;
            }else{
                d->jour = datel.at(0).toInt();
                d->mois = datel.at(1).toInt();
                d->annee = datel.at(2).toInt();
            }
            t->setDateAction(*d);
            i->addTache(t);
        }
    }
    //qDebug() << "fin";

    //this->contact->addInteraction(i);

    GestionInteraction *gi;
    //qDebug() << "fin2";
    gi->GetInstance()->addInteraction(i);
    std::string test = this->contact->getNom();
    //qDebug() << "fin2.5 "+QString::fromStdString(test);
    gi->GetInstance()->addLienContactInteraction(i,this->contact);
    //qDebug() << "fin3";
    emit AjoutInteractionSign();
}


void AddInteraction::InitInteraction(Contact * c){
    //qDebug() << "hello " <<QString::fromStdString(c->getNom());
    this->contact = new Contact(c);
    ui->titre_edit->clear();
    ui->interaction_txt->clear();
}

void AddInteraction::on_valider_btn_clicked()
{
    this->AjoutInteraction();
    this->close();
}


void AddInteraction::on_annuler_btn_clicked()
{
    this->close();
}

