#ifndef JEU_H
#define JEU_H
#endif

#include "Consommable.h"
#include <vector>

class Jeu{
    private:
    std::vector<Consommable> tabConsommable;

    public:
    Jeu();
    Consommable getConsommable(int index);
    int nouvellePartie();
};