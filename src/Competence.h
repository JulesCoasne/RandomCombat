#ifndef COMPETENCE_H
#define _COMPETENCE_H
#endif

#include <string>

class Competence {
private:
    int degat;
    int soin;

public:
    Competence();
    Competence(int stat, bool estSoin);
    ~Competence();

    void genereCompetence(std::string FileName);
    
    int getDegat() const;
    int getSoin() const;
};

