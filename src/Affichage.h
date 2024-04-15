#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

/**
 * @struct Sprite
 * @brief struct servant à gérer les sprites des personnages.
*/
struct Sprite{
    SDL_Texture* texture;   ///< gère la texture du sprite.
    SDL_Rect descRect;  ///< gère la position et taille du sprite.
};


/**
 * @struct Button
 * @brief struct servant à gérer les buttons à afficher.
*/
struct Button{
    char * texte;   ///< gère le texte sur le boutton.
    SDL_Texture* texture;   ///< gère la texture (la couleur) du boutton.
    SDL_Rect descRect;  ///< gère la position et taille du boutton.
};

/**
 * @struct Texte
 * @brief struct servant à gérer les textes à afficher (dialogue, titre, ...).
*/
struct Texte{
    SDL_Texture * texture;  ///< gère la texture du texte créer par SDL_ttf.
    SDL_Rect diaRect;   ///< gère la taille de la boite de texte et de sa position.
};

/**
 * @struct stateManagerAffichage
 * @brief gère ce qui doit être afficher ou non à l'écran par le renderer.
*/
struct stateManagerAffichage{
    bool backgoundEnable;   ///< gère si le background doit être affiché.
    bool buttonEnable;  ///< gère si les bouttons doivent être affiché.
    bool spriteEnable;  ///< gère si les sprites doivent être affiché.
    bool dialogueEnable;    ///< gère si la boite de dialogue doit être affiché.
    bool texteEnable;   ///< gère si les boites de texte (hors bouttons) doivent être affiché.
};

/**
 * @class Affichage
 * @brief Classe gèrant l'affichage graphique en utilisant SDL2
*/
class Affichage {
private:
    const int h = 720;  ///< hauteur de la fenêtre.
    const int w = 1280; ///< largeur de la fenêtre.
    const int dialogueH = 108;  ///< hauteur de la boite de dialogue.
    const int dialogueW = 1008; ///< largeur de la boite de dialogue.

    TTF_Font * font16;  ///< pointeur vers un TTF de 16pt.
    TTF_Font * font24;  ///< pointeur vers un TTF de 24pt.
    TTF_Font * font64;  ///< pointeur vers un TTF de 64pt.

    SDL_Window* window; ///< pointeur SDL_Window vers la fenêtre.
    SDL_Renderer* renderer; ///< pointeur SDL_Renderer vers le renderer SDL.
    SDL_Texture * backgroundTexture;    ///< pointeur vers la texture du background.
    SDL_Texture * dialogueTexture;  ///< pointeur vers la texture de la boite de dialogue.
    std::vector<Sprite> vectSprite; ///< vecteur de tous les sprites à afficher.
    std::vector<Button> vectButton; ///< vecteur de tous les bouttons à afficher.

    Texte texte;    ///< Texte à afficher.
    
public:
    stateManagerAffichage state;    ///< State manager des éléments à afficher (True pour afficher, false sinon)

    /**
     * @brief Constructeur de la classe affichage, initialise SDL2 ainsi que certain assets
    */
    Affichage();

    /**
     * @brief Destructeur de la classe affichage, ferme SDL
    */
    ~Affichage();

    /**
     * @brief initialiseur de certains assets (comme le fond ou la boite de dialogue)
     * @return True si l'initialisation c'est effectué sans erreur, false sinon
    */
    bool initAssets();


    /**
     * @brief créer et affiche un fond noir
    */
    void gameStartBG();

    /**
     * @brief créer le fond des niveaux
    */
    void createBackground();

    /**
     * @brief affiche le fond des niveaux
    */
    void renderBackground();


    /**
     * @brief rempli vectSprite avec les sprites
     * 
     * @param path path vers le sprite à charger
     * @param place position du sprite sur la colonne des ennemies
    */
    void createSprites(string path, int place); 

    /**
     * @brief vide le vectSprite
    */
    void deleteSprites();

    /**
     * @brief affiche les sprites
    */
    void renderSprites();


    /**
     * @brief rempli vectButton des bouttons à afficher
     * 
     * @param x position x du boutton
     * @param y position y du boutton
     * @param txt libellé du boutton
    */
    void createButton(int x, int y, string txt);

    /**
     * @brief vide le vectButton
    */
    void deleteButton();

    /**
     * @brief affiche les bouttons
    */
    void renderButtons();


    /**
     * @brief créer la boite de dialogue
    */
    void createDialogue();

    /**
     * @brief affiche la boite de dialogue
    */
    void renderDialogue();


    /**
     * @brief Créer le texte à afficher
     * 
     * @param str contenu du texte
     * @param fontSize taille de la police
     * @param x position x du texte
     * @param y position y du texte
    */
    void createTexte(string str, int fontSize, int x, int y);

    /**
     * @brief supprime le texte
    */
    void deleteTexte();

    /**
     * @brief affiche le texte
    */
    void renderTexte();


    /**
     * @brief Lors d'un clique gauche de la souris, vérifie si un boutton a été cliqué
     * 
     * @param e pointeur vers le SDL_Event dans lequel le clique est enregistrer
     * @return Un int représentant le bouton cliqué
    */
    int buttonIsClicked(SDL_Event * e);


    /**
     * @brief affiche tous les éléments dans le render copy suivant le state manager
    */
    void render();


    /**
     * @brief lance l'animation d'attaque de l'ennemi
     * 
     * @param i index du sprite l'ennemi qui attaque
    */
    void attackAnimation(int i);

    /**
     * @brief lance l'animation de dégat de l'ennemi
     * 
     * @param i index du sprite l'ennemi qui prend des dégats
    */
    void damageAnimation(int i);
};


