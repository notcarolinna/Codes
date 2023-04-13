#include <iostream>
#include "Trie.h"

/*
Uma trie é uma estrutura de dados que permite armazenar um conjunto de palavras
de forma eficiente e possibilita uma rápida busca e inserção de novas palavras.
A trie é especialmente útil em problemas que envolvem a busca de palavras em um
grande conjunto de strings, como em dicionários, sistemas de sugestão de autocompletar,
sistemas de correção ortográfica, etc.
*/

int main() {
	Trie trie;

	trie.inserir("macaquinho");
	trie.inserir("pedra");
	trie.inserir("coco");
	trie.inserir("JB");
	trie.inserir("Zorg");

	while (true) {

		std::string palavra;
		std::cout << "Digite a palavra a ser buscada na trie (ou F para sair): ";
		std::cin >> palavra;

		if (palavra == "F" || palavra == "f") {
			break;
		}

		if (trie.busca(palavra)) {
			std::cout << "A palavra '" << palavra << "' foi encontrada na trie!" << std::endl;
		}
		else {
			std::cout << "A palavra '" << palavra << "' nao foi encontrada na trie." << std::endl;
		}
	}

	return 0;
}
