#include <stdio.h>
#include <stdlib.h>

int main(){

  FILE * arquivo = fopen("arquivoex4.txt", "r");
  char letra;
  int contalinha = 1;

  for (letra = fgetc(arquivo); letra != EOF; letra = fgetc(arquivo)){
    printf("%c", letra);
    if (letra == '\n'){
      contalinha++;
    }
  }

  printf("\nA quantidade de linhas deste texto é de: %d", contalinha);

  fclose(arquivo);

}