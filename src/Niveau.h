#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Niveau{
    private:
    int difficulte;

    public:
    Niveau();
    Niveau(int diff);
    ~Niveau();

    bool nouveauCombat();
};