#ifndef NODE_H
#define NODE_H

class Node {
public:
    int key;
    int value;
    Node* next;

    Node(int key, int value) : key(key), value(value), next(nullptr) {}
};

#endif
