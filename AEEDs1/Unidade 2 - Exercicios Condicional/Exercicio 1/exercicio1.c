#include <stdio.h>
#include <stdlib.h>

int main()
{
  // 1. Faça um programa que leia dois números e mostre o maior.

  float num1, num2;

  puts("Digite o valor de dois números e direi o maior:");
  scanf("%f %f", &num1, &num2);

  if (num1 > num2)
  {
    printf("O maior numero é: %.2f", num1);
  }
  else
  {
    printf("O maior numero é: %.2f", num2);
  }
  return 0;
}