#ifndef JEU_H
#define JEU_H

#include "Partie.h"
#include "Competence.h"
#include "Consommable.h"
#include "Equipement.h"
#include <vector>

class Jeu {
private:
    std::vector<Competence> tabCompetence;
    std::vector<Consommable> tabConsommable;
    std::vector<Equipement> tabEquipement;
    Partie p;
    int difficulte = 1; 

public:
    Jeu();
    Competence getCompetence(int index);
    Consommable getConsommable(int index);
    Equipement getEquipement(int index);
    void addEquipement(const Equipement& equip);
    void addConsommable(const Consommable& cons);
    int nouvellePartie();
    void useConsommable(size_t index);
};

#endif // JEU_H
