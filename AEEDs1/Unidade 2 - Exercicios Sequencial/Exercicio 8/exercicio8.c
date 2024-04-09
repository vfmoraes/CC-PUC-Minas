#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  // 8. Faça  um  algoritmo  para  calcular  a  área  de  um  trapézio.  O  algoritmo  deve  ler  o  valor  da  base  menor,  da  base maior e da altura. Em seguida, imprima o valor da área do trapézio.

  float basemenor, basemaior, altura, area;

  printf("Digite o comprimento da base menor do trapézio:");
  scanf("%f", &basemenor);
  printf("Digite a altura do trapézio:");
  scanf("%f", &altura);

  area = ((basemaior + basemenor) * altura) / 2;

  printf("A área do trapézio é: %.2f\n", area);

  return 0;
}