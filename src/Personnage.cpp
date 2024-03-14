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
    
    // Si la compétence est offensive, réduire les points de vie de l'adversaire
    // Si la compétence est de soin, augmenter les points de vie du personnage
    if (comp.getDegat() > 0) {
        // La compétence est offensive
        updatePV(-comp.getDegat()); // Réduction des points de vie du personnage
    } else if (comp.getSoin() > 0) {
        // La compétence est de soin
        updatePV(comp.getSoin()); // Augmentation des points de vie du personnage
    }

    
}
