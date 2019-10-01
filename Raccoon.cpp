//
// (C) Danielle Drouin 2019 - github.com/dndrouin
//

#include "Raccoon.h"
#include <stdlib.h>
#include <string>

//raccoon constructors

Raccoon::Raccoon(){
    preset = 2;
    name = "null";
    hunger=50;
    fun=50;
    care=50;

    hyper=false;
    smelly=false;
    dead=false;

}

//adjustor methods for stats
//pass in a number and bool and if bool is true, adds the number to the current stats. otherwise subtracts

void Raccoon::adjustHunger(int num, bool adds){
    if(adds) {
        this->hunger += num;
    }
    else{
        this->hunger -= num;
    }
}

void Raccoon::adjustFun(int num, bool adds){
    if(adds) {
        this->fun += num;
    }
    else{
        this->fun -= num;
    }
}

void Raccoon::adjustCare(int num, bool adds){
    if(adds) {
        this->care += num;
    }
    else{
        this->care -= num;
    }
}

//checkIfDead method, which checks the current stats of the raccoon to see if any are below zero. If they are, it sets dead to true.
bool Raccoon::checkIfDead(){

}





