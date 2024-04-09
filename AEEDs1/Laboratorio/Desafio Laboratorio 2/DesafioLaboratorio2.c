#include <stdio.h>
#include <stdlib.h>

int main()
{
    char letra_min, letra_mai;

    puts("Digite uma letra minuscula do Alfabeto");
    scanf("%c", &letra_min);
    letra_mai = letra_min - 32;
    printf("A letra maiuscula dessa eh: %c", letra_mai);
    return 0;

}
