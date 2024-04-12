#ifndef NIVEAU_H
#define NIVEAU_H

#include "Ennemi.h"
#include "Personnage.h"
#include "Combat.h"

#include <iostream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

class Niveau {
private:
    int numNiveau;
    int nbEnnemi;
    vector<Ennemi> tabEnnemi;
    vector<Ennemi::nomEnnemi> ennemiFacile = {Ennemi::SQUELETTE, Ennemi::CHAUVE_SOURIS, Ennemi::PIRATE};

public:
    Combat * combat;

    Niveau();
    ~Niveau();

    void generateTabEnnemi();
    void checkEnnemiStatus(Affichage& affichage);
    void nouveauCombat(Affichage& affichage, Personnage &joueur);
    void levelCleared();

    int getNumNiveau();

    vector<Ennemi> * getTabEnnemi();
    Ennemi getEnnemi(int i);
    int getNbEnnemi();
};

#endif // NIVEAU_H
