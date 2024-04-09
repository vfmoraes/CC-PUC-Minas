#include <stdio.h>
#include <stdlib.h>

typedef struct veiculo {
  char marca[20];
  char modelo[20];
  char cor[20];
  int ano;
} Veiculo;

int main(){
  FILE * arquivo = fopen("arquivoex4.txt", "r");
  Veiculo veiculos[2];
  for (int i = 0; i < 2; i++){
    fscanf(arquivo, " %[^ ] %[^ ] %[^ ] %d", veiculos[i].marca, veiculos[i].modelo, veiculos[i].cor, &veiculos[i].ano);
  }

  for(int i = 0; i < 2; i++){
    printf("Carro %d | Marca: %s | Modelo: %s | Cor: %s | Ano: %d\n", i+1, veiculos[i].marca, veiculos[i].modelo, veiculos[i].cor, veiculos[i].ano);
  }
}