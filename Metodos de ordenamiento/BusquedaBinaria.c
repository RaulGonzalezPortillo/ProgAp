#include <stdio.h>

int binaria (int m [], int v, int n_elementos);

void main ()
{
  int m [] = {1, 2, 3, 7, 8, 15, 25, 32, 43, 67};
  int i, pos, cual;

  printf ("Arreglo original\n");
  for (i = 0; i < 10; i++)
    {
      printf ("%d ", m [i]);
    }
  printf ("\n\nQue numero quieres buscar? ");
  scanf ("%d", &cual);
  pos = binaria (m, cual, 10);
  if (pos != -1)
    {
      printf ("Está en la posición %d ", pos);
    }
  else
    {
      printf ("Ese numero no se encontró en el arreglo\n");
    }
}

int binaria (int m [], int v, int n_elementos)
{
  int mitad, inf = 0, sup = n_elementos - 1;
  if (n_elementos == 0)
    {
      return -1;
    }
  do
    {
      mitad = (inf + sup) / 2;
      if (v > m [mitad])
	{
	  inf = mitad + 1;
	}
      else
	{
	  sup = mitad - 1;
	}
    }
  while (m [mitad] != v && inf <= sup);
  if (m [mitad] == v)
    {
      return mitad;
    }
  else
    {
      return -1;
    }
}
