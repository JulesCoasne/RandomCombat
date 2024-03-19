#include "Partie.h"

int main(int argc, char const *argv[]){
    Partie partie = Partie(1);
    
    partie.joueur.updateNom("Joueur");

    if(!partie.nouveauNiveau()){
        cout << "Erreur lors du chargement du niveau" << endl;
    }

    partie.niveau->nouveauCombat();

    return 0;
}

