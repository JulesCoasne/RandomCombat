#include "Ennemi.h"
#include "../lib/json.hpp"
#include <fstream>
#include <fcntl.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
using json = nlohmann::json;

Ennemi::Ennemi(nomEnnemi e) {
    string path = "../randomcombat/data/ennemi/squelette.json";
    cout << path << endl;

    fstream f;
     // Ouvrir le fichier JSON
    f.open(path, ios::in);
    if (!f) {
        cerr << "Erreur : impossible d'ouvrir le fichier " << jsonEnnemi[e] << endl;
    }

    // Analyser le fichier JSON
    json jsonData;
    f >> jsonData;
    f.close();

    // Récupérer les données du JSON
    nom = jsonData["nom"];
    pv = jsonData["pv"];
    force = jsonData["force"];
    resistance = jsonData["resistance"];

    tabCompetence.push_back(Competence(Competence::COUP_DE_POING));
}

Ennemi::Ennemi(string nom) : nom(nom), pv(0), force(0), resistance(0) {}

Ennemi::Ennemi(string nom, int p, int f, int r) : nom(nom), pv(p), force(f), resistance(r) {}

Ennemi::Ennemi(string nom, int diff) : nom(nom) {
    pv = diff * 10;
    force = diff * 5;
    resistance = diff * 3;
}

string Ennemi::getNom() const {
    return nom;
}

int Ennemi::getPV() const {
    return pv;
}

int Ennemi::getForce() const {
    return force;
}

int Ennemi::getResistance() const {
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
