/*
  Guia_0105.c
  802371 - Victor Ferraz de Moraes
*/

#include <stdio.h>
#include <string.h>

// Função para converter ASCII para hexadecimal
void ASCII2hex(char input[]) {
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        printf("%02X ", input[i]);
    }
    printf("(16)\n");
}

// Função para converter hexadecimal para ASCII
void hex2ASCII(char input[]) {
    int len = strlen(input);
    char byte[3];
    byte[2] = '\0';

    int num;
    for (int i = 0; i < len; i += 3) {
        byte[0] = input[i];
        byte[1] = input[i + 1];
        sscanf(byte, "%x", &num);
        printf("%c", num);
    }
    printf("(ASCII)\n");
}

int main() {
    char str1[] = "PUC-Minas";
    char str2[] = "2023-02";
    char str3[] = "Belo Horizonte";
    char hex1[] = "4E 6F 69 74 65";
    char hex2[] = "4D 2E 20 47 2E";

    printf("a.) \"PUC-Minas\" = ");
    ASCII2hex(str1);

    printf("b.) \"2023-02\" = ");
    ASCII2hex(str2);

    printf("c.) \"Belo Horizonte\" = ");
    ASCII2hex(str3);

    printf("d.) 116 157 151 164 145 (8) = 4E 6F 69 74 65(16) = ");
    hex2ASCII(hex1);

    printf("e.) 4D 2E 20 47 2E(16) = ");
    hex2ASCII(hex2);

    return 0;
}
