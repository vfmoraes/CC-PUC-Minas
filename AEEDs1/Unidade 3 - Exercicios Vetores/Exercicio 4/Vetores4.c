#include <stdio.h>

int
main ()
{
  int tam = 30, v[tam];

  for (int i = 0; i < tam; i++)
    {
      v[i] = i * i;
    }
  printf ("\n");

  printf ("Posições elevadas ao quadrado:");
  for (int i = 0; i < tam; i++)
    {
      printf ("%d ", v[i]);
    }
}
