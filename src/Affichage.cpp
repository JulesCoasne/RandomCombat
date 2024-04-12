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

    if(font16 == NULL){
        cout << "Erreur de l'initialisation de font16" << TTF_GetError() << endl;
    }

    font24 = TTF_OpenFont("data/font/runescape_uf.ttf", 24);

    if(font24 == NULL){
        cout << "Erreur de l'initialisation de font24" << TTF_GetError() << endl;
    }

    font64 = TTF_OpenFont("data/font/runescape_uf.ttf", 64);

    if(font64 == NULL){
        cout << "Erreur de l'initialisation de font64" << TTF_GetError() << endl;
    }


    if(font16 == NULL){
        cout << TTF_GetError();
    }

    if(font24 == NULL){
        cout << TTF_GetError();
    }

    if(font64 == NULL){
        cout << TTF_GetError();
    }

    state.backgoundEnable = false;
    state.buttonEnable = false;
    state.spriteEnable = false;
    state.dialogueEnable = false;

    initAssets();
}

Affichage::~Affichage(){
    for(size_t i = 0; i < vectButton.size(); i++){
       SDL_DestroyTexture(vectButton[i].texture);
    }

    for(size_t i = 0; i < vectSprite.size(); i++){
        SDL_DestroyTexture(vectSprite[i].texture);
    }

    SDL_DestroyTexture(backgroundTexture);
    SDL_DestroyTexture(dialogueTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_CloseFont(font16);
    TTF_CloseFont(font24);
    TTF_CloseFont(font64);
    TTF_Quit();
    SDL_Quit();
}

bool Affichage::initAssets(){
    createBackground();
    createDialogue();

    return true;
}

void Affichage::gameStartBG(){
    SDL_Surface * s = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0);
    if(s == NULL){
        cout << "Erreur lors de l'initialisation de la surface startBG" << SDL_GetError() << endl;
    }
    SDL_SetSurfaceBlendMode(s, SDL_BLENDMODE_BLEND);

    SDL_Texture * t = SDL_CreateTextureFromSurface(renderer, s);
    if(t == NULL){
        cout << "Erreur lors de l'initialisation de la texture startBG" << SDL_GetError() << endl;
    }
    

    SDL_RenderCopy(renderer, t, NULL, NULL);
    SDL_FreeSurface(s);
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

void Affichage::createSprites(string path, int place){
    cout << "Chargement du sprite : " << path << endl;
    int l = path.length();
    char * char_sprite = new char[l + 1];
    strcpy(char_sprite, path.c_str());

    Sprite s;
    SDL_Surface *sprite_surf = IMG_Load(char_sprite);
    if(sprite_surf == NULL){cout << "Erreur lors du chargement du sprite" << path << SDL_GetError() << endl;}
    delete [] char_sprite;

    s.texture = SDL_CreateTextureFromSurface(renderer, sprite_surf);
    SDL_FreeSurface(sprite_surf);

    s.descRect.w = sprite_surf->w / 2;
    s.descRect.h = sprite_surf->h / 2;
    s.descRect.x = w / 10;
    s.descRect.y = (place * 130) + 50 ;

    vectSprite.push_back(s);
}

void Affichage::deleteSprites(){
    for(size_t i = 0; i < vectSprite.size(); i++){
       SDL_DestroyTexture(vectSprite[i].texture);
    }
    vectSprite.clear();
}

void Affichage::renderSprites(){
    for(int i = 0; i < vectSprite.size(); i++){
        SDL_RenderCopy(renderer, vectSprite[i].texture, NULL, &vectSprite[i].descRect);
    }
}

void Affichage::createButton(int x, int y, string txt){
    Button b;

    char * c = new char[txt.size() + 1];
    strcpy(c, txt.c_str());

    b.texte = c;
    b.descRect.x = x;
    b.descRect.y = y;
    b.descRect.w = 200;
    b.descRect.h = 50;

    SDL_Surface * surface = SDL_CreateRGBSurface(0, 200, 50, 32, 0, 0, 0, 0);
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 42, 96, 245));

    b.texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    vectButton.push_back(b);
}

