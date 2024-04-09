#include <stdio.h>

int main()
{

  int c, d, subtracao = 0;

  puts("Digite os valores de A e B para formar uma subtração:");
  scanf("%i %i", &c, &d);

  while (subtracao != d)
  {
    subtracao++;
    c--;
  }

  printf("SUBTRACAO = %i", c);
}