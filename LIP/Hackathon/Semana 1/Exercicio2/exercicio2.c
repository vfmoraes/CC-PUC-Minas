#include <stdio.h>

int main(){

  int c, d, produto;

  puts("Digite os valores de C e D para calcular o produto:");
  scanf("%i %i", &c, &d);
  produto = c * d;
  printf("PRODUTO = %i", produto);

}