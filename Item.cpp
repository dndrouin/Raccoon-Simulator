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
    nameOfItem = "Granny Smith Apple";
    changeInStats = 10;
    description = "A large, bright green, tart apple perfect for baking a pie with.";
}

//more specific item constructor for use in game
Item::Item(int itemType, int statValue, int numUses, std::string name, std::string itemDescription){
    equipped = false;
    changeInStats = statValue;
    typeOfItem = itemType;
    nameOfItem = name;
    uses = numUses;
    description = itemDescription;
}

void inspectItem(Item selected){
//shows item name, description, and gives user the option to use the item or return to the item list
}


//useItem method which uses an item and deletes it afterwards
void useItem(Item selected, Raccoon& yourPet){
    bool validResponse = false;
    std::string response;
    if(selected.typeOfItem == 0){
        //item must be cosmetic. ask user if they would like to equip it to their raccoon
    }
    if(selected.typeOfItem == 1){
        //item must be food. ask user if they would like to feed it to their raccoon
        while(!validResponse) {
            std::cout << "Would you like to feed this " << selected.nameOfItem << " to " << yourPet->name << "? Y/N";
            std::cin >> response;
            //user must give either Y or N as response otherwise it will keep asking them for one, Y or N turns validResponse true so they can exit the loop
            if (response.compare("Y") == 0) {
                //item is fed to the raccoon, if item has multiple uses, uses decrease. if uses hits 0, deconstructor is called and item is deleted
                if (selected.uses > 1) {
                    selected.uses--;
                } else {
                    //item deconstructor called because item has no uses left
                    //TODO: call deconstructor and delete item if it runs out of uses
                    //TODO: actually make the deconstructor first

                }
                //raccoon has been fed today, so bool fedToday turns to true and prevents user from feeding pet again
                yourPet.fedToday = true;
                validResponse = true;
            } else if (response.compare("N") == 0) {
                    //do nothing? test out what happens first
                    std::cout << "Returning to inventory.";
                    validResponse = true;
                }
        }

    }
    if(selected.typeOfItem == 2){
        //item must be a toy. ask user if they would like to use it to play with their raccoon
    }
    if(selected.typeOfItem == 3){
        //item must be for care. ask user if they would like to use it to care for their raccoon.
    }
}

void giveStarterItems(Raccoon* startPet){
    //when game first begins, give user 1 granny smith apple, 1 cup of black coffee, 2 bowls of cat food
    //also give 1 brush with 5 uses
    //also give
}