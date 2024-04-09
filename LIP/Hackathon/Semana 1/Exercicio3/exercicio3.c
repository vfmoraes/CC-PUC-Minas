#include <stdio.h>

int main(){

  int c, d, quociente;

  puts("Digite os valores de C e D para calcular a divisão:");
  scanf("%i %i", &c, &d);
  quociente = c / d;
  printf("QUOCIENTE = %i", quociente);

}