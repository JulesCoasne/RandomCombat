#include "Niveau.h"

using namespace std;

Niveau::Niveau(){
    combat = nullptr;
    numNiveau = 1;
    nbEnnemi = 0;
}

Niveau::~Niveau() {
    delete combat;
    combat = nullptr;
}

void Niveau::generateTabEnnemi(){
    srand(time(NULL));

    if(numNiveau <= 2){
        nbEnnemi = rand() % 2 + 1;

        for(int i = 0; i < nbEnnemi; i++){
            srand(time(NULL));

            int ennemi = rand() % 3;
            tabEnnemi.push_back(Ennemi(ennemiFacile[ennemi]));
        }
    }

    if(numNiveau > 2){
        nbEnnemi = rand() % 4 + 2;

        for(int i = 0; i < nbEnnemi; i++){
            srand(time(NULL));

            int ennemi = rand() % 3;
            tabEnnemi.push_back(Ennemi(ennemiFacile[ennemi]));
        }
    }
}

void Niveau::checkEnnemiStatus(Affichage& affichage){
    affichage.deleteSprites();

    for(size_t i = 0; i < tabEnnemi.size(); i++){
        if(tabEnnemi[i].isDead() == false){
            affichage.createSprites(tabEnnemi[i].getSprite(), i);
        }else{
            nbEnnemi--;
        }
    }
}

void Niveau::nouveauCombat(Affichage& affichage, Personnage &joueur){
    affichage.deleteSprites();
    generateTabEnnemi();
    combat = new Combat(tabEnnemi, joueur);
    for(size_t i = 0; i < tabEnnemi.size(); i++){
        affichage.createSprites(tabEnnemi[i].getSprite(), i);
    }
}

void Niveau::levelCleared(){
    numNiveau++;
    tabEnnemi.clear();
}

int Niveau::getNumNiveau(){
    return numNiveau;
}

vector<Ennemi> * Niveau::getTabEnnemi(){
    return &tabEnnemi;
}

Ennemi Niveau::getEnnemi(int i){
    return tabEnnemi[i];
}

int Niveau::getNbEnnemi(){
    return nbEnnemi;
}