#ifndef COMPETENCE_H
#define _COMPETENCE_H
#endif

#include <string>
#include <vector>

using namespace std;

class Competence {
private:
    const enum nomCompetence{
        COUP_DE_POING
    };

    const string filePath = "data/competence/";
    const vector<string> jsonCompetence = {"coup_de_poing.json"};

    int degat;
    int soin;

public:
    Competence();
    Competence(int stat, bool estSoin);
    Competence(enum nomCompetence);
    ~Competence();
    
    int getDegat() const;
    int getSoin() const;
};

