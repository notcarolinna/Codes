#define _CRT_SECURE_NO_WARNINGS // define para usar o scanf sem o compilador brigar comigo
#include <stdio.h>
#include <stdlib.h>

/*
Encontra o menor elemento da lista e troca com o primeiro elemento,
depois encontra o próximo menor e troca com o segundo elemento e assim
por diante até que o vetor esteja ordenado.
*/

void selection_sort(int vet[], int n) {

	int i, j, menor_valor, aux;

	for (i = 0; i < n - 1; i++) {

		menor_valor = i;

		for (j = i + 1; j < n; j++) {
			if (vet[j] < vet[menor_valor]) {
				menor_valor = j;
			}
		}

		if (menor_valor != i) {
			aux = vet[i];
			vet[i] = vet[menor_valor];
			vet[menor_valor] = aux;
		}
	}
}

int main() {

	int n, i;

	printf("Digite o tamanho do vetor: ");
	scanf("%d", &n);

	int* vet = (int*)malloc(n * sizeof(int));
	if (vet == NULL) {
		printf("Erros acontecem\n");
		return 1;
	}

	printf("Digite %d valores para o vetor:\n", n);
	for (i = 0; i < n; i++) {
		scanf("%d", &vet[i]);
	}

	selection_sort(vet, n);

	printf("vetor ordenado em ordem crescente:\n");
	for (i = 0; i < n; i++) {
		printf("%d ", vet[i]);
	}
	printf("\n");

	free(vet); // libera a memória alocada 
	return 0;
}

