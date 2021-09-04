//
// (C) Danielle Drouin 2019 - github.com/dndrouin
//

#include <string>
#include "Item.h"

//default item constructor
Item::Item(){
    equipped = false;
    typeOfItem = 1;
    nameOfItem = "Granny Smith Apple";
    uses = 1;
    changeInStats = 10;
    description = "A large green apple, perfect for baking a pie with.";
}

bool Item::operator==(const Item& rhs) {
    return this->nameOfItem == rhs.nameOfItem;
}











