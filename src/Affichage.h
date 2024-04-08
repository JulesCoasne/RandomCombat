#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>
#include <vector>

struct Sprite{
    SDL_Texture* texture;
    SDL_Rect descRect;
};

struct Button{
    std::string nom;
    SDL_Texture* texture;
    SDL_Rect descRect;
};

class Affichage {
private:
    const int h = 720;
    const int w = 1280;
    const int dialogueH = 108;
    const int dialogueW = 1008;

    TTF_Font * font16;
    TTF_Font * font24;
    TTF_Font * font64;

    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture * backgroundTexture;
    SDL_Texture * dialogueTexture;
    std::vector<Sprite> vectSprite;
    std::vector<Button> vectButton;
    
public:
    Affichage();
    ~Affichage();
    bool initAssets();

    void gameStartBG();

    void createBackground();
    void renderBackground();

    void createSprites();
    void renderSprites();

    void createButton();
    void renderButtons();

    void createDialogue();
    void renderDialogue();

    void afficherTexte16(const char * txt);
    void afficherTexteDialogue(const char * txt);
    void afficherTexteTitre(const char * txt);

    int buttonIsClicked(SDL_Event * e);

    void render();
    bool animateSprite();
};


