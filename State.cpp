#include "State.h"

State::State(int itemCount) 
    : totalValue(0), totalWeight(0), totalVolume(0), selectedItems(itemCount, false) {}

State& State::operator=(const State& other) {
    if (this == &other)
        return *this;

    totalValue = other.totalValue;
    totalWeight = other.totalWeight;
    totalVolume = other.totalVolume;
    selectedItems = other.selectedItems;

    return *this;
}

int State::GetLength() const {
    return selectedItems.GetLength();
}

bool State::Get(int i) const {
    return selectedItems.Get(i);
}

void State::Set(int i, bool value) {
    selectedItems.Set(i, value);
}