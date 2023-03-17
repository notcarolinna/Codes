/*
Resolva o seguinte problema usando a linguagem C:
Um método para cálculo de raizes quadradas de um número N já era conhecido pelos babilônios em... bom, há muito tempo atrás. 
(Este método também é conhecido como método de Heron, um matemático grego que o descreveu 20 séculos depois dos babilônios, perto do ano 50 DC.) 
Começando de um valor inicial k (geralmente valendo um) os babilônios geravam um novo valor de k de acordo com a regra:

k = (k + N/k) / 2

recalculando k várias vezes. À medida que o processo é repetido, os novos valores de k se aproximam 
cada vez mais da raiz de N. Escreva um programa que recebe o valor de N e imprime os primeiros doze valores obtidos com esta fórmula, testando-os 
para ver se eles realmente se aproximam da raiz de N .
*/

#include <stdio.h>

int main()
{
    double n;
    double k = 1.0, k_antigo = 0.0, raiz = 0.0;

    printf("Digite o valor de N: ");
    scanf("%lf", &n);

    for (int i = 1; i <= 12; i++)
    {
        k_antigo = k;
        k = (k + n / k) / 2;
        printf("k%d = %.1lf\n", i, k);

        if (i == 1)
        {
            raiz = k;
        }
    }

    printf("\nRaiz de %.1lf = %.1lf\n", n, raiz);

    return 0;
}
