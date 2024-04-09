#include <stdio.h>

int main(){

  /*15. Escreva um programa em linguagem C que leia um peso e o número de um planeta, e imprima o valor
  correspondente do peso neste planeta. A relação de planetas é dada a seguir juntamente com o valor das
  gravidades relativas à Terra.*/
  
  float PT, PP;
  int codigo;

  puts("Forneça um peso em KG medido no Planeta Terra:");
  scanf("%f", &PT);
  puts("Agora, informe um dos planetas abaixo para ver como seria lá:");
  puts("1 - Mercúrio");
  puts("2 - Vênus");
  puts("3 - Marte");
  puts("4 - Júpiter");
  puts("5 - Saturno");
  puts("6 - Urano");
  scanf("%i", &codigo);
  switch (codigo){

    case 1:
      PP = PT * 0.37;
      printf("%.2f KG em Mercúrio seria de: %.2f KG",PT, PP);
      break;
    case 2:
      PP = PT * 0.88;
      printf("%.2f KG em Vênus seria de: %.2f KG", PT, PP);
      break;
    case 3:
      PP = PT * 0.38;
      printf("%.2f KG em Marte seria de: %.2f KG", PT, PP);
      break;
    case 4:
      PP = PT * 2.64;
      printf("%.2f KG em Júpiter seria de: %.2f KG", PT, PP);
      break;
    case 5:
      PP = PT * 1.15;
      printf("%.2f KG em Saturno seria de: %.2f KG", PT, PP);
      break;
    case 6:
      PP = PT * 1.17;
      printf("%.2f KG em Urano seria de: %.2f KG", PT, PP);
      break;
    default:
      puts("Código Inválido");
  }
  return 0;
}