#include "Node.hpp"
#include <iostream>

Node::Node(int elem) : element(elem), father(nullptr), left(nullptr), right(nullptr) 
{
}

void Node::print()
{
    std::cout << "Elemento: " << element << std::endl;
    std::cout << "Pai: ";
    if (father == nullptr)
    {
        std::cout << "Nenhum" << std::endl;
    }
    else
    {
        std::cout << father->element << std::endl;
    }
    std::cout << "Filho Esquerdo: ";
    if (left == nullptr)
    {
        std::cout << "Nenhum" << std::endl;
    }
    else
    {
        std::cout << left->element << std::endl;
    }
    std::cout << "Filho Direito: ";
    if (right == nullptr)
    {
        std::cout << "Nenhum" << std::endl;
    }
    else
    {
        std::cout << right->element << std::endl;
    }
}
