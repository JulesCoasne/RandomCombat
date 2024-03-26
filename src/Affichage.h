#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

struct Sprite
{
    SDL_Texture* texture;
    SDL_Rect descRect;

};


class Affichage {
private:
    int h, w;
    SDL_Window* window;
    SDL_Renderer* renderer;
    std::vector<Sprite> vectSprite;
    
public:
    Affichage();
    ~Affichage();
    bool renderDecor();
    bool renderSprite();
    bool animateSprite();
    bool afficher();
};


