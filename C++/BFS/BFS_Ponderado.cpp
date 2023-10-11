#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <limits>

class Graph {
    int numVertices;
    std::vector<std::list<std::pair<char, int>>> listaAdjacentes;
    bool* visitados;

public:
    Graph(int vertices);
    void addAresta(char inicio, char fim, int peso);
    int BFS(char inicio, char fim);
};

Graph::Graph(int vertices) {
    numVertices = vertices;
    listaAdjacentes.resize(vertices);
}

void Graph::addAresta(char inicio, char fim, int peso) {
    listaAdjacentes[inicio - 'A'].push_back(std::make_pair(fim, peso));
    listaAdjacentes[fim - 'A'].push_back(std::make_pair(inicio, peso));
}

int Graph::BFS(char inicio, char fim) {
    std::vector<int> pai(numVertices, -1); 
    std::vector<int> custo(numVertices, std::numeric_limits<int>::max()); 
    custo[inicio - 'A'] = 0;

    std::priority_queue<std::pair<int, char>, std::vector<std::pair<int, char>>, std::greater<std::pair<int, char>>> filaPrioridade;
    filaPrioridade.push(std::make_pair(0, inicio));

    while (!filaPrioridade.empty()) {
        char verticeAtual = filaPrioridade.top().second;
        filaPrioridade.pop();

        if (verticeAtual == fim) {
            return custo[verticeAtual - 'A'];
        }

        for (const auto& aresta : listaAdjacentes[verticeAtual - 'A']) {
            char verticeAdjacente = aresta.first;
            int pesoAresta = aresta.second;
            int custoNovo = custo[verticeAtual - 'A'] + pesoAresta;

            if (custoNovo < custo[verticeAdjacente - 'A']) {
                custo[verticeAdjacente - 'A'] = custoNovo;
                filaPrioridade.push(std::make_pair(custoNovo, verticeAdjacente));
                pai[verticeAdjacente - 'A'] = verticeAtual;
            }
        }
    }
    return -1; 
}

int main() {
    Graph g(7);

    g.addAresta('A', 'B', 2);
    g.addAresta('A', 'C', 3);
    g.addAresta('B', 'D', 2);
    g.addAresta('C', 'E', 1);
    g.addAresta('D', 'F', 2);
    g.addAresta('E', 'F', 3);
    g.addAresta('A', 'G', 5);
    g.addAresta('G', 'F', 2);

    char inicio = 'A';
    char fim = 'F';

    int pesoCaminho = g.BFS(inicio, fim);

    if (pesoCaminho != -1) {
        std::cout << "Menor peso do caminho de " << inicio << " para " << fim << ": " << pesoCaminho << std::endl;
    }
    else {
        std::cout << "Não há caminho de " << inicio << " para " << fim << std::endl;
    }

    return 0;
}
