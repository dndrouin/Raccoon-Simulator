//
// (C) Danielle Drouin 2019 - github.com/dndrouin
//

#include "Raccoon.h"
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>

//raccoon constructors

Raccoon::Raccoon(){
    preset = 2;
    name = "null";
    hunger=50;
    fun=50;
    care=50;
    age=0;

    hyper=false;
    smelly=false;
    dead=false;

    fedToday=false;
    caredToday=false;
    playedToday=false;

}

//adjustor methods for stats
//pass in a number and bool and if bool is true, adds the number to the current stats. otherwise subtracts

void Raccoon::adjustHunger(int num, bool adds){
    if(adds) {
        this->hunger += num;
        //do not let stats go over 100, which is the cap UNLESS raccoon is preset type 1 which has hunger cap set to 200 instead
        if (this->hunger > 100 && this->preset != 1){
            this-> hunger = 100;
        }
        else if(this->hunger > 200 && this->preset == 1){
            this->hunger = 200;
        }
    }
    else{
        this->hunger -= num;
    }
}

void Raccoon::adjustFun(int num, bool adds){
    if(adds) {
        this->fun += num;
        //do not let stats go over 100, which is the cap
        if (this->fun > 100){
            this-> care = 100;
        }
    }
    else{
        this->fun -= num;
    }
}

void Raccoon::adjustCare(int num, bool adds){
    if(adds) {
        this->care += num;
        //do not let stats go over 100, which is the cap
        if (this->care > 100){
            this-> care = 100;
        }
    }
    else{
        this->care -= num;
    }
}

//checkIfDead method, which checks the current stats of the raccoon to see if any are below zero. If they are,
//returns an integer representing what stat had hit zero or below and killed them, or returns zero if alive
int Raccoon::checkIfDead(){
    if(this->hunger == 0 || this->hunger < 0){
        return 1;
    }
    if(this->care == 0 || this->care < 0){
        return 2;
    }
    if(this->fun == 0 || this->fun < 0){
        return 3;
    }
    //raccoon is alive
    return 0;
}


//INVENTORY METHODS

//add an item to the inventory
void Raccoon::addItem(Item currentItem){
        if(currentItem.typeOfItem == 0){
            //item must be cosmetic, therefore is added to the closet
            this->closet.push_back(currentItem);
        }
        if(currentItem.typeOfItem == 1) {
            //item must be food, therefore is added to food inventory
            this->food.push_back(currentItem);
        }
        if(currentItem.typeOfItem == 2){
            //item must be care item, therefore is added to care inventory
            this->cares.push_back(currentItem);
        }
        if(currentItem.typeOfItem == 3) {
            //item must be toy, therefore is added to the play inventory
            this->play.push_back(currentItem);
        }
    }


//lists all of one type of item in inventory
void Raccoon::listItems(int type){
    if(type == 0) {
        //list all cosmetic items (that aren't equipped)
        if(closet.size() == 0){
            //if there's none, inform the user
            std::cout << "No items found.";
        }
        else {
            //otherwise, print their place in inventory and name
            for (int i = 1; i < closet.size(); i++) {
                std::cout << "\t" << i << ". " << closet[i].nameOfItem << "\n";
            }
        }
    }
    if(type == 1) {
        //list all food items
        if(food.size() == 0){
            //if there's none, inform the user
            std::cout << "No items found.";
        }
        else {
            //otherwise, print their place in inventory and name
            for (int i = 1; i < food.size(); i++) {
                std::cout << "\t" << i << ". " << food[i].nameOfItem << "\n";
            }
        }
    }
    if(type == 2) {
        //list all care items
        if(cares.size() == 0){
            //if there's none, inform the user
            std::cout << "No items found.";
        }
        else {
            //otherwise, print their place in inventory and name
            for (int i = 1; i < cares.size(); i++) {
                std::cout << "\t" << i << ". " << cares[i].nameOfItem << "\n";
            }
        }
    }
    if(type == 3) {
        //list all play items
        if(play.size() == 0){
            //if there's none, inform the user
            std::cout << "\nNo items found.\n";
        }
        else {
            //otherwise, print their place in inventory and name
            for (int i = 1; i < play.size(); i++) {
                std::cout << "\t" << i << ". " << play[i].nameOfItem << "\n";
            }
        }
    }
}




