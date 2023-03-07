#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class Queue
{
private:
    T *array;
    int frontIndex;
    int backIndex;
    int capacidade;
    int size;

public:
    Queue(int capacidadeInicial = 10);
    ~Queue();
    void enqueue(T element);
    void dequeue();
    T &front();
    T &back();
    bool empty();
    int getSize();
};

#endif
