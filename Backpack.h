
#ifndef BACKPACK_H
#define BACKPACK_H

#include <vector>
#include "Item.h"

class Backpack {
public:
    int capacity;
    std::vector<Item> items;

    Backpack(int cap);
    void addItem(Item item);
};

#endif
