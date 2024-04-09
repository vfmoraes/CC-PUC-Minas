#include <stdio.h>
#include <stdlib.h>

int main(){

  FILE * arquivo = fopen("arquivoex2.txt", "w");
  char string[20];

  puts("Insira um texto que ficará salvo no arquivo:");
  scanf(" %s", string);

  fprintf(arquivo, "%s", string);

  fclose(arquivo);
}