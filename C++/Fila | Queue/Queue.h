#pragma once

class Queue {
private:
    int* list;
    int count;

    void addMoreSpaceList();

public:
    Queue();

    void enqueue(int element);
    int dequeue();
    int head();
    int size();
    bool isEmpty();
    void clear();

};
