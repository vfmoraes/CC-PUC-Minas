#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    /*5. Faça um programa que mostre o menu de opções a seguir, receba a opção do usuário e os dados necessários
    para executar cada operação.
    Menu de opções:
    1. Somar dois números.
    2. Raiz quadrada de um número.
    Digite a opção desejada:*/

    int menu;
    float num1, num2, numraiz, raiz, soma;

    puts("Menu de opções:");
    puts("1. Somar dois numeros.");
    puts("2. Raiz quadrada de um numero.");
    puts("Digite a opcao desejada:");

    scanf("%i", &menu);

    switch (menu)
    {

    case 1:
        puts("Digite dois numeros:");
        scanf("%f %f", &num1, &num2);
        soma = num1 + num2;
        printf("A soma de %.2f e %.2f eh: %.2f", num1, num2, soma);
        break;
    case 2:
        puts("Digite o numero");
        scanf("%f", &numraiz);
        raiz = sqrt(numraiz);
        printf("A raiz quadrada de %.2f eh %.2f", numraiz, raiz);
        break;
    }
}