#include "winTxt.h"
#include "txtCombat.h"

int main(int argc, char **argv)
{
    termClear();
    Jeu jeu;
    TxtCombat::startCombat(jeu); // Utilisation de la méthode statique
    termClear();
    return 0;
}
