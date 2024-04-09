#include <stdio.h>

int main()
{
    const int linha = 4, coluna = 4;
    float num[linha][coluna];

    // Preenchendo a Matriz

    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            puts("Digite um numero:");
            scanf("%f", &num[i][j]);
        }
    }

    // Mostrando a Matriz com numeros maiores que 15 e menores que 25

    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            if (num[i][j] > 15 && num[i][j] < 25)
            {
                printf("%8.2f", num[i][j]);
            }
            else
            {
                printf("%8.2f", 0.0);
            }
        }
        printf("\n");
    }

    return 0;
}
