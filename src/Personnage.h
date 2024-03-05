#ifndef PERSONNAGE_H
#define _PERSONNAGE_H
#endif
#include <iostream>
#include <string>

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
    void useCompetence(const Competence& comp);
    bool isDead() const;
};


