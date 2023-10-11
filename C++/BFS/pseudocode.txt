void Caminha(Grafo& v, int u) { // Declaração da função com o grafo v e o vértice inicial u
    vector<bool> visitado(v.size(), false); // Cria um vetor booleano para marcar os vértices visitados e inicializa todos como não visiados
    visitado[u] = true; // Marca o vértice inicial como visitado
    stack<int> caderninho; // Cria uma pilha para armazenar os vértices a serem visitados

    while (!caderninho.empty()) { // Enquanto a pilha não estiver vazia
        caderninho.push(u); // Adiciona o vértice inicial na pilha
        int atual = caderninho.top(); // Armazena o topo da pilha (o último vértice adicionado) na variável atual
        caderninho.pop(); // Remove o topo da pilha

        // Percorre todos os vizinhos não visitados do vértice atual
        for (int i = 0; i < v[atual].size(); i++) {
            int vizinho = v[atual][i]; // Armazena o vizinho atual
            if (!visitado[vizinho]) { // Se o vizinho não foi visitado
                visitado[vizinho] = true; // Marca o vizinho como visitado
                caderninho.push(vizinho); // Adiciona o vizinho na pilha
            }
        }
    }
}
