#include <stdio.h>

int
main ()
{
  int tam = 10, contador_n = 0;
  float v[tam], soma = 0;

  for (int i = 0; i < tam; i++)
    {
      scanf ("%f", &v[i]);
    }
  printf ("\n");

  for (int i = 0; i < tam; i++)
    {
      if (v[i] > 0)
	{
	  soma += v[i];
	}
      else if (v[i] < 0)
	{
	  contador_n++;
	}
    }
  printf ("Soma dos numeros positivos: %.2f\n", soma);
  printf ("Numero de negativos: %d", contador_n);
}
