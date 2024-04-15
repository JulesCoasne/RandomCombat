#ifndef CONSOMMABLE_H
#define CONSOMMABLE_H

#include "../lib/json.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

/**
 * @class Consommable
 * 
 * @brief Classe gérant les consommables du joueur
*/
class Consommable {
private:
    std::string nom; ///< Nom du consommable
    int pv; ///< Nombre de pv rendu par le consommable

    vector<string> FileName = {"potion.json", "petite_potion.json", "grande_potion.json"}; ///< Nom du .json du consommable
    string FilePath = "data/consommable";   ///< Chemin vers le répertoire des données des consommables

public:
    /**
     * @enum nomConsommable
     * 
     * @brief nom des consommables
    */
    enum nomConsommable {
        POTION,
        PETITE_POTION,
        GRANDE_POTION,
        Count
    };

    /**
     * @brief Constructeur sans paramètre du la classe consommable
    */
    Consommable();

    /**
     * @brief Constructeur de la classe Consommable 
     * 
     * @param c Prend un nomConsommalbe pour générer un consommable à partir de son .json
    */
    Consommable(nomConsommable c);

    /**
     * @brief Constructeur de la classe Consommable
     * 
     * @param c Prend un int pour générer un consommable à partir de son .json
    */
    Consommable(int c);

    /**
     * @brief Destructeur de la classe consommable
    */
    ~Consommable();


    /**
     * @brief retourne le nom du consommalbe
     * @return Le nom du consommable sous forme de string
     */
    std::string getNom() const;

    /**
     * @brief retourne le soin procurré par le consommable
     * @return Les PV rendu par le consommable sous forme d'un int
    */
    int getPV() const;
};

#endif // CONSOMMABLE_H
