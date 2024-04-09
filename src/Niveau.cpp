#include "Niveau.h"

Niveau::Niveau(){
    tabEnnemi.push_back(Ennemi(Ennemi::SQUELETTE));
}

Niveau::~Niveau() {
    // Nettoyage des ressources
}

bool Niveau::nouveauCombat(){
    Combat combat = Combat(tabEnnemi, &joueur);

    return combat.tour();
}
