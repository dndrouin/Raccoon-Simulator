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

    //default constructor
    Item();
    friend bool Item::operator==(const Item&, const Item&);
};

#endif
