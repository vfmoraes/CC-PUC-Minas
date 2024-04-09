#include <stdio.h>

int main(){

  /*6. Ler 100 números inteiros e exibir a soma dos números.*/
  
  int num, soma;

  for(int i = 0; i < 100; i++){
    printf("Digite o %i numero:\n", i + 1);
    scanf("%i", &num);
    soma += num;
  }
  printf("A soma dos 100 números é: %i", soma);
  return 0;
}