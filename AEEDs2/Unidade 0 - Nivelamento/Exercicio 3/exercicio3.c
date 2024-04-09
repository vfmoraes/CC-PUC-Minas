#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void MaiorMenorNumero(int array[], int tam){
  int maior, menor;
  for (int i = 0; i < tam; i++){
    if(i == 0){
      maior = array[i];
      menor = array[i];
    }
    if (array[i] > maior){
      maior = array[i];
    }
    if (array[i] < menor){
      menor = array[i];
    }
  }
  printf("O menor numero do array é o %d e o maior é o %d", menor, maior);
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
  MaiorMenorNumero(array, index);

  return 0;

}
