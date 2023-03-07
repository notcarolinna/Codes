#include "Vector.hpp"

Vector::Vector()
{
    array = new int[1];
    capacity = 1;
    size = 0;
}

Vector::~Vector()
{
    delete[] array;
}

void Vector::push_back(int element)
{
    if (size == capacity)
    {
        int *newArray = new int[capacity * 2];
        for (int i = 0; i < size; i++)
        {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
        capacity *= 2;
    }
    array[size] = element;
    size++;
}

void Vector::pop_back()
{
    if (size == 0)
    {
        throw std::out_of_range("Vector is empty");
    }
    size--;
}

int &Vector::operator[](int index)
{
    if (index < 0 || index >= size)
    {
        throw std::out_of_range("Index out of range");
    }
    return array[index];
}

int Vector::getSize()
{
    return size;
}
