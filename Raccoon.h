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
    std::string name;
    int preset, hunger, fun, care, age;
    bool hyper, smelly, dead;
    bool fedToday, playedToday, caredToday;

    //inventory
    std::vector<Item> food;
    std::vector<Item> play;
    std::vector<Item> cares;
    std::vector<Item> closet;

    void addItem(Item currentItem);


    Raccoon();
    void adjustHunger(int num, bool adds);
    void adjustFun(int num, bool adds);
    void adjustCare(int num, bool adds);

    int checkIfDead();

    void listItems(int type);
};
#endif
