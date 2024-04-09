#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    /*
    3. Se o valor de A é 4, o valor de B é 5 e o valor de C é 1, avaliar as seguintes expressões, considerando ^ como uma
    operação de potenciação, e % como o resto da divisão inteira:
    (a)  B * A – B ^ 2 / 4 * C
    (b)  (A * B) / 3 ^ 2
    (c)  (((B + C) / 2 * A + 10) * 3 * B) – 6
    (d)  7 * 10 – 50 % 3 * 4 + 9
    (e)  (7 * (10 – 5) % 3) * 4 + 9
     */

    int A = 4, B = 5, C = 1;
    float resultado;

    resultado = B * A - pow(B, 2) / 4 * C;
    printf("(a) %f\n", resultado);

    resultado = (A * B) / pow(3, 2);
    printf("(b) %f\n", resultado);

    resultado = (((B + C) / 2 * A + 10) * 3 * B) - 6;
    printf("(c) %f\n", resultado);

    resultado = 7 * 10 - 50 % 3 * 4 + 9;
    printf("(d) %f\n", resultado);

    resultado = (7 * (10 - 5) % 3) * 4 + 9;
    printf("(e) %f\n", resultado);

    return 0;
}
