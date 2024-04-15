#ifndef COMBAT_H
#define COMBAT_H

#include "Affichage.h"
#include "Ennemi.h"
#include "Consommable.h"

#include <stdlib.h>
#include <vector>
#include <string>
#include <time.h>

using namespace std;

class Combat{
    private:
        int nbTour;
        vector<Ennemi> &tabEnnemi;
        Personnage &joueur;
        bool isUsingConsommable;
        Consommable usedConsommable;
        
    public:
        Combat(vector<Ennemi> &e, Personnage &j);
        ~Combat();

        int deroulerCombat();
        string attaque(int choixCompetence, int choixEnnemi);
        string tourEnnemi(Affichage &affichage);
        string consommable(int choixConsommable);
        int consultEnnemi();
        int abandonner();
};
#endif
