#include "Ennemie.h"


Ennemie::Ennemie(std::string nom) : nom(nom), pv(0), force(0), resistance(0) {}

Ennemie::Ennemie(std::string nom, int p, int f, int r) : nom(nom), pv(p), force(f), resistance(r) {}

Ennemie::Ennemie(std::string nom, int diff) : nom(nom) {
   
    pv = diff * 10;
    force = diff * 5;
    resistance = diff * 3;
}

// Méthodes
void Ennemie::useCompetence(Competence comp) {
    // Utilisation de la compétence par l'ennemi
}
