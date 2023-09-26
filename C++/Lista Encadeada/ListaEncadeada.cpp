#include "Lista.h"

ListaEncadeada::ListaEncadeada() {
    nElementos = 0;
    fim = inicio = nullptr;
};

bool ListaEncadeada::add(int value) {
    if (this->isEmpty()) {
        inicio = new Nodo(value);
        fim = inicio;
        nElementos++;
    }
    else {
        Nodo* auxiliar = new Nodo(value);
        nElementos++;
        Nodo* busca = inicio;
        while (busca->getProximo() != nullptr)
            busca = busca->getProximo();

        busca->setProximo(auxiliar);

        fim = auxiliar;
    }
    return true;
}

bool ListaEncadeada::remove(int idx) {
    if ((idx > 0) && (idx < nElementos)) {
        Nodo* busca = inicio;
        if (idx == 0) {
            inicio = busca->getProximo();
            busca->setProximo(nullptr);
        }
        else {
            idx--;
            while (idx > 0) {
                busca = busca->getProximo();
                idx--;
            }
            Nodo* nodoAEliminar = busca->getProximo();
            busca->setProximo(nodoAEliminar->getProximo());
            nodoAEliminar->setProximo(nullptr);
        }

        nElementos--;
        return true;
    }
    else
        return false;
}

int ListaEncadeada::size() {
    return nElementos;
}

bool ListaEncadeada::isEmpty() {
    return (nElementos == 0);
}

int ListaEncadeada::get(int idx) {
    
    if ((idx < 0) || (idx >= nElementos))
        return -1;
    else {
        Nodo* busca = inicio;
        for (int i = 0; i < idx; i++)
            busca = busca->getProximo();
        return busca->getValor();
    }
}

void ListaEncadeada::clear() {
    while (nElementos > 0)
    {
        Nodo* auxiliar = inicio;
        inicio->setProximo(inicio->getProximo());
        delete auxiliar;
        nElementos--;
    }
    inicio = fim = nullptr;
}

ListaEncadeada::Nodo::Nodo(int valor) {
    this->valor = valor;
    this->proximo = nullptr;
}

int ListaEncadeada::Nodo::getValor() {
    return this->valor;
}

void ListaEncadeada::Nodo::setValor(int valor) {
    this->valor = valor;

}
ListaEncadeada::Nodo* ListaEncadeada::Nodo::getProximo() {
    return this->proximo;
}

void ListaEncadeada::Nodo::setProximo(Nodo* proximo) {
    this->proximo = proximo;
}
