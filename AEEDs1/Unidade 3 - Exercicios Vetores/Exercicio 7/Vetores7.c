#include <stdio.h>

int
main ()
{
  int tam;
  puts ("Digite o tamanho do vetor:");
  scanf ("%d", &tam);
  int v[tam];

  for (int i = 0; i < tam; i++)
    {
      scanf ("%d", &v[i]);
    }
  printf ("Numeros das posiçoes impares:");

  for (int i = 0; i < tam; i++)
    {
      if (i % 2 != 0)
	{
	  printf ("%d ", v[i]);
	}
    }
}
