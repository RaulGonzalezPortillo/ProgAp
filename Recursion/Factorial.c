#include <stdio.h>
#include <stdlib.h>

void Factorial (int Numero, long *Res);

int main (void)
{
  int Numero;
  long Res;
  system ("clear");
  printf ("\n");
  printf ("Ingrese un numero para obtener su factorial: ");
  scanf ("%d", &Numero);
  printf ("\n");
  if (Numero == 0)
    {
      printf ("0! = 0");
    }
  if (Numero > 0)
    {
      Factorial (Numero, &Res);
      printf ("%d! = %li", Numero, Res);
    }
  if (Numero < 0)
    {
      Numero *= -1;
      Factorial (Numero, &Res);
      printf ("-%d! = -%li", Numero, Res);
    }
  printf ("\n\n");
}

void Factorial (int Numero, long *Res)
{
  if (Numero == 1)
    {
      *Res = 1;
    }
  else
    {
      Factorial (Numero - 1, Res);
      *Res = *Res * Numero;
    }
}
