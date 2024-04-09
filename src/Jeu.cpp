#include "Jeu.h"

Jeu::Jeu() {

}

int main(int argc, char const *argv[])
{
    bool start = false;
    bool nvPartie = false;
    int classe = 0;
    Partie * p;
    Affichage * affichage;
    SDL_Event e;

    affichage->createButton(540, 335, "Nouvelle Partie");

    while(!nvPartie){
        SDL_PollEvent(&e);
        affichage->gameStartBG();

        if(start == false){
            affichage->afficherTexteTitre("RandomCombat");
            if(e.key.keysym.sym == SDLK_RETURN) start = true;
        }else{
            affichage->renderButtons();
            if(e.type == SDL_MOUSEBUTTONUP && e.button.button == SDL_BUTTON_LEFT){
                if(affichage->buttonIsClicked(&e) == 0){
                    p->nouvellePartie(affichage);
                    return 0;
                }
            }
        }

        if(e.key.keysym.sym == SDLK_ESCAPE || e.type == SDL_QUIT) return 0;

        
        affichage->render();
    }


    

    return 0;
}
