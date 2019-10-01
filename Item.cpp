//
// (C) Danielle Drouin 2019 - github.com/dndrouin
//

#include "Item.h"
#include "Raccoon.h"
#include <iostream>

//default item constructor, shouldn't ever be actually used, just to test item creation and inventory
Item::Item(){
    equipped = false;
    typeOfItem = 1;
    nameOfItem = "Apple";
    changeInStats = 10;

}

//more specific item constructor for use in game
Item::Item(int itemType, int statValue, std::string name){
    equipped = false;
    changeInStats = statValue;
    typeOfItem = itemType;
    nameOfItem = name;
}

//useItem method which uses an item and deletes it afterwards
void useItem(Item selected, Raccoon* yourPet){
    std::string response;
    if(selected.typeOfItem == 0){
        //item must be cosmetic. ask user if they would like to equip it to their raccoon
    }
    if(selected.typeOfItem == 1){
        //item must be food. ask user if they would like to feed it to their raccoon
        std::cout << "Would you like to feed this " << selected.nameOfItem << " to " << yourPet->name << "? Y/N";
        std::cin >> response;
        if(response.compare("Y") == 0){
            //item is fed to the raccoon and deleted using deconstructor
            //raccoon has been fed today, so bool fedToday turns to true and prevents user from feeding pet again
            yourPet->fedToday = true;
        }
        else if(response.compare("N") == 0){

        }
        else{
            //TODO: prevent user from giving responses besides Y or N
        }

    }
    if(selected.typeOfItem == 2){
        //item must be a toy. ask user if they would like to use it to play with their raccoon
    }
    if(selected.typeOfItem == 3){
        //item must be for care. ask user if they would like to use it to care for their raccoon.
    }
}