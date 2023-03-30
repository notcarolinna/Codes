#include "HashTable.h"

HashTable::HashTable(int capacidade) : capacidade_(capacidade) {

    // Inicializando a tabela com ponteiros nulos
    tabela = std::vector<Node*>(capacidade_, nullptr);
}

HashTable::~HashTable() {
    for (Node* node : tabela) {
        while (node) {
            Node* next = node->next;
            delete node;
            node = next;
        }
    }
}

void HashTable::insert(int key, int value) {
    int indice = hash(key);
    Node* node = tabela[indice];

    // Procurando um nó com a mesma chave na lista encadeada
    while (node) {
        if (node->key == key) {
            node->value = value;
            return;
        }
        node = node->next;
    }

    // Criando um novo nodo e adicionando no início da lista encadeada
    Node* new_node = new Node(key, value);
    new_node->next = tabela[indice];
    tabela[indice] = new_node;
}

bool HashTable::remove(int key) {

    int indice = hash(key);
    Node* node = tabela[indice];
    Node* prev_node = nullptr;

    // Procurando um nodo com a chave a ser removida na lista encadeada
    while (node) {
        if (node->key == key) {
            if (prev_node) {
                prev_node->next = node->next;
            }
            else {
                tabela[indice] = node->next;
            }
            delete node;
            return true;
        }
        prev_node = node;
        node = node->next;
    }
    return false;
}

bool HashTable::busca(int key, int& value) const {

    int indice = hash(key);
    Node* node = tabela[indice];

    // Procurando um nó com a chave desejada na lista encadeada
    while (node) {
        if (node->key == key) {
            value = node->value;
            return true;
        }
        node = node->next;
    }
    return false;
}

int HashTable::hash(int key) const {
    // Função de hash simples usando o operador de resto (%)
    return key % capacidade_;
}
