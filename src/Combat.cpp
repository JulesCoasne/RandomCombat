#include "Combat.h"

using namespace std;

Combat::Combat(vector<Ennemi> e, Personnage * j): tabEnnemi(e), joueur(j), nbTour(0){}

Combat::~Combat(){}

int Combat::deroulerCombat(){
    int ennemiRestant = tabEnnemi.size();
    if(tour()){
        
    }
}

bool Combat::attaque(){
    vector<Competence> c = joueur->getTabCompetence();
    bool aJouer = false;
    int choixCompetence, choixEnnemi;
    
    while(!aJouer){
        if(choixCompetence == 0) return 0;
        int degat = c[choixCompetence].getDegat() * joueur->getForce();

        if(choixEnnemi != 0){
            tabEnnemi[choixEnnemi].prendDegat(degat);
            aJouer = true;
        }
    }
}

//event: 1 = Attaque - 2 = Consommable - 3 = Consulter les ennemies - 4 = Abandonner
bool Combat::tour(){
    bool aJouer = false;
    int event;

    nbTour++;

    while(!aJouer){
        if(event == 1) aJouer = attaque();
        //if(event == 2) aJouer = consommable();
        //if(event == 3) consultEnnemi();
        //if(event == 4){
        //    if(abandonner()){
        //        return false;
        //    }
        //}
    }
    return true;
} 