#include <stdio.h>

int main()
{
  const int linha = 3, coluna = 5;
  int num[linha][coluna];

  // Preenchendo a Matriz
  for (int i = 0; i < linha; i++)
  {
    for (int j = 0; j < coluna; j++)
    {
      scanf("%d", &num[i][j]);
    }
  }

  printf("Matriz digitada:\n");

  // Imprimindo a Matriz
  for (int i = 0; i < linha; i++)
  {
    for (int j = 0; j < coluna; j++)
    {
      printf("%8.d", num[i][j]);
    }
    printf("\n");
  }

  printf("\nMatriz Transposta:\n");

  // Imprimindo a matriz transposta
  for (int i = 0; i < coluna; i++)
  {
    for (int j = 0; j < linha; j++)
    {
      printf("%8.d", num[j][i]);
    }
    printf("\n");
  }
}