#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  /* 
  18.  Sejam P(x1,y1) e Q(x2,y2) dois pontos quaisquer no plano. A distância entre os pontos é dada por 
  d=√(x2 −x1)² +(y2 −y1)². 
  Faça um algoritmo que leia as coordenadas dos dois pontos, determine e escreva a distância entre eles. 
  */

  float x1, y1, x2, y2, distancia;

  printf("Digite a coordenada x de P: ");
  scanf("%f", &x1);
  printf("Digite a coordenada y de P: ");
  scanf("%f", &y1);
  printf("Digite a coordenada x de Q: ");
  scanf("%f", &x2);
  printf("Digite a coordenada y de Q: ");
  scanf("%f", &y2);

  distancia = sqrt(pow((x2-x1),2) + pow((y2-y1),2));

  printf("A distância entre os dois pontos é de: %f", distancia);

  return 0;
}