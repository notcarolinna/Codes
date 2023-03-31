#include "BinaryTree.h"
#include <iostream>

Node::Node(int value) {
	this->value = value;
	this->left = nullptr;
	this->right = nullptr;
}

Node::~Node() {
	delete left;
	delete right;
}

BinaryTree::BinaryTree() {
	root = nullptr;
}

BinaryTree::~BinaryTree() {
	delete root;
}

void BinaryTree::insert(int value) {

	// Verifica se a árvore está vazia

	if (root == nullptr) {
		root = new Node(value);
	}
	else {
		insert(root, value);
	}
}

void BinaryTree::insert(Node* node, int value) {

	// Realiza a inserção do nodo

	if (value < node->value) {
		if (node->left == nullptr) {
			node->left = new Node(value);
		}
		else {
			insert(node->left, value);
		}
	}
	else {
		if (node->right == nullptr) {
			node->right = new Node(value);
		}
		else {
			insert(node->right, value);
		}
	}
}

bool BinaryTree::busca(int value) {
	return busca(root, value);
}

bool BinaryTree::busca(Node* node, int value) {

	// Busca um valor específico na árvore e retorna um bool
	// indicando se o valor foi encontrado ou não.
	// A função para de percorrer a árvore assim que encontra
	// o valor procurado ou quando chega numa folha que não
	// contém o valor procurado

	if (node == nullptr) {
		return false;
	}
	else if (node->value == value) {
		return true;
	}
	else if (value < node->value) {
		return busca(node->left, value);
	}
	else {
		return busca(node->right, value);
	}
}

void BinaryTree::buscaOrdenada() {
	buscaOrdenada(root);
}

void BinaryTree::buscaOrdenada(Node* node) {

	// Percorre todos os nodos da árvore imprime cada um;
	// A função não para quando encontra um determinado valor,
	// mas continua a percorrer todos os nodos da árvore

	if (node != nullptr) {
		buscaOrdenada(node->left);
		std::cout << node->value << " ";
		buscaOrdenada(node->right);
	}
}

void BinaryTree::print(Node* node) {
	if (node != nullptr) {
		print(node->left);
		std::cout << node->value << " ";
		print(node->right);
	}
}

void BinaryTree::print() {
	print(root);
	std::cout << std::endl;
}

