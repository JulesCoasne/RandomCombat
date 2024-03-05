#include "Consommable.h"
#include "../lib/json.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
using json = nlohmann::json;

Consommable::Consommable(){
    nom = "";
    dure = 0;
    pv = 0;
    force = 0;
    resistance = 0;
}

Consommable::Consommable(string n, int d, int p, int f, int r){
    nom = n;
    dure = d;
    pv = p;
    force = f;
    resistance =r;
}

Consommable::~Consommable(){

}

string Consommable::getNom(){
    return nom;
}

int Consommable::getDure(){
    return dure;
}

int Consommable::getPV(){
    return pv;
}

int Consommable::getForce(){
    return force;
}

int Consommable::getResistance(){
    return resistance;
}

void Consommable::genereConsommable(string FileName){
    string FilePath = "data/consommable/" + FileName;

    cout << FilePath << endl;

    ifstream file(FilePath);

    json Doc = json::parse(file);

    nom = {Doc["nom"]};
    dure = {Doc["dure"]};
    pv = {Doc["pv"]};
    force = {Doc["force"]};
    resistance = {Doc["resistance"]};
}