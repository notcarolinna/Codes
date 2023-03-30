#include <iostream>
#include "HashTable.h"

using namespace std;

/*
	Hash é uma estrutura que mapeia chaves para valores.
O objetivo da tabela hash é calcular um índice em uma
tabela, que contém o valor da chave. As chaves devem ser
mapeadas em um índice exclusivo de modo que as pesquisas
possam ser feitas em notação O(1).

Lógica de resolução:

	1 - Criação de um vetor de ponteiros para os nodos,
onde cada nodo é uma lista encadeada
	2 - A chave é usada para calcular o índice no vetor.
Se a chave já existir na lista, o valor correspondente é
atualizado (ossinhos do Rubens), caso contrário, um novo
nodo é adicionado à lista.
	3 - Se a tabela ficara muito cheía, é necessário aumentar
o tamanho do vetor.
	4 - Operações: remoção e pesquisa de valores por chave.

*/

int main() {

	int capacidade = 0, op = 0;

	cout << "Digite a capacidade da hash: ";
	cin >> capacidade;

	HashTable hash(capacidade);

	do {

		cout << endl;
		cout << "Digite a funcionalidade desejada:" << endl;
		cout << "1. Adicionar um valor" << endl;
		cout << "2. Remover um valor" << endl;
		cout << "3. Buscar um valor" << endl;
		cout << "4. Exibir a hash" << endl;
		cout << "5. Encerrar o programa" << endl;
		cin >> op;


		switch (op) {

		case 1:

			int indice, valor;
			cout << "Digite o indice: ";
			cin >> indice;
			cout << "Digite o valor: ";
			cin >> valor;
			hash.insert(indice, valor);
			break;

		case 2:

			cout << "Digite o indice do valor a ser removido: ";
			cin >> indice;
			if (hash.remove(indice)) {
				cout << "Valor removido." << endl;
			}
			else {
				cout << "Valor nao encontrado." << endl;
			}
			break;

		case 3:

			cout << "Digite o indice do valor a ser buscado: ";
			cin >> indice;
			int resultado;
			if (hash.busca(indice, resultado)) {
				cout << "Valor encontrado: " << resultado << endl;
			}
			else {
				cout << "Valor nao encontrado." << endl;
			}
			break;


		case 4:

			hash.print();
			break;

		case 5:

			cout << "Programa encerrado" << endl;
			break;

		default:

			cout << "Erro: funcionalidade inva lida." << endl;
			break;
		}

	} while (op != 5);

	return 0;
}
