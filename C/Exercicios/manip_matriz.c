#include <stdio.h>
#include <stdlib.h>

int calcularSomaElementos(int **matriz, int linhas, int colunas) {
  int soma = 0;
  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
      soma += matriz[i][j];
    }
  }
  return soma;
}

void calcularSomaColunas(int **matriz, int linhas, int colunas, int *somaColunas) {
  for (int j = 0; j < colunas; j++) {
    int soma = 0;
    for (int i = 0; i < linhas; i++) {
      soma += matriz[i][j];
    }
    somaColunas[j] = soma;
  }
}

void transposicao(int **matriz, int linhas, int colunas) {

  int **matrizTransposta = (int **)malloc(colunas * sizeof(int *));

  for (int i = 0; i < colunas; i++) {
    matrizTransposta[i] = (int *)malloc(linhas * sizeof(int));
    for (int j = 0; j < linhas; j++) {
      matrizTransposta[i][j] = matriz[j][i];
    }
  }

  printf("\n\nMatriz transposta:\n");
  for (int i = 0; i < colunas; i++) {
    for (int j = 0; j < linhas; j++) {
      printf("%d ", matrizTransposta[i][j]);
    }
    printf("\n");
  }
  free(matrizTransposta);
}

float calcularMediaElementos(int **matriz, int linhas, int colunas) {
  int soma = calcularSomaElementos(matriz, linhas, colunas);
  return (float)soma / (linhas * colunas);
}

void encontrarMaiorElemento(int **matriz, int linhas, int colunas, int *maiorValor, int *linhaMaior, int *colunaMaior) {

  *maiorValor = matriz[0][0];
  *linhaMaior = 0;
  *colunaMaior = 0;

  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
      if (matriz[i][j] > *maiorValor) {
        *maiorValor = matriz[i][j];
        *linhaMaior = i;
        *colunaMaior = j;
      }
    }
  }
}

int main() {
  int linhas, colunas;

  printf("Digite o número de linhas da matriz: ");
  scanf("%d", &linhas);
  printf("Digite o número de colunas da matriz: ");
  scanf("%d", &colunas);

  int **matriz = (int **)malloc(linhas * sizeof(int *));
  for (int i = 0; i < linhas; i++) {
    matriz[i] = (int *)malloc(colunas * sizeof(int));
  }

  printf("Digite os elementos da matriz:\n");
  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
      scanf("%d", &matriz[i][j]);
    }
  }

  // Calcula a soma dos elementos
  int somaElementos = calcularSomaElementos(matriz, linhas, colunas);
  printf("\n\nSoma dos elementos: %d\n", somaElementos);

  // Calcula a soma dos elementos de cada coluna
  int *somaColunas = (int *)malloc(colunas * sizeof(int));
  calcularSomaColunas(matriz, linhas, colunas, somaColunas);
  printf("Soma dos elementos de cada coluna: ");
  for (int j = 0; j < colunas; j++) {
    printf("%d ", somaColunas[j]);
  }

  // Calcula a média dos elementos
  float mediaElementos = calcularMediaElementos(matriz, linhas, colunas);
  printf("\nMedia dos elementos: %.2f\n", mediaElementos);

  // Encontra as coordenadas do maior elemento da matriz
  int maiorValor, linhaMaior, colunaMaior;
  encontrarMaiorElemento(matriz, linhas, colunas, &maiorValor, &linhaMaior,
                         &colunaMaior);
  printf("Coordenadas do maior elemento: (%d, %d)\n", linhaMaior, colunaMaior);

  // Troca as linhas da matriz pelas colunas (transposição)
  transposicao(matriz, linhas, colunas);

  // Liberar a memória alocada para a matriz e somaColunas
  for (int i = 0; i < linhas; i++) {
    free(matriz[i]);
  }
  free(matriz);
  free(somaColunas);

  return 0;
}
