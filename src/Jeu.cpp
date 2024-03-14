#include "Jeu.h"

Jeu::Jeu() : p(1) {}

Competence Jeu::getCompetence(int index) {
    return tab_competence[index];
}

Consommable Jeu::getConsommable(int index) {
    return tab_consommable[index];
}

Equipement Jeu::getEquipement(int index) {
    return tab_equipement[index];
}

void Jeu::addEquipement(const Equipement& equip) {
    tab_equipement.push_back(equip);
}

void Jeu::addConsommable(const Consommable& cons) {
    tab_consommable.push_back(cons);
}

int Jeu::nouvellePartie() {
    // Logique pour initialiser une nouvelle partie
    difficulte = 1; // Exemple de déclaration de la difficulté
    return p.nouveauNiveau(difficulte);
}

void Jeu::useConsommable(int index) {
    // Logique pour utiliser le consommable
}
