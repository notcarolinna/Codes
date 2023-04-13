#include <iostream>
#include "trie.h"

Trie::Trie() {
	raiz = new Nodo('\0');
}

void Trie::inserir(std::string palavra) {

	/*
	Insere uma nova palavra na trie.
	1. iterar sobre cada caractere, começando pela raíz
	2. para cada caractere, verificar se já existe um filho com aquele valor e
		caso não exista, cria um novo nodo com o valor do caractere e adiciona-o
		como filho do nodo atual.
	3. atualizar o nodo atual para o novo filho criado e, com isso, o nodo atual é
		marcado como o final de uma palavra.
	*/

	Nodo* nodo_ = raiz;
	for (char c : palavra) {
		Nodo* filho = nodo_->buscaFilho(c);
		if (filho == nullptr) {
			filho = new Nodo(c);
			nodo_->filho.push_back(filho);
		}
		nodo_ = filho;
	}
	nodo_->fimPalavra = true;
}

bool Trie::busca(std::string palavra) {
	Nodo* nodo_ = raiz;
	for (char c : palavra) {
		nodo_ = nodo_->buscaFilho(c);
		if (nodo_ == nullptr) {
			return false;
		}
	}
	return nodo_->fimPalavra;
}
