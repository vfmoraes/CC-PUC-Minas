#include <stdio.h>
#include <math.h>

int main ()
{
    int num[100];
    
    for (int i = 0; i < 100; i++){
        if (i % 2 == 0){
            num[i] = i * i;
        } else {
            num[i] = i * i * i;
        }
    }
    for (int j = 0; j < 100; j++){
        printf("%d: %4d\n", j+1, num[j]);
    }
    
    return 0;
}
