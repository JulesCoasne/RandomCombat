#ifndef CONSOMMABLE_H
#define CONSOMMABLE_H
#endif

#include <string>

using namespace std;

class Consommable{
    private:
    string nom;
    int dure, pv, force, resistance;

        const enum nomConsommable{
        POTION
    };

    const string filePath = "data/consommable/";
    const vector<string> jsonConsommable = {"potion.json"};

    public:
    Consommable();
    Consommable(nomConsommable c);
    Consommable(string n, int d, int p, int f, int r);
    ~Consommable();

    /**
     * @brief charge un consommble précréer
    */
    string getNom();
    int getDure();
    int getPV();
    int getForce();
    int getResistance();
};