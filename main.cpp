#include "mainwindow.h"
#include <QDir>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GestionnaireJeux gestionnaire;
    //gestionnaire.chargerDepuisFichier("C:\\Users\\jeffl\\OneDrive\\Bureau\\TP6\\jeux.txt"); //TODO --- INSERER VOTRE CHEMIN ABSOLU VERS jeux.txt
    gestionnaire.chargerDepuisFichier("/Users/laurentdebane/Dropbox/POLY_Mtl/A2020/INF1010/TP/Fichiers_TP06/jeu.txt");
    Utilisateur utilisateur("nom", 20, 1000);
    MainWindow w(&gestionnaire, &utilisateur);
    w.show();
    return a.exec();
}
