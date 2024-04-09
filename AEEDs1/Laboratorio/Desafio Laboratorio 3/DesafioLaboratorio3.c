#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char texto[20];
    int tamanho;

    puts("Digite uma frase para dizer o tamanho do texto:");
    scanf("%s", texto);
    tamanho = strlen(texto);
    printf("O tamanho do texto eh: %i", tamanho);
    return 0;
}
