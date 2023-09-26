#include <iostream>
#include "Queue.hpp";

using namespace std;

int main()
{

    Queue* queue = new Queue();

    cout << "Lista vazia: ";
    cout << queue->isEmpty() << endl << endl;

    for (int i = 0; i < 25; i++) {
        queue->enqueue(i);
    }

    cout << "Primeiro Elemento: ";
    cout << queue->head() << endl;

    cout << "Lista vazia: ";
    cout << queue->isEmpty() << endl << endl;

    cout << "\nFila: \n";

    for (int i = 0; i < 25; i++) {
        cout << queue->dequeue() << endl;
    }

    cout << "Lista vazia: ";
    cout << queue->isEmpty() << endl << endl;

    for (int i = 0; i < 5; i++) {
        queue->enqueue(i);
    }

    cout << "Tamanho Lista: ";
    cout << queue->size() << endl;

    queue->clear();

    cout << "Lista vazia: ";
    cout << queue->isEmpty() << endl << endl;

    for (int i = 0; i < 125; i++) {
        queue->enqueue(i);
    }

    cout << "\nFila: \n";

    for (int i = 0; i < 125; i++) {
        cout << queue->dequeue() << endl;
    }

}
/*
FIFO: First in first out
Métodos:
enqueue(e): insere o elemento no final da fila.
dequeue(): remove e retorna o elemento do início da fila.
head(): retorna, mas não remove, o primeiro elemento da fila.
size(): retorna o número de elementos da fila.
isEmpty: retorna true se a fila estiver vazia.
clear(): esvazia a fila.
*/