void Affichage::deleteButton(){
    for(size_t i = 0; i < vectButton.size(); i++){
       SDL_DestroyTexture(vectButton[i].texture);
    }
    vectButton.clear();
}

void Affichage::renderButtons(){
    for(size_t i = 0; i < vectButton.size(); i++){
        SDL_Surface * surface = TTF_RenderText_Solid(font16, vectButton[i].texte, SDL_Color {255, 255, 255});
        SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, surface);

        SDL_Rect txtRect;
        txtRect.w = surface->w;
        txtRect.h = surface->h;
        txtRect.x = vectButton[i].descRect.x + (vectButton[i].descRect.w - txtRect.w) / 2;
        txtRect.y = vectButton[i].descRect.y + (vectButton[i].descRect.h - txtRect.h) / 2;

        SDL_RenderCopy(renderer, vectButton[i].texture, NULL, &vectButton[i].descRect);
        SDL_RenderCopy(renderer, texture, NULL, &txtRect);

        SDL_FreeSurface(surface);
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

void Affichage::createTexte(string str, int fontSize, int x, int y){
    char * c = new char[str.size() + 1];
    strcpy(c, str.c_str());

    SDL_Surface * surfaceMessage;

    if(fontSize == 16) surfaceMessage = TTF_RenderText_Blended_Wrapped(font16, c, SDL_Color {255, 255, 255}, 968);
    if(fontSize == 24) surfaceMessage = TTF_RenderText_Solid(font24, c, SDL_Color {255, 255, 255});
    if(fontSize == 64) surfaceMessage = TTF_RenderText_Solid(font64, c, SDL_Color {255, 255, 255});

    if(surfaceMessage == NULL) surfaceMessage = TTF_RenderText_Solid(font16, c, SDL_Color {255, 255, 255});

    texte.texture = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
    SDL_FreeSurface(surfaceMessage);

    
    texte.diaRect.w = surfaceMessage->w;
    texte.diaRect.h = surfaceMessage->h;
    texte.diaRect.x = x - (texte.diaRect.w / 2);
    texte.diaRect.y = y - (texte.diaRect.h / 2);
}

void Affichage::deleteTexte(){
    SDL_DestroyTexture(texte.texture);
    texte.texture = NULL;
}

void Affichage::renderTexte(){
    SDL_RenderCopy(renderer, texte.texture, NULL, &texte.diaRect);
}

int Affichage::buttonIsClicked(SDL_Event * e){
    int x = e->motion.x;
    int y = e->motion.y;

    for(int i = 0; i < vectButton.size(); i++){
        SDL_Rect r = vectButton[i].descRect;

        if((x > r.x && x < r.x + r.w) && (y > r.y && y < r.y + r.h)){
            return i + 1;
        }
    }

    return 0;
}

void Affichage::animateSprite(int i){
    int fps = 60;
    int dd = 1000 / 60;

    while(vectSprite[i].descRect.x < w / 2){
        int startLoop = SDL_GetTicks64();

        render();
        vectSprite[i].descRect.x += 20;

        int delta = SDL_GetTicks64() - startLoop;
        if(delta < dd){
            SDL_Delay(dd - delta);
        }
    }

    SDL_Delay(1000);

    while(vectSprite[i].descRect.x >= w / 10){
        int startLoop = SDL_GetTicks64();
        
        render();
        vectSprite[i].descRect.x -= 20;

        int delta = SDL_GetTicks64() - startLoop;
        if(delta < dd){
            SDL_Delay(dd - delta);
        }
    }
}

void Affichage::render(){ 
    if(state.backgoundEnable){
        renderBackground();
    }else{
        gameStartBG();
    }

    if(state.spriteEnable) renderSprites();

    if(state.buttonEnable) renderButtons();

    if(state.dialogueEnable) renderDialogue();

    if(state.texteEnable) renderTexte();

    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);
}
