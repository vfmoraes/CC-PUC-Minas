#include <stdio.h>

int main()
{
  const int linha = 3, coluna = 3;
  float num[linha][coluna], maior, menor;

  // Preenchendo a Matriz
  for (int i = 0; i < linha; i++)
  {
    for (int j = 0; j < coluna; j++)
    {
      scanf("%f", &num[i][j]);
    }
  }
  printf("\n");

  maior = num[0][0];
  menor = num[0][0];

  // Exibindo o maior e menor número da matriz
  for (int i = 0; i < linha; i++)
  {
    for (int j = 0; j < coluna; j++)
    {
      if (num[i][j] > maior)
      {
        maior = num[i][j];
      }
      else if (num[i][j] < menor)
      {
        menor = num[i][j];
      }
      printf("%8.2f", num[i][j]);
    }
    printf("\n");
  }

  printf("\nO maior numero da matriz é %.2f e o menor é %.2f", maior, menor);
}