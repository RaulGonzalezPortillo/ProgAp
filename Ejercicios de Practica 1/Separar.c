#include <stdio.h>
#include <string.h>

int separa (char frase [], char palabras [20] [10]);

int main (void)
{
  int numero, i;
  char linea [300], lista [20] [10];
  printf ("Introduzca la frase:\n");
  gets (linea);
  numero = separa (linea, lista);
  for (i = numero - 1; i >= 0; i --)
    printf ("%s ", lista [i]);
  printf ("\n");
}
  
int separa (char frase [], char palabras [20] [10])
{
  int i, j = 0, k = 0;
  for (i = 0; i < strlen (frase); i++)
    if (frase [i] != ' ')
      {
	palabras [k] [j] = frase [i];
	j++;
      }
    else
      {
	palabras [k] [j] = '\0';
	j = 0;
	k++;
      }
  palabras [k] [j] = '\0';
  k++;
  return k;
}
