#ifndef COMBAT_H
#define COMBAT_H

#include "Ennemi.h"
#include "Personnage.h"
#include "affichageText.h"

#include <vector>

class Combat{
    private:
        int nbTour;
        vector<Ennemi> tabEnnemi;
        Personnage * joueur;

    public:
        Combat(vector<Ennemi> e, Personnage * j);
        ~Combat();

        bool tour();
};
#endif
