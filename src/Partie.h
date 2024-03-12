#ifndef PARTIE_H
#define PARTIE_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Partie {
private:
    int difficulte;

public:
    Partie(int diff);
    ~Partie();

    bool estTerminee();
    void afficherEtat();
    int demanderChoix();
    void executerChoix(int choix);
};
#endif  // PARTIE_H
