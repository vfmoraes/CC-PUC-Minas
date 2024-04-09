#include <stdio.h>

int
main ()
{
  int tam = 10, v[tam];

  for (int i = 0; i < tam; i++)
    {
      scanf ("%d", &v[i]);
    }
  printf ("\nNumeros digitados: ");
  for (int j = 0; j < tam; j++)
    {
      printf ("%d ", v[j]);
    }
}
