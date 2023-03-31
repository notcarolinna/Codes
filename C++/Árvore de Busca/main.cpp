#include <iostream>
#include "BinaryTree.h"

// Cada nodo tem no máximo dois filhos.
// Já insere os elementos na árvore em ordem

int main() {
	BinaryTree tree;

	int opcao = 0, valor = 0;

	do {
		std::cout << "\nEscolha uma opcao:" << std::endl;
		std::cout << "1 - Inserir valor" << std::endl;
		std::cout << "2 - Buscar valor" << std::endl;
		std::cout << "3 - Buscar valores em ordem" << std::endl;
		std::cout << "4 - Imprimir arvore" << std::endl;
		std::cout << "5 - Encerrar o programa" << std::endl;

		std::cin >> opcao;

		switch (opcao) {
		case 1:

			std::cout << "\nDigite o valor a ser inserido: ";
			std::cin >> valor;
			tree.insert(valor);
			break;

		case 2:

			std::cout << "\nDigite o valor a ser buscado: ";
			std::cin >> valor;
			if (tree.busca(valor)) {
				std::cout << "Valor encontrado!" << std::endl;
			}
			else {
				std::cout << "Valor nao encontrado." << std::endl;
			}
			break;

		case 3:

			std::cout << "\nValores na arvore em ordem:" << std::endl;
			tree.buscaOrdenada();
			std::cout << std::endl;
			break;

		case 4:

			std::cout << "\nArvore:" << std::endl;
			tree.print();
			break;

		case 5:

			std::cout << "\nEncerrando programa." << std::endl;
			break;

		default:
			std::cout << "\nOpcao invalida." << std::endl;
		}
	} while (opcao != 5);

	return 0;
}
