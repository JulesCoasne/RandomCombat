#ifndef COMBAT_H
#define COMBAT_H

#include "Affichage.h"
#include "Ennemi.h"
#include "Consommable.h"

#include <stdlib.h>
#include <vector>
#include <string>
#include <time.h>

using namespace std;


/**
 * @class Combat
 * 
 * @brief Classe gérant le combat des niveaux
*/
class Combat{
    private:
        vector<Ennemi> &tabEnnemi;  ///< vecteur des ennemis du combat
        Personnage &joueur; ///< Le joueur
        
    public:
        /**
         * @brief Constructeur de la classe Combat
         * 
         * @param e vecteur des ennemis initialisé par le niveau
         * @param j Personnage joueur initialiser à la sélection du personnage
        */
        Combat(vector<Ennemi> &e, Personnage &j);

        /**
         * @brief Destructeur de la classe combat
        */
        ~Combat();

        /**
         * @brief Gére lorsque le joueur lance une compétence
         * 
         * @param choixCompetence index de la competence choisi dans le tabCompetence du joueur
         * @param choixEnnemi index de l'ennemi choisi dans le tabEnnemi
         * @return Un string du résumé de l'attaque
        */
        string attaque(int choixCompetence, int choixEnnemi);

        /**
         * @brief Gère le tour des ennemis, choisi un ennemi au hasard et le fait attaquer
         * 
         * @param affichage instance d'affichage pour afficher le résumer du tour des ennemis
         * @return Un string du résumé du tour ennemi
        */
        string tourEnnemi(Affichage &affichage);

        /**
         * @brief gère l'utilisation d'un consommable
         * 
         * @param choixConsommable index du consommable à utiliser dans le tabConsommable du joueur
         * @return Un string du résumé de l'utilisation du consommable
        */
        string consommable(int choixConsommable);
};
#endif
