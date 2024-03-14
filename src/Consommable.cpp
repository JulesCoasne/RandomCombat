#include "Consommable.h"

Consommable::Consommable() : nom(""), dure(0), pv(0), force(0), resistance(0) {}

Consommable::Consommable(const std::string& nom, int dure, int pv, int force, int resistance)
    : nom(nom), dure(dure), pv(pv), force(force), resistance(resistance) {}

std::string Consommable::getNom() const {
    return nom;
}

int Consommable::getDure() const {
    return dure;
}

int Consommable::getPV() const {
    return pv;
}

int Consommable::getForce() const {
    return force;
}

int Consommable::getResistance() const {
    return resistance;
}
