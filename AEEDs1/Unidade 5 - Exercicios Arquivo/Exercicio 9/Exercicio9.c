#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *arquivo = fopen("arquivoex9.txt", "r");
  
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return 1;
  }
  
  float maior, menor, soma = 0, media, numeros[100];
  int i;

  for (i = 0; fscanf(arquivo, "%f", &numeros[i]) == 1; i++) {
    printf("%.1f\n", numeros[i]);
    if (i == 0) {
      maior = numeros[0];
      menor = numeros[0];
    } else {
      if (numeros[i] > maior) {
        maior = numeros[i];
      } else if (numeros[i] < menor) {
        menor = numeros[i];
      }
    }
    
    soma += numeros[i];
  }

  fclose(arquivo);

  if (i == 0) {
    printf("O arquivo está vazio.\n");
    return 1;
  }

  media = soma / i;
  printf("Maior número: %.1f\n", maior);
  printf("Menor número: %.1f\n", menor);
  printf("Média dos números: %.2f\n", media);

  return 0;
}
