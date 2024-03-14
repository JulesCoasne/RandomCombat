#ifndef CONSOMMABLE_H
#define CONSOMMABLE_H

#include <string>

class Consommable {
private:
    std::string nom;
    int dure, pv, force, resistance;

public:
    Consommable();
    explicit Consommable(const std::string& nom, int dure, int pv, int force, int resistance);

    std::string getNom() const;
    int getDure() const;
    int getPV() const;
    int getForce() const;
    int getResistance() const;
};

#endif // CONSOMMABLE_H
