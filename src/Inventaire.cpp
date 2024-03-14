#include "Inventaire.h"

Inventaire::Inventaire() {
    // Initialisation des membres de la classe
}

Inventaire::~Inventaire() {
    // Nettoyage des ressources si nécessaire
}

void Inventaire::useConsommable(int index) {
    // Vérification si l'index est valide
    if (index < 0 || index >= tabConsommable.size()) {
        // Index de consommable invalide, sortie de la fonction
        return;
    }

    // Obtention des attributs du consommable
    int consoDure =  tabConsommable[index].getDure();
    int consoPV = tabConsommable[index].getPV();
    int consoForce = tabConsommable[index].getForce();
    int consoResistance = tabConsommable[index].getResistance();

   
}

void Inventaire::addEquipement(const Equipement& equip) {
    tabEquipement.push_back(equip);
}

void Inventaire::addConsommable(const Consommable& conso) {
    tabConsommable.push_back(conso);
}
