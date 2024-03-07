#include "Personnage.h"
#include <iostream>


using namespace std;


Personnage::Personnage(const string &nom) : nom(nom), pv(100), force(10), resistance(10) {
    tabCompetence.push_back(Competence::COUP_DE_POING);
}


string Personnage::getNom() const {
    return nom;
}

int Personnage::getPV() const {
    return pv;
}

int Personnage::getForce() const {
    return force;
}

int Personnage::getResistance() const {
    return resistance;
}

void Personnage::updatePV(int update) {
    pv += update;
}

void Personnage::updateForce(int update) {
    force += update;
}

void Personnage::updateResistance(int update) {
    resistance += update;
}

bool Personnage::isDead() const {
    return pv <= 0;
}
