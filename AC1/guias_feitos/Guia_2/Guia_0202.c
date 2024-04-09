/*
Nome: Victor Ferraz de Moraes
Matrícula: 802371
*/
#include <stdio.h>

void double2bin(double x) {
    
    int integerPart = (int)x;

    double fractionalPart = x - integerPart;

    printf("Parte inteira em binário: ");
    int binary[32];
    int i = 0;
    while (integerPart > 0) {
        binary[i] = integerPart % 2;
        integerPart /= 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
    printf("\n");

    printf("Parte fracionária em binário: ");
    i = 0;
    while (i < 23 && fractionalPart > 0) {
        fractionalPart *= 2;
        binary[i] = (int)fractionalPart;
        fractionalPart -= binary[i];
        i++;
    }
    for (int j = 0; j < i; j++) {
        printf("%d", binary[j]);
    }
    printf("\n");
}

int main() {
    double values[] = {0.75, 1.375, 2.625, 6.875, 11.03125};
    int numValues = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < numValues; i++) {
        printf("Valor decimal: %.5f\n", values[i]);
        double2bin(values[i]);
        printf("\n");
    }

    return 0;
}
