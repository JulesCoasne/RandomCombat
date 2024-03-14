#include "Competence.h"
#include "Personnage.h"
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

Competence::Competence(nomCompetence c) {
    string path = filePath + jsonCompetence[c];
    ifstream file(path);

    json Doc = json::parse(file);

    degat = Doc["degat"];
    soin = Doc["soin"];
}

int Competence::getDegat() const {
    return degat;
}

int Competence::getSoin() const {
    return soin;
}

void Competence::useCompetence(Personnage &p, int force) {
    p.updatePV(-(degat * force));
    p.updatePV(soin);
}
