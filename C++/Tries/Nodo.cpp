#include "Nodo.h"

Nodo::Nodo(char c) {
	valorNodo = c;
	fimPalavra = false;
}

Nodo* Nodo::buscaFilho(char c) {
	for (Nodo* filho : filho) {
		if (filho->valorNodo == c) {
			return filho;
		}
	}
	return nullptr;
}
