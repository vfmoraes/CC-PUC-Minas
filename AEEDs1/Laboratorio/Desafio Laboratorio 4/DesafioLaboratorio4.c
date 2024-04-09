#include <stdio.h>
#include <stdlib.h>

int main()
{
    char texto[10];

    puts("Digite uma frase para transformar em maiusculo:");
    scanf("%s", texto);
    texto[0] -= 32;
    texto[1] -= 32;
    texto[2] -= 32;
    texto[3] -= 32;
    texto[4] -= 32;
    texto[5] -= 32;
    texto[6] -= 32;
    texto[7] -= 32;
    texto[8] -= 32;
    texto[9] -= 32;
    printf("%s", texto);
    return 0;
}
