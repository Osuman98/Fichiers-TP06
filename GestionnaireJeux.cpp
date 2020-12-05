#include "GestionnaireJeux.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

GestionnaireJeux& GestionnaireJeux::operator+=(const Jeu& jeu)
{
    jeux_.push_back(jeu);

    return *this;
}

GestionnaireJeux& GestionnaireJeux::operator-=(const std::string& nom)
{
    for (std::size_t i = 0; i < jeux_.size(); ++i)
    {
        if (jeux_[i] == nom)
        {
            jeux_[i] = jeux_[jeux_.size() - 1];
            jeux_.pop_back();
            break;
        }
    }
    
    return *this;
}

GestionnaireJeux& GestionnaireJeux::operator-=(const Jeu& jeu)
{
    for (std::size_t i = 0; i < jeux_.size(); ++i)
    {
        if (jeux_[i] == jeu)
        {
            jeux_[i] = jeux_[jeux_.size() - 1];
            jeux_.pop_back();
            break;
        }
    }

    return *this;
}

/// Cherche un jeu par son nom complet et qui retourne un pointeur vers le jeu
/// correspondant. \param  nomJeu  Le nom du jeu à chercher. \return         Un pointeur vers le
/// premier jeu comportant le nom spécifié. Si le jeu n'est pas trouvé, cette fonction retourne un
/// pointeur nul.
const Jeu* GestionnaireJeux::chercherJeu(const std::string& nomJeu) const
{
    for (std::size_t i = 0; i < jeux_.size(); ++i)
    {
        if (jeux_[i] == nomJeu)
        {
            return &jeux_[i];
        }
    }

    return nullptr;
}

/// Charge les jeux depuis un fichier.
/// \param nomFichier   Le nom du fichier à charger.
/// \return             Un bool représentant si le chargement a été effectué avec succès.
bool GestionnaireJeux::chargerDepuisFichier(const std::string& nomFichier)
{
    std::ifstream fichier(nomFichier);
    if (fichier)
    {
        jeux_.clear();
        std::string ligne;
        while (std::getline(fichier, ligne))
        {
            if (lireLigneJeu(ligne) == false)
            {
                return false;
            }
        }
        return true;
    }
    std::cerr << "Le fichier " << nomFichier
              << " n'existe pas. Assurez vous de le mettre au bon endroit.\n";

    return false;
}

std::ostream& operator<<(std::ostream& stream, const GestionnaireJeux& gestionnaireJeux)
{
    for (const Jeu& jeu : gestionnaireJeux.jeux_)
    {
        stream << jeu << std::endl;
    }
 
    return stream;
}

/// Retourne le nombre de jeux
/// \return Le nombre de jeux
std::size_t GestionnaireJeux::getNbJeux() const
{
    return jeux_.size();
}

std::vector<Jeu>& GestionnaireJeux::getJeux() {
    return jeux_;
}

/// Ajoute un jeu avec un string venant d'un fichiers.
/// \param ligne    La ligne qui comporte les différentes informations du jeu.
/// \return         Un bool qui représente si la ligne a été lue correctement.
bool GestionnaireJeux::lireLigneJeu(const std::string& ligne)
{
    std::istringstream stream(ligne);
    std::string nomJeu;
    unsigned int prixJeu;

    //if (stream >> std::quoted(nomJeu) >> prixJeu)
    if (stream >> std::quoted(nomJeu) >> prixJeu)
    {
        *this += Jeu(nomJeu, prixJeu);

        return true;
    }

    return false;
}
