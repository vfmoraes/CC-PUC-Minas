#include <stdio.h>
#include <stdlib.h>

int main(){

  FILE * arquivo = fopen("resultado.txt", "w");
  int qtdveiculos;
  float valorporaluguel, faturamentoanual, faturamentomensal, atraso, manutencao;

  puts("Insira a quantidade de veiculos da locadora:");
  scanf("%d", &qtdveiculos);
  puts("Quanto ela cobra por aluguel?");
  scanf("%f", &valorporaluguel);

  faturamentomensal = (qtdveiculos/3.0) * valorporaluguel;
  faturamentoanual = faturamentomensal  * 12;

  atraso = (valorporaluguel*0.2) * (qtdveiculos/10.0);

  manutencao = (qtdveiculos*0.02) * 600;

  printf("Faturamento Anual: R$ %.2f\nGanhos de atraso por mês: R$ %.2f\nGastos de manutenção anual: R$ %.2f", faturamentoanual, atraso, manutencao);

  fprintf(arquivo, "Faturamento Anual: R$ %.2f\nGanhos de atraso por mês: R$ %.2f\nGastos de manutenção anual: R$ %.2f", faturamentoanual, atraso, manutencao);

  fclose(arquivo);




}