#ifndef CONSOMMABLE_H
#define CONSOMMABLE_H

#include "../lib/json.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Consommable {
private:
    std::string nom;
    int pv;

    vector<string> FileName = {"potion.json"};
    string FilePath = "data/consommable";

public:
    enum nomConsommable {
        POTION,
        Count
    };

    Consommable();
    Consommable(nomConsommable c);
    Consommable(int c);
    ~Consommable();

    /**
     * @brief charge un consommble précréer
     */
    std::string getNom() const;
    int getPV() const;
};

#endif // CONSOMMABLE_H
