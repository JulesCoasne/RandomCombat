#ifndef SDLSPRITE_H
#define SDLSPRITE_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <iostream>

class SDLSprite
{
private:
    SDL_Surface *m_surface;
    SDL_Texture *m_texture;

public:
    SDLSprite();
    ~SDLSprite();
    void loadFromFile(const char *filename, SDL_Renderer *renderer);
    void loadFromCurrentSurface(SDL_Renderer *renderer);
    void draw(SDL_Renderer *renderer, int x, int y, int w = -1, int h = -1);
    SDL_Texture *getTexture() const;
    void setSurface(SDL_Surface *surf);
};

#endif
