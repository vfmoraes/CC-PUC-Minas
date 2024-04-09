#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  // 12.  Um  funcionário  receberá  um  aumento  de  salário.  Faça  um  algoritmo  que  receba  o  salário  e  o  percentual  de aumento, calcule e mostre o valor do aumento e o novo salário.

  float salario, percentual, aumento;

  printf("Digite o valor de seu salário:");
  scanf("%f", &salario);
  printf("Digite o percentual de aumento:");
  scanf("%f", &percentual);

  aumento = salario + (salario * (percentual / 100));

  printf("Parabéns! Você recebeu um Aumento de %.2f por cento e agora seu salário passa a ser de %.2f reais", percentual, aumento);

  return 0;
}