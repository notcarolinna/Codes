#pragma once
#ifndef NODE_H
#define NODE_H

class Node {
public:
    char data;
    int frequencia;
    Node* left;
    Node* right;

    Node(char data, int frequencia);
    bool is_leaf() const;
};

#endif
