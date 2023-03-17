 /*
 
Trabalho 1 de Introdução à Programação refeito de uma forma mais eficiente.

1) Receber salário báse b, número de dependentes d, número de anos de casa c,
ano atual;
2) Recebe acréscimo de 1% sobre o salário base para cada dependente (máx 5 dep);
3) Se o funcionário tem menos de 3 dependentes, recebe um acréscimo de 4% sobre
o salário base para cada 5 anos de casa que ele tem (máx 6 acréscimos);
4) Se o funcionário tem 3 ou mais dependentes, ele recebe um acréscimo de 7%
sobre o salário base para cada 8 anos de casa que ele tem (máx 5 acréscimos);
5) Todos ganham 1% extra de aumento sobre o salário base se for um ano bissexto
 
  p = dinheiro referente a porcentagem de acréscimo referente ao tempo de casa;
  rc = parte inteira da divisão do tempo de casa para saber se deve ou não
  receber o bônus; 
  a_d = dinheiro referente a quantidade de dependentes;
  
  */

#include <stdio.h>

int isBissexto(int ano) {
  return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

float calcularBonusTempoCasa(int anos) {
  if (anos >= 5 && anos <= 10) {
    return 0.04 * (anos / 5);
  } else if (anos > 10) {
    return 0.04 * 2;
  } else {
    return 0.0;
  }
}

float calcularBonusDependentes(int dependentes) {
  if (dependentes >= 1 && dependentes <= 2) {
    return 0.01 * dependentes;
  } else if (dependentes >= 3 && dependentes <= 5) {
    return 0.05;
  } else {
    return 0.0;
  }
}

int main() {
  float salario_base, salario_final, bonus_tempo_casa, bonus_dependentes, bonus_bissexto = 0.0;
  int dependentes, anos_casa, ano_atual;

  printf("Digite o seu salario: ");
  scanf("%f", &salario_base);

  printf("Digite o numero seu de dependentes: ");
  scanf("%d", &dependentes);

  printf("Digite o seu tempo de empresa: ");
  scanf("%d", &anos_casa);

  printf("Digite o seu ano: ");
  scanf("%d", &ano_atual);

  if (isBissexto(ano_atual)) {
    printf("%d É um ano bissexto.\n", ano_atual);
    bonus_bissexto = salario_base * 0.01;
  }

  bonus_tempo_casa = calcularBonusTempoCasa(anos_casa);
  bonus_dependentes = calcularBonusDependentes(dependentes);

  salario_final = salario_base + salario_base * (bonus_tempo_casa + bonus_dependentes) + bonus_bissexto;

  printf("Salario Final: %.2f", salario_final);

  return 0;
}
