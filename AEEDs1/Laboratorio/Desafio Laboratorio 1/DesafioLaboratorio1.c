#include <stdio.h>
#include <stdlib.h>

int main()
{
    char letra, proxima_letra;

    puts("Digite uma Letra do Alfabeto");
    scanf("%c", &letra);
    proxima_letra = letra + 1;
    printf("A letra seguinte eh: %c", proxima_letra);
    return 0;
}
