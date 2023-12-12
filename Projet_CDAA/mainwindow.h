#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "addcontact.h"
#include "modificationcontact.h"
#include "addinteraction.h"
#include <QDebug>
#include "gestionnairecontact.h"
#include "affichageinteraction.h"
#include "affhisto.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void majListContact();
    void majListInteraction();
    void on_AjoutContact_BTN_clicked();

    void on_ModifContact_BTN_clicked();

    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

    void on_actionHistorique_triggered();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    AddContact *ad;
    ModificationContact *mc;
    AddInteraction *ai;
    AffichageInteraction *Affi;
};
#endif // MAINWINDOW_H
