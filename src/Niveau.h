#ifndef NIVEAU_H
#define NIVEAU_H

#include "Ennemi.h"
#include "Personnage.h"
#include "Combat.h"
#include <vector> // N'oubliez pas d'inclure la bibliothèque vector

class Niveau {
private:
    int numNiveau;
    Personnage joueur;
    std::vector<Ennemi> tabEnnemi; // Vector pour stocker les ennemis

public:
    Niveau(int diff);
    ~Niveau();

    bool nouveauCombat();
};

#endif // NIVEAU_H
