#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <iostream>
#include <string>
#include <vector>
#include "Competence.h"
#include "Inventaire.h"

using namespace std;

class Personnage {
private:
    string nom;
    int pv;
    int force;
    int resistance;
    vector<Competence> tabCompetence;
    Inventaire inv;

public:
    Personnage(const string &nom);

    string getNom() const;
    int getPV() const;
    int getForce() const;
    int getResistance() const;

    void updatePV(int update);
    void updateForce(int update);
    void updateResistance(int update);

    bool isDead() const;
};

#endif // PERSONNAGE_H
