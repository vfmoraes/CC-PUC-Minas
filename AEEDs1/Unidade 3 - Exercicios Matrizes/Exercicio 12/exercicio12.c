#include <stdio.h>

int main()
{
  const int alunos = 15, provas = 5;
  float notasalunos[alunos][provas], media[15], mediaprova[5];

  // Recebendo as notas em 5 provas diferentes de 15 alunos e calculando a média
  for (int i = 0; i < alunos; i++)
  {
    media[i] = 0;
    printf("Digite a nota do aluno %d:\n", i + 1);
    for (int j = 0; j < provas; j++)
    {
      scanf("%f", &notasalunos[i][j]);
      media[i] = media[i] + notasalunos[i][j];
    }
    media[i] = media[i] / 5;
  }

  // Imprimindo resultado dos alunos
  for (int i = 0; i < alunos; i++)
  {
    if (media[i] <= 4)
    {
      printf("Aluno %d: Reprovado\n", i + 1);
    }
    else if (media[i] < 7)
    {
      printf("Aluno %d: Exame Especial\n", i + 1);
    }
    else
    {
      printf("Aluno %d: Aprovado\n", i + 1);
    }
  }

  // Calculando média das provas
  for (int i = 0; i < provas; i++)
  {
    mediaprova[i] = 0;
    for (int j = 0; j < alunos; j++)
    {
      mediaprova[i] = mediaprova[i] + notasalunos[j][i];
    }
    mediaprova[i] = mediaprova[i] / 15;
    printf("Média da prova %d: %f\n", i + 1, mediaprova[i]);
  }
}