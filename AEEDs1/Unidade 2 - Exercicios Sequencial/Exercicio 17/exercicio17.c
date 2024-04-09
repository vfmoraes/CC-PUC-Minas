#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  // 17.  Faça um algoritmo que receba uma quantidade qualquer em minutos e converta em horas. 

  float horas, minutos;

  printf("Digite um número de minutos para serem convertidas em horas:");
  scanf("%f", &minutos);

  horas = minutos / 60;

  printf("%.1f minuto(s) são %.1f hora(s)", minutos, horas);

  return 0;
}