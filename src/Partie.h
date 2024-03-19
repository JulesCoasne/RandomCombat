#ifndef PARTIE_H
#define PARTIE_H

#include "Niveau.h"
#include "Personnage.h"

class Partie {
private:
    int difficulte;

public:
    Personnage joueur;
    Niveau * niveau;

    Partie();
    Partie(int diff);
    ~Partie();

    bool nouveauNiveau();
};

#endif // PARTIE_H
