#include "Partie.h"

Partie::Partie(int diff) : difficulte(diff){}

Partie::~Partie() {
    delete niveau;
}

bool Partie::nouveauNiveau() {
    niveau = new Niveau(difficulte);
    // Le niveau est créé avec succès, donc retourne vrai
    return true;
}