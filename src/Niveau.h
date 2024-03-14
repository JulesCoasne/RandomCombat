#ifndef NIVEAU_H
#define NIVEAU_H

#include "Ennemi.h"
#include "Personnage.h"

class Niveau {
private:
    int numNiveau;
    int difficulte;
    Personnage joueur;
    std::vector<Ennemi> tabEnnemi;

public:
    Niveau(int diff);
    ~Niveau();

    bool nouveauCombat();
    bool Combat();
};

#endif // NIVEAU_H
