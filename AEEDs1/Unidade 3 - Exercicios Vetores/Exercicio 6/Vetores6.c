#include <stdio.h>

int
main ()
{
  int tam = 10, v[tam];

  for (int i = 0; i < tam; i++)
    {
      scanf ("%d", &v[i]);
    }
  printf ("Numeros positivos:");

  for (int i = 0; i < tam; i++)
    {
      if (v[i] > 0)
	{
	  printf ("%d ", v[i]);
	}
    }
}
