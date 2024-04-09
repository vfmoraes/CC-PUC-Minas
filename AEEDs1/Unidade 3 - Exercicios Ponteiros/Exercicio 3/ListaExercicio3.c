#include <stdio.h>
#include <math.h>

int main ()
{
    float nota[10], maior, menor, soma, media;
    
    for(int i = 0; i < 10; i++){
        printf("Digite a nota do aluno %d:\n", i+1);
        scanf("%f", &nota[i]);
    }
    maior = nota[0];
    menor = nota[0];
    for (int i = 0; i < 10; i++){
        soma += nota[i];
        if(maior < nota[i]){
            maior = nota[i];
        } else if (menor > nota[i]){
            menor = nota[i];
        }
    }
    media = soma / 10;
    printf("A media das notas eh: %.2f\n", media);
    printf("A maior nota eh: %.2f\n", maior);
    printf("A menor nota eh: %.2f\n", menor);
    return 0;
}
