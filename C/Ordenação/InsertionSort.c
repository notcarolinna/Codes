#define _CRT_SECURE_NO_WARNINGS // define para usar o scanf sem o compilador brigar comigo
#include <stdio.h>
#include <stdlib.h>
 
//O Insertion Sort seleciona um elemento para análise e compara com os elementos de sua esquerda.

void insertion_sort(int vet[], int n) {

	int i, aux, j;

	// O aux nesse código é usado para armazenar temporariamente o valor do elemento
	// que está ssendo analisado

	for (i = 1; i < n; i++) {
		aux = vet[i];
		j = i - 1;

		while (j >= 0 && vet[j] > aux) {
			vet[j + 1] = vet[j];
			j = j--;
		}
		vet[j + 1] = aux;
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

	insertion_sort(vet, n);

	printf("vetor ordenado em ordem crescente:\n");
	for (i = 0; i < n; i++) {
		printf("%d ", vet[i]);
	}
	printf("\n");

	free(vet); // libera a memória alocada 
	return 0;
}
