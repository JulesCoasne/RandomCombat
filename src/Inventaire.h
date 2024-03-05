#ifndef INVENTAIRE_H
#define _INVENTAIRE_H
#endif

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
        Inventaire ();
        ~Inventaire();
        void useConsommable(int index);
        void addEquipement(const Equipement& equip);
        void addConsommable(const Consommable& conso);
        
};







