#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int nCartelas;
    int numsNaCartela;
    int numSorteados;
    scanf("%d %d %d", &nCartelas, &numsNaCartela, &numSorteados);
    int cartelas[nCartelas][numsNaCartela];
    for (int i = 0; i < nCartelas; i++)
    {
        for (int j = 0; j < numsNaCartela; j++)
        {
            scanf("%d", &cartelas[i][j]);
        }
    }
    int sorteados[numSorteados];
    for (int i = 0; i < numSorteados; i++)
    {
        scanf("%d", &sorteados[i]);
    }
    int ganhadores[nCartelas];
    int rodadaGanhador[nCartelas];
    for (int i = 0; i < nCartelas; i++)
    {
        ganhadores[i] = 0;
        rodadaGanhador[i] = -1;
    }

    for(int i = 0; i < numSorteados; i++) {
        // Iterando sobre cada número na cartela
        for(int k = 0; k < numsNaCartela; k++) {
            // Iterando sobre cada cartela
            for(int j = 0; j < nCartelas; j++) {
                if(cartelas[j][k] == sorteados[i]) {
                    ganhadores[j]++;
                    if(ganhadores[j] == numsNaCartela && rodadaGanhador[j] == -1) {
                        rodadaGanhador[j] = i;
                    }
                }
            }
        }
    }

    int menorRodada = numSorteados;
    for(int i = 0; i < nCartelas; i++) {
        if(rodadaGanhador[i] != -1 && rodadaGanhador[i] < menorRodada) {
            menorRodada = rodadaGanhador[i];
        }
    }

    if(menorRodada != numSorteados) {
        for(int i = 0; i < nCartelas; i++) {
            if(rodadaGanhador[i] == menorRodada) {
                printf("%d ", i + 1);
            }
        }
    }
    printf("\n");

    return 0;
}
