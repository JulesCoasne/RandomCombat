#ifndef JEU_H
#define JEU_H

#include "Partie.h"
#include "Competence.h"
#include "Consommable.h"
#include "Equipement.h"
#include <vector>

class Jeu {
private:
    std::vector<Competence> tab_competence;
    std::vector<Consommable> tab_consommable;
    std::vector<Equipement> tab_equipement;
    Partie p;
    int difficulte;

public:
    Jeu();
    Competence getCompetence(int index);
    Consommable getConsommable(int index);
    Equipement getEquipement(int index);
    void addEquipement(const Equipement& equip);
    void addConsommable(const Consommable& cons);
    int nouvellePartie();
    void useConsommable(int index);
};

#endif // JEU_H
