#include "Jeu.h"

Jeu::Jeu() {

}

int main(int argc, char const *argv[])
{
    Affichage affichage;
    SDL_Event e;

    while(true){
        SDL_PollEvent(&e);

        if(e.key.keysym.sym == SDLK_RETURN) break;
        affichage.gameStartBG();
        affichage.afficherTexteTitre("RandomCombat");
        affichage.render();
    }

    while(true){
        affichage.gameStartBG();
        affichage.createButton(540, 335, "Quit");

        SDL_PollEvent(&e);
        if(e.key.keysym.sym == SDLK_ESCAPE || e.type == SDL_QUIT) break;

        if(e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT){
            if(affichage.buttonIsClicked(&e) == 0) break;
        }
        affichage.render();
    }

    return 0;
}
