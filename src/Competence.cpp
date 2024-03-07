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

Competence::Competence(nomCompetence c){
    string path = filePath +jsonCompetence[c];
    ifstream file(path);

    json Doc = json::parse(file);

    degat = {Doc["degat"]};
    soin = {Doc["soin"]};
}

Competence::~Competence(){
    
}

int Competence::getDegat() const {
    return degat;
}

int Competence::getSoin() const {
    return soin;
}
