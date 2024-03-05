#include "Competence.h"
#include "../lib/json.hpp"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;
using json = nlohmann::json;

Competence::Competence() : degat(0), soin(0) {}

Competence::Competence(int stat, bool estSoin) {
    if (estSoin) {
        soin = stat;
        degat = 0;
    } else {
        soin = 0;
        degat = stat;
    }
}

Competence::~Competence(){
    
}

void Competence::genereCompetence(string FileName){
    string FilePath = "data/competence/" + FileName;

    cout << FilePath << endl;

    ifstream file(FilePath);

    json Doc = json::parse(file);

    bool estSoin = {Doc["soin"]};
    int stat = {Doc["stat"]};

    Competence c = Competence(stat, estSoin);

    degat = c.degat;
    soin = c.soin;
}

int Competence::getDegat() const {
    return degat;
}

int Competence::getSoin() const {
    return soin;
}
