#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  /* 15.  Faça um algoritmo que leia as seguintes informações de um empregado: o número de horas trabalhadas, o valor
  do salário mínimo e o número de horas extras trabalhadas. Calcule e mostre o salário que o empregado receberá
  seguindo as seguintes regras:
  • o valor pago por hora trabalhada é 1/8 do salário mínimo;
  • o valor pago por hora extra vale 1/4 do salário mínimo;
  • o salário bruto equivale ao número de horas trabalhadas vezes o valor pago por hora trabalhada;
  • a quantia a receber por horas extras equivale  ao número de  horas extras realizadas multiplicado pelo valor
  pago por hora extra;
  • o salário a receber é a soma do salário bruto e da quantia a receber pelas horas extras.
  */

  float horas_trabalhadas, salariomin, horas_extras, valor_por_hora_trabalho, valor_por_hora_extra, salario_bruto, quantia_hora_extra, salario_final;

  printf("Digite o número de horas trabalhadas:");
  scanf("%f", &horas_trabalhadas);
  printf("Digite o valor do salário mínimo:");
  scanf("%f", &salariomin);
  printf("Digite o número de horas extras trabalhadas:");
  scanf("%f", &horas_extras);

  valor_por_hora_trabalho = salariomin * 1 / 8;
  valor_por_hora_extra = salariomin * 1 / 4;
  salario_bruto = horas_trabalhadas * valor_por_hora_trabalho;
  quantia_hora_extra = horas_extras * valor_por_hora_extra;
  salario_final = salario_bruto + quantia_hora_extra;

  printf("O seu salário do mês é de: %.2f reais\n", salario_final);

  return 0;
}