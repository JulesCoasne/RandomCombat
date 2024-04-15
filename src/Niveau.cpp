#include "Niveau.h"

using namespace std;

Niveau::Niveau(){
    combat = nullptr;
    numNiveau = 1;
}

Niveau::~Niveau() {
    delete combat;
    combat = nullptr;
}

void Niveau::generateTabEnnemi(){
    int nbEnnemi;

    if(numNiveau <= 2){
        nbEnnemi = rand() % 2 + 1;

        for(int i = 0; i < nbEnnemi; i++){
            srand(time(NULL) + i);

            int ennemi = rand() % ennemiFacile.size();
            tabEnnemi.push_back(Ennemi(ennemiFacile[ennemi]));
        }
    }

    if(numNiveau > 2){
        nbEnnemi = rand() % 3 + 2;

        for(int i = 0; i < nbEnnemi; i++){
            srand(time(NULL) + i);

            int ennemi = rand() % ennemiFacile.size();
            tabEnnemi.push_back(Ennemi(ennemiFacile[ennemi]));
        }
    }
}

void Niveau::createEnnemisSprites(Affichage& affichage){
    affichage.deleteSprites();
    for(size_t i = 0; i < tabEnnemi.size(); i++){
        affichage.createSprites(tabEnnemi[i].getSprite(), i);
    }
}

void Niveau::checkEnnemiStatus(Affichage& affichage){
    for(size_t i = 0; i < tabEnnemi.size(); i++){
        if(tabEnnemi[i].isDead()){
            tabEnnemi.erase(tabEnnemi.begin() + i);
        }
    }

    createEnnemisSprites(affichage);
}

void Niveau::nouveauCombat(Affichage& affichage, Personnage &joueur){
    generateTabEnnemi();
    createEnnemisSprites(affichage);
    combat = new Combat(tabEnnemi, joueur);
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