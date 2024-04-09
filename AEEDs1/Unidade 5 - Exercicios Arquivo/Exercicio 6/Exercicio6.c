#include <stdio.h>
#include <stdlib.h>

int main(){

  FILE * arquivo = fopen("arquivoex6.txt", "w");
  int letras, contadordevogal = 0;
  char letra;

  puts("Insira a quantidade de letras que irá digitar:");
  scanf("%i", &letras);

  for(int i = 0; i < letras; i++){
    printf("Digite a letra %d: ", i+1);
    scanf(" %c", &letra);
    fprintf(arquivo, "%c ", letra);
  }

  fclose(arquivo);

  arquivo = fopen("arquivoex6.txt", "r");
  for(char letter = fgetc(arquivo); letter != EOF; letter = fgetc(arquivo)){
    if (letter == 'A' || letter == 'a' || letter == 'E' || letter == 'e' || letter == 'I' || letter == 'i' || letter == 'O' || letter == 'o' || letter == 'U' || letter == 'u'){
      printf("%c ", letter);
      contadordevogal++;
    }
  }

  printf("\nA quantidade de vogais dentre as letras digitadas é: %d", contadordevogal);

  fclose(arquivo);
}