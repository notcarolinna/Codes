#include "Compressed.h"

CompressedTrie::CompressedTrie() {
	this->nodoRaiz = new Nodo();
}

void CompressedTrie::inserir(std::string palavra) {
	Nodo* nodo = nodoRaiz;
	for (char c : palavra) {
		int index = c - 'a';
		if (!nodo->filho[index]) {
			nodo->filho[index] = new Nodo();
		}
		nodo = nodo->filho[index];
	}
	nodo->palavraCompleta = true;
}

bool CompressedTrie::busca(std::string palavra) {
	Nodo* node = nodoBusca(palavra);
	return node && node->palavraCompleta;
}

Nodo* CompressedTrie::buscaPrefixo(std::string prefixo) {
	Nodo* nodo = nodoRaiz;
	for (char c : prefixo) {
		int index = c - 'a';
		if (!nodo->filho[index]) {
			return nullptr;
		}
		nodo = nodo->filho[index];
	}
	return nodo;
}

Nodo* CompressedTrie::nodoBusca(std::string& palavra) {
	Nodo* nodo = nodoRaiz;
	for (char c : palavra) {
		int index = c - 'a';
		if (!nodo->filho[index]) {
			return nullptr;
		}
		nodo = nodo->filho[index];
	}
	return nodo;
}
