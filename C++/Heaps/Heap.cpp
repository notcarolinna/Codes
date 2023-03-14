#include <iostream>
#include "Heap.hpp"

using namespace std;

Heap::Heap()
{
    used = 0;
    v = new int[100];
}

Heap::~Heap()
{
    delete[] v;
}

int Heap::left(int i)
{
    // O filho esquerdo de quem está na pos i
    // está na posição 2i+1

    return 2 * i + 1;
}

int Heap::right(int i)
{
    // O filho direito de quem está na pos i
    // está na posição 2i+2

    return 2 * i + 2;
}

int Heap::parent(int i)
{
    // Fórmula para saber o pai: (i - 1) / 2

    return (i - 1) / 2;
}

void Heap::sift_down(int pos) // IMPLEMENTAR
{

    /*
    sift_down: a raíz é substituída pelo último elemento da árvore e, para restaurar o heap, utiliza o sift_down.
    Compara o elemento que foi movido para a raiz com os dois filhos, efetuando as trocas necessárias.

    Max-heap: Pai >= Filhos
    Min-heap: Pai <= Filhos

    Complexidade: O(log n)
    */

    int maxIndex = pos;
    int l = left(pos);
    int r = right(pos);

    // Verifica se o índice do filho está dentro da heap (l/r < used)
    // E SE o valor dos filhos for maior que o valor atual (v[l/r] > v[maxIndex]),
    // irá retornar l/r.

    if (l < used && v[l] > v[maxIndex])
    {
        maxIndex = l;
    }

    if (r < used && v[r] > v[maxIndex])
    {
        maxIndex = r;
    }

    // Se a condição abaixo for verdadeira, significa que um dos filhos tem valor maior
    // que a posição atual.

    if (pos != maxIndex)
    {
        // troca
        int aux = v[pos];
        v[pos] = v[maxIndex];
        v[maxIndex] = aux;

        sift_down(maxIndex); // Recursão :)
    }
}

void Heap::sift_up(int pos) // IMPLEMENTAR
{
    // pos: novo elemento inserido no heap

    int aux;

    // Enquanto a posição de pos for maior que 0 E o valor de pos for maior que o do seu pai

    while (pos > 0 && v[pos] > v[parent(pos)])
    {
        // troca
        aux = v[parent(pos)];
        v[parent(pos)] = v[pos];
        v[pos] = aux;

        pos = parent(pos); // Recursão
    }
}

void Heap::put(int data)
{
    v[used] = data;
    sift_up(used);
    used++;
}

int Heap::get()
{
    int res = v[0];
    v[0] = v[--used];
    sift_down(0);
    return res;
}

int Heap::len(int a)
{
    int res = 0;
    while (a > 0)
    {
        res++;
        a /= 10;
    }
    return res;
}

void Heap::print(int b, int elem, int sp)
{
    // Os parâmetros da função são usados para controlar
    // a posição de impressão dos elementos do heap na tela.
    // A variável sp controla o espaçamento entre os elementos.

    int i, j;

    // Imprime os elementos do heap em uma única linha:

    cout << endl;
    for (j = 0; j < used; j++)
        cout << v[j] << " ";
    cout << endl;

    // Imprime a estrutura do heap:

    while (true)
    {
        // Primeiro for: printa espaços em branco para alinhar a raíz da sub-árvore

        for (j = 0; j <= sp / 2; j++)
            cout << " ";

        // Imprime os elementos da sub-árvore

        for (i = b; i < b + elem; i++)
        {
            if (i == used) // Se todos os elementos da sub-árvore já foram impressos, dá retorno
                return;

            // Caso exista elementos de alguma sub-árvore que não foram impressos:

            int aux = len(v[i]);
            cout << v[i]; // Printa o valor armazenado no array na posição i

            // Impressão dos espaços em branco para completar a largura de sp

            for (j = 0; j < sp - aux; j++)
                cout << " ";
        }

        cout << endl;
        b = b + elem;    // atualiza o valor da raíz
        elem = 2 * elem; // atualiza o número de elementos na linha atual
        sp = sp / 2;     // atualiza o espaçamento
    }
}

