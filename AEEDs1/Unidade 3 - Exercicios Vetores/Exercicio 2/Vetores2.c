#include <stdio.h>

int
main ()
{
  int tam = 100, v[tam];

  for (int i = 0; i < tam; i++)
    {
      if (i % 2 == 0)
	{
	  v[i] = i * i;
	}
      else
	{
	  v[i] = i * i * i;
	}
    }
  printf ("\nNumeros elevados: ");
  for (int j = 0; j < tam; j++)
    {
      printf ("%d ", v[j]);
    }
}
