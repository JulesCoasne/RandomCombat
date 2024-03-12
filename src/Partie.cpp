#include "Partie.h"

Partie::Partie(int diff) : difficulte(diff) {}

Partie::~Partie() {}

bool Partie::estTerminee() {
    // Ici, vous pouvez ajouter la logique pour déterminer si la partie est terminée
    return false;  // Retourne faux pour l'instant
}

void Partie::afficherEtat() {
    // Ici, vous pouvez ajouter la logique pour afficher l'état actuel du jeu
}

int Partie::demanderChoix() {
    // Ici, vous pouvez ajouter la logique pour demander à l'utilisateur de faire un choix
    return 0;  // Retourne 0 pour l'instant
}

void Partie::executerChoix(int choix) {
    // Ici, vous pouvez ajouter la logique pour exécuter le choix de l'utilisateur
}
