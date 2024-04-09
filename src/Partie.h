#ifndef PARTIE_H
#define PARTIE_H

#include "Niveau.h"
#include "Personnage.h"
#include "Affichage.h"

class Partie {
private:
    int difficulte;

public:
    Personnage joueur;
    Niveau * niveau;

    Partie();
    ~Partie();

    void nouvellePartie(Affichage * affichage);
    int choixClasse();
};

#endif // PARTIE_H
