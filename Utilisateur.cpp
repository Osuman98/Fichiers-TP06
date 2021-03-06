#include "Utilisateur.h"

/// Constructeur de la classe Utilisateur
Utilisateur::Utilisateur(const std::string& nom, unsigned int age, unsigned int fonds)
    : nom_(nom)
    , age_(age)
    , fonds_(fonds)
{
}

std::ostream& operator<<(std::ostream& stream, const Utilisateur& utilisateur)
{
    stream << utilisateur.nom_ << " (" << utilisateur.age_ << " ans). Fonds: " << utilisateur.fonds_ << "$. ";
    stream << "Jeux: [";
    for (std::size_t i = 0; i < utilisateur.librairieJeux_.size(); ++i)
    {
        stream << utilisateur.librairieJeux_[i]->getNom();
        if (i != utilisateur.librairieJeux_.size() - 1)
        {
            stream << ',';
        }
    }

    return stream << ']';
}

Utilisateur& Utilisateur::operator+=(unsigned int fonds)
{
    fonds_ += fonds;

    return *this;
}


/// Retourne le nombre de jeux à l'utilisateur.
/// \return Le nombre de jeux à l'utilisateur.
std::size_t Utilisateur::getNbJeux() const
{
    return librairieJeux_.size();
}

/// Retourne le nom de l'utilisateur.
/// \return Le nom de l'utilisateur.
const std::string& Utilisateur::getNom() const
{
    return nom_;
}

/// Retourne l'age de l'utilisateur.
/// \return L'age de l'utilisateur.
unsigned int Utilisateur::getAge() const
{
    return age_;
}

/// Retourne les fonds de l'utilsateur.
/// \return Les fonds de l'utilsateur.
unsigned int Utilisateur::getFonds() const
{
    return fonds_;
}


void Utilisateur::acheterJeu(const Jeu* jeu)
{
    if (jeu)
    {
        for (std::size_t i = 0; i < librairieJeux_.size(); ++i) {
            if (librairieJeux_[i] == jeu)
            {
                throw (JEU_DEJA_ACHETER);
                break;
            }

            // Sera lance si le jeu n'est pas trouve TODO Laurent
            else if (i == librairieJeux_.size()-1 && fonds_ >= jeu->getPrix())
            {
                librairieJeux_.push_back(jeu);
                fonds_ -= jeu->getPrix();
                emit fondsModifier(fonds_);
            }

            else if (i == librairieJeux_.size()-1 && fonds_ < jeu->getPrix())
            {
                throw (FOND_INSUFFISANTS);
            }
        }
    }
}

void Utilisateur::vendreJeu(const Jeu* jeu)
{
    if (jeu)
    {
        for (std::size_t i = 0; i < librairieJeux_.size(); ++i)
        {
            if (librairieJeux_[i] == jeu)
            {
                librairieJeux_[i] = librairieJeux_[librairieJeux_.size() - 1];
                librairieJeux_.pop_back();
                fonds_ += jeu->getPrix() / 2;
                emit fondsModifier(fonds_);
                break;
            }

            else if (i == librairieJeux_.size()-1)
            {
                throw (JEU_PAS_DANS_LIBRAIRIE);
            }
        }
    }
}

std::vector<const Jeu*>& Utilisateur::getJeux() {
    return librairieJeux_;
}
