#include <stdio.h>

int main()
{
  const int linha = 4, coluna = 4;
  int num[linha][coluna];

  // Preenchendo a Matriz
  for (int i = 0; i < linha; i++)
  {
    for (int j = 0; j < coluna; j++)
    {
      scanf("%d", &num[i][j]);
    }
  }

  printf("Diagonal principal da matriz:\n");

  // Mostrando apenas os números da diagonal principal
  for (int i = 0; i < linha; i++)
  {
    for (int j = 0; j < coluna; j++)
    {
      if (i == j)
      {
        printf("%8.d", num[i][j]);
      }
      else
      {
        printf("%8.d", 0);
      }
    }
    printf("\n");
  }

  printf("Números abaixo da diagonal principal da matriz:\n");

  // Mostrando apenas os números abaixo da diagonal principal
  for (int i = 0; i < linha; i++)
  {
    for (int j = 0; j < coluna; j++)
    {
      if (i - j >= 1)
      {
        printf("%8.d", num[i][j]);
      }
      else
      {
        printf("%8.d", 0);
      }
    }
    printf("\n");
  }

  printf("Números acima da diagonal principal da matriz:\n");

  // Mostrando apenas os números acima da diagonal principal
  for (int i = 0; i < linha; i++)
  {
    for (int j = 0; j < coluna; j++)
    {
      if (j - i >= 1)
      {
        printf("%8.d", num[i][j]);
      }
      else
      {
        printf("%8.d", 0);
      }
    }
    printf("\n");
  }
}