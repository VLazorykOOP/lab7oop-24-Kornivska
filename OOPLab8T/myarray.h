#ifndef MYARRAY_H
#define MYARRAY_H

template <typename T> class MyArray {
private:
	unsigned int size;
	T* arr;

public:
	MyArray();
	MyArray(unsigned int size_);
	MyArray(unsigned int size_, T num);
	MyArray(const MyArray& input);  // copy
	/*  MyArray(MyArray &input); */ // move
	~MyArray();
	T& operator[](int index);
	MyArray<T>& operator=(const MyArray<T>& input); // copy assignment
	MyArray<T>& operator=(MyArray<T>&& input);      // move assignment
	MyArray<T> operator+(const MyArray<T>& input);
	MyArray<T> operator-(const MyArray<T>& input);
	MyArray<T>& operator+=(const MyArray<T>& input);
	MyArray<T>& operator-=(const MyArray<T>& input);
};

#endif // MYARRAY_H
#pragma once
