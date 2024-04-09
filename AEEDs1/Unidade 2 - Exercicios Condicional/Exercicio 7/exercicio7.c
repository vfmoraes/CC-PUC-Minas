#include <stdio.h>

int main()
{

  /*7. A nota de um estudante é calculada a partir de 3 notas atribuídas respectivamente a um trabalho de laboratório,
  uma avaliação semestral e um exame final. Cada uma dessas notas possuem pesos diferentes para o cálculo da
  média final do aluno. Assim,faça um algoritmo que receba as 3 notas, os pesos das mesmas e a média necessária
  para aprovação do aluno. O algoritmo deve calcular e exibir a média ponderada para o aluno. Além disso, mostre
  a situação "Aprovado" (média maior ou igual que media aprovação), "exame especial" (média entre 4 e a média
  de aprovação) ou "Reprovado" (média menor que 4).*/
  
  float nota1, nota2, nota3, media;
  int peso1, peso2, peso3;

  puts("Digite o valor das 3 notas do aluno:");
  scanf("%f %f %f", &nota1, &nota2, &nota3);
  puts("Digite o peso de cada nota, respectivamente:");
  scanf("%i %i %i", &peso1, &peso2, &peso3);
  if (peso1 + peso2 + peso3 == 100)
  {
    media = (nota1 * (peso1 / 100.0)) + (nota2 * (peso2 / 100.0)) + (nota3 * (peso3 / 100.0));
    printf("Sua média é: %.2f\n", media);
    if (media < 4)
    {
      puts("Situação: Reprovado");
    }
    else if (media < 7)
    {
      puts("Situação: Exame Especial");
    }
    else
    {
      puts("Situação: Aprovado");
    }
  }
  else
  {
    puts("A soma dos pesos deve dar 100");
  }
  return 0;
}