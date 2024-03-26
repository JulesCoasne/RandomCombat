#include "Affichage.h"

#include <iostream>

using namespace std;

Affichage::Affichage(){
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        cout << "Erreur initialisation de SDL : " <<   SDL_GetError() << endl;
    }

    window = SDL_CreateWindow("Random Combat", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_FULLSCREEN);
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
