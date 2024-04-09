#include <stdio.h>

int
main ()
{
  float num[10];

  for (int i = 0; i < 10; i++)
    {
      printf ("Digite o numero %d:", i + 1);
      scanf ("%f", &num[i]);
    }
  puts ("Numeros do vetor:");
  for (int j = 0; j < 10; j++)
    {
      printf ("%.2f ", num[j]);
    }
  return 0;
}
