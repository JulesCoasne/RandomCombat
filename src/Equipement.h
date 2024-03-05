#ifndef EQUIPEMENT_H
#define _EQUIPEMENT_H
#endif
#include <fstream>


using namespace std;

class Equipement{
    private:
        int pv;
        int force ;
        int resistence;
    
    public:
        Equipement (const int &pvE , const int &forceE , const int &resistenceE);
        ~Equipement();
        int getPV() const ;
        int getForce() const ;
        int getResistence() const ;
        static Equipement genereEquipement(int difficulty);
};