#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct produto{
  int codigo;
  char nome[20];
  float preco;
} Produto;

void MostrarProduto(Produto p){
  printf("Código do produto: %d\n", p.codigo);
  printf("Nome do Produto: %s\n", p.nome);
  printf("Preço do produto: R$ %.2f\n", p.preco);
}

Produto CadastroProduto(int codigo, const char * nome, float preco){
  Produto novoProduto;
  novoProduto.codigo = codigo;
  strcpy(novoProduto.nome, nome);
  novoProduto.preco = preco;

  return novoProduto;
}

float MediaProdutos(Produto produtos[], int tamanho){
  float soma = 0, media;
  for(int i = 0; i < tamanho; i++){
    soma += produtos[i].preco;
  }
  media = soma / tamanho;
  return media;
}

int main(){
  //Testando a função MediaProdutos  
  Produto produtos[3], produto1, novoProduto;
  float media;
  for(int i = 0; i < 3; i++){
    printf("Digite o Código do produto %d:\n", i+1);
    scanf("%d", &produtos[i].codigo);
    printf("Digite o Nome do produto %d:\n", i+1);
    scanf(" %[^\n]", produtos[i].nome);
    printf("Digite o Preço do produto %d:\n", i+1);
    scanf("%f", &produtos[i].preco);
  }
  media = MediaProdutos(produtos, 3);
  printf("Média do preço dos produtos digitados: %.2f\n", media);
  //Função para receber uma estrutura e exibir suas informações
  printf("Digite o Código do produto:\n");
  scanf("%d", &produto1.codigo);
  printf("Digite o Nome do produto:\n");
  scanf(" %[^\n]", produto1.nome);
  printf("Digite o Preço do produto:\n");
  scanf("%f", &produto1.preco);
  MostrarProduto(produto1);
  //Função para receber informações do produto e retornar uma estrutura
  novoProduto = CadastroProduto(48756,"Ketchup", 14.5);
  MostrarProduto(novoProduto);
}