#include <iostream>
#include "Heap.hpp"

using namespace std;

int main()
{
    Heap heap;
    int n, op, val;

    cout << "Digite a quantidade de valores a serem inseridos: ";
    cin >> n;
    cout << "Digite o valor a ser inserido: ";

    for (int i = 0; i < n; i++)
    {

        cin >> val;
        heap.put(val);
    }

    heap.print(0, 1, 32);

    while (true)
    {
        cout << endl
             << endl;
        cout << "1 - Inserir um número" << endl;
        cout << "2 - Remover raíz" << endl;
        cout << "3 - Sair" << endl;

        cin >> op;

        if (op == 1)
        {
            cout << "Digite o valor a ser inserido: ";
            cin >> val;
            heap.put(val);
        }
        else if (op == 2)
        {
            int res = heap.get();
            cout << "Valor removido: " << res << endl;
        }
        else if (op == 3)
        {
            break;
        }
        else
        {
            cout << "Erro." << endl;
        }

        heap.print(0, 1, 32);
    }

    return 0;
}
