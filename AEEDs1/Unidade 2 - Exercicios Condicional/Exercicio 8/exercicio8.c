#include <stdio.h>
#include <stdlib.h>

int main()
{
    int codigo;
    float aumento, salario_atual, salario_aumento;

    puts("Digite o valor de seu salario atual:");

    scanf("%f", &salario_atual);

    puts("1 - Escrituario");
    puts("2 - Secretario");
    puts("3 - Caixa");
    puts("4 - Gerente");
    puts("5 - Diretor");
    puts("Digite o c�digo de seu cargo:");

    scanf("%i", &codigo);

    switch (codigo){

case 1:
    puts("Cargo: Escrituario");
    aumento = (salario_atual * 0.5);
    printf("Voc� recebeu um aumento de %.2f Reais\n", aumento);
    salario_aumento = aumento + salario_atual;
    printf("Seu sal�rio agora � de: %.2f Reais", salario_aumento);
    break;
case 2:
    puts("Cargo: Secretario");
    aumento = (salario_atual * 0.35);
    printf("Voc� recebeu um aumento de %.2f Reais\n", aumento);
    salario_aumento = aumento + salario_atual;
    printf("Seu sal�rio agora � de: %.2f Reais", salario_aumento);
    break;
case 3:
    puts("Cargo: Caixa");
    aumento = (salario_atual * 0.2);
    printf("Voc� recebeu um aumento de %.2f Reais\n", aumento);
    salario_aumento = aumento + salario_atual;
    printf("Seu sal�rio agora � de: %f Reais", salario_aumento);
    break;
case 4:
    puts("Cargo: Gerente");
    aumento = (salario_atual * 0.1);
    printf("Voc� recebeu um aumento de %.2f Reais\n", aumento);
    salario_aumento = aumento + salario_atual;
    printf("Seu sal�rio agora � de: %.2f Reais", salario_aumento);
    break;
case 5:
    puts("Cargo: Diretor");
    printf("Sem aumento. Seu sal�rio � de: %.2f Reais\n", salario_atual);
    break;
default:
    puts("C�digo inv�lido");
    break;
}

    return 0;
}
