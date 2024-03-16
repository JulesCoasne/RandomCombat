#ifndef CONSOMMABLE_H
#define CONSOMMABLE_H

#include <string>
#include <vector>

class Consommable {
private:
    std::string nom;
    int dure, pv, force, resistance;

public:
    Consommable();
    ~Consommable();

    /**
     * @brief charge un consommble précréer
     */
    void genereConsommable(std::vector<Consommable> *v);
    std::string getNom();
    int getDure();
    int getPV();
    int getForce();
    int getResistance();
};

#endif // CONSOMMABLE_H
