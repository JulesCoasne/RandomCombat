#ifndef SDLSPRITE_H
#define SDLSPRITE_H

#include "/mnt/c/Users/chahed/Desktop/libgraphique/gkit2light/extern/mingw/include/SDL2/SDL.h"
#include "/usr/include/SDL2/SDL_image.h"
#include <iostream>

class SDLSprite
{
private:
    SDL_Surface *m_surface;
    SDL_Texture *m_texture;
    bool m_hasChanged;

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
