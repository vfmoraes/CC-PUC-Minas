#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*4. Faça um algoritmo que calcula e imprima a soma dos números entre 1 e 20. Utilize estrutura de repetição.*/
    
    int i, soma = 0;

    for(i = 1; i <=20; i++){
        soma += i;
    }
    printf("A soma dos numeros de 1 a 20 eh: %d", soma);
    return 0;
}