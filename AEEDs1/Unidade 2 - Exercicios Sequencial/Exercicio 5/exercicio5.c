#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    /*
    5. Faça um algoritmo que receba um número positivo, calcule e mostre:
    • o número ao cubo;
    • a raiz quadrada do número;
    • a raiz cúbica do número;
    • o seno do número;
    • o cosseno do número.
    */

    float num;

    printf("Digite um numero positivo:\n");
    scanf("%f", &num);
    printf("Numero ao cubo: %.2f\n", pow(num, 3));
    printf("A raiz quadrada do número: %.2f\n", sqrt(num));
    printf("A raiz cúbica do número: %.2f\n", pow(num, 1.0 / 3));
    printf("o seno do número: %.2f\n", sin(num));
    printf("o cosseno do número: %.2f\n", cos(num));

    return 0;
}
