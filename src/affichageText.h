#include "Personnage.h"
#include "Ennemi.h"

class affichageText
{
private:

public:
    affichageText();
    ~affichageText();

    int quitter();
    int debutTour(int nbEnnemi);
    int attaque(const Personnage& joueur);
    void attaqueEnnemi(int degat, Ennemi ennemi);
    int choixEnnemiCombat(vector<Ennemi> tabEnnmi);
    void resumeCombat(string nomEnnemi, int degat, int soin);
    void pvRestant(int pv);
    void infoCombat(vector<Ennemi> tabEnnmi);
    void finDuCombat();
};
