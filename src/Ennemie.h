#ifndef ENNEMI_H
#define _ENNEMI_H
#endif
#include <iostream>
#include <string>
#include <vector>
#include "Competence.h"

using namespace std;

class Ennemie {
private:
    string nom;
    int pv;
    int force;
    int resistance;
    vector<Competence> tabCompetence;

public:
    Ennemie(string nom);
    Ennemie(string nom, int p, int f, int r);
    Ennemie(string nom, int diff);

    void useCompetence(Competence comp);
};


