#ifndef PARTIE_H
#define PARTIE_H

#include "Niveau.h"
#include "Personnage.h"

class Partie {
private:
    int difficulte;
    Niveau* niveau;
    Personnage joueur;

public:
    Partie(int diff);
    ~Partie();

    bool nouveauNiveau(int diff);
    const Personnage& getPersonnage() const;
};

#endif // PARTIE_H
