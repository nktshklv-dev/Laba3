#ifndef DYNAMICARRAY_TPP
#define DYNAMICARRAY_TPP

#include "DynamicArray.h"

template <class T>
void DynamicArray<T>::Resize(int newSize) {
    T* newData = new T[newSize];
    int minSize = (newSize < size) ? newSize : size;
    for (int i = 0; i < minSize; ++i) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    size = newSize;
}

template <class T>
DynamicArray<T>::DynamicArrayIterator::DynamicArrayIterator(T* current) : current(current) { }

template <class T>
bool DynamicArray<T>::DynamicArrayIterator::operator==(const typename ISequence<T>::Iterator& other) const {
    const DynamicArrayIterator* otherIterator = static_cast<const DynamicArrayIterator*>(&other);
    return otherIterator && current == otherIterator->current;
}

template <class T>
bool DynamicArray<T>::DynamicArrayIterator::operator!=(const typename ISequence<T>::Iterator& other) const {
    return !(*this == other);
}

template <class T>
T& DynamicArray<T>::DynamicArrayIterator::operator*() {
    return *current;
}

template <class T>
typename ISequence<T>::Iterator& DynamicArray<T>::DynamicArrayIterator::operator++() {
    ++current;
    return *this;
}

template <class T>
typename ISequence<T>::Iterator* DynamicArray<T>::ToBegin() {
    return new DynamicArrayIterator(data);
}

template <class T>
typename ISequence<T>::Iterator* DynamicArray<T>::ToEnd() {
    return new DynamicArrayIterator(data + size);
}

template <class T>
DynamicArray<T>::DynamicArray(T* items, int size) {
    this->size = size;
    data = new T[size];
    for (int i = 0; i < size; ++i) {
        Set(i, items[i]);
    }
}

template <class T>
DynamicArray<T>::DynamicArray(int size) {
    this->size = size;
    data = new T[size];
}

template <class T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& dynamicArray) {
    size = dynamicArray.size;
    data = new T[size];
    for (int i = 0; i < size; ++i) {
        Set(i, dynamicArray.data[i]);
    }
}

template <class T>
DynamicArray<T>::~DynamicArray() {
    delete[] data;
}

template <class T>
T& DynamicArray<T>::operator[](int index) {
    return data[index];
}

template <class T>
const T& DynamicArray<T>::operator[](int index) const {
    return data[index];
}

template <class T>
T& DynamicArray<T>::GetFirstElement() {
    return GetElement(0);
}

template <class T>
T& DynamicArray<T>::GetLastElement() {
    return GetElement(size - 1);
}

template <class T>
T& DynamicArray<T>::GetElement(int index) {
    return data[index];
}

template <class T>
void DynamicArray<T>::Swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template <class T>
void DynamicArray<T>::Set(int index, T value) {
    data[index] = value;
}

template <class T>
ISequence<T>* DynamicArray<T>::GetSubSequence(int startIndex, int endIndex) {
    int length;
    if (endIndex > size) {
        length = size - startIndex;
    } else {
        length = endIndex - startIndex + 1;
        if (startIndex == 0) {
            length -= 1;
        }
    }
    T* items = new T[length];
    for (int i = 0; i < length; ++i) {
        items[i] = GetElement(startIndex + i);
    }
    return new DynamicArray<T>(items, length);
}

template <class T>
int DynamicArray<T>::GetLength() const {
    return size;
}

template <class T>
void DynamicArray<T>::Append(T item) {
    InsertAt(item, size);
}

template <class T>
void DynamicArray<T>::Append(T* items, int dataSize) {
    int oldSize = size;
    Resize(size + dataSize);
    for (int i = oldSize; i < oldSize + dataSize; i++) {
        Set(i, items[i - oldSize]);
    }
}

template <class T>
void DynamicArray<T>::Prepend(T item) {
    InsertAt(item, 0);
}

template <class T>
void DynamicArray<T>::InsertAt(T item, int index) {
    Resize(size + 1);
    for (int i = size - 1; i > index; --i) {
        Set(i, GetElement(i - 1));
    }
    Set(index, item);
}

template <class T>
void DynamicArray<T>::Union(ISequence<T>* dynamicArray) {
    for (int i = 0; i < dynamicArray->GetLength(); ++i) {
        Append(dynamicArray->GetElement(i));
    }
}

#endif // DYNAMICARRAY_TPP