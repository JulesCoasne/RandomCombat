#include "Competence.h"
#include "Personnage.h"
#include "../lib/json.hpp"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;
using json = nlohmann::json;

Competence::Competence() : degat(0), soin(0) {}

Competence::Competence(int stat, bool estSoin) {
    if (estSoin) {
        soin = stat;
        degat = 0;
    } else {
        soin = 0;
        degat = stat;
    }
}

Competence::Competence(nomCompetence c) {
    string path = filePath + jsonCompetence[c];

    fstream f;
     // Ouvrir le fichier JSON
    f.open(path, ios::in);
    if (!f) {
        cerr << "Erreur : impossible d'ouvrir le fichier " << jsonCompetence[c] << endl;
    }

    // Analyser le fichier JSON
    json jsonData;
    f >> jsonData;
    f.close();

    // Récupérer les données du JSON
    nom = jsonData["nom"];
    degat = jsonData["degat"];
    soin = jsonData["soin"];
}

string Competence::getNom() const {
    return nom;
}

int Competence::getDegat() const {
    return degat;
}

int Competence::getSoin() const {
    return soin;
}

void Competence::useCompetence(Personnage &p, int force) {
    p.updatePV(-(degat * force));
    p.updatePV(soin);
}
