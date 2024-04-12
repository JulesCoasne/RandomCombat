#ifndef ENNEMI_H
#define ENNEMI_H

#include <iostream>
#include <string>
#include <vector>
#include "Competence.h"
#include "Personnage.h"

using namespace std;

class Ennemi {
private:
    string sprite;
    string nom;
    int pv;
    int force;
    int resistance;
    vector<Competence> tabCompetence;

public:
    enum nomEnnemi {
        SQUELETTE,
        CHAUVE_SOURIS,
        PIRATE
    };

    Ennemi() = delete;
    Ennemi(nomEnnemi e);
    Ennemi(string nom, int p, int f, int r);
    Ennemi(string nom, int diff);

    string getSprite();
    string getNom() const; // Déclarez-les comme constantes ici
    int getPV() const;      // Ajoutez const après la liste des paramètres
    int getForce() const;
    int getResistance() const;

    int prendDegat(int degat);
    void updatePV(int update);

    bool isDead() const;
};
#endif
