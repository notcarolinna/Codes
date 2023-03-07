/*
Escreva um programa que recebe um número x < 1 e apresenta uma soma de frações que
aproxima x. Por exemplo, se recebermos x = 0.543 uma soma de frações que pode aproximar
x seria x ≈ 1/2 + 1/24 + 1/750 = 0.5429999999999
Seu programa deve ter algum tipo de controle para o grau de aproximação desejado pelo
usuário.
*/

#include <stdio.h>

int main()
{
    double x, soma = 0.0, termo = 0.5;
    int n = 2;

    printf("Digite um valor de x entre 0 e 1: ");
    scanf("%lf", &x);

    while (x - soma >= 0.000001)
    {
        soma += termo;

        if (n % 2 == 0)
        {
            termo = 1.0 / ((double)n * (double)(n + 1));
        }
        else
        {
            termo = -1.0 / ((double)n * (double)(n + 1));
        }

        n += 1;
    }

    printf("Soma das frações que aproxima x = %.2lf\n", soma);

    return 0;
}
