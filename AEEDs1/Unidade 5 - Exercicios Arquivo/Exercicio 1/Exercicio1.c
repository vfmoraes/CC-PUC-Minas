#include <stdio.h>

int main(){

  FILE * arquivo = fopen("arquivoex1.txt", "w");
  for (int i = 1; i <= 10; i++){
    fprintf(arquivo, "%d\n", i);
  }

  fclose(arquivo);
}