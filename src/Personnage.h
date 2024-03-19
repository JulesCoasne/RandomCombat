#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <string>
#include <vector>
#include "Competence.h"

class Personnage {
private:
    std::string nom;
    int pv;
    int force;
    int resistance;
    vector<Competence> tabCompetence;

public:
    Personnage();
    Personnage(const std::string &nom);

    std::string getNom() const;
    int getPV() const;
    int getForce() const;
    int getResistance() const;
    vector<Competence> getTabCompetence() const;

    void updateNom(string update);
    void updatePV(int update);
    void updateForce(int update);
    void updateResistance(int update);

    bool isDead() const;
    Competence getCompetence(int index) const;
    void addCompetence(Competence::nomCompetence c);
    void useCompetence(int index);

};

#endif // PERSONNAGE_H
