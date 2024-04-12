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
        for(size_t i = 0; i < length; i++){
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
        for(size_t i = 0; i < length; i++){
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

bool createTurnStartButton(){
    affichage.createButton(415, 520, "Attaque");
    affichage.createButton(655, 520, "Consommable");
    affichage.createButton(415, 620, "Ennemi");
    affichage.createButton(655, 620, "Abandonner");
    return true;
}

bool combatRoll(Niveau &n){
    affichage.deleteButton();
    int attaque, ennemi;
    int action = 0;
    bool finCombat = false;
    bool attaqueChoisi = false;
    bool ennemiChoisi = false;
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

        if(e.key.keysym.sym == SDLK_ESCAPE || e.type == SDL_QUIT) break;
        if(e.type == SDL_MOUSEBUTTONUP && e.button.button == SDL_BUTTON_LEFT){
            if(action == 0){
                action = affichage.buttonIsClicked(&e);
            }
        }

        if(action == 1 && !aJouer){
            attaque = choixAttaque();
            ennemi = choixEnnemi();
            affichage.deleteButton();
            string str = niveau.combat->attaque(attaque, ennemi);
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

        if(aJouer == true && niveau.getNbEnnemi() > 0){
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
            attaqueChoisi = false;
            ennemiChoisi = false;
            aJouer = false;

            createTurnStartButton();
        }

        if(niveau.getNbEnnemi() == 0){
            affichage.state.buttonEnable = false;
            affichage.state.dialogueEnable = true;
            affichage.state.texteEnable = true;
            affichage.createTexte("Combat fini !", 24, 640, 616);
            affichage.render();

            SDL_Delay(2000);

            affichage.state.backgoundEnable = false;
            affichage.state.buttonEnable = false;
            affichage.state.spriteEnable = false;
            affichage.state.dialogueEnable = false;
            affichage.state.texteEnable = false;
            
            return true;
        }

        if(joueur.isDead()){
            return false;
        }
    }
}

int main(int argc, char const *argv[]){

    while(true){
        SDL_PollEvent(&e);
        affichage.createTexte("RandomCombat", 64, 640, 360);

        if(e.key.keysym.sym == SDLK_RETURN){
            break;
        }

        if(e.key.keysym.sym == SDLK_ESCAPE || e.type == SDL_QUIT) return 0;

        affichage.render();
    }

    affichage.createButton((1280 / 3) - 100, 335, "Guerrier");
    affichage.createButton(((2 * 1280) / 3) - 100, 335, "Mage");

    while(true){
        SDL_PollEvent(&e);
        affichage.state.buttonEnable = true;

        if(e.key.keysym.sym == SDLK_ESCAPE || e.type == SDL_QUIT) return 0;

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
        niveau.nouveauCombat(affichage, joueur);

        if(!combatRoll(niveau)){
            affichage.state.backgoundEnable = false;
            affichage.state.buttonEnable = false;
            affichage.state.spriteEnable = false;
            affichage.state.dialogueEnable = false;
            affichage.state.texteEnable = true;

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

        affichage.state.backgoundEnable = false;
        affichage.state.buttonEnable = false;
        affichage.state.spriteEnable = false;
        affichage.state.dialogueEnable = false;
        affichage.state.texteEnable = true;

        affichage.deleteTexte();
        string str = "Combat suivant";
        affichage.createTexte(str, 64, w / 2, h / 2);

        affichage.render();

        SDL_Delay(5000);
    }

    return 0;
}
