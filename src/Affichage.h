#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

struct Sprite{
    SDL_Texture* texture;
    SDL_Rect descRect;
};

struct Button{
    char * texte;
    SDL_Texture* texture;
    SDL_Rect descRect;
};

struct Texte{
    SDL_Texture * texture;
    SDL_Rect diaRect;
};

struct stateManagerAffichage{
    bool backgoundEnable;
    bool buttonEnable;
    bool spriteEnable;
    bool dialogueEnable;
    bool texteEnable;
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

    Texte texte;
    
public:
    stateManagerAffichage state;

    Affichage();
    ~Affichage();
    bool initAssets();

    void gameStartBG();

    void createBackground();
    void renderBackground();

    void createSprites(string path, int place);
    void deleteSprites();
    void renderSprites();

    void createButton(int x, int y, string txt);
    void deleteButton();
    void renderButtons();

    void createDialogue();
    void renderDialogue();

    void createTexte(string str, int fontSize, int x, int y);
    void deleteTexte();
    void renderTexte();

    int buttonIsClicked(SDL_Event * e);

    void render();

    void attackAnimation(int i);
    void damageAnimation(int i);
};


