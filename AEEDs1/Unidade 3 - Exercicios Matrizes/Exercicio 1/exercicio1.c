#include <stdio.h>

int main()
{
    const int linha = 4, coluna = 2;
    float num[linha][coluna];
    //Preenchendo a Matriz
    
    for (int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            puts("Digite um numero:");
            scanf("%f", &num[i][j]);
        }
    }
    
    //Imprimir a Matriz
    
    for (int i = 0; i < linha; i++){
        for (int j = 0; j < coluna; j++){
            printf("%8.2f ", num[i][j]);
        }
        printf("\n");
    }
    
    printf("\n");
    
    //Mostrar somente os positivos
    
    for (int i = 0; i < linha; i++){
        for (int j = 0; j < coluna; j++){
            if (num[i][j] > 0){
                printf("%8.2f", num[i][j]);
            } else {
                num[i][j] = 0;
                printf("%8.0f", num[i][j]);
            }
        }
        printf("\n");
    }
    

    return 0;
}
