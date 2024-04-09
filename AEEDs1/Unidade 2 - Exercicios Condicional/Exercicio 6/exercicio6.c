#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*6. Faça um programa que receba três notas de 0 a 10 de um aluno, calcule e mostre a nota final do aluno, dada
    pela média aritmética, e a situação do aluno conforme a tabela.
    Tabela:
    0 - 3.9 = Reprovado
    4,0 - 6.9 = Exame
    7.0 - 10.0 = Aprovado
    */
    
    float nota1, nota2, nota3, media;

    puts("Digite tres notas de 0 a 10 e diremos sua situacao:");
    scanf("%f %f %f", &nota1, &nota2, &nota3);

    media = (nota1 + nota2 + nota3) / 3;
    printf("Sua média é: %.2f\n", media);

    if (media < 4) {
        puts("Situação: Reprovado");
    } else if (media < 7) {
        puts("Situacao: Exame");
    } else {
        puts ("Situacao: Aprovado");
    }
    return 0;
}