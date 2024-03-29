#include "Jeu.h"

Jeu::Jeu() {

}

int main(int argc, char const *argv[])
{
    Affichage affichage;
    SDL_Event e;

    while(true){
        affichage.afficher();
        if(SDL_PollEvent(&e)){
            if(e.key.keysym.sym == SDLK_ESCAPE){
                break;
            }
        }
    }

    return 0;
}
