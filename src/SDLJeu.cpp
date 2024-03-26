#include "SDLJeu.h"

SDLJeu::SDLJeu() : jeu(), font(nullptr), sound(nullptr), withSound(true)
{
    // Initialisation de la SDL (à adapter selon vos besoins)
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << std::endl;
        SDL_Quit();
        exit(1);
    }

    // Création de la fenêtre (à adapter selon vos besoins)
    window = SDL_CreateWindow("Random Combat", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    if (!window)
    {
        std::cerr << "Erreur lors de la création de la fenêtre : " << SDL_GetError() << std::endl;
        SDL_Quit();
        exit(1);
    }

    // Création du renderer (à adapter selon vos besoins)
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        std::cerr << "Erreur lors de la création du renderer : " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        exit(1);
    }

    // Chargement de l'image du terrain
    terrain.loadFromFile("data/terrain.jfif", renderer);

    // Autres initialisations...
}

SDLJeu::~SDLJeu()
{
    // Libération des ressources (à adapter selon vos besoins)
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void SDLJeu::sdlBoucle()
{
    // Boucle principale (à adapter selon vos besoins)
    bool quit = false;
    SDL_Event event;
    while (!quit)
    {
        // Gestion des événements (à adapter selon vos besoins)
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                quit = true;
        }

        // Affichage du terrain (à adapter selon vos besoins)
        sdlAff();

        // Mettre à jour l'écran (à adapter selon vos besoins)
        SDL_RenderPresent(renderer);
    }
}

void SDLJeu::sdlAff()
{
    // Effacer l'écran (à adapter selon vos besoins)
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Affichage du terrain (à adapter selon vos besoins)
    terrain.draw(renderer, 0, 0); // Affichage du terrain aux coordonnées (0, 0)

    // Autres éléments à afficher...
}
