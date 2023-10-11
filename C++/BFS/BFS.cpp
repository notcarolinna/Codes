#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <unordered_map>

class Graph {
	std::map<std::string, std::list<std::pair<std::string, int>>> listaAdjacentes;

public:
	Graph();
	void addAresta(const std::string& u, const std::string& v, int peso);
	bool BFS(const std::string& u, const std::string& v);
};

Graph::Graph() {
}

void Graph::addAresta(const std::string& u, const std::string& v, int peso) {
	listaAdjacentes[u].push_back(std::make_pair(v, peso));
}

bool Graph::BFS(const std::string& u, const std::string& v) {
	if (u == v) {
		return true;
	}

	std::queue<std::string> fila;
	std::unordered_map<std::string, bool> visitados;

	for (const auto& pair : listaAdjacentes) {
		visitados[pair.first] = false;
	}

	fila.push(u);
	visitados[u] = true;

	while (!fila.empty()) {
		std::string vertice_atual = fila.front();
		fila.pop();

		for (const auto& vizinho : listaAdjacentes[vertice_atual]) {
			std::string vertice_vizinho = vizinho.first;
			if (!visitados[vertice_vizinho]) {
				fila.push(vertice_vizinho);
				visitados[vertice_vizinho] = true;

				if (vertice_vizinho == v) {
					return true;
				}
			}
		}
	}

	return false; 
}

int main() {
	Graph g;

	g.addAresta("A", "B", 2);
	g.addAresta("B", "C", 1);
	g.addAresta("C", "D", 3);
	g.addAresta("D", "E", 4);

	if (g.BFS("A", "E")) {
		std::cout << "Caminho de A para E encontrado." << std::endl;
	}
	else {
		std::cout << "Caminho de A para E não encontrado." << std::endl;
	}

	return 0;
}
