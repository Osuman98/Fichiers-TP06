#include "Jeu.h"
#include <limits>

/// Constructeur par défaut de la classe Jeu.
Jeu::Jeu()
    : nom_("Inconnu")
    , prix_(std::numeric_limits<unsigned int>::max())
{
}

/// Constructeur par paramètres de la classe Jeu.
/// \param nom  Le nom du jeu.
/// \param prix Le prix du jeu en sous.
Jeu::Jeu(std::string nom, unsigned int prix)
    : nom_(nom)
    , prix_(prix)
{
}

std::ostream& operator<<(std::ostream& stream, const Jeu& jeu)
{
    return stream << jeu.nom_ << ": " << jeu.prix_ / 100.0 << "$";
}

bool Jeu::operator<(const Jeu& jeu) const
{
    return prix_ < jeu.prix_;
}

bool Jeu::operator>(const Jeu& jeu) const
{
    return prix_ > jeu.prix_;
}

bool Jeu::operator==(const Jeu& jeu) const
{
    return prix_ == jeu.prix_ && nom_ == jeu.nom_;
}

bool Jeu::operator==(const std::string& nom) const
{
    return nom_ == nom;
}

bool operator==(const std::string& nom, const Jeu& jeu)
{
    return nom == jeu.nom_;
}

/// Retourne le nom du jeu.
/// \return Le nom du jeu.
const std::string& Jeu::getNom() const
{
    return nom_;
}

/// Retourne le prix du jeu.
/// \return Le prix du jeu.
unsigned int Jeu::getPrix() const
{
    return prix_;
}
