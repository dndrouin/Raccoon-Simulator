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
    //when game first begins, give user 1 granny smith apple, 1 cup of black coffee, 2 bowls of cat food
    //also give 1 brush with 5 uses
    //also give a big red ball with 10 uses
    Item temp = new Item();
    //TODO: why doesn't this work?
}

void populateStore(){
    //when game first begins, generates items for the store to sell

}
