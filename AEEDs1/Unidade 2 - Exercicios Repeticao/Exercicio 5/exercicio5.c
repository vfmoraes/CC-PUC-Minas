#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*5. Faça um algoritmo que calcula e imprima o produto dos números entre 1 e 20. Utilize estrutura de repetição.*/
    
    float produto = 1, i;

    for (i = 1; i<=20; i++){
        produto = produto * i;
    }
    printf("A soma dos numeros de 1 a 20 eh: %f", produto);
    return 0;
}