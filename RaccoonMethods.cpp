//
// (C) Danielle Drouin 2019 - github.com/dndrouin
//

#include <stdlib.h>
#include <iostream>
#include "RaccoonMethods.h"
#include "Raccoon.h"

using namespace std;

void statDecay(Raccoon* pet){

    //method called when user selects to advance to the next day
    //lower all stats by a random number between 40 and 5
    pet->adjustHunger((rand() % 35) + 5, false);
    pet->adjustFun((rand() % 35) + 5, false);
    pet->adjustCare((rand() % 35) + 5, false);

    //increase the raccoon's age by a day
    pet->age++;

    //reset booleans that limit feeding/playing/caring to once a day
    pet->fedToday = false;
    pet->playedToday = false;
    pet->caredToday = false;
}

void raccoonTypesList(){

    //list the available options for raccoons to the user for them to pick
    cout <<"\nHere are the available raccoons:";
    cout <<"\nRaccoon 1:\n\tSex: Male\n\tAppearance: Fat and fluffy, like a giant raccoon-colored cotton ball\n\tPersonality: A lazy slob\n\tBonus: His hunger caps at 200 instead of 100.";
    cout <<"\nRaccoon 2:\n\tSex: Male\n\tAppearance: Small and scraggly with patches of fur missing\n\tPersonality: A bit creepy and probably up to no good\n\tBonus: The first time he dies, he will resurrect himself.";
    cout<<"\nRaccoon 3:\n\tSex: Male\n\tAppearance: Your average raccoon but he's wearing a tiny pair of jeans\n\tPersonality: Just a normal raccoon, nothing to see here\n\tBonus: He comes with free pants.";
}

