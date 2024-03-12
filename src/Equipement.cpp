#include "Equipement.h"
#include <cstdlib> 
#include <iostream>


using namespace std;


Equipement::Equipement(const int &pvE, const int &forceE, const int &resistenceE) {
    // Initialisation des membres de la classe
}

Equipement::~Equipement() {
    // Nettoyage des ressources si nécessaire
}


Equipement Equipement::genereEquipement(int difficulty) {
    int pv = rand() % (difficulty * 5) + 1; 
    int force = rand() % (difficulty * 3) + 1;
    int resistence = rand() % (difficulty * 3) + 1;

    return Equipement(pv, force, resistence);
}

int Equipement::getPV() const {
    return pv;
}

int Equipement::getForce() const {
    return force;
}

int Equipement::getResistence() const {
    return resistence;
}
