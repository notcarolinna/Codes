#ifndef QUEUE_HPP
#define QUEUE_HPP

class Stack
{
private:
    Node *top;
    bool inOrder(bool increasing) const;

public:
    Stack() : top(nullptr) {}
    ~Stack();
    void push(int data);
    int pop();
    bool isEmpty() const;
    void print() const;
    void add();
    void sub();
    void mult();
    void div();
    void sin();
    void cos();
    void atan2();
    void dup();
    void swap();
    bool exist(int data) const;
    bool ordena(bool increasing) const;
};
#endif
