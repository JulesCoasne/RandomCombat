#include "Personnage.h"

Personnage::Personnage() : nom("") {}

Personnage::Personnage(const std::string &nom) : nom(nom), pv(100), force(10), resistance(10) {
    addCompetence(Competence::COUP_DE_POING);
}

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

void Personnage::updateNom(string update){
    nom = update;
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

Competence Personnage::getCompetence(int index) const{
    return tabCompetence[index];
}

vector<Competence> Personnage::getTabCompetence() const{
    return tabCompetence;
}

void Personnage::addCompetence(Competence::nomCompetence c){
    tabCompetence.push_back(Competence(c));
}

void Personnage::useConsommable(int index) {
    
    while (Consommable:getDure() != 0){
        return Personnage:getForce()+ Consommable:getForce();


    }
    
}