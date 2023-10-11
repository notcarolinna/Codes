#include <iostream>
#include <list>
#include <queue>
#include <vector>

class Graph {
    int numVertices;
    std::list<int>* listaAdjacentes;
    bool* visitados;

public:
    Graph(int vertices);
    void addAresta(int inicio, int fim);
    void BFS(int verticeInicial);
    std::vector<int> BFS(int inicio, int fim);
};

Graph::Graph(int vertices) {
    numVertices = vertices;
    listaAdjacentes = new std::list<int>[vertices];
}

void Graph::addAresta(int inicio, int fim) {
    listaAdjacentes[inicio].push_back(fim);
    listaAdjacentes[fim].push_back(inicio);
}


std::vector<int> Graph::BFS(int inicio, int fim) {
    std::vector<int> caminho;
    std::queue<int> fila;
    std::vector<int> pai(numVertices, -1); 

    visitados = new bool[numVertices];
    for (int i = 0; i < numVertices; i++) {
        visitados[i] = false;
    }

    visitados[inicio] = true;
    fila.push(inicio);

    while (!fila.empty()) {
        int verticeAtual = fila.front();
        fila.pop();

        if (verticeAtual == fim) {
            int v = fim;
            while (v != -1) {
                caminho.push_back(v);
                v = pai[v];
            }
            std::reverse(caminho.begin(), caminho.end());
            return caminho;
        }

        for (int verticeAdjacente : listaAdjacentes[verticeAtual]) {
            if (!visitados[verticeAdjacente]) {
                visitados[verticeAdjacente] = true;
                fila.push(verticeAdjacente);
                pai[verticeAdjacente] = verticeAtual;
            }
        }
    }

    return caminho; 
}

int main() {
    Graph g(30);

    g.addAresta(0, 1);
    g.addAresta(0, 2);
    g.addAresta(1, 3);
    g.addAresta(2, 4);
    g.addAresta(3, 5);
    g.addAresta(4, 5);
    g.addAresta(0, 6);
    g.addAresta(6, 5);
    g.addAresta(1, 7);
    g.addAresta(2, 8);
    g.addAresta(3, 9);
    g.addAresta(4, 10);
    g.addAresta(5, 11);
    g.addAresta(6, 12);
    g.addAresta(7, 13);
    g.addAresta(8, 14);
    g.addAresta(9, 15);
    g.addAresta(10, 16);
    g.addAresta(11, 17);
    g.addAresta(12, 18);
    g.addAresta(13, 19);
    g.addAresta(14, 20);
    g.addAresta(15, 21);
    g.addAresta(16, 22);
    g.addAresta(17, 23);
    g.addAresta(0, 5);
    g.addAresta(19, 25);
    g.addAresta(20, 26);
    g.addAresta(21, 27);
    g.addAresta(22, 28);
    g.addAresta(23, 29);

    int inicio = 0;
    int fim = 5;

    std::vector<int> caminho = g.BFS(inicio, fim);

    if (!caminho.empty()) {
        std::cout << "Menor caminho de " << inicio << " para " << fim << ": ";
        for (int vertice : caminho) {
            std::cout << vertice << " ";
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "Não há caminho de " << inicio << " para " << fim << std::endl;
    }

    return 0;
}
