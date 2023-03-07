
#include "Queue.hpp"

template <typename T>
Queue<T>::Queue(int capacidadeInicial)
{
    array = new T[capacidadeInicial];
    frontIndex = 0;
    backIndex = -1;
    capacidade = capacidadeInicial;
    size = 0;
}

template <typename T>
Queue<T>::~Queue()
{
    delete[] array;
}

template <typename T>
void Queue<T>::enqueue(T element)
{
    if (size == capacidade)
    {
        T *newArray = new T[capacidade * 2];
        int j = 0;
        for (int i = frontIndex; i <= backIndex; i++)
        {
            newArray[j] = array[i];
            j++;
        }
        delete[] array;
        array = newArray;
        capacidade *= 2;
        frontIndex = 0;
        backIndex = size - 1;
    }
    backIndex++;
    array[backIndex] = element;
    size++;
}

template <typename T>
void Queue<T>::dequeue()
{
    if (size == 0)
    {
        throw std::out_of_range("A fila está vazia");
    }
    frontIndex++;
    size--;
}

template <typename T>
T &Queue<T>::front()
{
    if (size == 0)
    {
        throw std::out_of_range("A fila está vazia");
    }
    return array[frontIndex];
}

template <typename T>
T &Queue<T>::back()
{
    if (size == 0)
    {
        throw std::out_of_range("A fila está vazia");
    }
    return array[backIndex];
}

template <typename T>
bool Queue<T>::empty()
{
    return size == 0;
}

template <typename T>
int Queue<T>::getSize()
{
    return size;
}
