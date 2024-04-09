/*
 * Nome: Victor Ferraz de Moraes
 * Matrícula: 802371
 * Curso: Ciência da Computação
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

// Definindo a estrutura CelulaDupla para a lista duplamente encadeada
typedef struct CelulaDupla
{
    Jogador jogador;
    struct CelulaDupla *prox;
    struct CelulaDupla *ant;
} CelulaDupla;

CelulaDupla *primeiro;
CelulaDupla *ultimo;

// Função para inicializar a lista duplamente encadeada
void iniciarLista()
{
    primeiro = (CelulaDupla *)malloc(sizeof(CelulaDupla));
    ultimo = primeiro;
    primeiro->prox = NULL;
    primeiro->ant = NULL;
}

// Função para inserir um jogador no final da lista
void inserirFimLista(Jogador jogador)
{
    CelulaDupla *novaCelula = (CelulaDupla *)malloc(sizeof(CelulaDupla));
    novaCelula->jogador = jogador;
    novaCelula->prox = NULL;
    novaCelula->ant = ultimo;

    ultimo->prox = novaCelula;
    ultimo = novaCelula;
}

// Função para imprimir os detalhes do jogador
void toString(Jogador jogador)
{
    printf("[%d ## %s ## %d ## %d ## %d ## %s ## %s ## %s]\n", jogador.id, jogador.nome, jogador.altura,
           jogador.peso, jogador.anoNascimento, jogador.universidade, jogador.cidadeNascimento, jogador.estadoNascimento);
}

// Função para imprimir a lista de jogadores
void imprimirLista()
{
    CelulaDupla *atual = primeiro->prox;
    while (atual != NULL)
    {
        toString(atual->jogador);
        atual = atual->prox;
    }
}

// Função para liberar a memória alocada para a lista
void liberarLista()
{
    CelulaDupla *atual = primeiro;
    while (atual != NULL)
    {
        CelulaDupla *prox = atual->prox;
        free(atual);
        atual = prox;
    }
}

int comparacoes = 0;
int movimentacoes = 0;

// Função para trocar dois jogadores
void troca(Jogador *a, Jogador *b)
{
    Jogador t = *a;
    *a = *b;
    *b = t;
    movimentacoes += 3;
}

// Função para particionar a lista para o quicksort
CelulaDupla *particiona(CelulaDupla *low, CelulaDupla *high)
{
    Jogador pivo = high->jogador;
    CelulaDupla *i = low->ant;

    for (CelulaDupla *j = low; j != high; j = j->prox)
    {
        comparacoes++;
        if (strcmp(j->jogador.estadoNascimento, pivo.estadoNascimento) < 0 ||
            (strcmp(j->jogador.estadoNascimento, pivo.estadoNascimento) == 0 && strcmp(j->jogador.nome, pivo.nome) < 0))
        {
            i = (i == NULL) ? low : i->prox;
            troca(&(i->jogador), &(j->jogador));
        }
    }
    i = (i == NULL) ? low : i->prox;
    troca(&(i->jogador), &(high->jogador));
    return i;
}

// Função para ordenar a lista usando quicksort
void quickSortLista(CelulaDupla *low, CelulaDupla *high)
{
    if (high != NULL && low != high && low != high->prox)
    {
        CelulaDupla *pi = particiona(low, high);
        quickSortLista(low, pi->ant);
        quickSortLista(pi->prox, high);
    }
}

// Função principal
int main()
{
    iniciarLista(); // Inicializa a lista duplamente encadeada

    char id[50], nome[50];
    int numJogadores = 0;

    // Loop para ler IDs até que "FIM" seja inserido
    while (fgets(id, sizeof(id), stdin) != NULL)
    {
        id[strcspn(id, "\n")] = '\0'; // Removendo o '\n' do final da string
        if (strcmp(id, "FIM") == 0)
            break;

        Jogador jogador;
        initJogador(&jogador);
        ler(&jogador, id);
        inserirFimLista(jogador);
        numJogadores++;
    }

    FILE *log = fopen("matricula_quicksort2.txt", "w");
    if (log == NULL)
    {
        printf("Não foi possível abrir o arquivo de log :(\n");
        return 1;
    }

    clock_t inicio = clock();

    quickSortLista(primeiro->prox, ultimo);

    for (CelulaDupla *i = primeiro->prox; i != NULL; i = i->prox)
    {
        toString(i->jogador);
    }

    clock_t fim = clock();
    double tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    fprintf(log, "802371\t%.5f\t%d\t%d\n", tempo, comparacoes, movimentacoes);

    fclose(log);

    liberarLista(); // Libera a memória alocada para a lista duplamente encadeada

    return 0;
}