#include <iostream>
#include <string>
#include "Compressed.h"

int main() {

	CompressedTrie trie;

	trie.inserir("macaco");
	trie.inserir("coco");
	trie.inserir("pedra");
	trie.inserir("anna");
	trie.inserir("banana");

	std::string palavra;

	while (true) {
		std::cout << "Digite uma palavra para nodoBuscar na trie (ou 1 para sair): ";
		std::getline(std::cin, palavra);

		if (palavra == "1") {
			break;
		}

		if (trie.busca(palavra)) {
			std::cout << "Palavra encontrada na trie!" << std::endl;
		}
		else {
			std::cout << "Palavra nao encontrada na trie." << std::endl;
		}
	}

	return 0;
}
