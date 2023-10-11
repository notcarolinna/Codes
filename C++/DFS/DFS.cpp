#include <iostream>
#include <list>

class Graph {
    int numVertices;
    std::list<int>* listaAdjacentes;
    bool* visitados;

public:
    Graph(int V);
    void addAresta(int inicio, int fim);
    int Caminhos(int u, int v);
    int ContarCaminhos(int u, int v);
};

Graph::Graph(int vertices) {
    numVertices = vertices;
    listaAdjacentes = new std::list<int>[vertices];
    visitados = new bool[vertices];
}

void Graph::addAresta(int inicio, int fim) {
    listaAdjacentes[inicio].push_back(fim);
}

int Graph::Caminhos(int u, int v) {
    visitados = new bool[numVertices]; 
    for (int i = 0; i < numVertices; i++) {
        visitados[i] = false;
    }
    return ContarCaminhos(u, v);
}

int Graph::ContarCaminhos(int u, int v) {
    if (u == v) {
        return 1; // Encontrou um caminho
    }

    visitados[u] = true;
    int contagem = 0;

    for (const auto& adjacente : listaAdjacentes[u]) {
        if (!visitados[adjacente]) {
            contagem += ContarCaminhos(adjacente, v);
        }
    }

    visitados[u] = false;
    return contagem;
}

int main() {
    Graph g(7);

    g.addAresta(0, 1);
    g.addAresta(0, 2);
    g.addAresta(1, 3);
    g.addAresta(2, 4);
    g.addAresta(3, 5);
    g.addAresta(4, 5);
    g.addAresta(0, 6);
    g.addAresta(6, 5);

    int u = 0; // inicio
    int v = 5; // fim

    int numeroCaminhos = g.Caminhos(u, v);

    std::cout << "Total de caminhos diferentes: " << numeroCaminhos << std::endl;

    return 0;
}
