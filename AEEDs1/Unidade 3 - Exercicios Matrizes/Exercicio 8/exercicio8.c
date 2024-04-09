#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    const int linha = 3, coluna = 5, n = 3;
    float A[linha][coluna], media[3], desvio[3];

    // Preencher a matriz com números reais
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            scanf("%f", &A[i][j]);
        }
    }

    // Calcular a média de cada coluna
    for (int i = 0; i < coluna; i++)
    {
        media[i] = 0;
        for (int j = 0; j < linha; j++)
        {
            media[i] += A[j][i];
        }
        media[i] /= n;
    }

    // Calcular o desvio padrão de cada coluna
    for (int i = 0; i < n; i++)
    {
        desvio[i] = 0;
        for (int j = 0; j < n; j++)
        {
            desvio[i] += pow(A[j][i] - media[i], 2);
        }
        desvio[i] = sqrt(desvio[i] / n);
    }

    // Armazenar a média e o desvio padrão em vetores
    for (int i = 0; i < n; i++)
    {
        printf("Média da coluna [%d]: %.2lf\n", i + 1, media[i]);
        printf("Desvio padrão da coluna [%d]: %.2lf\n", i + 1, desvio[i]);
    }

    return 0;
}
