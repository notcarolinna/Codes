#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Node.h"
#include <vector>

class HashTable {

private:
	int capacidade_;
	std::vector<Node*> tabela; // armazena os nodos da tabela hash

	int hash(int key) const; // calcula o índice do vetor onde o nodo com a chave especificada deve ser inserido ou buscado

public:
	HashTable(int capacidade = 100);
	~HashTable();

	void insert(int key, int value);
	bool remove(int key);
	bool busca(int key, int& value) const;
	void print();


};

#endif
