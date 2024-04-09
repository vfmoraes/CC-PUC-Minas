#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  // 10.  Faça um algoritmo que encontre as raízes de uma equação do segundo grau ax2 +bx + c. O algoritmo deve ler os coeficientes a, b e c e determinar as raízes da equação.

  float a, b, c, delta;

  printf("Digite o valor de a:");
  scanf("%f", &a);
  printf("Digite o valor de b:");
  scanf("%f", &b);
  printf("Digite o valor de c:");
  scanf("%f", &c);

  delta = pow(b, 2) - (4 * a * c);

  printf("A raiz da equação de segundo grau é: +- √%.2f", delta);

  return 0;
}