#include <math.h>
#include <stdio.h>

/*
O programa abaixo retorna os números não primos entre A e B, calcula a soma de
todos esses valores e depois o produto de cada dígito da soma.
  */

int main() {
  int a, b, primo, count = 0, soma = 0, produto = 1;

  printf("Digite dois números inteiros positivos: ");
  scanf("%d %d", &a, &b);

  printf("Os números não primos entre %d e %d são:\n", a, b);

  for (int i = a + 1; i < b; i++) {
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
      if (count % 10 == 0) {
        printf("\n");
      }
    }
  }

  printf("\n\nA soma de todos os números não primos é: %d", soma);

  printf("\nO produto de cada dígito da soma é: ");
  while (soma > 0) {
    int digito = soma % 10;
    if (digito != 0) {
      produto *= digito;
    }
    soma /= 10;
  }
  printf("%d", produto);

  return 0;
}
