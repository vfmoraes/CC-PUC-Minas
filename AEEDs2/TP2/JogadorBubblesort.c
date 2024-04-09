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
int movimentacoes = 0;

void bubbleSort(Jogador arr[], int n) 
{
  int i, j;
  for (i = 0; i < n-1; i++)      
    for (j = 0; j < n-i-1; j++) 
    {
      comparacoes++;
      if (arr[j].anoNascimento > arr[j+1].anoNascimento || 
          (arr[j].anoNascimento == arr[j+1].anoNascimento && strcmp(arr[j].nome, arr[j+1].nome) > 0)) 
      {
        Jogador temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
        movimentacoes+= 3;
      }
    }
}

// Função principal
int main()
{
  char id[50], nome[50];
  Jogador jogadores[1000];
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
    jogadores[numJogadores++] = jogador;
  }

  FILE *log = fopen("matricula_bolha.txt", "w");
  if (log == NULL)
  {
    printf("Não foi possível abrir o arquivo de log :(\n");
    return 1;
  }

  clock_t inicio = clock();

  bubbleSort(jogadores, numJogadores);

  for (int i = 0; i < numJogadores; i++)
  {
    toString(&jogadores[i]);
  }

  clock_t fim = clock();
  double tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

  fprintf(log, "802371\t%.5f\t%d\t%d\n", tempo, comparacoes, movimentacoes);

  fclose(log);

  return 0;
}
