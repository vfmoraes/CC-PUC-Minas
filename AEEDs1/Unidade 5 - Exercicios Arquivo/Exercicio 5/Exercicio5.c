#include <stdio.h>
#include <stdlib.h>

int main(){

  FILE * arquivo1 = fopen("arquivo1ex5.txt", "w");
  FILE * arquivo2 = fopen("arquivo2ex5.txt", "w");
  FILE * arquivo3 = fopen("arquivo3ex5.txt", "w");

  char texto1[20], texto2[20], letra;

  puts("Insira o texto do arquivo 1:");
  scanf(" %[^\n]",texto1);
  fprintf(arquivo1, "%s ", texto1);
  puts("Insira o texto do arquivo 2:");
  scanf(" %[^\n]",texto2);
  fprintf(arquivo2, "%s", texto2);

  fclose(arquivo1);
  fclose(arquivo2);

  arquivo1 = fopen("arquivo1ex5.txt", "r");
  arquivo2 = fopen("arquivo2ex5.txt", "r");

  for(letra = fgetc(arquivo1); letra != EOF; letra = fgetc(arquivo1)){
    fprintf(arquivo3, "%c", letra);
  }
  for(letra = fgetc(arquivo2); letra != EOF; letra = fgetc(arquivo2)){
    fprintf(arquivo3, "%c", letra);
  }

  fclose(arquivo1);
  fclose(arquivo2);
  fclose(arquivo3);


}