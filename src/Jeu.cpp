#include "Personnage.h"
#include "Niveau.h"
#include "Ennemi.h"
#include "Competence.h"
#include "Consommable.h"
#include "Equipement.h"
#include <vector>

Affichage affichage;
SDL_Event e;

Personnage joueur;
Niveau niveau;

const int w = 1280;
const int h = 720;

bool createButtonFromEnnemi(){
    int length = niveau.getTabEnnemi()->size();
    if(length > 0){
        string str;
        for(int i = 0; i < length; i++){
            str = niveau.getEnnemi(i).getNom();
            if(i == 0 && niveau.getEnnemi(i).isDead() == false) affichage.createButton(415, 520, str);
            if(i == 1 && niveau.getEnnemi(i).isDead() == false) affichage.createButton(655, 520, str);
            if(i == 2 && niveau.getEnnemi(i).isDead() == false) affichage.createButton(415, 620, str);
            if(i == 3 && niveau.getEnnemi(i).isDead() == false) affichage.createButton(655, 620, str);
        }
        return true;
    }else{
        return false;
    }
}

bool createButtonFromCompetence(){
    const vector<Competence> v = joueur.getTabCompetence();
    int length = v.size();
    if(length > 0){
        string str;
        for(int i = 0; i < length; i++){
            str = v[i].getNom();
            if(i == 0) affichage.createButton(415, 520, str);
            if(i == 1) affichage.createButton(655, 520, str);
            if(i == 2) affichage.createButton(415, 620, str);
            if(i == 3) affichage.createButton(655, 620, str);
        }
        return true;
    }else{
        return false;
    }
}

void createButtonFromConsommable(){
    const vector<Consommable> v = joueur.getTabConsommable();
    int length = v.size();
    string str;
    if(length){
        for(int i = 0; i < length; i++){
            str = v[i].getNom();
            if(i == 0) affichage.createButton(415, 520, str);
            if(i == 1) affichage.createButton(655, 520, str);
            if(i == 2) affichage.createButton(415, 620, str);
            if(i == 3) affichage.createButton(655, 620, str);
        }
    }
}

int choixAttaque(){
    affichage.deleteButton();
    createButtonFromCompetence();

    while(true){
        affichage.render();

        SDL_PollEvent(&e);

        if(e.type == SDL_MOUSEBUTTONUP && e.button.button == SDL_BUTTON_LEFT){
            int click = affichage.buttonIsClicked(&e);
            if(click != 0) return click - 1;
        }
    }
}

int choixEnnemi(){
    affichage.deleteButton();

    createButtonFromEnnemi();

    while(true){
        affichage.render();

        SDL_PollEvent(&e);

        if(e.type == SDL_MOUSEBUTTONUP && e.button.button == SDL_BUTTON_LEFT){
            int click = affichage.buttonIsClicked(&e);
            if(click != 0) return click - 1;
        }
    }
}

int choixConsommable(){
    affichage.deleteButton();

    createButtonFromConsommable();

    while(true){
        affichage.render();

        SDL_PollEvent(&e);

        if(e.type == SDL_MOUSEBUTTONUP && e.button.button == SDL_BUTTON_LEFT){
            int click = affichage.buttonIsClicked(&e);
            if(click != 0) return click - 1;
        }
    }
}

bool createTurnStartButton(){
    affichage.createButton(415, 520, "Attaque");
    affichage.createButton(655, 520, "Consommable");
    affichage.createButton(415, 620, "Ennemi");
    affichage.createButton(655, 620, "Joueur");
    return true;
}

void infoEnnemi(Niveau &n){
    string str;
    affichage.state.buttonEnable = false;
    affichage.state.dialogueEnable = true;
    affichage.state.texteEnable = true;

    for(size_t i = 0; i < n.getTabEnnemi()->size(); i++){
        affichage.deleteTexte();
        str = "Ennemi " + to_string(i+1) + " : " + n.getEnnemi(i).getNom() + " a " + to_string(n.getEnnemi(i).getPV()) + " PV.";
        affichage.createTexte(str, 24, 640, 616);

        while(true){
            affichage.render();

            SDL_PollEvent(&e);

            if(e.key.keysym.sym == SDLK_ESCAPE || e.type == SDL_QUIT) exit(EXIT_SUCCESS);

            SDL_Delay(3000);
            break;
        }
    }

    affichage.state.buttonEnable = true;
    affichage.state.dialogueEnable = false;
    affichage.state.texteEnable = false;

    affichage.deleteTexte();
}

