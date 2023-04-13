#include <math.h>
#include <stdio.h>

int main() {
  int a, b, primo, count = 0, soma = 0;

  printf("Digite dois números inteiros positivos: ");
  scanf("%d %d", &a, &b);

  printf("Os números não primos entre %d e %d são:\n", a, b);

  for (int i = a; i <= b; i++) {
    primo = 1; // 1 = verdadeiro

    // se um número for menor que 2, ele não tem chance alguma de ser primo,
    // com isso, primo recebe o valor de falso.
    if (i < 2) {
      primo = 0; // 0 = falso
    }

    // O loop abaixo começa com j igual a 2, que é o menor fator possível para
    // um número ser primo. Ele continua até j ser maior do que a raiz quadrada
    // de i, pois um número não pode ter um fator maior que a sua raiz quadrada.

    for (int j = 2; j <= sqrt(i); j++) {
      if (i % j == 0) {
        primo = 0;
        break;
      }
    }

    if (!primo) {
      printf("%d ", i);
      soma += i;
      count++;
      if (count % 5 == 0) {
        printf("\n");
      }
    }
  }

  printf("\nA soma de todos os números não primos é: %d", soma);

  return 0;
}
