#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <stdexcept>

class Vector
{
private:
    int *array;
    int capacity;
    int size;

public:
    Vector();
    ~Vector();
    void push_back(int element);
    void pop_back();
    int &operator[](int index);
    int getSize();
};

#endif
