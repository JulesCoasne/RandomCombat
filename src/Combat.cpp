#include "Combat.h"

using namespace std;

Combat::Combat(vector<Ennemi> &e, Personnage &j): tabEnnemi(e), joueur(j){}

Combat::~Combat(){}

string Combat::attaque(int choixCompetence, int choixEnnemi){
    int degat = 0;

    if(joueur.getCompetence(choixCompetence).getType() == 0){
        degat = joueur.getCompetence(choixCompetence).getDegat() * joueur.getForce();
    }

    if(joueur.getCompetence(choixCompetence).getType() == 1){
        degat = joueur.getCompetence(choixCompetence).getDegat() * joueur.getIntelligence();
    }

    int degatRecu = tabEnnemi[choixEnnemi].prendDegat(degat);

    string str = tabEnnemi[choixEnnemi].getNom() + " prend " + to_string(degatRecu) + " de degat(s) !";
    str.append(" Il reste " + to_string(tabEnnemi[choixEnnemi].getPV()) + " PV a " + tabEnnemi[choixEnnemi].getNom() + " ");
    if(tabEnnemi[choixEnnemi].isDead()) str += tabEnnemi[choixEnnemi].getNom() + " est mort(e) !";

    return str;
}

string Combat::consommable(int choixConsommable){
    vector<Consommable> * v = joueur.getPtrTabConsommable();

    int heal = joueur.getConsommable(choixConsommable).getPV();

    joueur.updatePV(heal);

    string str = "Vous vous êtes soignée de " + to_string(heal) + " PV. Vous avez maintenant " + to_string(joueur.getPV()) + " PV.";

    cout << str << endl;

    v->erase(v->begin() + choixConsommable);

    return str;
}

string Combat::tourEnnemi(Affichage &affichage){
    int degatRecu = 0;
    int e = 0;

    vector<int> ennemiAlive;

    for(size_t i = 0; i < tabEnnemi.size(); i++){
        if(!tabEnnemi[i].isDead()){
            ennemiAlive.push_back(i);
        }
    }

    srand(time(NULL));
    e = rand() % ennemiAlive.size();

    int degat = tabEnnemi[e].getForce();
    degatRecu = joueur.takeDamage(degat);

    affichage.attackAnimation(e);

    string str = "Vous prenez " + to_string(degatRecu) + " degat(s) ! " + "Il vous reste " + to_string(joueur.getPV()) + " PV ! ";
    
    if(joueur.isDead()){
        str += " Vous êtes mort(e)...";
    }

    return str;
}