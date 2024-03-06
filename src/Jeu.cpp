#include "Jeu.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

Jeu::Jeu(){
    Personnage joueur = Personnage("John Doe");
}

Jeu::~Jeu(){
}

int main(int argc, char const *argv[])
{
    Jeu j;
    return 0;
}
