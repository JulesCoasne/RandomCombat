#include "Jeu.h"

Jeu::Jeu() {

}

int main(int argc, char const *argv[])
{
    SDLJeu jeu;
    jeu.sdlBoucle(); // Cette fonction appelle sdlAff() à l'intérieur de sa boucle
    return 0;
}
