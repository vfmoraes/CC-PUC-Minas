#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool EncontraNumero(int array[], int tam, int x){
  for (int i = 0; i < tam; i++){
    if(array[i] == x){
      return true;
    }
  }
  return false;
}

int main(){

  int index, pesquisa;
  printf("Defina o tamanho do array:\n");
  scanf("%d", &index);
  int array[index];
  for (int i = 0; i < index; i++){
    printf("Digite o número da posição %d: ", i+1);
    scanf("%d", &array[i]);
  }
  printf("Digite um numero para pesquisar no array:\n");
  scanf("%d", &pesquisa);
  if (EncontraNumero(array, index, pesquisa) == true){
    printf("O numero %d está presente no array", pesquisa);
  } else {
    printf("O numero %d não está presente no array", pesquisa);
  }

  return 0;

}
