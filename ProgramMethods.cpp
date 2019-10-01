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
