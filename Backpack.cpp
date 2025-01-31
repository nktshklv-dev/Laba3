
#include "Backpack.h"

Backpack::Backpack(int cap): capacity(cap) {}

void Backpack::addItem(Item item) {
    items.push_back(item);
}

