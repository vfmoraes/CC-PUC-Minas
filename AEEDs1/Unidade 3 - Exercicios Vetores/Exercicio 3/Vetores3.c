#include <stdio.h>

int
main ()
{
  int tam = 10, v[tam], maior, menor, media;

  for (int i = 0; i < tam; i++)
    {
      scanf ("%d", &v[i]);
    }
  printf ("\n");

  maior = v[0];
  menor = v[0];
  for (int i = 0; i < tam; i++)
    {
      if (maior < v[i])
	{
	  maior = v[i];
	}
      else if (menor > v[i])
	{
	  menor = v[i];
	}
      media += v[i];
    }
  media /= 10;
  printf ("Menor nota: %d\n", menor);
  printf ("Maior nota: %d\n", maior);
  printf ("Media da turma: %d", media);
}
