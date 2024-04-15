#include "Consommable.h"

using json = nlohmann::json;
using namespace std;

Consommable::Consommable() {}

Consommable::Consommable(int c){
    fstream f;
    // Ouvrir le fichier JSON
    f.open(FilePath + "/" + FileName[c], ios::in);
    if (!f) {
        cerr << "Erreur : impossible d'ouvrir le fichier " << FileName[c] << endl;
        exit(EXIT_FAILURE);
    }

    // Analyser le fichier JSON
    json jsonData;
    f >> jsonData;
    f.close();

    // Récupérer les données du JSON
    nom = jsonData["nom"];
    pv = jsonData["pv"];
}

Consommable::Consommable(nomConsommable c){
    fstream f;
    // Ouvrir le fichier JSON
    f.open(FilePath + "/" + FileName[c], ios::in);
    if (!f) {
        cerr << "Erreur : impossible d'ouvrir le fichier " << FileName[c] << endl;
        exit(EXIT_FAILURE);
    }

    // Analyser le fichier JSON
    json jsonData;
    f >> jsonData;
    f.close();

    // Récupérer les données du JSON
    nom = jsonData["nom"];
    pv = jsonData["pv"];
}

// Destructeur
Consommable::~Consommable() {
    // Code du destructeur
}

int Consommable::getPV() const{
    return pv;
}

std::string Consommable::getNom() const{
    return nom;
}
