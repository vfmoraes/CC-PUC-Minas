/*
Nome: Victor Ferraz de Moraes
Matrícula: 802371
*/
#include <stdio.h>
#include <math.h>

double bin2double(const char *binary) {
    double result = 0.0;
    double fraction = 0.5;

    while (*binary != '\0' && *binary != '.') {
        if (*binary == '1') {
            result += 1.0;
        }
        binary++;
    }

    if (*binary == '.') {
        binary++;

        while (*binary != '\0') {
            if (*binary == '1') {
                result += fraction;
            }
            fraction *= 0.5;
            binary++;
        }
    }

    return result;
}

int main() {
    printf("a.) %.5f\n", bin2double("0.01101"));
    printf("b.) %.5f\n", bin2double("0.10011"));
    printf("c.) %.5f\n", bin2double("0.10101"));
    printf("d.) %.5f\n", bin2double("1.11001"));
    printf("e.) %.5f\n", bin2double("11.11011"));

    return 0;
}
