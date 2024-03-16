#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <string>
#include "Competence.h"

class Personnage {
private:
    std::string nom;
    int pv;
    int force;
    int resistance;

public:
    Personnage(const std::string &nom);

    std::string getNom() const;
    int getPV() const;
    int getForce() const;
    int getResistance() const;

    void updatePV(int update);
    void updateForce(int update);
    void updateResistance(int update);

    bool isDead() const;
    void useCompetence(const Competence &comp);
    Personnage getPersonnage() const;

};

#endif // PERSONNAGE_H
