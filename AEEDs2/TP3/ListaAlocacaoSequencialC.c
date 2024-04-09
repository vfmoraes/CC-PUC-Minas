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

// LISTA PROPRIAMENTE DITA =======================================================
Jogador *lista; // Array para armazenar os jogadores
int tamanho;     // Número de elementos na lista
int capacidade;   // Capacidade máxima da lista

/**
 * Cria uma lista sem elementos.
 */
void start(int capacidade_lista)
{
    lista = (Jogador *)malloc(capacidade_lista * sizeof(Jogador));
    if (lista == NULL)
    {
        errx(1, "Erro ao alocar memória para a lista!");
    }

    tamanho = 0;
    capacidade = capacidade_lista;
}

/**
 * Insere um jogador no início da lista.
 * @param jogador Jogador a ser inserido.
 */
void inserirInicio(Jogador jogador)
{
    if (tamanho == capacidade)
    {
        errx(1, "Erro ao inserir (lista cheia)!");
    }

    // Desloca os elementos para a direita
    for (int i = tamanho; i > 0; i--)
    {
        lista[i] = lista[i - 1];
    }

    // Insere o jogador no início
    lista[0] = jogador;
    tamanho++;
}

/**
 * Insere um jogador no final da lista.
 * @param jogador Jogador a ser inserido.
 */
void inserirFim(Jogador jogador)
{
    if (tamanho == capacidade)
    {
        errx(1, "Erro ao inserir (lista cheia)!");
    }

    // Insere o jogador no final
    lista[tamanho] = jogador;
    tamanho++;
}

/**
 * Insere um jogador em uma posição específica da lista.
 * @param jogador Jogador a ser inserido.
 * @param pos Posição de inserção.
 */
void inserir(Jogador jogador, int pos)
{
    if (pos < 0 || pos > tamanho || tamanho == capacidade)
    {
        errx(1, "Erro ao inserir (posição inválida ou lista cheia)!");
    }

    // Desloca os elementos para a direita a partir da posição de inserção
    for (int i = tamanho; i > pos; i--)
    {
        lista[i] = lista[i - 1];
    }

    // Insere o jogador na posição especificada
    lista[pos] = jogador;
    tamanho++;
}

/**
 * Remove o jogador do início da lista.
 * @return Jogador removido.
 */
Jogador removerInicio()
{
    if (tamanho == 0)
    {
        errx(1, "Erro ao remover (lista vazia)!");
    }

    Jogador removido = lista[0];

    // Desloca os elementos para a esquerda
    for (int i = 0; i < tamanho - 1; i++)
    {
        lista[i] = lista[i + 1];
    }

    tamanho--;
    return removido;
}

/**
 * Remove o jogador do final da lista.
 * @return Jogador removido.
 */
Jogador removerFim()
{
    if (tamanho == 0)
    {
        errx(1, "Erro ao remover (lista vazia)!");
    }

    Jogador removido = lista[tamanho - 1];
    tamanho--;

    return removido;
}

/**
 * Remove um jogador de uma posição específica da lista.
 * @param pos Posição de remoção.
 * @return Jogador removido.
 */
Jogador remover(int pos)
{
    if (pos < 0 || pos >= tamanho)
    {
        errx(1, "Erro ao remover (posição inválida)!");
    }

    Jogador removido = lista[pos];

    // Desloca os elementos para a esquerda a partir da posição de remoção
    for (int i = pos; i < tamanho - 1; i++)
    {
        lista[i] = lista[i + 1];
    }

    tamanho--;

    return removido;
}

/**
 * Mostra os jogadores na lista.
 */
void mostrar()
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("[%d] ", i);
        toString(&lista[i]);
    }
}

// Função principal
int main()
{
    int capacidade_lista = 4000;
    start(capacidade_lista);

    // Primeira parte: inserir jogadores na lista
    char id[50];
    scanf("%s", id);
    while (strcmp(id, "FIM") != 0)
    {
        Jogador jogador;
        initJogador(&jogador);
        ler(&jogador, id);
        inserirFim(jogador);
        scanf("%s", id);
    }

    // Segunda parte: inserir ou remover jogadores
    char line[50];
    while (fgets(line, sizeof(line), stdin) != NULL)
    {
        char comando[3];
        sscanf(line, "%s", comando);
        if (strcmp(comando, "II") == 0)
        {
            char id[50];
            sscanf(line, "%*s %s", id);
            Jogador jogador;
            initJogador(&jogador);
            ler(&jogador, id);
            inserirInicio(jogador);
        }
        else if (strcmp(comando, "I*") == 0)
        {
            int posicao;
            char id[50];
            sscanf(line, "%*s %d %s", &posicao, id);
            Jogador jogador;
            initJogador(&jogador);
            ler(&jogador, id);
            inserir(jogador, posicao);
        }
        else if (strcmp(comando, "IF") == 0)
        {
            char id[50];
            sscanf(line, "%*s %s", id);
            Jogador jogador;
            initJogador(&jogador);
            ler(&jogador, id);
            inserirFim(jogador);
        }
        else if (strcmp(comando, "RI") == 0)
        {
            Jogador jogador = removerInicio();
            printf("(R) %s\n", jogador.nome);
        }
        else if (strcmp(comando, "R*") == 0)
        {
            int posicao;
            sscanf(line, "%*s %d", &posicao);
            Jogador jogador = remover(posicao);
            printf("(R) %s\n", jogador.nome);
        }
        else if (strcmp(comando, "RF") == 0)
        {
            Jogador jogador = removerFim();
            printf("(R) %s\n", jogador.nome);
        }
    }

    // Exibir os jogadores restantes na lista
    mostrar();

    // Libera a memória alocada para a lista
    free(lista);

    return 0;
}
