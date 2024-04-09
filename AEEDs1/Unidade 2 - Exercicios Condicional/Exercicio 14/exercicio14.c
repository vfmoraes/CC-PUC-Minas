#include <stdio.h>

int main(){

  int N1, N2;
  scanf("%i %i", &N1, &N2);
  if (N1>N2)
  {
    N1 = N1 - 10;
    N2 = N1 + 10;
  }
  else
  {
    printf("%i menor que %i", N1, N2);
  }
  return 0;
}