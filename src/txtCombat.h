#ifndef TXTCOMBAT_H
#define TXTCOMBAT_H

#include "Jeu.h"
#include "winTxt.h"

class TxtCombat {
public:
    static void txtAff(WinTXT &win, const Jeu &jeu);
    static void startCombat(Jeu &jeu);
};

#endif // TXTCOMBAT_H
