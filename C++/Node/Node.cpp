#ifndef Node_hpp
#define Node_hpp

class Node
{
public:
    int element;
    Node *father;
    Node *left;
    Node *right;

    Node(int elem);
    void print();
};

#endif
