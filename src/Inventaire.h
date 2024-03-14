#ifndef INVENTAIRE_H
#define INVENTAIRE_H

#include "Consommable.h"
#include "Equipement.h"
#include <vector>

class Inventaire {
private:
    std::vector<Consommable> tabConsommable;
    std::vector<Equipement> tabEquipement;

public:
    Inventaire(); // Constructeur par défaut
    ~Inventaire(); // Destructeur

    void useConsommable(int index);
    void addEquipement(const Equipement& equip);
    void addConsommable(const Consommable& conso);
};

#endif // INVENTAIRE_H
