#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*3. Ler 10 números reais e imprimir qual foi o maior e o menor número informado.*/
    
    float num = 0, maior, menor;
    puts("Digite 10 numeros reais:");
    for (int i = 0; i <10; i++){
        scanf("%f", &num);
       if(i == 0){
        menor = num;
        maior = num;
       }
        if(maior < num){
            maior = num;
    } else if (num < menor) {
            menor = num;
    }
}
    printf("O maior numero digitado eh: %.2f e o menor eh: %.2f", maior, menor);
    return 0;
}