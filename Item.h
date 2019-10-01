//
// (C) Danielle Drouin 2019 - github.com/dndrouin
//


#ifndef ITEM_H
#define ITEM_H

#include <string>


class Item {
public:
    bool equipped;
    int typeOfItem, changeInStats;
    std::string nameOfItem;

    Item();
    Item(int itemType, int statValue, std::string name);
};

void useItem(Item selected);



#endif
