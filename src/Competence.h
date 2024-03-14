#ifndef COMPETENCE_H
#define COMPETENCE_H

class Personnage; // Déclaration anticipée
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
    enum nomCompetence {
        COUP_DE_POING
    };

    Competence();
    Competence(int stat, bool estSoin);
    Competence(nomCompetence c);
    
    int getDegat() const;
    int getSoin() const;

    void useCompetence(Personnage &p, int force);
};
#endif
