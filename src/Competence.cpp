#include "Competence.h"

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

int Competence::getDegat() const {
    return degat;
}

int Competence::getSoin() const {
    return soin;
}
