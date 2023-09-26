#include <iostream>
#include "Queue.h";

using namespace std;

int MAX_SIZE = 25;

Queue::Queue() {
    this->list = (int*) malloc (MAX_SIZE * sizeof (int));
    this->count = 0;
}

void Queue::enqueue(int element) {
    if (count >= MAX_SIZE) {
        addMoreSpaceList();
    }

    list[count] = element;
    count++;
}

int Queue::dequeue() {
    if (count <= 0) {
        return 0; // Need to be improved
    }
    else {
        int element = list[0];

        for (int i = 1; i <= count; i++) {
            list[i - 1] = list[i];
        }

        count--;
        return element;
    }
}

int Queue::head() {
    return list[0];
}

int Queue::size() {
    return count;
}

bool Queue::isEmpty() {
    return count == 0;
}

void Queue::clear() {
    count = 0;
}

void Queue::addMoreSpaceList() {
    MAX_SIZE += 20;
    list = (int*) realloc(list, MAX_SIZE * sizeof(int));
}
