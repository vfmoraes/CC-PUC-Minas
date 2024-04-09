#include <stdio.h>

int main()
{
  const int linha = 3, coluna = 4;
  int num[linha][coluna], soma[3];

  // Preenchendo a Matriz
  for (int i = 0; i < linha; i++)
  {
    for (int j = 0; j < coluna; j++)
    {
      scanf("%d", &num[i][j]);
    }
  }

  // Somando cada linha
  for (int i = 0; i < linha; i++)
  {
    for (int j = 0; j < coluna; j++)
    {
      soma[i] = soma[i] + num[i][j];
    }
    printf("A soma da linha %d é: %d\n", i + 1, soma[i]);
  }
}