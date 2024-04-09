#include <stdio.h>
#include <math.h>

int main(){

  /*13. Faça um algoritmo que encontre as raízes de uma equação do segundo grau 𝑎𝑥2 + 𝑏𝑥 + 𝑐. O algoritmo deve ler
  os coeficientes 𝑎, 𝑏 e 𝑐 e determinar as raízes da equação. Caso as raízes não sejam reais, imprimir uma
  mensagem informando.*/
  
  float a, b, c, delta, bhaskara;

  puts("Digite o valor de A:");
  scanf("%f", &a);
  puts("Digite o valor de B:");
  scanf("%f", &b);
  puts("Digite o valor de C:");
  scanf("%f", &c);
  if (a != 0) {
    delta = pow(b,2) - (4 * a * c);
    if (delta<0){
      puts("A equação não possui raízes reais");
    } else {
      bhaskara = (-b + sqrt(delta)) / (2*a);
      printf("Raíz 1: %f\n", bhaskara);
      bhaskara = (-b - sqrt(delta)) / (2*a);
      printf("Raíz 2: %f\n", bhaskara);
    }
  }
  else{
    puts("O valor de A não pode ser 0");
  }
  return 0;

}