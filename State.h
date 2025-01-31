#ifndef STATE_H
#define STATE_H

#include "DynamicArray.h"

struct State {
    int totalValue;
    int totalWeight;
    int totalVolume;
    DynamicArray<bool> selectedItems;

    State(int itemCount);
    State& operator=(const State& other);
    int GetLength() const;
    bool Get(int i) const;
    void Set(int i, bool value);
};

#endif // STATE_H