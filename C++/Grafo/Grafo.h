#pragma once

#include <vector>

class GrafoDir {
private:
	int max;
	std::vector<bool> mark;
	std::vector<bool> inuse;
	std::vector<std::vector<bool>> matAdj;
	std::vector<int> Nodos();
	std::vector<int> Vizinhos(int elem);

public:
	void Mark(int n);
	void UnMark(int n);
	bool isMarked(int n);

	GrafoDir(int n);
	int NumNodos();
	int CapNodos();
	void DesmarcaNodos();

	int NumArestas();
	void InsereAresta(int orig, int dest);
	void RemoveAresta(int orig, int dest);
	bool ExisteAresta(int orig, int dest);

	void Marca(int n);
	void Graphviz();
	void Explore(int u);
};
