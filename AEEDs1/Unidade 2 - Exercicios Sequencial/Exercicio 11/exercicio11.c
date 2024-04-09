#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  //11.  Faça  um  algoritmo  que  receba  o  salário  de  um  funcionário,  calcule  e  mostre  o  novo  salário  considerando  um aumento de 25%.    

  float salario, aumento;

  printf("Digite o valor de seu salário:");
  scanf("%f", &salario);

  aumento = salario + (salario * 1/4);

  printf("Parabéns! Você recebeu um aumento de 25 por cento e agora seu salário passa a ser de: %.2f", aumento);

  return 0;
}