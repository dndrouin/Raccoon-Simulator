//
// (C) Danielle Drouin 2019 - github.com/dndrouin
//


#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "Raccoon.h"


class Item {
public:
    bool equipped;
    int typeOfItem, changeInStats, uses;
    std::string nameOfItem, description;

    //constructors
    Item();
    Item(int itemType, int statValue, int numUses, std::string name, std::string itemDescription); //for testing purposes only
};

void inspectItem(Item selected);
void useItem(Item selected);
void giveStarterItems(Raccoon* startPet);



#endif
