#include "include.h"
#define ITEM_H
#ifndef ITEM_H

class Item:

public:
    bool isWeapon();
    void use(Unit *Unit);
};
#endif