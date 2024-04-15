#ifndef COMPETENCE_H
#define COMPETENCE_H

class Personnage; // Déclaration anticipée
#include "../lib/json.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

/**
 * @class Competence
 * @brief classe gérant les compétences du joueur
*/
class Competence {
private:
    string filePath = "data/competence/"; ///< Chemin vers le fichier stockant les compétences.
    vector<string> jsonCompetence = {"coup_de_poing.json", "coup_epee.json", "boule_de_feu.json", "eclaire.json"}; ///< Nom du .json de chaque compétence

    /**
     * @enum typeCompetence
     * 
     * @brief les statistique que la compétence pourra utiliser
    */
    enum typeCompetence {FORCE, INTELLIGENCE};

    string nom; ///< Nom de la compétence.
    int degat;  ///< Dégat de la compétence.
    int soin;   ///< Nombre de PV que la compétence redonne à son utilisation.
    typeCompetence type;    ///< Type de la compétence, elle utilise l'intelligence du joueur ou sa force

public:
    /**
     * @enum nomCompetence
     * 
     * @brief toute les compétences du jeu
    */
    enum nomCompetence {
        COUP_DE_POING,
        COUP_EPEE,
        BOULE_DE_FEU,
        ECLAIRE
    };

    /**
     * @brief Constructeur sans paramètre de la classe Competence
    */
    Competence();

    /**
     * @brief Constructeur principal de la classe Competence
    */
    Competence(nomCompetence c);
    
    
    /**
     * @brief retourne le nom de la competence
     * @return Le nom de la compétence sous forme d'un string
    */
    string getNom() const;

    /**
     * @brief retourne les dégats de la competence
     * @return Les dégats de la compétence sous un int
    */
    int getDegat() const;

    /**
     * @brief retourne le soin donné par la compétence
     * @return Les soins de la compétence sous un int
    */
    int getSoin() const;

    /**
     * @brief retourn le type de la compétence sous la forme d'un int (un enum étant un int)
     * @return Un int représentant le type de la compétence
    */
    int getType() const;
};
#endif
