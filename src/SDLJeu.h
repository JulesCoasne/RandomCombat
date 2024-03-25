#ifndef SDLJEU_H
#define SDLJEU_H

#include "/mnt/c/Users/chahed/Desktop/libgraphique/gkit2light/extern/mingw/include/SDL2/SDL.h"
#include "/usr/include/SDL2/SDL_ttf.h"
#include "/usr/include/SDL2/SDL_image.h"
#include "/usr/include/SDL2/SDL_mixer.h"
#include <iostream>
#include "Jeu.h"
#include "SDLSprite.h"

class SDLJeu
{
private:
    Jeu jeu;
    SDL_Window *window;
    SDL_Renderer *renderer;
    TTF_Font *font;
    SDLSprite font_im;
    SDL_Color font_color;
    Mix_Chunk *sound;
    bool withSound;
    SDLSprite terrain;

public:
    SDLJeu();
    ~SDLJeu();
    void sdlBoucle();
    void sdlAff();
};

#endif
