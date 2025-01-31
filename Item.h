#ifndef ITEM_H
#define ITEM_H

struct Item {
    int weight;
    int volume;
    int value;

    Item(int weight, int volume, int value);
    Item();
    bool operator==(const Item& other) const;
    bool operator!=(const Item& other) const;
};

#endif // ITEM_H