#include "Combat.h"

using namespace std;

Combat::Combat(vector<Ennemi> e, Personnage& j): tabEnnemi(e), joueur(j), nbTour(0){}

Combat::~Combat(){}

bool Combat::tour(){
    affichageText affichage;
    bool continuer = true;
    bool aJouer = false;
    int action = 0;

    while(continuer){
        nbTour++;
        action = 0;
        aJouer = false;

        while(!aJouer){
            if(action == 0){
                affichage.infoCombat(tabEnnemi);
                action = affichage.debutTour(tabEnnemi.size());
            }

            if(action == 1){
                int attaque = affichage.attaque(joueur);
                if(attaque != 0){
                    int choixEnnemi = affichage.choixEnnemiCombat(tabEnnemi);
                    if(choixEnnemi != 0){
                        int degat = joueur.getCompetence(action - 1).getDegat() - tabEnnemi[choixEnnemi - 1].getResistance();
                        int soin = joueur.getCompetence(action - 1).getSoin();

                        tabEnnemi[choixEnnemi - 1].updatePV(-degat);
                        joueur.updatePV(soin);

                        affichage.resumeCombat(tabEnnemi[choixEnnemi - 1].getNom(), degat, soin);

                        if(tabEnnemi[0].isDead()){
                            int degatEnnemi = tabEnnemi[0].getForce() - joueur.getResistance();
                            joueur.updatePV(degatEnnemi);
                            affichage.attaqueEnnemi(degatEnnemi, tabEnnemi[0]);

                            affichage.pvRestant(joueur.getPV());
                        }
            
                        aJouer = true;
                    }
                }else{
                    action = 0;
                }
            }

            if(action == 3){
                action = affichage.quitter();
                if(action == 0){
                    aJouer = true;
                    continuer = false;
                }else{
                    action = 0;
                }
            }
        }

        if(joueur.isDead()){
            continuer = false;
        }

        if(tabEnnemi[0].isDead()){
            continuer = false;
        }
    }

    affichage.finDuCombat();

    return true;
} 