/*
  Guia_0101.c
  802371 - Victor Ferraz de Moraes
*/

#include <stdio.h>

// Função para converter decimal para binário
void dec2bin(int decimal) {
    if (decimal == 0) {
        printf("0");
        return;
    }

    int binary[32];
    int index = 0;

    while (decimal > 0) {
        binary[index++] = decimal % 2;
        decimal /= 2;
    }

    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
}

int main() {
    int decimal;

    printf("Guia_0101.c - Tests\n");
    printf("a.) 26 = ");
    dec2bin(26);
    printf("\n");
    printf("b.) 53 = ");
    dec2bin(53);
    printf("\n");
    printf("c.) 723 = ");
    dec2bin(723);
    printf("\n");
    printf("d.) 312 = ");
    dec2bin(312);
    printf("\n");
    printf("e.) 365 = ");
    dec2bin(365);
    printf("\n");

    return 0;
}