void infoJoueur(){
    affichage.state.buttonEnable = false;
    affichage.state.dialogueEnable = true;
    affichage.state.texteEnable = true;

    string strPv = to_string(joueur.getPV());
    string strPvMax = to_string(joueur.getPVMax());
    string strForce = to_string(joueur.getForce());
    string strIntelligence = to_string(joueur.getIntelligence());
    string strResistance = to_string(joueur.getResistance());
    string str = " PV : " + strPv + " PV Max : " + strPvMax + " Force : " + strForce + " Intelligence : " + strIntelligence + " Resistance : " + strResistance;

    affichage.deleteTexte();
    affichage.createTexte(str, 16, 640, 616);

    while(true){
        affichage.render();

        SDL_PollEvent(&e);

        if(e.key.keysym.sym == SDLK_RETURN) break;
    }

    affichage.state.buttonEnable = true;
    affichage.state.dialogueEnable = false;
    affichage.state.texteEnable = false;

    affichage.deleteTexte();
}

void recompenseFinCombat(){
    affichage.deleteTexte();
    string str;
    srand(time(NULL));

    int random = rand() % 5;

    if(random == 0){
        str = "Vous gagner 5 PV Max.";
        joueur.updatePVMax(5);
    }

    if(random == 1){
        str = "Vous gagner 5 de Force.";
        joueur.updateForce(5);
    }

    if(random == 2){
        str = "Vous gagner 5 d'intelligence.";
        joueur.updateIntelligence(5);
    }

    if(random == 3){
        str = "Vous gagner 5 de resistance.";
        joueur.updateResistance(5);
    }

    if(random == 4){
        str = "Vous gagner un(e) ";
        srand(time(NULL) + 1);

        int cons = rand() % Consommable::Count;

        if(joueur.getTabConsommable().size() >= 4){
            joueur.getTabConsommable().erase(joueur.getTabConsommable().begin());
        }

        joueur.getTabConsommable().push_back(Consommable(cons));
    }

    affichage.state.backgoundEnable = false;
    affichage.state.buttonEnable = false;
    affichage.state.spriteEnable = false;
    affichage.state.dialogueEnable = false;
    affichage.state.texteEnable = true;

    affichage.deleteTexte();
    affichage.createTexte(str, 64, w / 2, h / 2);

    while(true){
        affichage.render();

        SDL_Delay(3000);

        break;
    }
}

bool combatRoll(Niveau &n){
    affichage.deleteButton();
    int action = 0;
    bool finCombat = false;
    bool aJouer = false;

    affichage.state.backgoundEnable = true;
    affichage.state.buttonEnable = true;
    affichage.state.spriteEnable = true;
    affichage.state.dialogueEnable = false;
    affichage.state.texteEnable = false;

    createTurnStartButton();

    while(!finCombat){
        affichage.render();

        SDL_PollEvent(&e);

        if(e.key.keysym.sym == SDLK_ESCAPE || e.type == SDL_QUIT) exit(EXIT_SUCCESS);
        if(e.type == SDL_MOUSEBUTTONUP && e.button.button == SDL_BUTTON_LEFT){
            if(action == 0){
                action = affichage.buttonIsClicked(&e);
            }
        }

        if(action == 1 && !aJouer){
            int attaque = choixAttaque();
            int ennemi = choixEnnemi();
            affichage.deleteButton();
            string str = niveau.combat->attaque(attaque, ennemi);

            affichage.damageAnimation(ennemi);

            niveau.checkEnnemiStatus(affichage);
            affichage.createTexte(str, 24, 640, 616);
            affichage.state.buttonEnable = false;
            affichage.state.dialogueEnable = true;
            affichage.state.texteEnable = true;
            aJouer = true;

            while(true){
                affichage.render();

                SDL_PollEvent(&e);

                if(e.key.keysym.sym == SDLK_RETURN) break;
            }
        }

        if(action == 2 && !aJouer){
            if(joueur.getTabConsommable().size() <= 0){
                affichage.state.buttonEnable = false;
                affichage.state.dialogueEnable = true;
                affichage.state.texteEnable = true;
                affichage.createTexte("Vous n'avez pas de consommable", 24, 640, 616);
                while(true){
                    affichage.render();

                    SDL_PollEvent(&e);
                    
                    if(e.key.keysym.sym == SDLK_RETURN){
                        affichage.state.buttonEnable = true;
                        affichage.state.dialogueEnable = false;
                        affichage.state.texteEnable = false;
                        affichage.deleteTexte();
                        affichage.deleteButton();
                        createTurnStartButton();
                        action = 0;
                        break;
                    }
                }
            }else{
                int consommable = choixConsommable();
                cout << to_string(consommable) << endl;
                affichage.deleteButton();
                string str = niveau.combat->consommable(consommable);

                affichage.createTexte(str, 24, 640, 616);
                affichage.state.buttonEnable = false;
                affichage.state.dialogueEnable = true;
                affichage.state.texteEnable = true;
                aJouer = true;

                while(true){
                    affichage.render();

                    SDL_PollEvent(&e);
                    if(e.key.keysym.sym == SDLK_RETURN) break;
                }
            }
        }

        if(action == 3){
            infoEnnemi(niveau);
            action = 0;
        }

        if(action == 4){
            infoJoueur();
            action = 0;
        }

        if(aJouer == true && niveau.getTabEnnemi()->size() > 0){
            string str = niveau.combat->tourEnnemi(affichage);
            cout << str << endl;
            affichage.deleteTexte();
            affichage.createTexte(str, 24, 640, 616);

            affichage.render();

            SDL_Delay(1000);

            affichage.state.backgoundEnable = true;
            affichage.state.buttonEnable = true;
            affichage.state.spriteEnable = true;
            affichage.state.dialogueEnable = false;
            affichage.state.texteEnable = false;
            action = 0;
            aJouer = false;

            createTurnStartButton();
        }

        if(niveau.getTabEnnemi()->size() <= 0){
            affichage.state.buttonEnable = false;
            affichage.state.dialogueEnable = true;
            affichage.state.texteEnable = true;
            affichage.createTexte("Combat fini !", 24, 640, 616);
            affichage.render();

            SDL_Delay(2000);

            return true;
        }

        if(joueur.isDead()){
            return false;
        }
    }

    return false;
}

