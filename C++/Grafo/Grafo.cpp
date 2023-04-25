#include "Grafo.h"
#include <stdexcept>
#include <iostream>

void GrafoDir::Mark(int n) {
	mark[n] = true;
}

void GrafoDir::UnMark(int n) {
	mark[n] = false;
}

bool GrafoDir::isMarked(int n) {
	return mark[n] == true;
}

/* criação com capacidade para n nodos */
GrafoDir::GrafoDir(int n) {
	max = 100;
	if (n > 0) max = n;
	mark.resize(max, false);
	inuse.resize(max, false);
	matAdj.resize(max, std::vector<bool>(max, false));
}

/* Retorna número de nodos maximo do grafo */
int GrafoDir::NumNodos() {
	return max;
}

/* Retorna número de nodos em uso */
int GrafoDir::CapNodos() {
	int res = 0;
	for (int i = 0; i < max; i++)
		if (inuse[i]) res++;
	return res;
}

/* Retorna lista de nodos sendo usados no grafo: 0, 1, 2,..., n - 1 */
std::vector<int> GrafoDir::Nodos() {
	std::vector<int> res;
	for (int i = 0; i < max; i++)
		if (inuse[i])
			res.push_back(i);
	return res;
}

/* Retorna número total de arestas */
int GrafoDir::NumArestas() {
	int res = 0;
	for (int i = 0; i < max; i++)
		for (int j = 0; j < max; j++)
			if (matAdj[i][j]) res++;
	return res;
}

/* Insere Aresta
A inserção de aresta também cria os nodos se for preciso */
void GrafoDir::InsereAresta(int orig, int dest) {
	if (orig >= 0 && orig < max && dest >= 0 && dest < max) { //precisa ser 2 ifs separados?
		inuse[orig] = true;
		inuse[dest] = true;
		matAdj[orig][dest] = true;
		return;
	}
	throw std::invalid_argument("Insere aresta: Nodo(s) Invalidos(s)");
}

/* Remove Aresta */
void GrafoDir::RemoveAresta(int orig, int dest) {
	if (orig >= 0 && orig < max && dest >= 0 && dest < max) {
		matAdj[orig][dest] = false;
		return;
	}
	throw std::invalid_argument("Nodos: Nodo Invalido");
}

/* Retorna lista de vizinhos */
std::vector<int> GrafoDir::Vizinhos(int elem) {
	std::vector<int> res;
	if (elem >= 0 && elem < max) {
		for (int i = 0; i < max; i++) {
			if (matAdj[elem][i]) {
				res.push_back(i);
			}
		}
	}
	else {
		throw std::invalid_argument("Vizinhos: Nodo Invalido");
	}
	return res;
}

/* Insere Aresta /
/ A inserção de aresta também cria os nodos se for preciso */
void GrafoDir::InsereAresta(int orig, int dest) {
	if (orig >= 0 && orig < max)
		if (dest >= 0 && dest < max) {
			inuse[orig] = true;
			inuse[dest] = true;
			matAdj[orig][dest] = true;
			return;
		}
	throw std::invalid_argument("InsereAresta: Nodo(s) Invalidos(s)");
}

/* Remove Aresta */
void GrafoDir::RemoveAresta(int orig, int dest) {
	if (orig >= 0 && orig < max)
		if (dest >= 0 && dest < max) {
			matAdj[orig][dest] = false;
			return;
		}
	throw std::invalid_argument("RemoveAresta: Nodo(s) Invalidos(s)");
}

/* Testa se existe aresta */
bool GrafoDir::ExisteAresta(int orig, int dest) {
	if (orig >= 0 && orig < max)
		if (dest >= 0 && dest < max)
			return matAdj[orig][dest];
	throw std::invalid_argument("ExisteAresta: Nodo(s) Invalidos(s)");
}

/* Desmarca todos os nodos */
void GrafoDir::DesmarcaNodos() {
	for (int n : Nodos())
		UnMark(n);
}

/* Marca um nodo */
void GrafoDir::Marca(int n) {
	if (n >= 0 && n < max) {
		Mark(n);
		return;
	}
	throw std::invalid_argument("Marca: Nodo Invalido");
}

/* Desenho de grafos, ver http://www.graphviz.org/Gallery.php */
void GrafoDir::Graphviz() {
	std::cout << "digraph G {" << std::endl;
	std::cout << " rankdir = LR; " << std::endl;
	std::cout << " node [shape = circle]; " << std::endl;
	for (int i = 0; i < max; i++) {
		for (int j = 0; j < max; j++) {
			if (ExisteAresta(i, j)) {
				std::cout << " " << i << " -> " << j << ";" << std::endl;
			}
		}
	}
	std::cout << "}" << std::endl;
}

/* Busca em Profundidade */
void GrafoDir::Explore(int u) {
	if (!isMarked(u)) {
		Mark(u);
		std::vector<int> viz = Vizinhos(u);
		for (int i = 0; i < viz.size(); i++) {
			Explore(viz[i]);
		}
	}
}
