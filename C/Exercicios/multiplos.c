#include <stdio.h>
#include <stdlib.h>

/*
Etapas de desenvolvimento de frescura do código abaixo:
1. Calcular todos os múltiplos de A
2. Separar os múltiplos em um vetor
3. Separar os múltiplos pares e ímpares em dois vetores diferentes
4. Somar os elementos do vetor par e vetor ímpar
5. Somar os elemtentos pares na ordem crescente com os ímpares decrescentes
  */

int main() {
  int a, n;
  int vetor[10], pares[10], impares[10], soma[5];
  int j = 0, k = 0, s = 0; // contadores para os vetores pares, ímpares e soma
  int somaPares = 0, somaImpares = 0;

  printf("Digite um valor: ");
  scanf("%d", &a);

  // múltiplo: números inteiros que são divisíveis pelo A sem deixar resto.
  // para obtê-los, basta multiplicar o A por cada inteiro positivo.

  printf("\nMúltiplos de %d: ", a);
  for (int i = 1; i <= 10; i++) {
    n = a * i;
    printf("%d ", n);

    if (n % 2 == 0) { // se o múltiplo é par
      pares[j] = n;
      j++;
      somaPares += n;

    } else { // se o múltiplo é ímpar
      impares[k] = n;
      k++;
      somaImpares += n;
    }
  }

  // armazenando os múltiplos em um vetor
  for (int i = 0; i < 10; i++) {
    vetor[i] = a * (i + 1);
  }

  // imprimindo os vetores de pares e ímpares
  printf("\n\nMúltiplos pares: ");
  for (int i = 0; i < j; i++) {
    printf("%d ", pares[i]);
  }

  printf("\nMúltiplos ímpares: ");
  for (int i = 0; i < k; i++) {
    printf("%d ", impares[i]);
  }

  // imprimindo as somas de pares e ímpares
  printf("\n\nSoma dos múltiplos pares: %d", somaPares);
  printf("\nSoma dos múltiplos ímpares: %d\n", somaImpares);

  // criando o vetor de soma
  for (int i = 0; i < j / 2; i++) {
    soma[s] = pares[i] + impares[k - i - 1];
    s++;
  }

  // imprimindo o vetor de soma
  printf("\nVetor de soma: ");
  for (int i = 0; i < j && i < k; i++) {
    soma[i] = pares[i] + impares[k - i - 1];
    printf("%d ", soma[i]);
  }

  return 0;
}
