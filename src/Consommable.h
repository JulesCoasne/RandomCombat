#ifndef CONSOMMABLE_H
#define CONSOMMABLE_H
#endif

class Consommable{
    private:
    string nom;
    int dure, pv, force, resistance;

    public:
    Consommable();
    ~Consommable();

    /**
     * @brief charge un consommble précréer
    */
    void genereConsommable(vector<Consommable> * v);
    string getNom();
    int getDure();
    int getPV();
    int getForce();
    int getResistance();
};