//
// (C) Danielle Drouin 2019 - github.com/dndrouin
//

#ifndef RACCOON_H
#define RACCOON_H

#include <string>
#include <vector>
#include "Item.h"

class Raccoon {
public:
    //raccoon info and stats
    std::string name;
    int preset, hunger, fun, care, age;
    bool hyper, smelly, dead;
    bool fedToday, playedToday, caredToday;

    //inventory subsections
    std::vector<Item> food;
    std::vector<Item> play;
    std::vector<Item> cares;
    std::vector<Item> closet;

    //items in inventory
    void addItem(Item currentItem);
    void useItem(Item& selected);
    void listItems(int type);
    void inspectItem(Item& selected);
    void trashItem(Item& selected);

    //raccoon constructor and methods
    Raccoon();
    void adjustHunger(int num, bool adds);
    void adjustFun(int num, bool adds);
    void adjustCare(int num, bool adds);
    int checkIfDead();


};
#endif
