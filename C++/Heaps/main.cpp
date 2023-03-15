#include <iostream>
#include "Heap.h"

using namespace std;

int main()
{
	Heap heap;
	int n, op, val;

	cout << "Digite o tamanho do vetor: ";
	cin >> n;

	cout << "Digite os elementos do vetor: ";

	for (int i = 0; i < n; i++)
	{
		cin >> val;
		heap.put(val);
	}

	do
	{
		cout << "\n\n---------------------------:\n";
		cout << "1 - Inserir novo elemento\n";
		cout << "2 - Remover raíz\n";
		cout << "3 - Imprimir heap\n";
		cout << "4 - Sift up\n";
		cout << "5 - Sift down\n";
		cout << "0 - Sair\n";
		cout << "---------------------------:\n";
		cin >> op;

		switch (op)
		{
		case 1:
			cout << "Digite o valor a ser inserido: ";
			cin >> val;
			heap.put(val);
			break;
		case 2:
			val = heap.get();
			cout << "Elemento removido: " << val << endl;
			break;
		case 3:
			heap.print(0, 1, 64);
			break;
		case 4:
			cout << "Digite a pos do elemento: ";
			cin >> val;
			heap.sift_up(val);
			break;
		case 5:
			cout << "Digite a pos do elemento:";
			cin >> val;
			heap.sift_down(val);
			break;
		case 0:
			cout << "Saindo...\n";
			break;
		default:
			cout << "Erro.\n";
		}
	} while (op != 0);

	return 0;
}
