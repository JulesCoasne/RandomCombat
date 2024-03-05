#ifndef COMPETENCE_H
#define _COMPETENCE_H
#endif

class Competence {
private:
    int degat;
    int soin;

public:
    Competence();
    Competence(int stat, bool estSoin);

    
    int getDegat() const;
    int getSoin() const;
};

