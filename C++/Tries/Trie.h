#pragma once
#include <string>
#include "Nodo.h"

class Trie {
public:
    Nodo* raiz;  // raiz da Trie
    Trie();
    void inserir(std::string palavra);
    bool busca(std::string palavra);

};
