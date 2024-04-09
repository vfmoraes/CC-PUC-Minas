#include <stdio.h>
#include <stdlib.h>

int main()
{
    int idade;


    puts("Digite a idade do nadador:");
    scanf("%i", &idade);

    if (idade < 5){
        puts("Nadador não apto");
    } else if (idade <8) {
        puts("Categoria: Infantil");
    } else if (idade <11) {
        puts("Categoria: Juvenil");
    } else if (idade <16) {
        puts("Categoria: Adolescente");
    } else if (idade < 31) {
        puts("Categoria: Adulto");
    } else {
        puts("Categoria: Senior");
    }
    return 0;
}