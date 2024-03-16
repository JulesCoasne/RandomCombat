#include "txtCombat.h"
#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32

void TxtCombat::txtAff(WinTXT &win, const Jeu &jeu) {
    // Effacer la console
    win.clear();

    // Récupérer les éléments du jeu
    const Personnage &personnage = jeu.getPersonnage();
    const Ennemi &ennemi = jeu.getEnnemi();

    // Afficher le personnage et l'ennemi
    win.print(0, 0, personnage.getNom().c_str()); // Correction ici
    win.print(0, 1, ennemi.getNom().c_str()); // Correction ici
    win.draw(); // Afficher la fenêtre de jeu
}

void TxtCombat::startCombat(Jeu &jeu) {
    // Déroulement du combat en mode texte

    // Boucle principale du combat
    bool continuer = true;
    while (continuer) {
        // Attendre un court instant pour donner l'impression de temps réel
        usleep(100000); // Utilisez la fonction sleep appropriée pour votre système

        // Récupérer l'entrée du joueur
        // Modifier ici pour utiliser une autre méthode pour obtenir l'entrée du joueur
        // char c = jeu.getCh();
        char c; // Placeholder pour l'entrée du joueur
        switch (c) {
            case 'k':
                // jeu.actionClavier('g');
                break;
            case 'm':
                // jeu.actionClavier('d');
                break;
            case 'l':
                // jeu.actionClavier('h');
                break;
            case 'o':
                // jeu.actionClavier('b');
                break;
            case 'c': // Utiliser une compétence
                // jeu.useCompetence(0); // Utiliser la première compétence
                break;
            case 'e': // Utiliser un consommable
                // jeu.useConsommable(0); // Utiliser le premier consommable
                break;
            case 'q':
                continuer = false;
                break;
        }
    }
}
