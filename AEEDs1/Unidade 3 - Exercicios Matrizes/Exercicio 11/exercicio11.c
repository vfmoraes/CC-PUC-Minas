#include <stdio.h>

int main()
{
  const int linha = 2, coluna = 2;
  int matrizA[linha][coluna], matrizB[linha][coluna], matrizC[linha][coluna];

  puts("Preencha a matriz A:");

  // Preenchendo a matriz A
  for (int i = 0; i < linha; i++)
  {
    for (int j = 0; j < coluna; j++)
    {
      scanf("%d", &matrizA[i][j]);
    }
  }

  puts("Preencha a matriz B:");

  // Preenchendo a matriz B
  for (int i = 0; i < linha; i++)
  {
    for (int j = 0; j < coluna; j++)
    {
      scanf("%d", &matrizB[i][j]);
    }
  }

  // Gerando a matriz C
  for (int i = 0; i < linha; i++)
  {
    for (int j = 0; j < coluna; j++)
    {
      matrizC[i][j] = matrizA[i][j] * matrizB[i][j];
    }
  }

  printf("Matriz A:\n");

  // Imprimindo Matriz A

  for (int i = 0; i < linha; i++)
  {
    for (int j = 0; j < coluna; j++)
    {
      printf("%8.d", matrizA[i][j]);
    }
    printf("\n");
  }

  printf("Matriz B:\n");

  // Imprimindo Matriz B
  for (int i = 0; i < linha; i++)
  {
    for (int j = 0; j < coluna; j++)
    {
      printf("%8.d", matrizB[i][j]);
    }
    printf("\n");
  }

  printf("Matriz C:\n");

  // Imprimindo Matriz C
  for (int i = 0; i < linha; i++)
  {
    for (int j = 0; j < coluna; j++)
    {
      printf("%8.d", matrizC[i][j]);
    }
    printf("\n");
  }
}