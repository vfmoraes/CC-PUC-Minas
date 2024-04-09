/*
 * Nome: Victor Ferraz de Moraes
 * Matrícula: 802371
 * Curso: Ciência da Computação
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <err.h>

// Definindo a estrutura Jogador
typedef struct
{
    int id;
    char nome[50];
    int altura;
    int peso;
    char universidade[50];
    int anoNascimento;
    char cidadeNascimento[50];
    char estadoNascimento[50];
} Jogador;

// Função para imprimir os detalhes do jogador
void toString(Jogador *jogador)
{
    printf("## %s ## %d ## %d ## %d ## %s ## %s ## %s ##\n", jogador->nome, jogador->altura,
           jogador->peso, jogador->anoNascimento, jogador->universidade, jogador->cidadeNascimento, jogador->estadoNascimento);
}

// Função para inicializar um jogador com valores padrão
void initJogador(Jogador *jogador)
{
    jogador->id = 0;
    strcpy(jogador->nome, "");
    jogador->altura = 0;
    jogador->peso = 0;
    strcpy(jogador->universidade, "nao informado");
    jogador->anoNascimento = 0;
    strcpy(jogador->cidadeNascimento, "nao informado");
    strcpy(jogador->estadoNascimento, "nao informado");
}

char *my_strtok(char **string, char *delimiter)
{
    if (*string == NULL)
    {
        // Não há mais tokens
        return NULL;
    }

    char *token_start = *string;
    *string = strpbrk(token_start, delimiter);
    if (*string)
    {
        // Termina o token atual e avança a string para o próximo token
        *(*string)++ = '\0';
    }

    return token_start;
}

// Função para ler os detalhes de um jogador a partir de um arquivo CSV
void ler(Jogador *jogador, char *id)
{
    char line[256];
    FILE *file = fopen("/tmp/players.csv", "r");
    if (file == NULL)
    {
        printf("Não foi possível abrir o arquivo :(\n");
        return;
    }

    // Pulando o cabeçalho do CSV
    fgets(line, sizeof(line), file);

    while (fgets(line, sizeof(line), file))
    {
        if (line[strlen(line) - 1] == '\n')
            line[strlen(line) - 1] = '\0';

        char *data[8];
        char *line_ptr = line;

        // Tokenizando os primeiros 8 campos da linha
        for (int i = 0; i < 8; i++)
        {
            data[i] = my_strtok(&line_ptr, ",");
            if (data[i] == NULL || strcmp(data[i], "") == 0)
            {
                data[i] = "nao informado"; // Substituindo os campos vazios ou NULL por "nao informado"
            }
        }

        // Convertendo a ID para um número antes de comparar
        if (atoi(data[0]) == atoi(id))
        {
            jogador->id = atoi(data[0]);
            strcpy(jogador->nome, data[1]);
            jogador->altura = atoi(data[2]);
            jogador->peso = atoi(data[3]);
            strcpy(jogador->universidade, data[4]);
            jogador->anoNascimento = (strcmp(data[5], "nao informado") != 0) ? atoi(data[5]) : 0;
            strcpy(jogador->cidadeNascimento, data[6]);
            strcpy(jogador->estadoNascimento, data[7]);

            break;
        }
    }

    fclose(file);
}

// FILA CIRCULAR ===================================================================
Jogador *fila;  // Array para armazenar os jogadores
int primeiro;    // Índice do primeiro elemento na fila
int ultimo;      // Índice do último elemento na fila
int tamanho;     // Número de elementos na fila
int capacidade;   // Capacidade máxima da fila

/**
 * Cria uma fila circular vazia com capacidade especificada.
 */
void start(int capacidade_fila)
{
    fila = (Jogador *)malloc(capacidade_fila * sizeof(Jogador));
    if (fila == NULL)
    {
        errx(1, "Erro ao alocar memória para a fila!");
    }

    primeiro = 0;
    ultimo = -1;
    tamanho = 0;
    capacidade = capacidade_fila;
}

/**
 * Insere um jogador na fila circular.
 * Se a fila estiver cheia, remove o primeiro elemento antes de inserir.
 * @param jogador Jogador a ser inserido.
 */
void inserir(Jogador jogador)
{
    if (tamanho == capacidade)
    {
        remover(); // Remove o primeiro elemento se a fila estiver cheia
    }

    ultimo = (ultimo + 1) % capacidade; // Calcula o próximo índice do último
    fila[ultimo] = jogador;
    tamanho++;
}

/**
 * Remove o primeiro jogador da fila circular.
 */
void remover()
{
    if (tamanho == 0)
    {
        errx(1, "Erro ao remover (fila vazia)!");
    }

    primeiro = (primeiro + 1) % capacidade; // Calcula o próximo índice do primeiro
    tamanho--;
}

/**
 * Mostra os jogadores na fila circular.
 */
void mostrar()
{
    int i;
    for (i = 0; i < tamanho; i++)
    {
        printf("[%d] ", i);
        toString(&fila[(primeiro + i) % capacidade]);
    }
}

// Função principal
int main()
{
    // Defina a capacidade da fila (por exemplo, 5)
    int capacidade_fila = 5;
    start(capacidade_fila);

    // Primeira parte: inserir jogadores na fila
    char id[50];
    scanf("%s", id);
    while (strcmp(id, "FIM") != 0)
    {
        Jogador jogador;
        initJogador(&jogador);
        ler(&jogador, id);
        inserir(jogador);
        float media = 0;

        // Calcular a média das alturas
        for (int i = 0; i < tamanho; i++)
        {
            media += fila[(primeiro + i) % capacidade].altura;
        }

        printf("%.f\n", media / tamanho);

        scanf("%s", id);
    }

    // Segunda parte: inserir ou remover jogadores
    char line[50];
    while (fgets(line, sizeof(line), stdin) != NULL)
    {
        char comando[3];
        sscanf(line, "%s", comando);
        if (strcmp(comando, "I") == 0)
        {
            char id[50];
            sscanf(line, "%*s %s", id);
            Jogador jogador;
            initJogador(&jogador);
            ler(&jogador, id);
            inserir(jogador);

            float media = 0;

            // Calcular a média das alturas
            for (int i = 0; i < tamanho; i++)
            {
                media += fila[(primeiro + i) % capacidade].altura;
            }

            printf("%.f\n", media / tamanho);
        }
        else if (strcmp(comando, "R") == 0)
        {
            Jogador jogador = fila[primeiro];
            remover();
            printf("(R) %s\n", jogador.nome);
        }
    }

    // Exibir os jogadores restantes na fila circular
    mostrar();

    // Libera a memória alocada para a fila
    free(fila);

    return 0;
}
