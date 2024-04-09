#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool EncontraNumero(int array[], int x){
  for (int i = 0; i < 5; i++){
    if(array[i] == x){
      return true;
    }
  }
  return false;
}

int main(){

  int pesquisa;
  int array[] = {0,1,2,3,4};
  printf("Digite um numero para pesquisar no array:\n");
  scanf("%d", &pesquisa);
  if (EncontraNumero(array, pesquisa) == true){
    printf("O numero %d está presente no array", pesquisa);
  } else {
    printf("O numero %d não está presente no array", pesquisa);
  }

  return 0;

}
