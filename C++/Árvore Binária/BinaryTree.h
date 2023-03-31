#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "Node.h"

class BinaryTree {
private:
	Node* root;

	void insert(Node* node, int value);
	bool busca(Node* node, int value);
	void buscaOrdenada(Node* node);
	void print(Node* node);

public:
	BinaryTree();
	~BinaryTree();

	void insert(int value);
	bool busca(int value);
	void buscaOrdenada();
	void print();
};


#endif
