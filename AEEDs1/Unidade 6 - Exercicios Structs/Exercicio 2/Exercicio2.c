#include <stdio.h>
#include <stdlib.h>

typedef struct veiculo {
  char marca[20];
  char modelo[20];
  char cor[20];
  int ano;
} Veiculo;

int main(){
  Veiculo veiculos[2];
  for (int i = 0; i < 2; i++){
    printf("Digite a Marca do carro %d:\n", i+1);
    scanf(" %[^\n]", veiculos[i].marca);
    printf("Digite o Modelo do carro %d:\n", i+1);
    scanf(" %[^\n]", veiculos[i].modelo);
    printf("Digite a Cor do carro %d:\n", i+1);
    scanf(" %[^\n]", veiculos[i].cor);
    printf("Digite o Ano do carro %d:\n", i+1);
    scanf("%d", &veiculos[i].ano);
  }

  for(int i = 0; i < 2; i++){
    printf("Carro %d | Marca: %s | Modelo: %s | Cor: %s | Ano: %d\n", i+1, veiculos[i].marca, veiculos[i].modelo, veiculos[i].cor, veiculos[i].ano);
  }
}