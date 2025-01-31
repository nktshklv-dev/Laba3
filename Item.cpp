#include "Item.h"

Item::Item(int weight, int volume, int value) 
    : weight(weight), volume(volume), value(value) {}

Item::Item() 
    : weight(0), volume(0), value(0) {}

bool Item::operator==(const Item& other) const {
    return other.weight == weight && other.volume == volume && other.value == value;
}

bool Item::operator!=(const Item& other) const {
    return other.weight != weight || other.volume != volume || other.value != value;
}