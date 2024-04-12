#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <string>
#include <vector>
#include "Consommable.h"
#include "Competence.h"

using namespace std;

class Personnage {
private:
    std::string nom;
    int pv;
    int force;
    int resistance;
    int intelligence;
    vector<Competence> tabCompetence;

public:
    enum classePersonnage{GUERRIER, MAGE};

    Personnage();
    Personnage(const std::string &nom);
    Personnage(classePersonnage c);

    std::string getNom() const;
    int getPV() const;
    int getForce() const;
    int getResistance() const;
    int getIntelligence() const;
    vector<Competence> getTabCompetence() const;

    void updateNom(string update);
    void updatePV(int update);
    void updateForce(int update);
    void updateResistance(int update);

    int takeDamage(int degat);

    bool isDead() const;
    Competence getCompetence(int index) const;
    void addCompetence(Competence::nomCompetence c);
    void useConsommable(int index);

};

#endif // PERSONNAGE_H
