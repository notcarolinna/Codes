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
    int len(int a);

public:
    Heap();
    ~Heap();
    void put(int data); // Adiciona
    int get();          // Remove 

    void sift_up(int pos);
    void sift_down(int pos);
    void print(int b, int elem, int sp);

    void sift_up();
    void sift_down();
    void print();
};

#endif
