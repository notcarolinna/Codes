/*
Escreva um programa em C que recebe dois pontos no plano, P1 = (x1, y1) e P2 = (x2, y2) e
calcula:
(a) A distância entre eles, dada por d(P1, P2) = raíz de ((x1 − x2)^2 + (y1 − y2)^2).
(b) A inclinação da reta y = ax+b que une estes dois pontos, dada por a = (y2−y1)/(x2−x1).
Faça uma análise de seu programa e verifique que existem certos valores que fazem com
que ele apresente um erro. Identifique o erro.
*/

// Usando <math.h>

#include <stdio.h>
#include <math.h>

int main()
{
    float x1, y1, x2, y2;
    float d, i;

    printf("Digite as coordenadas x e y do primeiro ponto: ");
    scanf("%f %f", &x1, &y1);

    printf("Digite as coordenadas x e y do segundo ponto: ");
    scanf("%f %f", &x2, &y2);

    d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    i = (y2 - y1) / (x2 - x1);

    printf("Distancia entre os pontos: %f\n", d);
    printf("Inclinacao da reta que une os pontos: %f\n", i);

    return 0;
}

/*
//Sem usar a <math.h>

#include <stdio.h>

int main() {
    
    float x1, y1, x2, y2;
    float d, i;

    printf("Digite as coordenadas x e y do primeiro ponto: ");
    scanf("%f %f", &x1, &y1);

    printf("Digite as coordenadas x e y do segundo ponto: ");
    scanf("%f %f", &x2, &y2);

    d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    i = (y2 - y1) / (x2 - x1);

    printf("Distancia entre os pontos %f\n", d);
    printf("Inclinacao da reta que une os ponto: %f\n", i);

    return 0;
}


*/
