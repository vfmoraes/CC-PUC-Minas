#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  /*1. Faça um programa que, dados os três lados x, y e z de um triângulo, verifique correspondem aos lados de um
  triângulo válido. Caso o triângulo seja válido, imprima se o triângulo é equilátero, isósceles ou escaleno.*/
  
  int lado1, lado2, lado3;

  puts("Digite os valores dos 3 lados do triangulo:");
  scanf("%i %i %i", &lado1, &lado2, &lado3);

  if (lado1 >= lado2 && lado1 >= lado3)
  {
    if (abs(lado2 - lado3) < lado1 && lado2 + lado3 > lado1)
    {
      puts("Triangulo valido");
      if (lado1 == lado2 && lado1 == lado3 && lado2 == lado3)
      {
        puts("Equilátero");
      }
      else if (lado1 != lado2 && lado1 != lado3 && lado2 != lado3)
      {
        puts("Escaleno");
      }
      else
      {
        puts("Isósceles");
      }
    }
    else
    {
      puts("Triângulo Inválido");
    }
  }
  else if (lado2 >= lado1 && lado2 >= lado3)
  {
    if (abs(lado1 - lado3) < lado2 && lado1 + lado3 > lado2)
    {
      puts("Triangulo valido");
      if (lado1 == lado2 && lado1 == lado3 && lado2 == lado3)
      {
        puts("Equilátero");
      }
      else if (lado1 != lado2 && lado1 != lado3 && lado2 != lado3)
      {
        puts("Escaleno");
      }
      else
      {
        puts("Isósceles");
      }
    }
    else
    {
      puts("Triângulo Inválido");
    }
  }
  else if (lado3 >= lado1 && lado3 >= lado2)
  {
    if (abs(lado1 - lado2) < lado3 && lado1 + lado2 > lado3)
    {
      puts("Triangulo valido");
      if (lado1 == lado2 && lado1 == lado3 && lado2 == lado3)
      {
        puts("Equilátero");
      }
      else if (lado1 != lado2 && lado1 != lado3 && lado2 != lado3)
      {
        puts("Escaleno");
      }
      else
      {
        puts("Isósceles");
      }
    }
    else
    {
      puts("Triângulo Inválido");
    }
  }
  return 0;
}