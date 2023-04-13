#pragma once
#include <vector>

class Nodo {
public:
    char valorNodo;  // valor do nó (caractere)
    bool fimPalavra;  // indica se o nó é o final de uma palavra
    std::vector<Nodo*> filho;  // filhos do nó

    Nodo(char c);

    Nodo* buscaFilho(char c);
};

#endif
