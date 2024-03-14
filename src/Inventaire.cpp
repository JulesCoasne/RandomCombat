#include "Inventaire.h"

Inventaire::Inventaire() {}

void Inventaire::useConsommable(size_t index) {
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

void Inventaire::addEquipement(const Equipement& equip) {
    tabEquipement.push_back(equip);
}

void Inventaire::addConsommable(const Consommable& conso) {
    tabConsommable.push_back(conso);
}
