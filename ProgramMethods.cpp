//
// Created by Danielle D on 9/30/2019.
//

#include "ProgramMethods.h"
#include <fstream>
#include "Raccoon.h"

//saves the game data in save.txt file in a way that can be read when loading it at the start of the game
void saveGame(Raccoon* pet){
    std::fstream saveFile;
    saveFile.open("save.txt", std::ios_base::out);
    saveFile << pet->preset << "#"<< pet->name << "#" << pet->hunger << "#" << pet->fun << "#" << pet->care << "#" << pet->hyper << "#" << pet->smelly << "#" << pet->dead << "#" << pet->age << "#";
    saveFile.close();
};


void giveStarterItems(Raccoon* startPet){
    //when game first begins, give them some items to start out with
    //create temporary item to contain the new items
    Item temp;
    startPet->addItem(temp);
    // change temp to be cup of black coffee
    temp.nameOfItem = "Cup of Black Coffee";
    temp.changeInStats = 5;
    temp.description = "A cup of extremely bitter black coffee. Probably not good for Raccoons.";
    startPet->addItem(temp);
    //change temp to be bowl of cat food
    temp.nameOfItem = "Bowl of Cat Food";
    temp.changeInStats = 25;
    temp.description = "Smells like it might be chicken flavored.";\
    //add to inventory twice
    startPet->addItem(temp);
    startPet->addItem(temp);
    //change temp to be red brush
    temp.nameOfItem = "Red Brush";
    temp.description = "Made of plastic and full of old Raccoon hair.";
    temp.typeOfItem = 3;
    temp.uses = 5;
    startPet->addItem(temp);
    temp.nameOfItem = "Rainbow Bouncy Ball";
    temp.description = "So many colors! So bouncy!";
    temp.typeOfItem = 2;
    temp.uses = 10;
    startPet->addItem(temp);




}

void populateStore(){
    //when game first begins, generates items for the store to sell

}
