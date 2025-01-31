#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

template <class T>
class DynamicArray {
private:
    T* data;
    int size;

public:
    DynamicArray(T* items, int size);
    DynamicArray(int size = 0);
    DynamicArray(const DynamicArray<T>& dynamicArray);
    DynamicArray(int size, const T& initialValue); // Новый конструктор
    ~DynamicArray();

    T& operator[](int index);
    const T& operator[](int index) const;

    int GetLength() const;
    void Set(int index, T value);
    T Get(int index) const;
};

#include "DynamicArray.tpp"

#endif // DYNAMICARRAY_H