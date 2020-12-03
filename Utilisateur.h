/// Classe qui represente un Utilisateur.
/// \author Simon Gauvin
/// \date 14 septembre 2020

#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <ostream>
#include <string>
#include <vector>
#include <algorithm>
#include <QObject>

#include "GestionnaireJeux.h"
#include "Jeu.h"
#include "def.h"
#include "ExceptionFondsInsuffisants.h"
#include "ExceptionJeuDejaAcheter.h"
#include "ExceptionJeuPasDansLaLibrairie.h"

class Utilisateur : public QObject
{
public:
    Utilisateur(const std::string& nom, unsigned int age, unsigned int fonds);

    friend std::ostream& operator<<(std::ostream& stream, const Utilisateur& utilisateur);

    Utilisateur& operator+=(unsigned int fonds);

    std::size_t getNbJeux() const;
    const std::string& getNom() const;
    unsigned int getAge() const;
    unsigned int getFonds() const;
    std::vector<const Jeu*>& getJeux();

    void acheterJeu(const Jeu* jeu);
    void vendreJeu(const Jeu* jeu);

    void fondsModifier(unsigned int nouveauFonds);

private:
    std::vector<const Jeu*> librairieJeux_;
    std::string nom_;
    unsigned int age_;
    unsigned int fonds_;
};

#endif // UTILISATEUR_H
