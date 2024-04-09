#include <stdio.h>

int main(){
  /*12. Uma empresa decide dar um aumento de 30% aos funcionários com salário inferior à R$700,00 e 10% aos
  funcionários com salário superior ou igual à R$700,00. Faça um algoritmo que leia o salário do funcionário,
  calcule o reajuste e mostre o novo salário*/

  float salario, aumento, novo_salario;

  puts("Digite seu salário:");
  scanf("%f", &salario);

  if (salario < 700){
    aumento = salario * 0.30;
    novo_salario = salario + aumento;
    puts("Seu salário foi reajustado e recebeu um aumento de 30 por certo");
    printf("Seu novo salário é: %.2f", novo_salario);
  } else {
    aumento = salario * 0.10;
    novo_salario = salario + aumento;
    puts("Seu salário foi reajustado e recebeu um aumento de 10 por certo");
    printf("Seu novo salário é: %.2f", novo_salario);
  }
  return 0;
}