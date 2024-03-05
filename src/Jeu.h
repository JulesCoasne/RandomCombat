#ifndef JEU_H
#define JEU_H
#endif

#include "Consommable.h"
#include <vector>
#include <string>

class Jeu{
    private:
    std::vector<Consommable> tabConsommable;

    void genereTabConsommable();

    public:
    Jeu();
    ~Jeu();
    
    Consommable getConsommable(int index);
    int nouvellePartie();
};