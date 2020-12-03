#include "mainwindow.h"
#include <QDir>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GestionnaireJeux gestionnaire;
    gestionnaire.chargerDepuisFichier("C:\\Users\\jeffl\\OneDrive\\Bureau\\TP6\\jeux.txt"); //TODO --- INSERER VOTRE CHEMIN ABSOLU VERS jeux.txt
    Utilisateur utilisateur("nom", 20, 1000);
    MainWindow w(&gestionnaire, &utilisateur);
    w.show();
    return a.exec();
}
