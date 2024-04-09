/*
 * Nome: Victor Ferraz de Moraes
 * Matrícula: 802371
 * Curso: Ciência da Computação
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;            // Variável para armazenar a quantidade de números a serem lidos
    double num;       // Variável para armazenar os números lidos

    // Lê a quantidade de números a serem lidos
    scanf("%d", &n);

    // Abre um arquivo para escrita
    FILE *escrita = fopen("teste", "wb");

    // Loop para ler e escrever os números no arquivo
    for (int i = 0; i < n; i++) {
        scanf("%lf", &num); // Lê um número da entrada padrão
        fwrite(&num, sizeof(double), 1, escrita); // Escreve o número no arquivo
    }

    fclose(escrita); // Fecha o arquivo de escrita

    // Abre o mesmo arquivo para leitura
    FILE *leitura = fopen("teste", "rb");

    // Posiciona o cursor no último número no arquivo (n * 8 - 8 bytes antes do fim)
    fseek(leitura, n * sizeof(double) - sizeof(double), SEEK_SET);

    // Loop para ler e imprimir os números do arquivo em ordem reversa
    for (int i = 1; i < n; i++) {
        fread(&num, sizeof(double), 1, leitura); // Lê um número do arquivo
        if ((num - (int)num) == 0)
            printf("%d\n", (int)num); // Se o número for um número inteiro, imprime como inteiro
        else
            printf("%g\n", num); // Caso contrário, imprime como número de ponto flutuante
        fseek(leitura, -2 * sizeof(double), SEEK_CUR); // Move o cursor 16 bytes para trás no arquivo (tamanho de um double)
    }

    fread(&num, sizeof(double), 1, leitura); // Lê e imprime o primeiro número no arquivo (primeiro na ordem original)
    printf("%g\n", num);

    fclose(leitura); // Fecha o arquivo de leitura

    return 0;
}
