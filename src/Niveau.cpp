#include "Niveau.h"

Niveau::Niveau(int nbNiveau, int diff) : numNiveau(nbNiveau), difficulte(diff), joueur("Joueur") {}

Niveau::~Niveau() {}

bool Niveau::nouveauCombat() {
    bool joueurMort = joueur.isDead();
    
    bool tousVaincus = true;

    // Vérifie si un ennemi est encore en vie
    for (size_t i = 0; i < tabEnnemi.size(); ++i) {
        if (!tabEnnemi[i].isDead()) {
            // S'il y a un ennemi encore en vie, retourne vrai
            return true;
        }
    }

    return (tousVaincus || joueurMort);
}

bool Niveau::Combat() {
    // Logique pour gérer le combat
    return true; // Placeholder
}
