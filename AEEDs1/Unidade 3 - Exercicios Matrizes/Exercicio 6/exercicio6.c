#include <stdio.h>

int main()
{
  const int linha = 3, coluna = 4;
  int num[linha][coluna], multiplicacao[4] = {1, 1, 1, 1};

  // Preenchendo a Matriz
  for (int i = 0; i < linha; i++)
  {
    for (int j = 0; j < coluna; j++)
    {
      scanf("%d", &num[i][j]);
    }
  }

  // Multiplicando cada coluna
  for (int i = 0; i < coluna; i++)
  {
    for (int j = 0; j < linha; j++)
    {
      multiplicacao[i] = multiplicacao[i] * num[j][i];
    }
  }

  // Imprimindo a multiplicação de cada coluna
  for (int i = 0; i < coluna; i++)
  {
    printf("A multiplicacao da coluna %d é: %d\n", i + 1, multiplicacao[i]);
  }
}