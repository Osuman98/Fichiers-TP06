/// Classe de la gestion des jeux.
/// \author Simon Gauvin
/// \date 14 septembre 2020

#ifndef GESTIONNAIREJEUX_H
#define GESTIONNAIREJEUX_H

#include <ostream>
#include <string>
#include <vector>

#include "Jeu.h"

class GestionnaireJeux
{
public:
    GestionnaireJeux() = default;

    GestionnaireJeux& operator+=(const Jeu& jeu);
    GestionnaireJeux& operator-=(const std::string& nom);
    GestionnaireJeux& operator-=(const Jeu& jeu);

    const Jeu* chercherJeu(const std::string& nomJeu) const;
    bool chargerDepuisFichier(const std::string& nomFichier);

    friend std::ostream& operator<<(std::ostream& stream, const GestionnaireJeux& gestionnaireJeux);

    std::size_t getNbJeux() const;
    std::vector<Jeu>& getJeux();

    static constexpr std::size_t nbJeuxMax = 8;

private:
    bool lireLigneJeu(const std::string& ligne);

    std::vector<Jeu> jeux_;
};

#endif // GESTIONNAIREJEUX_H
