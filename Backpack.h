#ifndef BACKPACK_H
#define BACKPACK_H

#include <string>
#include "DynamicArray.h"
#include "HashTable.h"
#include "Item.h"
#include "State.h"

std::string CreateCacheKey(int idx, int weight, int volume);

void FindBestCombination(const DynamicArray<Item>& items, int weightLimit, int volumeLimit,
                         State current, int idx, State& best, int& bestVal, HashTable<std::string, int>& cache);

State OptimizePack(const DynamicArray<Item>& items, int weightLimit, int volumeLimit);

#endif // BACKPACK_H