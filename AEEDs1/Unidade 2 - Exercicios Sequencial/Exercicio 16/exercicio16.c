#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  // 16.  Faça um algoritmo que receba uma quantidade qualquer em horas e converta em minutos.

  float horas, minutos;

  printf("Digite um número de horas para serem convertidas em minutos:");
  scanf("%f", &horas);

  minutos = horas * 60;

  printf("%.1f hora(s) são %.1f minutos", horas, minutos);

  return 0;
}