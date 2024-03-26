#include "SDLJeu.h"

int main(int argc, char *argv[])
{
    SDLJeu jeu;
    jeu.sdlBoucle(); // Cette fonction appelle sdlAff() à l'intérieur de sa boucle
    return 0;
}
