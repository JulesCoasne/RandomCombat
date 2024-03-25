#include "SDLSprite.h"

SDLSprite::SDLSprite() : m_surface(nullptr), m_texture(nullptr), m_hasChanged(false)
{
}

SDLSprite::~SDLSprite()
{
    SDL_FreeSurface(m_surface);
    SDL_DestroyTexture(m_texture);
    m_surface = nullptr;
    m_texture = nullptr;
    m_hasChanged = false;
}

void SDLSprite::loadFromFile(const char *filename, SDL_Renderer *renderer)
{
    m_surface = IMG_Load(filename);
    if (!m_surface)
    {
        std::cerr << "Erreur lors du chargement de l'image : " << filename << " : " << IMG_GetError() << std::endl;
        exit(1);
    }

    m_texture = SDL_CreateTextureFromSurface(renderer, m_surface);
    if (!m_texture)
    {
        std::cerr << "Erreur lors de la création de la texture : " << SDL_GetError() << std::endl;
        SDL_FreeSurface(m_surface);
        exit(1);
    }
}

void SDLSprite::loadFromCurrentSurface(SDL_Renderer *renderer)
{
    if (!m_surface)
    {
        std::cerr << "Aucune surface à charger pour la texture." << std::endl;
        return;
    }

    m_texture = SDL_CreateTextureFromSurface(renderer, m_surface);
    if (!m_texture)
    {
        std::cerr << "Erreur lors de la création de la texture : " << SDL_GetError() << std::endl;
        SDL_FreeSurface(m_surface);
        exit(1);
    }
}

void SDLSprite::draw(SDL_Renderer *renderer, int x, int y, int w, int h)
{
    if (!m_texture)
    {
        std::cerr << "Aucune texture à dessiner." << std::endl;
        return;
    }

    SDL_Rect destRect = {x, y, w, h};
    SDL_RenderCopy(renderer, m_texture, NULL, &destRect);
}

SDL_Texture *SDLSprite::getTexture() const
{
    return m_texture;
}

void SDLSprite::setSurface(SDL_Surface *surf)
{
    m_surface = surf;
}
