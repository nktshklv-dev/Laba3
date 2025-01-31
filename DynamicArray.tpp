#ifndef DYNAMICARRAY_TPP
#define DYNAMICARRAY_TPP

template <class T>
DynamicArray<T>::DynamicArray(T* items, int size) {
    this->size = size;
    data = new T[size];
    for (int i = 0; i < size; ++i) {
        data[i] = items[i];
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
        data[i] = dynamicArray.data[i];
    }
}

template <class T>
DynamicArray<T>::DynamicArray(int size, const T& initialValue) {
    this->size = size;
    data = new T[size];
    for (int i = 0; i < size; ++i) {
        data[i] = initialValue;
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
int DynamicArray<T>::GetLength() const {
    return size;
}

template <class T>
void DynamicArray<T>::Set(int index, T value) {
    data[index] = value;
}

template <class T>
T DynamicArray<T>::Get(int index) const {
    return data[index];
}

#endif // DYNAMICARRAY_TPP