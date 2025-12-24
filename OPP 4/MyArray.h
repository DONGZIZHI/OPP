#ifndef MYARRAY_H
#define MYARRAY_H

#include <iostream>
using namespace std;

class MyArray {
private:
    int* p;
    int N;

public:
    MyArray();
    MyArray(int n, int init = 0);
    MyArray(const MyArray& other);
    ~MyArray();

    MyArray& operator=(const MyArray& other);

    int size() const;
    int get(int index) const;
    void set(int index, int value);

    int& operator[](int index);
    const int& operator[](int index) const;

    MyArray merge(const MyArray& other) const;

    MyArray add(const MyArray& other) const;
    MyArray substract(const MyArray& other) const;
    MyArray Multiply(const MyArray& other) const;
    MyArray divide(const MyArray& other) const;

    void print() const;
};

#endif
