#ifndef ENNEMI_H
#define ENNEMI_H

#include <iostream>
#include <string>
#include <vector>
#include "Competence.h"
#include "Personnage.h"

using namespace std;

/**
 * @class Ennemi
 * 
 * @brief Classe de gestion des ennemis
*/
class Ennemi {
private:
    string sprite; ///< Chemin vers le sprite de l'ennemis
    string nom; ///< Nom de l'ennemi
    int pv; ///< PV de l'ennemi
    int force;  ///< force de l'ennemi, sert à calculer les dégats de l'ennemis
    int resistance; ///< resistance de l'ennemis, sert à réduire les dégats pris par l'ennemi
    vector<Competence> tabCompetence; ///< INUTILISE, L'ENNEMI N'UTILISE PAS ENCORE DE COMPETENCE

public:
    /**
     * @enum nomEnnemi
     * 
     * @brief nom de tous les ennemis présents dans le jeu
    */
    enum nomEnnemi {
        SQUELETTE,
        CHAUVE_SOURIS,
        PIRATE
    };

    /**
     * @brief Constructeur vide de l'ennemi, deleted
    */
    Ennemi() = delete;

    /**
     * @brief Constructeur principal de l'ennemi
     * 
     * @param e prend un nomEnnemi pour charger l'ennemi
    */
    Ennemi(nomEnnemi e);

    /**
     * @brief Constructeur d'ennemi pour teste 
     * 
     * @param nom nom de l'ennemi
     * @param p pv de l'ennemi
     * @param f force de l'ennemi
     * @param r resistance de l'ennemi
    */
    Ennemi(string nom, int p, int f, int r);

    /**
     * @brief INUTILISER, PAS DE SELECTION DE LA DIFFCULTER : Constructeur d'un ennemi en fonction d'une difficulté
     * 
     * @param nom nom de l'ennemi
     * @param diff difficulté à laquel l'ennemi doit être généré
    */
    Ennemi(string nom, int diff);

    
    /**
     * @brief retourne le chemin du sprite de l'ennemi
     * @return Le chemin du sprite de l'ennemi
    */
    string getSprite();

    /**
     * @brief retourne le nom de l'ennemi
     * @return le nom de l'ennemi
    */
    string getNom() const;

    /**
     * @brief retourn les pv de l'ennemi
     * @return Les PV de l'ennemi
    */
    int getPV() const;

    /**
     * @brief retourne la force de l'ennemi
     * @return La force de l'ennemi
    */
    int getForce() const;

    /**
     * @brief retourne la resistance de l'ennemi
     * @return La resistance de l'ennemi
    */
    int getResistance() const;

    /**
     * @brief gestion des dégats reçu par un ennemi
     * 
     * @param degat degat reçu par l'ennemi
     * @return Les dégats pris par l'ennemi après soustraction de la resistance
    */
    int prendDegat(int degat);

    /**
     * @brief gestion d'un ajout de PV à l'ennemi
     * 
     * @param update nombre de pv à ajouter
    */
    void updatePV(int update);

    
    /**
     * @brief Teste si l'ennemi est mort, retourne true si oui, false sinon
     * @return Un booléen représentant l'état de l'ennemi
    */
    bool isDead() const;
};
#endif
