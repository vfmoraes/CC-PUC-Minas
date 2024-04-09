/*
  Guia_0104.c
  802371 - Victor Ferraz de Moraes
*/

#include <stdio.h>
#include <string.h>

void reverseString(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }
}

void bin2base(int x, int base) {
    if (base < 2 || base > 36) {
        printf("Base inválida. A base deve estar entre 2 e 36.\n");
        return;
    }

    char result[32]; // Armazenar o resultado como uma string
    int index = 0;

    while (x > 0) {
        int remainder = x % base;
        if (remainder < 10) {
            result[index] = remainder + '0';
        } else {
            result[index] = remainder + 'A' - 10;
        }
        x /= base;
        index++;
    }

    if (index == 0) {
        result[index] = '0';
        index++;
    }

    result[index] = '\0';

    reverseString(result);

    printf("%s (%d)\n", result, base);
}

int main() {
    printf("Guia_0104.c - Tests\n");
    printf("a.) 10101(2) = ");
    bin2base(0b10101, 4);
    printf("b.) 11010(2) = ");
    bin2base(0b11010, 8);
    printf("c.) 100111(2) = ");
    bin2base(0b100111, 16);
    printf("d.) 101001(2) = ");
    bin2base(0b101001, 8);
    printf("e.) 101101(2) = ");
    bin2base(0b101101, 4);

    return 0;
}
