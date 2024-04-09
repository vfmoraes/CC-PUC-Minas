#include <stdio.h>
#include <stdlib.h>

typedef struct clientes{
  char nome[20];
  char endereco[100];
  char telefone[12];
} Cliente;

int main(){
  Cliente clientes[10];
  for(int i = 0; i < 2; i++){
    printf("Digite o nome do Cliente %d:\n", i+1);
    scanf(" %[^\n]", clientes[i].nome);
    printf("Digite o endereço do Cliente %d:\n", i+1);
    scanf(" %[^\n]", clientes[i].endereco);
    printf("Digite o número de telefone do Cliente %d:\n", i+1);
    scanf(" %[^\n]", clientes[i].telefone);
  }

  for(int i = 0; i < 2; i++){
    printf("Cliente %d: %s | Endereco: %s | Telefone: %s\n", i+1, clientes[i].nome, clientes[i].endereco, clientes[i].telefone);
  }
}