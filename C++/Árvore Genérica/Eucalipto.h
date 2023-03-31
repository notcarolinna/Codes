#include <iostream>
#include <cstdlib>
#include <list>
#include "Node.h"

using namespace std;

class Tree {
private:

	Node* root;
	int count;

	int countLeaves(Node* n);
	Node* searchNodeRef(int elem, Node* n);
	Node* smallest(Node* n);
	void positionsPreAux(Node* n, list<int>& lista);
	void positionsPosAux(Node* n, list<int>& lista);
	void positionsCentralAux(Node* n, list<int>& lista);
	int height(Node* n);
	int countNodos(Node* n);
	void GeraConexoesDOT(Node* nodo);
	void GeraNodosDOT(Node* nodo);
	int contaNodosFolha(Node* nodo);

public:

	Tree();
	void clear();				      // Remove todos os nodos da árvore e reseta os atributos root e count
	bool isEmpty();				    // Verifica se a árvore está vazia
	int size();					      // Retorna o número de nodos da árvore
	int getRoot();				    // Retorna o valor da raíz
	void add(int element);		// Insere um novo nodo
	Node* add(Node* nodo, int element, Node* father); // Utilizado pelo método add para percorrer a árvore recursivamente
	bool contains(int elem);			  // Verifica se um elemento está presente na árvore
	Node* getLeft(int element);			// Retorna o nodo esquerdo do nodo element
	Node* getRigh(int element);			// Retorna o nodo direito do nodo element
	Node* getParent(int element);		// Retorna o nodo pai do nodo element
	bool remove(int element);			  // Remove o nodo, reorganizando os demais nodos para manter a ABP
	bool set(int old, int element);		// Substitui o valor old pelo element
	list<int> positionsWidth();			  // Retorna uma lista contendo os valores dos nodos em ordem de nível
	list<int> positionsCentral();		  // Retorna uma lista contendo os valores dos novos em ordem central
	list<int> positionsPre();			    // Retorna uma lista contendo os nodos em pré-ordem
	list<int> positionsPos();			    // Retorna uma lista contendo os nodos em pós-ordem
	bool isExternal(int element);		  // Verifica se o nodo que contém element é um nodo folha
	bool isInternal(int element);		  // Verifica se o nodo que contém element é um nodo interno
	int height();						          // Retorna a altura da árvore
	int level(int element);				    // Retorna o nível em que element está
	int countLeaves();					      // Retorna o número de folhas da árvore
	int contaNodosFolha();				    // Retorna o número de nodos folha da árvore

};
