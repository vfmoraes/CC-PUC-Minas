#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  // 7. Faça um algoritmo que leia os lados de um retângulo e calcule sua área e seu perímetro.

  float lado1, lado2, lado3, perimetro, area, s;

  printf("Digite o primeiro lado do triangulo:");
  scanf("%f", &lado1);
  printf("Digite o segundo lado do triangulo:");
  scanf("%f", &lado2);
  printf("Digite o terceiro lado do triangulo:");
  scanf("%f", &lado3);

  perimetro = lado1 + lado2 + lado3;
  s = perimetro / 2;
  area = sqrt(s * (s - lado1) * (s - lado2) * (s - lado3));

  printf("A área do triângulo é: %.2f\n", area);
  printf("O perímetro do triângulo é: %.2f\n", perimetro);

  return 0;
}