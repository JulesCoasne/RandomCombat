#include "Affichage.h"

#include <iostream>

using namespace std;

Affichage::Affichage(){
    h = 720;
    w = 1280;

    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        cout << "Erreur initialisation de SDL : " <<   SDL_GetError() << endl;
    }

    window = SDL_CreateWindow("Random Combat", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_FULLSCREEN);
    if(window == NULL){
        cout << "Erreur initialisation de la fenêtre : " << SDL_GetError() << endl;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == NULL){
        cout << "Erreur initialisation renderer : " << SDL_GetError() << endl;
    }
}

Affichage::~Affichage(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

bool Affichage::renderDecor(){
    SDL_Surface *background_surface = IMG_Load("data/bg/background.png");
    if(background_surface == NULL){
        cout << "Erreur chargement du terrain" << SDL_GetError() << endl;
        return false;
    }

    SDL_Texture *background_texture = SDL_CreateTextureFromSurface(renderer, background_surface);
    SDL_FreeSurface(background_surface);

    SDL_Rect destRect;
    destRect.w = w;
    destRect.h = h;
    destRect.x = 0;
    destRect.y = 0;

    SDL_RenderCopy(renderer, background_texture, NULL, &destRect);

    return true;
}

bool Affichage::renderSprite(){
    Sprite s;
    SDL_Surface *sprite_surf = IMG_Load("data/sprite/squelette.png");

    s.texture = SDL_CreateTextureFromSurface(renderer, sprite_surf);
    SDL_FreeSurface(sprite_surf);

    s.descRect.w = sprite_surf->w / 2;
    s.descRect.h = sprite_surf->h / 2;
    s.descRect.x = w / 10;
    s.descRect.y = (9 * h / 10 ) - s.descRect.h;

    vectSprite.push_back(s);
    SDL_RenderCopy(renderer, s.texture, NULL, &s.descRect);

    return true;
}

bool Affichage::animateSprite(){
    Sprite * s = &vectSprite[0];
    
    s->descRect.x += 2;

    SDL_RenderCopy(renderer, s->texture, NULL, &s->descRect);
}

bool Affichage::afficher(){
    SDL_RenderClear(renderer);
    renderDecor();
    animateSprite();
    SDL_RenderPresent(renderer);
    return true;
}