#ifndef COMPETENCE_H
#define COMPETENCE_H

class Personnage; // Déclaration anticipée
#include "../lib/json.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


class Competence {
private:
    const string filePath = "data/competence/";
    const vector<string> jsonCompetence = {"coup_de_poing.json", "boulle_de_feu.json"};

    enum typeCompetence {FORCE, INTELLIGENCE};

    string nom;
    int degat;
    int soin;
    typeCompetence type;

public:
    enum nomCompetence {
        COUP_DE_POING,
        BOULLE_DE_FEU
    };

    Competence();
    Competence(int stat, bool estSoin);
    Competence(nomCompetence c);
    
    string getNom() const;
    int getDegat() const;
    int getSoin() const;
    int getType() const;
};
#endif
