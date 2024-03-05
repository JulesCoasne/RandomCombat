#include "Consommable.h"
#include "../lib/json.hpp"
#include <iostream>
#include <fstream>

using json = nlohmann::json;
using namespace std;

Consommable::Consommable(){
    dure = 0;
    pv = 0;
    force = 0;
    resistance = 0;
}

void Consommable::genereConsommable(vector<Consommable> * v){
    vector<string> FileName = {"potion.json"};
    string FilePath = "../data/consommable";

    for(int i = 0; i < FileName.size(); i++){
        fstream f;
    }
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