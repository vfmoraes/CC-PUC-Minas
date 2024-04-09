/*
 * Nome: Victor Ferraz de Moraes
 * Matrícula: 802371
 * Curso: Ciência da Computação
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Função que substitui aleatoriamente uma letra em uma palavra
void TrocaLetra(char palavra[], int pos, char letraA, char letraB) {
    if (palavra[pos] == '\0') { // Verifica se chegou ao final da palavra
        return;
    }

    if (palavra[pos] == letraA) {
        palavra[pos] = letraB;
    }

    TrocaLetra(palavra, pos+1, letraA, letraB); // Chama recursivamente para o restante da palavra
}

int main() {
    char palavra[999];
    srand(4); // Define a semente como 4

        scanf("%[^\n]%*c", palavra);
        while (strcmp(palavra, "FIM") != 0)
        {
        char letraA = 'a' + rand() % 26; // Gera letras aleatórias
        char letraB = 'a' + rand() % 26;
        TrocaLetra(palavra, 0, letraA, letraB);
        printf("%s\n", palavra);
        scanf("%[^\r\n]%*c", palavra);
        }

    return 0;
}