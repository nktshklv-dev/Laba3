#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include "ISequence.h"

template <class T>
class DynamicArray : public ISequence<T> {
private:
    T* data;
    int size;

    void Resize(int newSize);

public:
    class DynamicArrayIterator : public ISequence<T>::Iterator {
    private:
        T* current;

    public:
        DynamicArrayIterator(T* current);
        bool operator==(const typename ISequence<T>::Iterator& other) const override;
        bool operator!=(const typename ISequence<T>::Iterator& other) const override;
        T& operator*() override;
        typename ISequence<T>::Iterator& operator++() override;
    };

    typename ISequence<T>::Iterator* ToBegin() override;
    typename ISequence<T>::Iterator* ToEnd() override;

    DynamicArray(T* items, int size);
    DynamicArray(int size = 0);
    DynamicArray(const DynamicArray<T>& dynamicArray);
    ~DynamicArray() override;

    T& operator[](int index);
    const T& operator[](int index) const;

    T& GetFirstElement() override;
    T& GetLastElement() override;
    T& GetElement(int index) override;
    void Swap(T& a, T& b) override;
    void Set(int index, T value) override;

    ISequence<T>* GetSubSequence(int startIndex, int endIndex) override;

    int GetLength() const override;
    void Append(T item) override;
    void Append(T* items, int dataSize) override;
    void Prepend(T item) override;
    void InsertAt(T item, int index) override;
    void Union(ISequence<T>* dynamicArray) override;
};

#include "DynamicArray.tpp"

#endif // DYNAMICARRAY_H