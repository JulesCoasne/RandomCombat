#include "Consommable.h"
#include "../lib/json.hpp"
#include <iostream>
#include <fstream>

using json = nlohmann::json;
using namespace std;

Consommable::Consommable() {
    resistance = 0;
}

// Destructeur
Consommable::~Consommable() {
    // Code du destructeur
}

void Consommable::genereConsommable(vector<Consommable> *v) {
    vector<string> FileName = {"potion.json"};
    string FilePath = "data/consommable";

    for(int i = 0; i < FileName.size(); i++) {
        fstream f;
        // Ouvrir le fichier JSON
        f.open(FilePath + "/" + FileName[i], ios::in);
        if (!f) {
            cerr << "Erreur : impossible d'ouvrir le fichier " << FileName[i] << endl;
            continue;
        }

        // Analyser le fichier JSON
        json jsonData;
        f >> jsonData;
        f.close();

        // Récupérer les données du JSON
        nom = jsonData["nom"];
        dure = jsonData["dure"];
        pv = jsonData["pv"];
        force = jsonData["force"];
        resistance = jsonData["resistance"];

        // Ajouter le consommable à la liste
        v->push_back(*this);
    }
}

int Consommable::getDure() {
    return dure;
}

int Consommable::getPV() {
    return pv;
}

int Consommable::getForce() {
    return force;
}

int Consommable::getResistance() {
    return resistance;
}

std::string Consommable::getNom() {
    return nom;
}
