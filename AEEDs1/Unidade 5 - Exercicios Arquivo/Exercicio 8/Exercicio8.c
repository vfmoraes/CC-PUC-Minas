#include <stdio.h>
#include <stdlib.h>

int main(){
  FILE * arquivo;
  int matricula[3], escolha;
  double telefone[3];

  puts("1-Listar Dados");
  puts("2-Cadastrar dados");
  scanf("%d", &escolha);

  switch(escolha){
    case 1:
      arquivo = fopen("arquivoex8.txt", "r");
      for(char letra = fgetc(arquivo); letra != EOF; letra = fgetc(arquivo)){
        printf("%c", letra);
      }
      fclose(arquivo);
      break;
    case 2:
      arquivo = fopen("arquivoex8.txt", "w");
      for(int i = 0; i < 3; i++){
      printf("Digite o numero da matricula do aluno %d:", i+1);
      scanf("%d", &matricula[i]);
      printf("Digite o numero do telefone aluno %d:", i+1);
      scanf("%lf", &telefone[i]);
      fprintf(arquivo, "Aluno %d | Matricula: %d | Telefone: %.0lf\n", i+1, matricula[i], telefone[i]);
    }
    fclose(arquivo);
    break;
  }
}