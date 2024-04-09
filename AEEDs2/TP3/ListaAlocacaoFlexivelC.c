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

// LISTA PROPRIAMENTE DITA =======================================================
Celula *primeiro;
Celula *ultimo;

/**
 * Cria uma lista sem elementos (somente no cabeca).
 */
void start()
{
    primeiro = novaCelula(*(Jogador *)malloc(sizeof(Jogador)));
    ultimo = primeiro;
}

/**
 * Insere um elemento na primeira posicao da lista.
 * @param x Jogador elemento a ser inserido.
 */
void inserirInicio(Jogador jogador)
{
    Celula *tmp = novaCelula(jogador);
    tmp->prox = primeiro->prox;
    primeiro->prox = tmp;
    if (primeiro == ultimo)
    {
        ultimo = tmp;
    }
    tmp = NULL;
}

/**
 * Insere um elemento na ultima posicao da lista.
 * @param x Jogador elemento a ser inserido.
 */
void inserirFim(Jogador jogador)
{
    ultimo->prox = novaCelula(jogador);
    ultimo = ultimo->prox;
}

/**
 * Remove um elemento da primeira posicao da lista.
 * @return resp Jogador elemento a ser removido.
 * @throws Exception Se a lista nao contiver elementos.
 */
Jogador removerInicio()
{
    if (primeiro == ultimo)
    {
        errx(1, "Erro ao remover!");
    }

    Celula *tmp = primeiro;
    primeiro = primeiro->prox;
    Jogador resp = primeiro->jogador;
    tmp->prox = NULL;
    free(tmp);
    tmp = NULL;
    return resp;
}

/**
 * Remove um elemento da ultima posicao da lista.
 * @return resp Jogador elemento a ser removido.
 */
Jogador removerFim()
{
    if (primeiro == ultimo)
    {
        errx(1, "Erro ao remover!");
    }

    // Caminhar ate a penultima celula:
    Celula *i;
    for (i = primeiro; i->prox != ultimo; i = i->prox)
        ;

    Jogador resp = ultimo->jogador;
    ultimo = i;
    free(ultimo->prox);
    i = ultimo->prox = NULL;

    return resp;
}

/**
 * Calcula e retorna o tamanho, em numero de elementos, da lista.
 * @return resp int tamanho
 */
int tamanho()
{
    int tamanho = 0;
    Celula *i;
    for (i = primeiro; i != ultimo; i = i->prox, tamanho++)
        ;
    return tamanho;
}

/**
 * Insere um elemento em uma posicao especifica considerando que o 
 * primeiro elemento valido esta na posicao 0.
 * @param x Jogador elemento a ser inserido.
 * @param pos int posicao da insercao.
 * @throws Exception Se <code>posicao</code> invalida.
 */
void inserir(Jogador jogador, int pos)
{

    int tam = tamanho();

    if (pos < 0 || pos > tam)
    {
        errx(1, "Erro ao inserir posicao (%d/ tamanho = %d) invalida!", pos, tam);
    }
    else if (pos == 0)
    {
        inserirInicio(jogador);
    }
    else if (pos == tam)
    {
        inserirFim(jogador);
    }
    else
    {
        // Caminhar ate a posicao anterior a insercao
        int j;
        Celula *i = primeiro;
        for (j = 0; j < pos; j++, i = i->prox)
            ;

        Celula *tmp = novaCelula(jogador);
        tmp->prox = i->prox;
        i->prox = tmp;
        tmp = i = NULL;
    }
}

/**
 * Remove um elemento de uma posicao especifica da lista
 * considerando que o primeiro elemento valido esta na posicao 0.
 * @param posicao Meio da remocao.
 * @return resp Jogador elemento a ser removido.
 * @throws Exception Se <code>posicao</code> invalida.
 */
Jogador remover(int pos)
{
    Jogador resp;
    int tam = tamanho();

    if (primeiro == ultimo)
    {
        errx(1, "Erro ao remover (vazia)!");
    }
    else if (pos < 0 || pos >= tam)
    {
        errx(1, "Erro ao remover posicao (%d/ tamanho = %d) invalida!", pos, tam);
    }
    else if (pos == 0)
    {
        resp = removerInicio();
    }
    else if (pos == tam - 1)
    {
        resp = removerFim();
    }
    else
    {
        // Caminhar ate a posicao anterior a insercao
        Celula *i = primeiro;
        int j;
        for (j = 0; j < pos; j++, i = i->prox)
            ;

        Celula *tmp = i->prox;
        resp = tmp->jogador;
        i->prox = tmp->prox;
        tmp->prox = NULL;
        free(tmp);
        i = tmp = NULL;
    }
    return resp;
}

/**
 * Mostra os elementos da lista separados por espacos.
 */
void mostrar()
{
    Celula *i;
    int contador = 0;
    for (i = primeiro->prox; i != NULL; i = i->prox)
    {
        printf("[%d] ", contador);
        toString(&i->jogador);
        contador++;
    }
}

/**
 * Procura um elemento e retorna se ele existe.
 * @param x Elemento a pesquisar.
 * @return <code>true</code> se o elemento existir,
 * <code>false</code> em caso contrario.
 */
bool pesquisar(int x)
{
    bool retorno = false;
    Celula *i;

    for (i = primeiro->prox; i != NULL; i = i->prox)
    {
        if (i->jogador.id == x)
        {
            retorno = true;
            i = ultimo;
        }
    }
    return retorno;
}

// Função principal
int main()
{
    int posicao;
    start();
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

    // Exibir os jogadores restantes na lista encadeada
    mostrar();

    return 0;
}
