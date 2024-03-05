#include "Jeu.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

Jeu::Jeu(){
    genereTabConsommable();
}

Jeu::~Jeu(){
}

void Jeu::genereTabConsommable(){
    vector<string> FileName = {"potion.json"};

    Consommable c;

    for(int i = 0; i < FileName.size(); i++){
        c.genereConsommable(FileName[i]);
    }

    tabConsommable.push_back(c);
}

Consommable Jeu::getConsommable(int index){
    return tabConsommable[index];
}

int main(int argc, char const *argv[])
{
    Jeu j;

    cout << j.getConsommable(0).getNom() << endl;
    cout << j.getConsommable(0).getPV() << endl;
    return 0;
}
