#ifndef NIVEAU_H
#define NIVEAU_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Niveau {
private:
    int difficulte;

public:
    Niveau();
    Niveau(int diff);
    ~Niveau() = default;

    bool nouveauCombat();
};
#endif  // NIVEAU_H
