//
// (C) Danielle Drouin 2019 - github.com/dndrouin
//

#ifndef RACCOON_H
#define RACCOON_H

#include <string>

class Raccoon {
public:
    std::string name;
    int preset, hunger, fun, care;
    bool hyper, smelly, dead;

    Raccoon();
    void adjustHunger(int num, bool adds);
    void adjustFun(int num, bool adds);
    void adjustCare(int num, bool adds);

    bool checkIfDead();

};
#endif
