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

// TIPO CELULA ===================================================================
typedef struct Celula
{
    Jogador jogador;        // Elemento inserido na celula.
    struct Celula *prox; // Aponta a celula prox.
} Celula;

Celula *novaCelula(Jogador jogador)
{
    Celula *nova = (Celula *)malloc(sizeof(Celula));
    nova->jogador = jogador;
    nova->prox = NULL;
    return nova;
}

// FILA CIRCULAR ===================================================================
Celula *primeiro;
Celula *ultimo;
int tamanho = 0;

/**
 * Cria uma fila circular vazia.
 */
void start()
{
    primeiro = novaCelula(*(Jogador *)malloc(sizeof(Jogador)));
    ultimo = primeiro;
}

/**
 * Insere um jogador na fila circular.
 * Se a fila estiver cheia, remove o primeiro elemento antes de inserir.
 * @param jogador Jogador a ser inserido.
 */
void inserir(Jogador jogador)
{
    if (tamanho == 5)
    {
        remover(); // Remove o primeiro elemento se a fila estiver cheia
    }

    Celula *nova = novaCelula(jogador);

    if (tamanho == 0)
    {
        primeiro = nova;
        ultimo = nova;
        ultimo->prox = primeiro; // Faz a fila ser circular
    }
    else
    {
        ultimo->prox = nova;
        ultimo = nova;
        ultimo->prox = primeiro; // Faz a fila ser circular
    }

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

    Celula *tmp = primeiro;
    primeiro = primeiro->prox;

    free(tmp);
    tmp = NULL;

    tamanho--;
}

/**
 * Mostra os jogadores na fila circular.
 */
void mostrar()
{
    Celula *i;
    int contador = 0;
    for (i = primeiro; contador < tamanho; i = i->prox, contador++)
    {
        printf("[%d] ", contador);
        toString(&i->jogador);
    }
}

// Função principal
int main()
{
    start();

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
        Celula *temp = primeiro;
        for (int i = 0; i < tamanho; i++, temp = temp->prox)
        {
            media += temp->jogador.altura;
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
            Celula *temp = primeiro;
            for (int i = 0; i < tamanho; i++, temp = temp->prox)
            {
                media += temp->jogador.altura;
            }

            printf("%.f\n", media / tamanho);
        }
        else if (strcmp(comando, "R") == 0)
        {
            Jogador jogador = primeiro->jogador;
            remover();
            printf("(R) %s\n", jogador.nome);
        }
    }

    // Exibir os jogadores restantes na fila circular
    mostrar();

    return 0;
}
