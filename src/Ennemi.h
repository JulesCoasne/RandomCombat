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
    string nom;
    int pv;
    int force;
    int resistance;
    vector<Competence> tabCompetence;

    const string filePath = "data/ennemi/";
    const vector<string> jsonEnnemi = {"squelette.json"};

public:
    enum nomEnnemi {
            SQUELETTE
    };

    Ennemi(nomEnnemi e);
    Ennemi(string nom);
    Ennemi(string nom, int p, int f, int r);
    Ennemi(string nom, int diff);

    string getNom() const; // Déclarez-les comme constantes ici
    int getPV() const;      // Ajoutez const après la liste des paramètres
    int getForce() const;
    int getResistance() const;

    void updatePV(int update);

    bool isDead() const;
};
#endif
