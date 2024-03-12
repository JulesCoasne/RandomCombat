#ifndef INVENTAIRE_H
#define INVENTAIRE_H

#include "Consommable.h"
#include "Equipement.h"
#include <vector>
#include <iostream>

using namespace std;

class Inventaire
{
    private:
       vector<Consommable> tabConsommable ; 
       vector<Equipement> tabEquipement ;
    
    public:
        Inventaire();  // Déclaration du constructeur par défaut
        ~Inventaire();  // Déclaration du destructeur
        void useConsommable(int index);
        void addEquipement(const Equipement& equip);
        void addConsommable(const Consommable& conso);
        
};
#endif
