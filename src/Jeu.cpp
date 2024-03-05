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

void Jeu::genereTabCompetence(){
    vector<string> FileName = {"coup_de_poing.json"};

    Competence c;

    for(int i = 0; i < FileName.size(); i++){
        c.genereCompetence(FileName[i]);
    }

    tabCompetence.push_back(c);
}

Consommable Jeu::getConsommable(int index){
    return tabConsommable[index];
}

Competence Jeu::getCompetence(int index){
    return tabCompetence[index];
}

int main(int argc, char const *argv[])
{
    Jeu j;

    cout << j.getConsommable(0).getNom() << endl;
    cout << j.getConsommable(0).getPV() << endl;

    cout << endl;

    cout << j.getCompetence(0).getDegat() << endl;
    cout << j.getCompetence(0).getSoin() << endl;
    return 0;
}
