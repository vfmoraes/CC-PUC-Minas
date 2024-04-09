#include <stdio.h>
#include <stdlib.h>

int main()
{
    char texto[10];
    char inverso[11];

    puts("Digite uma frase para ficar inversa:");
    scanf("%s", texto);

    inverso[0] = texto[9];
    inverso[1] = texto[8];
    inverso[2] = texto[7];
    inverso[3] = texto[6];
    inverso[4] = texto[5];
    inverso[5] = texto[4];
    inverso[6] = texto[3];
    inverso[7] = texto[2];
    inverso[8] = texto[1];
    inverso[9] = texto[0];

    printf("%s", inverso);
    return 0;
}

