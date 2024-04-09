/*
  Guia_0103.c
  802371 - Victor Ferraz de Moraes
*/

#include <stdio.h>

void dec2base(int base, int x) {
    if (base < 2 || base > 16) {
        printf("Base inválida. A base deve estar entre 2 e 16.\n");
        return;
    }

    char digits[] = "0123456789ABCDEF";
    char result[32];  // Armazenar o resultado da conversão
    int index = 0;

    // Lidar com o caso especial de x igual a 0
    if (x == 0) {
        printf("0\n");
        return;
    }

    // Converter o número para a base desejada
    while (x > 0) {
        result[index] = digits[x % base];
        x /= base;
        index++;
    }

    // Imprimir o resultado na ordem correta
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", result[i]);
    }
    printf("(%d)", base);
    printf("\n");
}

int main() {
    int base, decimal;

    printf("Guia_0103.c - Tests\n");
    printf("a.) 61(10) = ");
    dec2base(4, 61);
    printf("b.) 54(10) = ");
    dec2base(8, 54);
    printf("c.) 77(10) = ");
    dec2base(16, 77);
    printf("d.) 151(10) = ");
    dec2base(16, 151);
    printf("e.) 738(10) = ");
    dec2base(16, 738);

    return 0;
}
