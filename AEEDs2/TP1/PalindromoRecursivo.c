/*
 * Nome: Victor Ferraz de Moraes
 * Matrícula: 802371
 * Curso: Ciência da Computação
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Função recursiva para verificar se uma string é um palíndromo
bool isPalindromo(char palavra[], int inicio, int fim) {
    // Caso base: quando o índice de início é maior ou igual ao índice de fim, a string é um palíndromo
    if (inicio >= fim) {
        return true;
    }

    // Verifica se os caracteres nas posições inicio e fim são iguais
    if (palavra[inicio] != palavra[fim]) {
        return false; // Se forem diferentes, a string não é um palíndromo
    }

    // Chamada recursiva para verificar os caracteres internos da string
    return isPalindromo(palavra, inicio + 1, fim - 1);
}

int main() {
    char palavra[900]; // Declara um array de caracteres para armazenar a palavra
    scanf("%[^\r\n]%*c", palavra); // Lê a primeira palavra da entrada (ignorando o caractere de nova linha)
    while (strcmp(palavra, "FIM") != 0) { // Enquanto a palavra lida não for "FIM"
        int tam = strlen(palavra);
        bool resultado = isPalindromo(palavra, 0, tam - 1); // Chama a função recursiva

        if (resultado) {
            printf("SIM\n"); // Se for um palíndromo, imprime "SIM"
        } else {
            printf("NAO\n"); // Se não for um palíndromo, imprime "NAO"
        }
        scanf("%[^\r\n]%*c", palavra); // Lê a próxima palavra da entrada (ignorando o caractere de nova linha)
    }

    return 0;
}
