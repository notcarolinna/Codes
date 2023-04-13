#include <stdio.h>

/*
O programa abaixo recebe dois valores A e B e um valor n (expoente) inseridos
pelo usuário e armazena a potência dos primos entre eles em um vetor. Depois,
substitui o elemento da posição i pela soma de todos os outros elementos do
vetor.
*/

int main() {
  int inicial, final, expoente;
  int flag;
  int k = 0;

  printf("Digite o valor inicial: ");
  scanf("%d", &inicial);
  printf("Digite o valor final: ");
  scanf("%d", &final);
  printf("Digite o valor do expoente: ");
  scanf("%d", &expoente);

  int vet[final - inicial + 1]; // vetor para armazenar as potências dos primos
  int somas[final - inicial + 1]; // vetor para armazenar as somas

  // imprime a lista de primos
  printf("\nPrimos entre %d e %d:", inicial, final);
  for (int i = inicial; i <= final; i++) {
    flag = 0; // flag para indicar se o número i é primo ou não
              // verifica se o número i é primo
    for (int j = 2; j < i; j++) {
      if (i % j == 0) {
        flag = 1;
        break;
      }
    }
    if (flag == 0 && i != 1) {
      printf(" %d", i);
    }
  }

  // imprime o vetor com as potências dos primos e calcula as somas
  printf("\n\nPotências dos primos entre %d e %d:\n", inicial, final);
  for (int i = inicial; i <= final; i++) {
    flag = 0; // flag para indicar se o número i é primo ou não
              // verifica se o número i é primo
    for (int j = 2; j < i; j++) {
      if (i % j == 0) {
        flag = 1;
        break;
      }
    }

    // se o número i for primo, calcula sua potência e armazena no vetor
    if (flag == 0 && i != 1) {
      int potencia = 1;
      for (int j = 1; j <= expoente; j++) {
        potencia *= i;
      }
      printf("%d^%d = %d\n", i, expoente,
             potencia); // imprime o valor primo elevado à n potência
      vet[k] = potencia;
    }
  }
  // imprime o vetor com as potências dos primos e calcula as somas
  printf("\nPotências dos primos entre %d e %d:\n", inicial, final);
  for (int i = inicial; i <= final; i++) {
    flag = 0; // flag para indicar se o número i é primo ou não
              // verifica se o número i é primo
    for (int j = 2; j < i; j++) {
      if (i % j == 0) {
        flag = 1;
        break;
      }
    }

    // se o número i for primo, calcula sua potência e armazena no vetor
    if (flag == 0 && i != 1) {
      int potencia = 1;
      for (int j = 1; j <= expoente; j++) {
        potencia *= i;
      }
      printf("%d^%d = %d\n", i, expoente,
             potencia); // imprime o valor primo elevado à n potência
      vet[k] = potencia;
      k++;
    }
  }

  // imprime o vetor com as potências dos primos
  printf("\nVetor com as potências dos primos:\n");
  for (int i = 0; i < k; i++) {
    printf("%d ", vet[i]);
  }

  // substitui o valor de i pela soma de todos os outros elementos do vetor, sem
  // contar o próprio i
  printf("\nSoma de todos os elementos do vetor:\n");
  for (int i = 0; i < k; i++) {
    somas[i] = 0;
    for (int j = 0; j < k; j++) {
      if (i != j) {
        somas[i] += vet[j];
      }
    }
    printf("%d ", somas[i]);
  }

  return 0;
}
