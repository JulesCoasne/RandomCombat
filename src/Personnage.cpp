#include "Personnage.h"

Personnage::Personnage(const std::string &nom) : nom(nom), pv(100), force(10), resistance(10) {}

std::string Personnage::getNom() const {
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
    if (pv < 0) {
        pv = 0;
    }
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

void Personnage::useCompetence(const Competence &comp) {
    // Implémentation de l'utilisation de la compétence
}
