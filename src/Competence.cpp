#include "Competence.h"

using namespace std;
using json = nlohmann::json;

Competence::Competence(){}

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
    if(jsonData["stat"] == "force") type = FORCE;
    if(jsonData["stat"] == "intelligence") type = INTELLIGENCE;
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

int Competence::getType() const{
    return type;
}
