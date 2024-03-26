#ifndef JEU_H
#define JEU_H

#include "Personnage.h"
#include "Ennemi.h"
#include "Partie.h"
#include "Competence.h"
#include "Consommable.h"
#include "Equipement.h"
#include "SDLJeu.h"
#include <vector>

class Jeu {
private:
    std::vector<Competence> tabCompetence;
    std::vector<Consommable> tabConsommable;
    std::vector<Equipement> tabEquipement;

public:
    Personnage joueur;

    Jeu();
};

#endif // JEU_H
