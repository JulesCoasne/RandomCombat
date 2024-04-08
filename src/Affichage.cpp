#include "Affichage.h"

#include <iostream>

using namespace std;

Affichage::Affichage(){
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        cout << "Erreur initialisation de SDL : " <<   SDL_GetError() << endl;
    }

    window = SDL_CreateWindow("Random Combat", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, 0);
    if(window == NULL){
        cout << "Erreur initialisation de la fenêtre : " << SDL_GetError() << endl;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == NULL){
        cout << "Erreur initialisation renderer : " << SDL_GetError() << endl;
    }

    if(TTF_Init() == -1){
        cout << TTF_GetError() << endl;
    }

    font16 = TTF_OpenFont("data/font/runescape_uf.ttf", 16);
    font24 = TTF_OpenFont("data/font/runescape_uf.ttf", 24);
    font64 = TTF_OpenFont("data/font/runescape_uf.ttf", 64);

    if(font16 == NULL){
        cout << TTF_GetError();
    }

    if(font24 == NULL){
        cout << TTF_GetError();
    }

    if(font64 == NULL){
        cout << TTF_GetError();
    }

    initAssets();
}

Affichage::~Affichage(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
}

bool Affichage::initAssets(){
    createBackground();
    createDialogue();
    createSprites();
    createButton();

    return true;
}

void Affichage::gameStartBG(){
    SDL_Surface * s = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0);
    SDL_SetSurfaceBlendMode(s, SDL_BLENDMODE_BLEND);
    SDL_Texture * t = SDL_CreateTextureFromSurface(renderer, s);
    SDL_FreeSurface(s);

    SDL_RenderCopy(renderer, t, NULL, NULL);
}

void Affichage::createBackground(){
    SDL_Surface *background_surface = IMG_Load("data/bg/background.png");
    if(background_surface == NULL){
        cout << "Erreur chargement du terrain" << SDL_GetError() << endl;
    }

    backgroundTexture = SDL_CreateTextureFromSurface(renderer, background_surface);
    SDL_FreeSurface(background_surface);
}

void Affichage::renderBackground(){
    SDL_Rect descRect;

    descRect.w = w;
    descRect.h = h;
    descRect.x = 0;
    descRect.y = 0;

    SDL_RenderCopy(renderer, backgroundTexture, NULL, &descRect);
}

void Affichage::createSprites(){
    Sprite s;
    SDL_Surface *sprite_surf = IMG_Load("data/sprite/squelette.png");

    s.texture = SDL_CreateTextureFromSurface(renderer, sprite_surf);
    SDL_FreeSurface(sprite_surf);

    s.descRect.w = sprite_surf->w / 2;
    s.descRect.h = sprite_surf->h / 2;
    s.descRect.x = w / 10;
    s.descRect.y = (7 * h / 10 ) - s.descRect.h;

    vectSprite.push_back(s);
}

void Affichage::renderSprites(){
    for(int i = 0; i < vectSprite.size(); i++){
        SDL_RenderCopy(renderer, vectSprite[i].texture, NULL, &vectSprite[i].descRect);
    }
}

void Affichage::createButton(){
    Button b;
    SDL_Surface * ButtonSurface = IMG_Load("data/HUD/button_attaque.png");

    b.texture = SDL_CreateTextureFromSurface(renderer, ButtonSurface);
    SDL_FreeSurface(ButtonSurface);

    b.descRect.w = ButtonSurface->w;
    b.descRect.h = ButtonSurface->h;
    b.descRect.x = w / 4;
    b.descRect.y = h / 10;

    b.nom = "attaque";

    vectButton.push_back(b);
}

void Affichage::renderButtons(){
    for(int i = 0; i < vectButton.size(); i++){
        SDL_RenderCopy(renderer, vectButton[i].texture, NULL, &vectButton[i].descRect);
    }
}

void Affichage::createDialogue(){
    SDL_Surface * surface = IMG_Load("data/HUD/text_space.png");
    dialogueTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
}

void Affichage::renderDialogue(){
    SDL_Rect descRect;
    descRect.h = dialogueH;
    descRect.w = dialogueW;
    descRect.x = w - 1144;
    descRect.y = h - 158;

    SDL_RenderCopy(renderer, dialogueTexture, NULL, &descRect);
}

void Affichage::afficherTexteDialogue(const char * txt){
    SDL_Surface * surfaceMessage = TTF_RenderText_Solid(font24, txt, SDL_Color {255, 255, 255});
    SDL_Texture * message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
    SDL_FreeSurface(surfaceMessage);

    SDL_Rect message_rect;
    message_rect.w = surfaceMessage->w;
    message_rect.h = surfaceMessage->h;
    message_rect.x = (w - 1144) + 20;
    message_rect.y = (h - 158) + 20;

    SDL_RenderCopy(renderer, message, NULL, &message_rect);
}

void Affichage::afficherTexteTitre(const char * txt){
    SDL_Surface * surfaceMessage = TTF_RenderText_Solid(font64, txt, SDL_Color {255, 255, 255});
    SDL_Texture * message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
    SDL_FreeSurface(surfaceMessage);

    SDL_Rect message_rect;
    message_rect.w = surfaceMessage->w;
    message_rect.h = surfaceMessage->h;
    message_rect.x = (w / 2) - (message_rect.w / 2);
    message_rect.y = (h / 2) - (message_rect.h / 2);

    SDL_RenderCopy(renderer, message, NULL, &message_rect);
}

int Affichage::buttonIsClicked(SDL_Event * e){
    int x = e->motion.x;
    int y = e->motion.y;

    for(int i = 0; i < vectButton.size(); i++){
        SDL_Rect r = vectButton[i].descRect;

        if((x > r.x && x < r.x + r.w) && (y > r.y && y < r.y + r.h)){
            if(vectButton[i].nom == "attaque") return 1;
            if(vectButton[i].nom == "consommable") return 2;
            if(vectButton[i].nom == "ennemi") return 3;
            if(vectButton[i].nom == "abandonner") return 4;
        }
    }

    return 0;
}

bool Affichage::animateSprite(){
    vectSprite[0].descRect.x += 20;
    return true;
}

void Affichage::render(){    
    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);
}
