//
// (C) Danielle Drouin 2019 - github.com/dndrouin
//

#include <string>
#include "Item.h"
#include "Raccoon.h"

//default item constructor, shouldn't ever be actually used, just to test item creation and inventory
Item::Item(){
    equipped = false;
    typeOfItem = 1;
    nameOfItem = "Granny Smith Apple";
    uses = 1;
    changeInStats = 10;
    description = "A large, bright green, tart apple, perfect for baking a pie with.";
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








