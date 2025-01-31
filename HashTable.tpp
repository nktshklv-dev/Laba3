#ifndef HASHTABLE_TPP
#define HASHTABLE_TPP

#include <functional>

template <typename K, typename V>
HashTable<K, V>::HashTable(size_t size) : capacity(size) {
    table.resize(capacity);
}

template <typename K, typename V>
size_t HashTable<K, V>::Hash(const K& key) const {
    return std::hash<K>{}(key) % capacity;
}

template <typename K, typename V>
void HashTable<K, V>::Add(const K& key, const V& value) {
    size_t index = Hash(key);
    while (table[index].occupied) {
        if (table[index].key == key) {
            table[index].value = value;
            return;
        }
        index = (index + 1) % capacity;
    }
    table[index] = {key, value, true};
}

template <typename K, typename V>
std::optional<V> HashTable<K, V>::GetValue(const K& key) const {
    size_t index = Hash(key);
    while (table[index].occupied) {
        if (table[index].key == key) {
            return table[index].value;
        }
        index = (index + 1) % capacity;
    }
    return std::nullopt;
}

#endif // HASHTABLE_TPP