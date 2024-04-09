#include <stdio.h>
#include <math.h>

int main(){

  /*16. Faça um algoritmo para calcular e mostrar os valores das funções ℎ, 𝑓 e ℎ abaixo no ponto 𝑥 fornecido pelo
  usuário.
  ℎ(𝑥) = 𝑥² − 16

  𝑓(𝑥) = { ℎ(𝑥), se ℎ(𝑥) ≥ 0
         { 1, se ℎ(𝑥) < 0

  𝑔(𝑥) = {𝑥² + 16, se 𝑥 > 5
         {−𝑥/2, se 𝑥 ≤ 5*/
  
  float x, hx, fx, gx;

  puts("Informe o valor de X:");
  scanf("%f", &x);

  hx = pow(x,2) - 16;
  printf("O valor da função h(x) é: %.2f\n", hx);
  if (hx>=0){
    fx = hx;
    printf("O valor da função f(x) é %.2f\n", fx);
  } else {
    fx = 1;
    printf("O valor da função f(x) é %.2f\n", fx);
  }
  if (x>5){
    gx = pow(x,2) + 16;
    printf("O valor da função g(x) é %.2f\n", gx);
  } else {
    gx = -x/2;
    printf("O valor da função g(x) é %.2f\n", gx);
  }
  return 0;
}