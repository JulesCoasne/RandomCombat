#ifndef ENNEMI_H
#define _ENNEMI_H
#endif

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

    const enum nomEnnemi{
        SQUELETTE
    };

    const string filePath = "data/ennemi/";
    const vector<string> jsonEnnemi = {"squelette.json"};

public:
    Ennemi(nomEnnemi e);
    Ennemi(string nom);
    Ennemi(string nom, int p, int f, int r);
    Ennemi(string nom, int diff);

    string getNom();
    int getPV();
    int getForce();
    int getResistance();
    
    void updatePV();

    bool isDead();
};


