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

// PILHA PROPRIAMENTE DITA =======================================================
Celula *topo; // Sem celula cabeca.

/**
 * Cria uma pilha sem elementos.
 */
void start()
{
    topo = NULL;
}

/**
 * Insere elemento na pilha (politica FILO).
 * @param jogador Jogador a inserir.
 */
void inserir(Jogador jogador)
{
    Celula *nova = novaCelula(jogador);
    nova->prox = topo;
    topo = nova;
}

/**
 * Remove elemento da pilha (politica FILO).
 * @return Jogador removido.
 */
Jogador remover()
{
    if (topo == NULL)
    {
        errx(1, "Erro ao remover (pilha vazia)!");
    }

    Jogador resp = topo->jogador;
    Celula *tmp = topo;
    topo = topo->prox;
    tmp->prox = NULL;
    free(tmp);
    tmp = NULL;
    return resp;
}

/**
 * Mostra os jogadores na pilha, começando da base para o topo.
 */
void mostrar()
{
    Celula *i = topo;
    Celula *anterior = NULL;

    // Inverte a ordem da pilha
    while (i != NULL)
    {
        Celula *proxima = i->prox;
        i->prox = anterior;
        anterior = i;
        i = proxima;
    }

    int contador = 0;
    for (i = anterior; i != NULL; i = i->prox)
    {
        printf("[%d] ", contador);
        toString(&i->jogador);
        contador++;
    }

    // Restaura a ordem original da pilha
    i = anterior;
    anterior = NULL;
    while (i != NULL)
    {
        Celula *proxima = i->prox;
        i->prox = anterior;
        anterior = i;
        i = proxima;
    }

    topo = anterior; // Atualiza o topo para a ordem original
}

// Função principal
int main()
{
    start();

    // Inserção de jogadores na pilha
    char id[50];
    scanf("%s", id);
    while (strcmp(id, "FIM") != 0)
    {
        Jogador jogador;
        initJogador(&jogador);
        ler(&jogador, id);
        inserir(jogador);

        scanf("%s", id);
    }

    // Inserção ou remoção de jogadores
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
        }
        else if (strcmp(comando, "R") == 0)
        {
            Jogador jogador = remover();
            printf("(R) %s\n", jogador.nome);
        }
    }

    // Exibir os jogadores restantes na pilha
    mostrar();

    return 0;
}
