#pragma once
#include <vector>
#include <string>

class Nodo {
public:
	bool palavraCompleta; 
	std::vector<Nodo*> filho; 
	Nodo(bool palavraCompleta = false) : palavraCompleta(palavraCompleta), filho(26, nullptr) {}
};

class CompressedTrie {
private:
	Nodo* nodoRaiz; 
	Nodo* nodoBusca(std::string& palavra);

public:
	CompressedTrie();
	~CompressedTrie();

	void inserir(std::string palavra);
	bool busca(std::string palavra);
	Nodo* buscaPrefixo(std::string prefixo);
};
