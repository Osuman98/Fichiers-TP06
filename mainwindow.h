#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QPushButton>
#include <QVariant>
#include <QPushButton>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QException>

#include "DebogageMemoire.h"
#include "GestionnaireJeux.h"
#include "Utilisateur.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(GestionnaireJeux* gestionnaire, Utilisateur* utilisateur, QWidget *parent = nullptr);
    ~MainWindow();
    void setup();

public slots :
    void selectionnerJeuBoutique(QListWidgetItem*);
    void selectionnerJeuLibrairie(QListWidgetItem*);
    void chargerFonds(unsigned int nouveauFonds);
    void acheterJeu();
    void vendreJeu();

private:
    void etablirConnections();
    void setUI();
    void chargerJeuxBoutique();
    void chargerJeuxLibrairie();
    void afficherMessage(QString msg);

    GestionnaireJeux* gestionnaire_;
    Utilisateur* utilisateur_;

    QListWidget* boutique_;
    QListWidget* librairieUtilisateur_;

    QLineEdit* editeurNomJeu_;
    QLineEdit* editeurPrixJeu_;
    QLineEdit* editeurFonds_;

    QPushButton* boutonAcheterJeu_;
    QPushButton* boutonVendreJeu_;
};
#endif // MAINWINDOW_H
