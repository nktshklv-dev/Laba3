#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <optional>
#include <string>
#include <vector>

template <typename K, typename V>
class HashTable {
private:
    struct Entry {
        K key;
        V value;
        bool occupied;
    };

    std::vector<Entry> table;
    size_t capacity;

    size_t Hash(const K& key) const;

public:
    HashTable(size_t size = 1000);
    void Add(const K& key, const V& value);
    std::optional<V> GetValue(const K& key) const;
};

#include "HashTable.tpp"

#endif // HASHTABLE_H