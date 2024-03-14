#include "Ennemi.h"
#include "../lib/json.hpp"
#include <fstream>
#include <vector>
#include <string>

using namespace std;
using json = nlohmann::json;


Ennemi::Ennemi(nomEnnemi e) {
    string path = filePath + jsonEnnemi[e];
    ifstream file(path);

    json Doc = json::parse(file);

    nom = Doc["nom"];
    pv = Doc["pv"];
    force = Doc["force"];
    resistance = Doc["resistance"];

    tabCompetence.push_back(Competence(Competence::COUP_DE_POING));
}

Ennemi::Ennemi(string nom) : nom(nom), pv(0), force(0), resistance(0) {}

Ennemi::Ennemi(string nom, int p, int f, int r) : nom(nom), pv(p), force(f), resistance(r) {}

Ennemi::Ennemi(string nom, int diff) : nom(nom) {
    pv = diff * 10;
    force = diff * 5;
    resistance = diff * 3;
}

string Ennemi::getNom() {
    return nom;
}

int Ennemi::getPV() {
    return pv;
}

int Ennemi::getForce() {
    return force;
}

int Ennemi::getResistance() {
    return resistance;
}

void Ennemi::updatePV(int update) {
    pv += update;
    if (pv < 0) {
        pv = 0;
    }
}

bool Ennemi::isDead() const {
    return pv <= 0;
}
