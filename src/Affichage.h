#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>

class Affichage {
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
public:
    
    Affichage();
    ~Affichage();
};


