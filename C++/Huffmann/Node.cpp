#include "Node.h"

Node::Node(char data, int frequencia) {
    this->data = data;
    this->frequencia = frequencia;
    this->left = nullptr;
    this->right = nullptr;
}

bool Node::is_leaf() const {
    return (this->left == nullptr && this->right == nullptr);
}
