#include "Ennemi.h"
#include "../lib/json.hpp"
#include <fstream>
#include <fcntl.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
using json = nlohmann::json;

const string filePath = "data/ennemi/";
const vector<string> pathEnnemi = {"squelette", "bat", "pirate"};

Ennemi::Ennemi(nomEnnemi e) {
    string path = filePath + pathEnnemi[e] + ".json";
    
    fstream f;
     // Ouvrir le fichier JSON
    f.open(path, ios::in);
    if (!f) {
        cerr << "Erreur : impossible d'ouvrir le fichier " << pathEnnemi[e] << endl;
    }

    // Analyser le fichier JSON
    json jsonData;
    f >> jsonData;
    f.close();

    // Récupérer les données du JSON
    sprite = "data/sprite/" + pathEnnemi[e] + ".png";
    nom = jsonData["nom"];
    pv = jsonData["pv"];
    force = jsonData["force"];
    resistance = jsonData["resistance"];

    tabCompetence.push_back(Competence(Competence::COUP_DE_POING));
}

Ennemi::Ennemi(string nom, int p, int f, int r) : nom(nom), pv(p), force(f), resistance(r) {}

Ennemi::Ennemi(string nom, int diff) : nom(nom) {
    pv = diff * 10;
    force = diff * 5;
    resistance = diff * 3;
}

string Ennemi::getSprite() {
    return sprite;
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

int Ennemi::prendDegat(int degat){
    degat = degat - resistance;

    if(degat < 0) degat = 0;

    pv -= degat;

    if(pv < 0) pv = 0;
    
    return degat;
}

void Ennemi::updatePV(int update) {
    pv += update;
    if (pv < 0) pv = 0;
}

bool Ennemi::isDead() const {
    return pv <= 0;
}
