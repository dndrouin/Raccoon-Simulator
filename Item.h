//
// (C) Danielle Drouin 2019 - github.com/dndrouin
//


#ifndef ITEM_H
#define ITEM_H

#include <string>


class Item {
public:
    bool equipped;
    int typeOfItem, changeInStats, uses;
    std::string nameOfItem, description;

    //constructors
    Item(); //for testing purposes only
    Item(int itemType, int statValue, int numUses, std::string name, std::string itemDescription);
};

#endif
