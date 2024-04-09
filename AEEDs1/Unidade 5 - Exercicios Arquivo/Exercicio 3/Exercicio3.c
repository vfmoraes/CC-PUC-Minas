#include <stdio.h>
#include <stdlib.h>

int main(){
  
  FILE * arquivo = fopen("arquivoex2.txt", "r");
  if (arquivo == NULL){
    printf("Arquivo não encontrado");
    return 0;
  }
  char letra;
  int contador = 0;

  for(letra = fgetc(arquivo); letra != EOF; letra = fgetc(arquivo)){
    if(letra == 'A' || letra == 'a'){
      contador++;
    }
  }

  printf("O número de letras 'A' do arquivo anterior é: %d", contador);

  fclose(arquivo);

}