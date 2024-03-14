#ifndef CONSOMMABLE_H
#define CONSOMMABLE_H

#include <string>
#include <vector>

using namespace std;

class Consommable {
private:
    string nom;
    int dure, pv, force, resistance;

    const string filePath = "data/consommable/";
    const vector<string> jsonConsommable = {"potion.json"};

public:
    enum nomConsommable {
        POTION
    };

    Consommable();
    Consommable(nomConsommable c);

    string getNom();
    int getDure();
    int getPV();
    int getForce();
    int getResistance();
};
#endif
