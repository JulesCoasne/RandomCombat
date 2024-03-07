#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Personnage.h"

#include "Competence.h"

using namespace std;

// Fonction pour choisir une compétence
int choisirCompetence(const Personnage& personnage) {
    int choix;
    cout << "Choisissez une compétence pour " << personnage.getNom() << " :\n";
    for (int i = 0; i < personnage.getNbCompetences(); ++i) {
        cout << i + 1 << ". " << personnage.getCompetence(i).getNom() << endl;
    }
    cout << "Votre choix : ";
    cin >> choix;
    return choix - 1;
}

// Fonction pour exécuter un tour de combat
void tourDeCombat(Personnage& joueur, Personnage& ennemi) {
    // Tour du joueur
    int choix = choisirCompetence(joueur);
    const Competence& competenceJoueur = joueur.getCompetence(choix);
    if (competenceJoueur.getSoin() > 0) {
        joueur.soigner(competenceJoueur, ennemi);
    } else {
        joueur.attaquer(competenceJoueur, ennemi);
    }

    // Vérification de la victoire du joueur
    if (ennemi.estVaincu()) {
        cout << "Vous avez vaincu " << ennemi.getNom() << " !\n";
        return;
    }

    // Tour de l'ennemi
    choix = rand() % ennemi.getNbCompetences();
    const Competence& competenceEnnemi = ennemi.getCompetence(choix);
    if (competenceEnnemi.getSoin() > 0) {
        ennemi.soigner(competenceEnnemi, joueur);
    } else {
        ennemi.attaquer(competenceEnnemi, joueur);
    }

    // Vérification de la défaite du joueur
    if (joueur.estVaincu()) {
        cout << "Vous avez été vaincu par " << ennemi.getNom() << " !\n";
    }
}

int main() {
    // Initialisation du générateur de nombres aléatoires
    srand(time(0));

    // Création des personnages
    Personnage joueur("Joueur", 100);
    Personnage ennemi("Ennemi", 80);

    // Initialisation des compétences
    joueur.initialiserCompetences();
    ennemi.initialiserCompetences();

    // Déroulement du combat
    while (!joueur.estVaincu() && !ennemi.estVaincu()) {
        tourDeCombat(joueur, ennemi);
    }

    return 0;
}
