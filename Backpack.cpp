#include <sstream>
#include <string>
#include "DynamicArray.h"
#include "HashTable.h"
#include "Item.h"
#include "State.h"

std::string CreateCacheKey(int idx, int w, int v) {
    std::ostringstream oss;
    oss << idx << "_" << w << "_" << v;
    return oss.str();
}

void FindBestCombination(const DynamicArray<Item>& items, int weightLimit, int volumeLimit,
                         State current, int idx, State& best, int& bestVal, HashTable<std::string, int>& cache) {
    if (idx == items.GetLength()) {
        if (current.totalWeight <= weightLimit && current.totalVolume <= volumeLimit) {
            if (current.totalValue > bestVal) {
                bestVal = current.totalValue;
                best = current;
            }
        }
        return;
    }

    std::string key = CreateCacheKey(idx, current.totalWeight, current.totalVolume);
    auto cachedVal = cache.GetValue(key);

    if (cachedVal.has_value() && cachedVal.value() >= current.totalValue)
        return;

    cache.Add(key, current.totalValue);

    FindBestCombination(items, weightLimit, volumeLimit, current, idx + 1, best, bestVal, cache);

    if (idx < current.GetLength() &&
        current.totalWeight + items[idx].weight <= weightLimit &&
        current.totalVolume + items[idx].volume <= volumeLimit) {
        current.totalWeight += items[idx].weight;
        current.totalVolume += items[idx].volume;
        current.totalValue += items[idx].value;
        current.selectedItems[idx] = true;

        FindBestCombination(items, weightLimit, volumeLimit, current, idx + 1, best, bestVal, cache);
        }
}

State OptimizePack(const DynamicArray<Item>& items, int weightLimit, int volumeLimit) {
    State best(items.GetLength());
    int bestVal = 0;
    HashTable<std::string, int> cache(1000);

    FindBestCombination(items, weightLimit, volumeLimit, State(items.GetLength()), 0, best, bestVal, cache);

    return best;
}