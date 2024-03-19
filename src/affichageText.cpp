#include "affichageText.h"

#include <iostream>

using namespace std;

affichageText::affichageText(){}

affichageText::~affichageText(){}

int affichageText::quitter(){
    int userInput;

    cout << "Etes-vous sur de vouloir quitter ?" << endl;
    cout << "   [0] Oui, quitter." << endl;
    cout << "   [1] Non, reprendre." << endl;

    cin >> userInput;

    return userInput;
}

int affichageText::debutTour(int nbEnnemi){
    int userInput;

    cout << endl;
    cout << "Début du tour !" << endl;
    cout << "Il reste " << nbEnnemi << " ennemi(s) !" << endl;
    cout << "Que souhaitez-vous faire ?" << endl;
    cout << "[1] Attaquer" << endl;
    cout << "[2] Utiliser un Consommalbe" << endl;
    cout << "[3] Quitter" << endl;

    cin >> userInput;

    return userInput;
}

int affichageText::attaque(const Personnage& joueur){
    int userInput;

    cout << endl;
    cout << "Choisissez une attaque :" << endl;

    for(int i = 0; i < 1; i++){
        cout << "   [" << i+1 << "] " << joueur.getCompetence(i).getNom() << endl;
    }

    cout << "[0] Retour" << endl;
    cout << endl;

    cin >> userInput;

    return userInput;
}

void affichageText::attaqueEnnemi(int degat, Ennemi ennemi){
    cout << endl;
    cout << ennemi.getNom() << " attaque !" << endl;
    cout << "Vous prenez " << degat << " degat(s) !" << endl;
}

int affichageText::choixEnnemiCombat(vector<Ennemi> tabEnnemi){
    int userInput;

    cout << endl;
    cout << "Quel ennemi attaquez-vous ?" << endl;

    for(int i = 0; i < tabEnnemi.size(); i++){
        cout << "   [" << i+1 << "] " << tabEnnemi[i].getNom() << endl;
    }

    cout << "[0] Retour" << endl;
    cout << endl;

    cin >> userInput;

    return userInput;
}

void affichageText::pvRestant(int pv){
    cout << endl;
    cout << "Il vous reste " << pv << " pv." << endl;
}

void affichageText::infoCombat(vector<Ennemi> tabEnnemi){
    cout << endl;
    for(int i = 0; i < tabEnnemi.size(); i++){
        cout << tabEnnemi[i].getNom() << " à " << tabEnnemi[i].getPV() << " pv restant." << endl;
    }
}

void affichageText::resumeCombat(string nomEnnemi, int degat, int soin){
    cout << endl;
    cout << "Vous avez fait " << degat << " dégat(s) à " << nomEnnemi << endl;
    cout << "Vous vous êtes soigné de " << soin << " pv." << endl;
}

void affichageText::finDuCombat(){
    cout << endl;
    cout << "Vous avez fini le combat" << endl;
}