/*
 * Nome: Victor Ferraz de Moraes
 * Matrícula: 802371
 * Curso: Ciência da Computação
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
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

// Estrutura da célula da lista
typedef struct Celula
{
  Jogador jogador;
  struct Celula *prox;
} Celula;

// Lista ligada
typedef struct
{
  Celula *primeiro;
  Celula *ultimo;
} Lista;

// Função para inicializar a lista
void startLista(Lista *lista)
{
  lista->primeiro = (Celula *)malloc(sizeof(Celula));
  lista->ultimo = lista->primeiro;
  lista->primeiro->prox = NULL;
}

// Função para inserir um elemento no início da lista
void inserirInicioLista(Lista *lista, Jogador jogador)
{
  Celula *tmp = (Celula *)malloc(sizeof(Celula));
  tmp->jogador = jogador;
  tmp->prox = lista->primeiro->prox;
  lista->primeiro->prox = tmp;
  if (lista->primeiro == lista->ultimo)
  {
    lista->ultimo = tmp;
  }
  tmp = NULL;
}

// Função para pesquisar um elemento na lista
bool pesquisarLista(Lista *lista, char *nome)
{
  Celula *i;
  for (i = lista->primeiro->prox; i != NULL; i = i->prox)
  {
    if (strcmp(i->jogador.nome, nome) == 0)
    {
      return true;
    }
  }
  return false;
}

// Função hash
int h(int altura)
{
  return altura % 25; // tamanho da tabela é 25
}

// Tabela hash
Lista tabela[25];

// Função para inicializar a tabela hash
void startTabela()
{
  for (int i = 0; i < 25; i++)
  {
    startLista(&tabela[i]);
  }
}

// Função para inserir um jogador na tabela hash
void inserirTabela(Jogador jogador)
{
  int posicao = h(jogador.altura);
  inserirInicioLista(&tabela[posicao], jogador);
}

// Função para pesquisar um jogador na tabela hash
bool pesquisarTabela(char *nome, int altura)
{
  int posicao = h(altura);
  Celula *i;

  // Verifica se o nome existe na lista
  for (i = tabela[posicao].primeiro->prox; i != NULL; i = i->prox)
  {
    if (strcmp(i->jogador.nome, nome) == 0)
    {
      return true;
    }
  }

  return false;
}

// Função principal
int main()
{
  char charProblematico[2] = {13};
  char id[50], nome[50];
  Jogador jogadores[1000];
  int numJogadores = 0;
  startTabela();

  // Loop para ler IDs até que "FIM" seja inserido
  while (fgets(id, sizeof(id), stdin) != NULL)
  {
    id[strcspn(id, charProblematico)] = '\0';
    id[strcspn(id, "\n")] = '\0'; // Removendo o '\n' do final da string
    if (strcmp(id, "FIM") == 0)
      break;
    Jogador jogador;
    initJogador(&jogador);
    ler(&jogador, id);
    jogadores[numJogadores++] = jogador;
    inserirTabela(jogador);
  }

  FILE *log = fopen("802371_hashIndireta.txt", "w");
  if (log == NULL)
  {
    printf("Não foi possível abrir o arquivo de log :(\n");
    return 1;
  }

  clock_t inicio = clock();

  // Segunda parte: pesquisar os jogadores
  while (fgets(nome, sizeof(nome), stdin) != NULL)
  {
    nome[strcspn(nome, charProblematico)] = '\0';
    nome[strcspn(nome, "\n")] = '\0'; // Removendo o '\n' do final da string
    if (strcmp(nome, "FIM") == 0)
      break;
    // Pesquisa pelo jogador no array de jogadores e atribui a um novo jogador
    Jogador jogador;
    initJogador(&jogador);
    for (int i = 0; i < numJogadores; i++)
    {
      if (strcmp(nome, jogadores[i].nome) == 0)
      {
        jogador = jogadores[i];
        break;
      }
    }
    if (pesquisarTabela(nome, jogador.altura))
    {
      printf("%s SIM\n", nome);
    }
    else
    {
      printf("%s NAO\n", nome);
    }
  }

  clock_t fim = clock();
  double tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
  fprintf(log, "802371\t%.5f\n", tempo);
  fclose(log);

  return 0;
}
