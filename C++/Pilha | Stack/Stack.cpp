#include "Stack.hpp"

Stack::~Stack()
{
    while (top)
    {
        Node *temp = top;
        top = top->next;
        delete temp;
    }
}

void Stack::push(int data)
{
    Node *newNode = new Node(data);
    newNode->next = top;
    top = newNode;
}

int Stack::pop()
{
    if (!isEmpty())
    {
        int data = top->data;
        Node *temp = top;
        top = top->next;
        delete temp;
        return data;
    }
    else
    {
        std::cout << "Erro: Pilha vazia!" << std::endl;
        return -1;
    }
}

bool Stack::isEmpty() const
{
    return (top == nullptr);
}

void Stack::print() const
{
    Node *temp = top;
    while (temp != nullptr)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

void Stack::add()
{
    if (!isEmpty())
    {
        int op1 = pop();
        int op2 = pop();
        push(op1 + op2);
    }
    else
    {
        std::cout << "Erro: Pilha vazia!" << std::endl;
    }
}

void Stack::sub()
{
    if (!isEmpty())
    {
        int op1 = pop();
        int op2 = pop();
        push(op2 - op1);
    }
    else
    {
        std::cout << "Erro: Pilha vazia!" << std::endl;
    }
}

void Stack::mult()
{
    if (!isEmpty())
    {
        int op1 = pop();
        int op2 = pop();
        push(op1 * op2);
    }
    else
    {
        std::cout << "Erro: Pilha vazia!" << std::endl;
    }
}

void Stack::div()
{
    if (!isEmpty())
    {
        int op1 = pop();
        int op2 = pop();
        if (op1 == 0)
        {
            std::cout << "Erro: divisão por zero!" << std::endl;
            push(op2);
            push(op1);
        }
        else
        {
            push(op2 / op1);
        }
    }
    else
    {
        std::cout << "Erro: Pilha vazia!" << std::endl;
    }
}

void Stack::sin()
{
    if (!isEmpty())
    {
        double op1 = pop();
        push(std::sin(op1));
    }
    else
    {
        std::cout << "Erro: Pilha vazia!" << std::endl;
    }
}

void Stack::cos()
{
    if (!isEmpty())
    {
        double op1 = pop();
        push(std::cos(op1));
    }
    else
    {
        std::cout << "Erro: Pilha vazia!" << std::endl;
    }
}
