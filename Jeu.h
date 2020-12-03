/// Classe qui represente un jeu.
/// \author Simon Gauvin
/// \date 14 septembre 2020

#ifndef JEU_H
#define JEU_H

#include <ostream>
#include <string>

class Jeu
{
public:
    Jeu();
    Jeu(std::string nom, unsigned int prix);

    friend std::ostream& operator<<(std::ostream &stream, const Jeu& jeu);

    bool operator<(const Jeu& jeu) const;
    bool operator>(const Jeu& jeu) const;
    bool operator==(const Jeu& jeu) const;
    bool operator==(const std::string& nom) const;
    friend bool operator==(const std::string& nom, const Jeu& jeu);

    const std::string& getNom() const;
    unsigned int getPrix() const;

private:
    std::string nom_;
    unsigned int prix_;
};

#endif // JEU_H
