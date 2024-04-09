#include <stdio.h>
#include <stdlib.h>

int main()
{
    // 1. Crie um algoritmo que calcule a soma e o produto de 3 números fornecidos pelo usuário.

    float num1, num2, num3;
    float soma, produto;

    printf("Digite o primeiro numero\n");
    scanf("%f", &num1);
    printf("Digite o segundo numero\n");
    scanf("%f", &num2);
    printf("Digite o terceiro numero\n");
    scanf("%f", &num3);

    soma = num1 + num2 + num3;
    produto = num1 * num2 * num3;

    printf("A soma dos tres numeros eh %.2f e o produto dos tres numeros eh %.2f", soma, produto);

    return 0;
}
