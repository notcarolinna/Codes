#define _CRT_SECURE_NO_WARNINGS // define para usar o scanf sem o compilador brigar comigo
#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int vet[], int n) {

    int i, j, aux, troca;

    for (i = 0; i < n - 1; i++) {

        troca = 0;

        for (j = 0; j < n - i - 1; j++) {
            if (vet[j] > vet[j + 1]) {
                aux = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = aux;
                troca = 1;
            }
        }
        if (troca == 0)
            break;
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

    bubble_sort(vet, n);

    printf("vetor ordenado em ordem crescente:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");

    free(vet); // libera a memória alocada 
    return 0;
}
