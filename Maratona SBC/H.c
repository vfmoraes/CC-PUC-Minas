#include <stdio.h>
#include <stdbool.h>

bool isPrimo(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

bool isNotPrimo(int n) {
    return !isPrimo(n);
}

int main() {
    int perguntas;
    scanf("%d", &perguntas);

    for (int i = 0; i < perguntas; i++) {
        int numero, x = -1, y = -1;
        scanf("%d", &numero);

        for (int j = 1; j <= numero; j++) {
            if (isNotPrimo(j)) {
                x = j;
                break;
            }
        }
        for(int j = x; j <= numero; j) {
            if (isNotPrimo(j)) {
                y = j;
                break;
            }
        }

        if (x != -1 && y != -1) {
            printf("%d %d\n", x, y);
        } else {
            printf("-1\n");
        }
    }

    return 0;
}
