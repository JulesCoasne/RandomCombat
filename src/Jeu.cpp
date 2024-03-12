#include "Partie.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    // Création d'une nouvelle partie
    Partie partie(1);  // Difficulté 1 pour commencer

    // Boucle de jeu principale
    while (!partie.estTerminee()) {
        // Affiche l'état actuel du jeu
        partie.afficherEtat();

        // Demande à l'utilisateur de faire un choix
        int choix = partie.demanderChoix();

        // Exécute le choix de l'utilisateur
        partie.executerChoix(choix);
    }

    return 0;
}
