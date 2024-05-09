#include "myarray.h"

template class MyArray<int>;
template class MyArray<double>;

template <typename T> MyArray<T>::MyArray() {
    size = 0;
    arr = nullptr;
}

template <typename T> MyArray<T>::MyArray(unsigned int size_) {
    size = size_;
    arr = new T[size];
    for (unsigned int i = 0; i < size; i++)
        arr[i] = 0;
}

template <typename T> MyArray<T>::MyArray(unsigned int size_, T num) {
    size = size_;
    arr = new T[size];
    for (unsigned int i = 0; i < size; i++)
        arr[i] = num;
}

template <typename T> MyArray<T>::MyArray(const MyArray& input) {
    arr = new T[input.size];
    size = input.size;
    for (unsigned int i = 0; i < size; i++)
        arr[i] = input.arr[i];
}

// template <typename T> MyArray<T>::MyArray(MyArray &input) {
//   size = input.size;
//   arr = input.arr;
//   input.arr = nullptr;
// }

template <typename T> MyArray<T>::~MyArray() {
    if (arr)
        delete[] arr;
}

template <typename T> T& MyArray<T>::operator[](int index) {
    if (index < 0 || index > size)
        return arr[0];
    return arr[index];
}

template <typename T>
MyArray<T>& MyArray<T>::operator=(const MyArray<T>& input) { // copy
    if (this != &input) {
        if (size != input.size) {
            delete[] arr;
            size = input.size;
            arr = new T[size];
        }
        for (int i = 0; i < size; i++) {
            arr[i] = input.arr[i];
        }
    }
    return *this;
}

template <typename T>
MyArray<T>& MyArray<T>::operator=(MyArray<T>&& input) { // move
    if (this != &input) {
        if (size != input.size) {
            delete[] arr;
            size = input.size;
        }
        arr = input.arr;
        input.arr = nullptr;
        input.size = 0;
    }
    return *this;
}

template <typename T>
MyArray<T> MyArray<T>::operator+(const MyArray<T>& input) {
    unsigned int elems = size <= input.size ? size : input.size;
    MyArray<T> result(elems);
    for (unsigned int i = 0; i < elems; i++) {
        result.arr[i] = arr[i] + input.arr[i];
    }
    return result;
}

template <typename T>
MyArray<T> MyArray<T>::operator-(const MyArray<T>& input) {
    unsigned int elems = size <= input.size ? size : input.size;
    MyArray<T> result(elems);
    for (unsigned int i = 0; i < elems; i++) {
        result.arr[i] = arr[i] - input.arr[i];
    }
    return result;
}

template <typename T>
MyArray<T>& MyArray<T>::operator+=(const MyArray<T>& input) {
    unsigned int elems = size <= input.size ? size : input.size;
    for (unsigned int i = 0; i < elems; i++) {
        arr[i] += input.arr[i];
    }
    return *this;
}

template <typename T>
MyArray<T>& MyArray<T>::operator-=(const MyArray<T>& input) {
    unsigned int elems = size <= input.size ? size : input.size;
    for (unsigned int i = 0; i < elems; i++) {
        arr[i] -= input.arr[i];
    }
    return *this;
}
#pragma once
