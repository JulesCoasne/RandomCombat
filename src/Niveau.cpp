#include "Niveau.h"

Niveau::Niveau(int diff) : numNiveau(diff), joueur("Joueur") {
    // Initialisation de votre niveau
}

Niveau::~Niveau() {
    // Nettoyage des ressources
}

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

    // S'il n'y a plus d'ennemi en vie ou si le joueur est mort, retourne faux
    return (tousVaincus || joueurMort);
}

bool Niveau::Combat() {
    // Logique pour gérer le combat
    return true; // Placeholder
}
