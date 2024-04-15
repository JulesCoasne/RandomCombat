#ifndef NIVEAU_H
#define NIVEAU_H

#include "Ennemi.h"
#include "Personnage.h"
#include "Combat.h"

#include <iostream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

/**
 * @class Niveau
 * 
 * @brief Classe de gestion d'un niveau
*/
class Niveau {
private:
    int numNiveau; ///< Niveau dans lequel ce trouve le joueur
    vector<Ennemi> tabEnnemi;   ///< vecteur d'ennemi que le joueur va devoir battre pour passer le niveau
    vector<Ennemi::nomEnnemi> ennemiFacile = {Ennemi::SQUELETTE, Ennemi::CHAUVE_SOURIS, Ennemi::PIRATE};    ///< vecteur des ennemis dit "Facile"

public:
    Combat * combat;    ///< Combat généré par le niveau

    /**
     * @brief Constructeur vide du niveau, initialise les ennemis
    */
    Niveau();

    /**
     * @brief Destructeur du niveau
    */
    ~Niveau();


    /**
     * @brief génère le vecteur d'ennemis du niveau en fonction du niveau
    */
    void generateTabEnnemi();

    /**
     * @brief Vérification de l'état des ennemis après le tour du joueur
     * 
     * @param affichage gère la destruction et la réaffectation des sprites lors de la mort d'un ennemi
    */
    void checkEnnemiStatus(Affichage& affichage);

    /**
     * @brief génère les sprites de tous les ennemis
     * 
     * @param affichage pour mettre à jour le vectSprites
    */
    void createEnnemisSprites(Affichage& affichage);

    /**
     * @brief Génère un nouveau combat
     * 
     * @param affichage pour mettre à jour les éléments graphiques
     * @param joueur pour que le Combat puisse mettre à jour les stats du joueur
    */
    void nouveauCombat(Affichage& affichage, Personnage &joueur);

    /**
     * @brief gère la fin du niveau
    */
    void levelCleared();


    /**
     * @brief getter pour le numéro du niveau
     * @return Retourne le numéro du niveau
    */
    int getNumNiveau();

    
    /**
     * @brief retourne un pointeur vers le tabEnnemi du niveau
     * @return Un pointeur vers tabEnnemi
    */
    vector<Ennemi> * getTabEnnemi();

    /**
     * @brief retourne un ennemi à l'index i
     * 
     * @param i index de l'ennmi à retourner
     * @return L'ennemi à l'index i
    */
    Ennemi getEnnemi(int i);
};

#endif // NIVEAU_H
