#pragma once

class ListaEncadeada {

private:

    class Nodo {
    private:
        int valor; 
        Nodo* proximo; 

    public:
        int getValor();
        Nodo(int valor);
        void setValor(int valor);
        Nodo* getProximo();
        void setProximo(Nodo* proximo);
    };


    Nodo* inicio;
    Nodo* fim;
    int nElementos;


public:
    ListaEncadeada();
    bool add(int value);
    bool remove(int pos);
    int size();
    bool isEmpty();
    int get(int pos);
    void clear();
};
