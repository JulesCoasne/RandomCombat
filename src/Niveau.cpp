#include "Niveau.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

Niveau::Niveau() : difficulte(1) {}

Niveau::Niveau(int diff) : difficulte(diff) {}

bool Niveau::nouveauCombat() {
    // Ici, vous pouvez ajouter la logique pour déterminer si un nouveau combat doit commencer
    return true;  // Retourne vrai pour l'instant
}
