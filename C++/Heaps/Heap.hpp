#ifndef HEAP_HPP
#define HEAP_HPP

class Heap
{
private:
    int *v;
    int used; // Elementos das sub-árvores

    int left(int i);
    int right(int i);
    int parent(int i);

    void sift_up(int pos);
    void sift_down(int pos);

    int len(int a);
    void print(int b, int elem, int sp);

public:
    Heap();
    ~Heap();
    void put(int data); // int data: valor do elemento que será inserido pela função no heap
    int get();          // Remove e retorna a raíz e substitui pelo elemento adicionado pelo sift_down
    void print();

};

#endif
