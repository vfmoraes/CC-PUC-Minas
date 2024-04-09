#include <stdio.h>
#include <stdlib.h>

int main()
{
    int idade;
    double altura;

    puts("Digite a idade do jogador:");
    scanf("%i", &idade);
    puts("Digite a altura do jogador:");
    scanf("%lf", &altura);

    if (idade < 6) {
        puts("Nao apto a jogar, idade minima nao antigida");
    } else if (idade < 11){
        if (altura >= 1.0){
        puts("Categoria: Infantil");
        } else {
            puts("Nao apto");
        }
    } else if (idade < 18){
        if (altura >= 1.4){
            puts("Categoria: Junior");
        } else {
            puts("Nao apto teste");
        }
    } else if (idade < 36){
        if (altura >= 1.70){
            puts ("Categoria: Profissional");
        } else {
            puts("Nao apto");
        }
    } else if (idade > 35) {
        if (altura >= 1.60){
            puts("Categoria: Senior");
        } else {
            puts("Nao apto");
        }
    } else {
        puts("Nao apto");
    }

    return 0;
}