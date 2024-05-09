#include <iostream>

using namespace std;

// TASK 1.8 = 1.1
template <typename T> void findEqual(T* arr, T key, unsigned int N) {
    cout << "Template for T" << endl;
    unsigned int pos = 0;
    for (unsigned int i = 0; i < N; i++) {
        if (arr[i] == key)
            pos = i;
    }
    cout << "Pos: " << pos << endl;
}

template <> void findEqual(char** arr, char* key, unsigned int N) {
    cout << "Template for char" << endl;
    unsigned int posI = 0, posZ = 0;
    for (unsigned int i = 0; i < N; i++) {
        for (unsigned int z = 0; z < N; z++) {
            if (arr[i][z] != key[z]) {
                break;
            }
            posI = i, posZ = z;
        }
    }
    cout << "PosI: " << posI << endl;
    cout << "PosZ: " << posZ << endl;
}

// TASK 2.8 = 2.3
template <typename T> T* sortInsert(T* arr, unsigned int N) {
    cout << "Template for T" << endl;
    T key;
    int j;
    for (unsigned int i = 1; i < N; i++) {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
    greater than key, to one position ahead
    of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    return arr;
}

template <> char** sortInsert(char** arr, unsigned int N) {
    cout << "Template for char" << endl;
    char* key;
    int j;
    for (unsigned int i = 1; i < N; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j][0] > key[0]) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    return arr;
}

// TASK 3.8 = 3.1
#include "myarray.h"

// TASK 4.8 = 4.3
#include "list.h"

int main() {
    // TASK 1.1
    char** array1 = new char* [2];
    for (int i = 0; i < 3; i++) {
        array1[i] = new char[2];
    }
    array1[0][0] = 'A';
    array1[0][1] = 'B';
    array1[1][0] = 'C';
    array1[1][1] = 'D';
    char* key1 = new char[2];
    key1[0] = 'C';
    key1[1] = 'D';
    findEqual(array1, key1, 2);
    int* arrayInt1 = new int[5];
    arrayInt1[0] = 1;
    arrayInt1[1] = 2;
    arrayInt1[2] = 3;
    arrayInt1[3] = 4;
    arrayInt1[4] = 5;
    findEqual(arrayInt1, 3, 5);
    delete[] arrayInt1;
    for (int i = 0; i < 2; i++) {
        delete[] array1[i];
    }
    delete[] array1;
    delete[] key1;

    // TASK2.3
    char** array2 = new char* [2];
    for (int i = 0; i < 3; i++) {
        array2[i] = new char[2];
    }
    array2[0][0] = 'C';
    array2[0][1] = 'D';
    array2[1][0] = 'A';
    array2[1][1] = 'B';
    sortInsert(array2, 2);
    for (int i = 0; i < 2; i++) {
        cout << array2[i] << endl;
    }
    for (int i = 0; i < 2; i++) {
        delete[] array2[i];
    }
    delete[] array2;
    int* arrayInt2 = new int[5];
    arrayInt2[0] = 4;
    arrayInt2[1] = 2;
    arrayInt2[2] = 3;
    arrayInt2[3] = 1;
    arrayInt2[4] = 5;
    sortInsert(arrayInt2, 5);
    for (int i = 0; i < 5; i++) {
        cout << arrayInt2[i] << endl;
    }

    // TASK 3.1
    MyArray<int> A(5, 1);
    MyArray<int> B(5, 2);
    // MyArray<double> B(5, 2);
    cout << "A:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << A[i] << " "; //[] operator
    }
    cout << endl;
    A[0] = 5; //[] operator
    cout << "A[0] = 5: " << endl;
    for (int i = 0; i < 5; i++) {
        cout << A[i] << " ";
    }
    A[0] = 1;
    cout << endl;
    MyArray<int> C(5);
    C = A; // = operator
    cout << "C = A, C: " << endl;
    for (int i = 0; i < 5; i++) {
        cout << C[i] << " ";
    }
    cout << endl;
    C = A + B; //+
    cout << "C = A+B, C: " << endl;
    for (int i = 0; i < 5; i++) {
        cout << C[i] << " ";
    }
    cout << endl;
    C -= B;
    cout << "C -= B, C:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << C[i] << " ";
    }
    cout << endl;
    cout << "C = A-B: " << endl;
    C = A - B;
    for (int i = 0; i < 5; i++) {
        cout << C[i] << " ";
    }
    cout << "C += B:" << endl;
    C += B;
    for (int i = 0; i < 5; i++) {
        cout << C[i] << " ";
    }

    // TASK 4.3
    List<int> A4;
    A4.add(1);
    A4.add(2);
    A4.add(3);
    A4.display();
    List<int>::iterator it4(A4);
    cout << "it: " << *it4 << endl;
    it4++;
    cout << "it++: " << *it4 << endl;
    List<int>::iterator it42(A4);
    it42++;
    cout << "it2: " << *it42 << endl;
    cout << "it==i2: " << (it4 == it42) << endl;
    it4++;
    cout << "it++: " << *it4 << endl;
    cout << "it==i2: " << (it4 == it42) << endl;
    it4++;
    cout << "it++ (out of bounds): " << *it4 << endl;
    List<int>::iterator it43(A4);
    it43--;
    cout << "it3-- (out of bounds): " << *it43 << endl;
    return 0;
}
#pragma once