int main(int argc, char const *argv[]){
    affichage.state.backgoundEnable = false;
    affichage.state.buttonEnable = false;
    affichage.state.dialogueEnable = false;
    affichage.state.spriteEnable = false;
    affichage.state.texteEnable = true;

    while(true){
        SDL_PollEvent(&e);
        affichage.createTexte("RandomCombat", 64, 640, 360);

        if(e.key.keysym.sym == SDLK_RETURN){
            affichage.state.backgoundEnable = false;
            affichage.state.buttonEnable = false;
            affichage.state.dialogueEnable = false;
            affichage.state.spriteEnable = false;
            affichage.state.texteEnable = false;
            affichage.deleteTexte();
            break;
        }

        if(e.key.keysym.sym == SDLK_ESCAPE || e.type == SDL_QUIT) exit(EXIT_SUCCESS);

        affichage.render();
    }

    affichage.createButton((1280 / 3) - 100, 335, "Guerrier");
    affichage.createButton(((2 * 1280) / 3) - 100, 335, "Mage");

    while(true){
        SDL_PollEvent(&e);
        affichage.state.buttonEnable = true;

        if(e.key.keysym.sym == SDLK_ESCAPE || e.type == SDL_QUIT) exit(EXIT_SUCCESS);

        if(e.type == SDL_MOUSEBUTTONUP && e.button.button == SDL_BUTTON_LEFT){
            int click = affichage.buttonIsClicked(&e);
            if(click == 1){
                joueur = Personnage(Personnage::GUERRIER);
                break;
            }

            if(click == 2){
                joueur = Personnage(Personnage::MAGE);
                break;
            }
        }

        affichage.render();
    }

    affichage.deleteButton();

    while(true){
        cout << "Nouveau Combat" << endl;
        niveau.nouveauCombat(affichage, joueur);

        bool resCombat = combatRoll(niveau);

        affichage.state.backgoundEnable = false;
        affichage.state.buttonEnable = false;
        affichage.state.spriteEnable = false;
        affichage.state.dialogueEnable = false;
        affichage.state.texteEnable = true;

        if(!resCombat){
            

            affichage.deleteTexte();
            string str = "Vous avez survecu " + to_string(niveau.getNumNiveau()) + " combats...";
            affichage.createTexte(str, 64, w / 2, h / 2);

            while(true){
                affichage.render();
                SDL_Delay(5000);
                break;
            }

            break;
        }

        niveau.levelCleared();

        recompenseFinCombat();

        affichage.deleteTexte();
        string str = "Combat suivant";
        affichage.createTexte(str, 64, w / 2, h / 2);

        while(true){
            affichage.render();
            SDL_Delay(5000);
            break;
        }
    }

    return 0;
}
