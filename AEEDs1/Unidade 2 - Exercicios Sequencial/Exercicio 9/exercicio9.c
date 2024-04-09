#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  // 9. Faça um algoritmo que calcule a área de uma circunferência, recebendo o valor do raio.

  int raio;
  float area, pi;

  printf("Digite o raio da circuferência em cm:");
  scanf("%i", &raio);
  area = pow(raio, 2) * 3.14;

  printf("A área da circuferência é: %.2f cm", area);

  return 0;
}