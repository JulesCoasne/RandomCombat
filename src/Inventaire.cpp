#include "Inventaire.h"

void Inventaire::useConsommable(int index) {
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