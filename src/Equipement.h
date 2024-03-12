#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H

#include <iostream>

using namespace std;

class Equipement{
    private:
        int pv;
        int force ;
        int resistence;
    
    public:
        Equipement(const int &pvE, const int &forceE, const int &resistenceE);  // Déclaration du constructeur
        ~Equipement();  // Déclaration du destructeur
        
        int getPV() const ;
        int getForce() const ;
        int getResistence() const ;
        static Equipement genereEquipement(int difficulty);
};
#endif
