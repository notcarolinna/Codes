#include <iostream>
#include <vector>
#include <algorithm>

#define LINHAS 9
#define COLUNAS 9

class Ponto {
public:
    int linha;
    int coluna;

    Ponto(int linha = 0, int coluna = 0) : linha(linha), coluna(coluna) {}
};

bool isValid(int linha, int coluna, char mapa[LINHAS][COLUNAS]) {
    if (linha < 0 || coluna < 0 || linha >= LINHAS || coluna >= COLUNAS) {
        return false;
    }
    if (mapa[linha][coluna] == 'X') {
        return false;
    }
    return true;
}

int BFS(char mapa[LINHAS][COLUNAS], Ponto inicio, Ponto final) {

    bool percorrido[LINHAS][COLUNAS] = {false};
    int distancia[LINHAS][COLUNAS] = {0};
    int linha_movimento[] = { -1, 0, 1, 0 };
    int coluna_movimento[] = { 0, 1, 0, -1 };

    percorrido[inicio.linha][inicio.coluna] = true;
    distancia[inicio.linha][inicio.coluna] = 0;

    std::vector<Ponto> fila;
    fila.push_back(inicio);

    while (!fila.empty()) {
        Ponto atual = fila[0];
        fila.erase(fila.begin());
        if (atual.linha == final.linha && atual.coluna == final.coluna) {
            return distancia[atual.linha][atual.coluna];
        }
        for (int i = 0; i < 4; i++) {
            int nova_linha = atual.linha + linha_movimento[i];
            int nova_coluna = atual.coluna + coluna_movimento[i];
            if (isValid(nova_linha, nova_coluna, mapa) && !percorrido[nova_linha][nova_coluna]) {
                percorrido[nova_linha][nova_coluna] = true;
                distancia[nova_linha][nova_coluna] = distancia[atual.linha][atual.coluna] + 1;
                fila.push_back(Ponto(nova_linha, nova_coluna));
            }
        }
    }

    return -1;
}


int main() {
	char mapa[LINHAS][COLUNAS] = {
		{ '0', '0', '3', 'X', '0', '0', 'X', '8', '0' },
		{ '0', 'X', 'X', '0', '0', '0', '0', '0', '0' },
		{ '0', '0', '0', '0', '9', '0', '0', 'X', '2' },
		{ '0', '0', '0', '0', '0', '0', '0', 'X', 'X' },
		{ '4', 'X', 'X', 'X', 'X', '0', '0', '0', '0' },
		{ '0', 'X', '1', '0', '0', '0', 'X', '0', '0' },
		{ '0', 'X', '0', '0', '0', '7', 'X', '0', '0' },
		{ '0', '0', '0', 'X', '0', '0', '0', 'X', '0' },
		{ '0', '6', '0', '0', 'X', '0', '0', 'X', '5' },
	};

	Ponto inicio = { 0, 0 };
	Ponto final = { 0, 0 };
	for (int i = 0; i < LINHAS; i++) {
		for (int j = 0; j < COLUNAS; j++) {
			if (mapa[i][j] == '9') {
				inicio.linha = i;
				inicio.coluna = j;
			}
			if (mapa[i][j] == '1') {
				final.linha = i;
				final.coluna = j;
			}
		}
	}

	int movimentos = BFS(mapa, inicio, final);
	if (movimentos == -1) {
		printf("Caminho entre os pontos inexistente\n");
	}
	else {
		printf("Menor quantidade de movimentos necessaria: %d\n", movimentos);
	}

	Ponto posicao_atual = inicio;
	int numero_atual = 1;
	int movimentos_totais = 0;
	while (numero_atual <= 9) {
		Ponto proximo_numero;
		bool encontrado = false;
		for (int i = 0; i < LINHAS; i++) {
			for (int j = 0; j < COLUNAS; j++) {
				if (mapa[i][j] == '0' + numero_atual) {
					proximo_numero.linha = i;
					proximo_numero.coluna = j;
					encontrado = true;
					break;
				}
			}
			if (encontrado) {
				break;
			}
		}

		int distancia = BFS(mapa, posicao_atual, proximo_numero);
		if (distancia == -1) {
			//printf("Caminho entre os pontos inexistente\n");
			return -1;
		}
		movimentos_totais += distancia;
		posicao_atual = proximo_numero;
		numero_atual++;
	}

	printf("Total de movimentos para percorrer todos os elementos de forma ordenada: %d\n", movimentos_totais);

	return 0;
}
