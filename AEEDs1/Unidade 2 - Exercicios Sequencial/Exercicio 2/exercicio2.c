#include <stdio.h>
#include <stdlib.h>

int main()
{
    // 2. Crie um algoritmo que calcule a média aritmética de 3 números fornecidos pelo usuário.

    float num1, num2, num3, media;

    printf("Digite o primeiro numero\n");
    scanf("%f", &num1);
    printf("Digite o segundo numero\n");
    scanf("%f", &num2);
    printf("Digite o terceiro numero\n");
    scanf("%f", &num3);

    media = (num1 + num2 + num3) / 3;

    printf("A media dos tres numeros eh %.2f", media);

    return 0;
}
