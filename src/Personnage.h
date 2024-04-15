#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <string>
#include <vector>
#include "Consommable.h"
#include "Competence.h"

using namespace std;

/**
 * @brief Classe gérant le personnage du joueur
*/
class Personnage {
private:
    string nom; ///< Nom du personnage
    int pv; ///< pv du personnage
    int pvMax;  ///< PV Max du personnage
    int force;  ///< Force du personnage
    int resistance; ///< Resistance du personnage
    int intelligence;   ///< Intelligence du personnage
    vector<Competence> tabCompetence;   ///< Liste des compétences du personnage
    vector<Consommable> tabConsommable; ///< Liste des consommable du personnage

public:
    /**
     * @enum classePersonnage
     * 
     * @brief Les deux classes possibles du personnage
    */
    enum classePersonnage{GUERRIER, MAGE};


    /**
     * @brief Constructeur sans paramètre du personnage
    */
    Personnage();

    /**
     * @brief Constructeur test du personnage, prend uniquement un nom
     * 
     * @param nom nom du personnage
    */
    Personnage(const std::string &nom);

    /**
     * @brief Constructeur principal du personnage
     * 
     * @param c classe du personnage, initialise différente stat de base suivant sa classe
    */
    Personnage(classePersonnage c);

    /**
     * @brief Destructeur de la classe Personnage
    */
    ~Personnage();


    /**
     * @brief retourne le nom du personnage
    */
    string getNom() const;

    /**
     * @brief retourne les PV du personnage
    */
    int getPV() const;

    /**
     * @brief retourne les PV Max du personnage
    */
    int getPVMax() const;

    /**
     * @brief retourne la force du personnage
    */
    int getForce() const;

    /**
     * @brief retourne la resistance du personnage
    */
    int getResistance() const;

    /**
     * @brief retourne l'intelligence du personnage
    */
    int getIntelligence() const;

    /**
     * @brief retourne le vecteur des compétences du personnage
    */
    vector<Competence> getTabCompetence();

    /**
     * @brief retourne le vecteur des consommables du personnage
    */
    vector<Consommable> getTabConsommable();

    /**
     * @brief retourne un pointeur vers le vecteur des consommable du personnage
    */
    vector<Consommable>  * getPtrTabConsommable();


    /**
     * @brief Change le nom du personnage
     * 
     * @param update Nouveau nom du personnage
    */
    void updateNom(string update);

    /**
     * @brief Ajoute des PV au personnage, vérifie qu'on ne dépasse pas la limite de PV pvMax
     * 
     * @param update Nombre de pv à ajouter au personnage
    */
    void updatePV(int update);

    /**
     * @brief Met à jour le nombre de PV Max du personnage
     * 
     * @param update Nombre de PV Max à ajouter au personnage
    */
    void updatePVMax(int update);

    /**
     * @brief Met à jour la force du personnage
     * 
     * @param update Force à ajouter au personnage
    */
    void updateForce(int update);

    /**
     * @brief Met à jour l'intelligence du personnage
     * 
     * @param update Intelligence à ajouter au personnage
    */
    void updateIntelligence(int update);

    /**
     * @brief Met à jour la resistance du personnage
     * 
     * @param update Resistance à ajouter au personnage
    */
    void updateResistance(int update);


    /**
     * @brief gère les dégat pris par le personnage, en fonction de sa resistance et de ses pv max
     * 
     * @param degat Degat reçu par le personnage
    */
    int takeDamage(int degat);


    /**
     * @brief Vérification de si le personnage et toujour en vie ou non
    */
    bool isDead() const;

    /**
     * @brief Retourne la compétence à l'index du vecteur du personnage
     * 
     * @param index index de la compétence dans le vecteur tabCompetence
    */
    Competence getCompetence(int index) const;

    /**
     * @brief Retourne le consommable à l'index du vecteur du personnage
     * 
     * @param index index du consommable dans le vecteur tabConsommable
    */
    Consommable getConsommable(int index) const;

    /**
     * @brief Ajoute une compétence au vecteur de compétence du personnage
     * 
     * @param c Nom de la compétence à ajouter au personnage
    */
    void addCompetence(Competence::nomCompetence c);

    /**
     * @brief Ajoute un consommable au vecteur de compétence du personnage
     * 
     * @param c Nom du consommable à ajouter au personnage
    */
    void addConsommable(Consommable::nomConsommable c);
};

#endif // PERSONNAGE_H
