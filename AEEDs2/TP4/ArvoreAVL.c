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

// Função para imprimir os detalhes do jogador
void toString(Jogador *jogador)
{
    printf("[%d ## %s ## %d ## %d ## %d ## %s ## %s ## %s]\n", jogador->id, jogador->nome, jogador->altura,
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

int comparacoes = 0;

// Estrutura para representar um nó da árvore AVL
typedef struct Node
{
    int id;
    char nome[50];
    struct Node *left;
    struct Node *right;
    int height;
} Node;

// Estrutura para representar a árvore AVL
typedef struct
{
    Node *root;
} AVLTree;

// Função para obter a altura de um nó
int height(Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Função para obter o máximo de dois inteiros
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Função para criar um novo nó
Node* newNode(int id, char* nome) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->id = id;
    strcpy(node->nome, nome);
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

// Função para realizar uma rotação simples para a direita
Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Realiza a rotação
    x->right = y;
    y->left = T2;

    // Atualiza alturas
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// Função para realizar uma rotação simples para a esquerda
Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Realiza a rotação
    y->left = x;
    x->right = T2;

    // Atualiza alturas
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Função para obter o fator de balanceamento de um nó
int getBalance(Node* node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

// Função para inserir um jogador na árvore AVL
Node* insert(Node* node, int id, char* nome) {
    // Realiza a inserção normal de uma BST
    if (node == NULL)
        return newNode(id, nome);

    if (strcmp(nome, node->nome) < 0)
        node->left = insert(node->left, id, nome);
    else if (strcmp(nome, node->nome) > 0)
        node->right = insert(node->right, id, nome);
    else // Duplicatas não são permitidas
        return node;

    // Atualiza a altura do nó atual
    node->height = 1 + max(height(node->left), height(node->right));

    // Obtém o fator de balanceamento deste nó para verificar se é necessário reequilibrar
    int balance = getBalance(node);

    // Casos de desequilíbrio

    // Rotação simples à direita
    if (balance > 1 && strcmp(nome, node->left->nome) < 0)
        return rotateRight(node);

    // Rotação simples à esquerda
    if (balance < -1 && strcmp(nome, node->right->nome) > 0)
        return rotateLeft(node);

    // Rotação dupla à esquerda-direita
    if (balance > 1 && strcmp(nome, node->left->nome) > 0) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Rotação dupla à direita-esquerda
    if (balance < -1 && strcmp(nome, node->right->nome) < 0) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

// Função para inserir um jogador na árvore AVL
void insertAVL(AVLTree* tree, int id, char* nome) {
    tree->root = insert(tree->root, id, nome);
}

int searchAVLWithPrint(Node* node, char* nome) {
    if (node == NULL)
        return -1;

    int cmp = strcmp(nome, node->nome);

    if (cmp == 0) {
        return node->id;
    } else if (cmp < 0) {
        printf("esq ");
        int result = searchAVLWithPrint(node->left, nome);
        return result;
    } else {
        printf("dir ");
        int result = searchAVLWithPrint(node->right, nome);
        return result;
    }
}

// Função para imprimir o caminho na árvore AVL
void printPath(AVLTree* tree, char* nome) {
    printf("%s ", nome);

    if (tree->root != NULL) {
        printf("raiz ");
    }

    int result = searchAVLWithPrint(tree->root, nome);
    if (result != -1)
        printf("SIM\n");
    else
        printf("NAO\n");
}

// Função principal
int main() {
    char id[50], nome[50];
    Jogador jogadores[1000];
    int numJogadores = 0;

    AVLTree avlTree;
    avlTree.root = NULL;

    // Loop para ler IDs até que "FIM" seja inserido
    while (fgets(id, sizeof(id), stdin) != NULL) {
        id[strcspn(id, "\n")] = '\0'; // Removendo o '\n' do final da string
        if (strcmp(id, "FIM") == 0)
            break;
        Jogador jogador;
        initJogador(&jogador);
        ler(&jogador, id);
        jogadores[numJogadores++] = jogador;
        insertAVL(&avlTree, jogador.id, jogador.nome);
    }

    FILE* log = fopen("matricula_avl.txt", "w");
    if (log == NULL) {
        printf("Não foi possível abrir o arquivo de log :(\n");
        return 1;
    }

    clock_t inicio = clock();

    while (fgets(nome, sizeof(nome), stdin) != NULL) {
        nome[strcspn(nome, "\n")] = '\0'; // Removendo o '\n' do final da string
        if (strcmp(nome, "FIM") == 0)
            break;
        printPath(&avlTree, nome);
    }

    clock_t fim = clock();
    double tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    fprintf(log, "802371\t%.5f\t%d\n", tempo, comparacoes);

    fclose(log);

    return 0;
}