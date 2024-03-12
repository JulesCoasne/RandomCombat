#include "Inventaire.h"

Inventaire::Inventaire() {
    // Initialisation des membres de la classe
}

Inventaire::~Inventaire() {
    // Nettoyage des ressources si nécessaire
}

void Inventaire::useConsommable(int index) {
    int consoDure =  tabConsommable[index].getDure();
    int consoPV = tabConsommable[index].getPV();
    int consoForce = tabConsommable[index].getForce();
    int consoResistance = tabConsommable[index].getResistance();

    // Ici, vous pouvez ajouter la logique pour utiliser le consommable
}

void Inventaire::addEquipement(const Equipement& equip) {
    tabEquipement.push_back(equip);
}

void Inventaire::addConsommable(const Consommable& conso) {
    tabConsommable.push_back(conso);
}  // Ajout de l'accolade fermante manquante
