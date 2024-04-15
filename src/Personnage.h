#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <string>
#include <vector>
#include "Consommable.h"
#include "Competence.h"

using namespace std;

class Personnage {
private:
    string nom;
    int pv;
    int pvMax;
    int force;
    int resistance;
    int intelligence;
    vector<Competence> tabCompetence;
    vector<Consommable> tabConsommable;

public:
    enum classePersonnage{GUERRIER, MAGE};

    Personnage();
    Personnage(const std::string &nom);
    Personnage(classePersonnage c);

    string getNom() const;
    int getPV() const;
    int getPVMax() const;
    int getForce() const;
    int getResistance() const;
    int getIntelligence() const;
    vector<Competence> getTabCompetence();
    vector<Consommable> getTabConsommable();
    vector<Consommable>  * getPtrTabConsommable();

    void updateNom(string update);
    void updatePV(int update);
    void updatePVMax(int update);
    void updateForce(int update);
    void updateIntelligence(int update);
    void updateResistance(int update);

    int takeDamage(int degat);

    bool isDead() const;
    Competence getCompetence(int index) const;
    Consommable getConsommable(int index) const;
    void addCompetence(Competence::nomCompetence c);
    void addConsommable(Consommable::nomConsommable c);
};

#endif // PERSONNAGE_H
