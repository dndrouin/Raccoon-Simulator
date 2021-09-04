//
// (C) Danielle Drouin 2019-2021 - github.com/dndrouin
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
      bool operator==(const Item&);
};

#endif
