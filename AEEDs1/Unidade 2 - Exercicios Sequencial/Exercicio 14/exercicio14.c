#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  /* 14.  Faça  um  programa  que  receba  o  preço  de  um  produto,  calcule  e  mostre  o  novo  preço  em  duas  condições distintas:
  (a)  o preço do produto sofreu um desconto de 10%.
  (b)  o preço do produto sofreu um aumento de 20%.
  */

  float produto, desconto10, aumento20;

  printf("Digite o valor do produto:");
  scanf("%f", &produto);

  desconto10 = produto - (produto * 0.1);
  aumento20 = produto + (produto * 0.2);

  printf("(a) O produto sofreu um desconto de 10 por cento: %.2f reais\n", desconto10);
  printf("(b) O produto sofreu um aumento de 20 por cento : %.2f reais\n", aumento20);

  return 0;
}