/*
  Guia_0102.c
  802371 - Victor Ferraz de Moraes
*/

#include <stdio.h>

void bin2dec(const char *bin) {
    int decimal = 0;
    int base = 1;
    int len = 0;

    // Calcula o comprimento da string binária
    while (bin[len] != '\0') {
        len++;
    }

    // Converte binário para decimal
    for (int i = len - 1; i >= 0; i--) {
        if (bin[i] == '1') {
            decimal += base;
        }
        base *= 2;
    }

    printf("%d\n", decimal);
}

int main() {
    char binary[32];  // Tamanho máximo de 31 dígitos binários

    printf("Guia_0102.c - Tests\n");
    printf("a.) 10110 = ");
    bin2dec("10110");
    printf("b.) 11011 = ");
    bin2dec("11011");
    printf("c.) 100100 = ");
    bin2dec("100100");
    printf("d.) 101001 = ");
    bin2dec("101001");
    printf("e.) 110111 = ");
    bin2dec("110111");

    return 0;
}
