#ifndef JEU_H
#define JEU_H
#endif

#include "Consommable.h"
#include "Equipement.h"
#include "Competence.h"
#include <vector>
#include <string>

class Jeu{
    private:
    std::vector<Consommable> tabConsommable;
    std::vector<Equipement> tabEquipement;
    std::vector<Competence> tabCompetence;

    void genereTabConsommable();
    void genereTabEquipement();
    void genereTabCompetence();

    public:
    Jeu();
    ~Jeu();
    
    Consommable getConsommable(int index);
    Competence getCompetence(int index);
    int nouvellePartie();
};