#include <stdio.h>

int main()
{
  const int linha = 3, coluna = 3;
  int num[linha][coluna], maior;

  // Preenchendo a matriz
  for (int i = 0; i < linha; i++)
  {
    for (int j = 0; j < coluna; j++)
    {
      scanf("%d", &num[i][j]);
    }
  }

  // Pegando o maior numero da matriz
  maior = num[0][0];

  for (int i = 0; i < linha; i++)
  {
    for (int j = 0; j < coluna; j++)
    {
      if (maior < num[i][j])
      {
        maior = num[i][j];
      }
    }
  }

  printf("O maior numero da matriz é: %d\nA matriz digitada multiplicada por ele ficaria:\n", maior);

  // Gerando uma matriz multiplicando o maior numero da matriz digitada
  for (int i = 0; i < linha; i++)
  {
    for (int j = 0; j < coluna; j++)
    {
      num[i][j] = num[i][j] * maior;
      printf("%8.d", num[i][j]);
    }
    printf("\n");
  }
}