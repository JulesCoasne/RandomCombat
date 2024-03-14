#include "Jeu.h"

Jeu::Jeu() : p(1) {}

Competence Jeu::getCompetence(int index) {
    return tabCompetence[index];
}

Consommable Jeu::getConsommable(int index) {
    return tabConsommable[index];
}

Equipement Jeu::getEquipement(int index) {
    return tabEquipement[index];
}

void Jeu::addEquipement(const Equipement& equip) {
    tabEquipement.push_back(equip);
}

void Jeu::addConsommable(const Consommable& cons) {
    tabConsommable.push_back(cons);
}

int Jeu::nouvellePartie() {
    return p.nouveauNiveau(difficulte);
}

void Jeu::useConsommable(size_t index) {
    if (index >= tabConsommable.size()) {
        // Gérer le cas où l'index est en dehors des limites du tableau
        return;
    }

    // Utiliser le consommable à l'index spécifié
    tabConsommable[index].getDure();
    tabConsommable[index].getPV();
    tabConsommable[index].getForce();
    tabConsommable[index].getResistance();

    // Supprimer le consommable utilisé
    tabConsommable.erase(tabConsommable.begin() + index);
}
