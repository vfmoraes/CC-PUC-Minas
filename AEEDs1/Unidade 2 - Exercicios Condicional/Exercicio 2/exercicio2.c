#include <stdio.h>
#include <stdlib.h>

int main()
{
    // 2. Faça um algoritmo que receba um número inteiro e verifique se é par ou ímpar

    int num;

    puts("Digite um numero e direi se é par ou impar:");
    scanf("%i", &num);

    if (num % 2 == 0)
    {
        printf("O número %i é par", num);
    }
    else
    {
        printf("O número %i é impar", num);
    }
    return 0;
}