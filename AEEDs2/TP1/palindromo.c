/*
 * Nome: Victor Ferraz de Moraes
 * Matrícula: 802371
 * Curso: Ciência da Computação
 */

#include <string.h>
#include <stdio.h>

// Função que verifica se uma string é um palíndromo
int isPalindromo(char palavra[]) {
    int tam = strlen(palavra); // Calcula o comprimento da string
    int meio = tam / 2; // Calcula o índice do meio da string
    for (int i = 0; i <= meio; i++) {
        if (palavra[i] != palavra[tam - i - 1]) {
            return 0; // Se os caracteres não forem iguais, a string não é um palíndromo
        }
    }
    return 1; // Se chegarmos aqui, a string é um palíndromo
}

int main() {
    char palavra[900]; // Declara um array de caracteres para armazenar a palavra
    scanf("%[^\r\n]%*c", palavra); // Lê a primeira palavra da entrada (ignorando o caractere de nova linha)
    while (strcmp(palavra, "FIM") != 0) { // Enquanto a palavra lida não for "FIM"
        if (isPalindromo(palavra)) {
            printf("SIM\n"); // Se for um palíndromo, imprime "SIM"
        } else {
            printf("NAO\n"); // Se não for um palíndromo, imprime "NAO"
        }
        scanf("%[^\r\n]%*c", palavra); // Lê a próxima palavra da entrada (ignorando o caractere de nova linha)
    }

    return 0;
}
