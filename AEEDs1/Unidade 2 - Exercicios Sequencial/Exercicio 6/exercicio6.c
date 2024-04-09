#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  // 6. Faça um algoritmo que receba 2 números inteiros x e y e calcule o resto da divisão x / y.

  int num1, num2;

  printf("Digite dois números para mostrar o resto de sua divisão:");
  scanf("%i\n %i", &num1, &num2);
  printf("O resto da divisão entre esses dois números é: %i", num1 % num2);

  return 0;
}
