#include "Partie.h"

Partie::Partie(int diff) : difficulte(diff), niveau(nullptr), joueur("Joueur") {}

Partie::~Partie() {
    delete niveau;
}

bool Partie::nouveauNiveau(int diff) {
    // Vérification pour libérer la mémoire si un niveau précédent existe
    if (niveau != nullptr) {
        delete niveau;
    }
    // Logique pour créer un nouveau niveau
    // Vous pouvez initialiser un nouveau niveau avec la difficulté donnée
    // et mettre à jour le niveau actuel de la partie
    niveau = new Niveau(diff);
    // Le niveau est créé avec succès, donc retourne vrai
    return true;
}
