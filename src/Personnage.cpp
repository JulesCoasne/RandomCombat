#include "Personnage.h"

using namespace std;

Personnage::Personnage() : nom("") {}

Personnage::Personnage(const std::string &nom) : nom(nom), pv(100), force(10), resistance(10), intelligence(10){
    addCompetence(Competence::COUP_DE_POING);
}

Personnage::Personnage(classePersonnage c){
    if(c == GUERRIER){
        cout << "début" << endl;
        nom = "Guerrier";
        pv = 200;
        pvMax = 200;
        force = 20;
        resistance = 20;
        intelligence = 5;
        addCompetence(Competence::COUP_DE_POING);
        addCompetence(Competence::COUP_EPEE);
        addConsommable(Consommable::POTION);
        cout << "fin" << endl;
    }

    if(c == MAGE){
        nom = "Mage";
        pv = 100;
        pvMax = 200;
        force = 10;
        resistance = 5;
        intelligence = 30;
        addCompetence(Competence::BOULE_DE_FEU);
        addCompetence(Competence::ECLAIRE);
        addConsommable(Consommable::POTION);
    }
}

Personnage::~Personnage(){
    nom.clear();
    tabCompetence.clear();
    tabConsommable.clear();
}

std::string Personnage::getNom() const {
    return nom;
}

int Personnage::getPV() const {
    return pv;
}

int Personnage::getPVMax() const {
    return pvMax;
}

int Personnage::getForce() const {
    return force;
}

int Personnage::getIntelligence() const{
    return intelligence;
}

int Personnage::getResistance() const {
    return resistance;
}

void Personnage::updateNom(string update){
    nom = update;
}

void Personnage::updatePV(int update) {
    pv += update;
    if (pv < 0) pv = 0;
    if (pv > pvMax) pv = pvMax;
}

void Personnage::updatePVMax(int update){
    pvMax += update;
}

int Personnage::takeDamage(int degat){
    degat = degat - resistance;

    if(degat < 0) degat = 0;

    pv -= degat;

    if(pv < 0) pv = 0;
    
    return degat;
}

void Personnage::updateForce(int update) {
    force += update;
}

void Personnage::updateIntelligence(int update){
    intelligence += update;
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

Consommable Personnage::getConsommable(int index) const{
    return tabConsommable[index];
}

vector<Consommable> * Personnage::getPtrTabConsommable(){
    return &tabConsommable;
}

vector<Competence> Personnage::getTabCompetence(){
    return tabCompetence;
}

void Personnage::addCompetence(Competence::nomCompetence c){
    tabCompetence.push_back(Competence(c));
}

void Personnage::addConsommable(Consommable::nomConsommable c){
    tabConsommable.push_back(Consommable(c));
}

vector<Consommable> Personnage::getTabConsommable(){
    return tabConsommable;
}