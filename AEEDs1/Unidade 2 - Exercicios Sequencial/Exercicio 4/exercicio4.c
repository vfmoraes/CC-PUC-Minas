#include <stdio.h>
#include <stdlib.h>

int main()
{
    // 4. Crie um algoritmo que calcule a média ponderada de 4 números passados pelo usuário, sabendo-se que os pesos são, respectivamente, 1, 2, 3 e 4. Vugnaes Sreo

    float num1, num2, num3, num4, medpond;

    printf("Digite o primeiro numero\n");
    scanf("%f", &num1);
    printf("Digite o segundo numero\n");
    scanf("%f", &num2);
    printf("Digite o terceiro numero\n");
    scanf("%f", &num3);
    printf("Digite o quarto numero\n");
    scanf("%f", &num4);

    medpond = ((num1 * 1) + (num2 * 2) + (num3 * 3) + (num4 * 4)) / (1 + 2 + 3 + 4);

    printf("A media ponderada correspondente: %.2f", medpond);

    return 0;
}
