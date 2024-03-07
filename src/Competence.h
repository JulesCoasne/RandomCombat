#ifndef COMPETENCE_H
#define _COMPETENCE_H
#endif

#include "Personnage.h"
#include "Ennemi.h"
#include <string>
#include <vector>

using namespace std;

class Competence {
private:

    const string filePath = "data/competence/";
    const vector<string> jsonCompetence = {"coup_de_poing.json"};

    int degat;
    int soin;

public:

    const enum nomCompetence{
        COUP_DE_POING
    };
    
    Competence();
    Competence(int stat, bool estSoin);
    Competence(nomCompetence c);
    ~Competence();
    
    int getDegat() const;
    int getSoin() const;

    void useCompetence(const Personnage &p);
    void useCompetence(const Ennemi &e); 
};

