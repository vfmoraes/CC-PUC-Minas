#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  // 13.  Um  funcionário  recebe  um  salário  fixo mais  4%  de  comissão  sobre  as vendas.  Faça  um  algoritmo  que  receba  o salário fixo do funcionário e o valor de suas vendas no mês, calcule e mostre a comissão e seu salário final.

  float salario, vendas, comissao, salario_final;

  printf("Digite o valor de seu salário fixo:");
  scanf("%f", &salario);
  printf("Digite o valor das vendas do mês:");
  scanf("%f", &vendas);

  comissao = vendas * 0.04;
  salario_final = salario + comissao;

  printf("Comissão sobre as vendas: %.2f\n", comissao);
  printf("Salário Final: %.2f\n", salario_final);

  return 0;
}