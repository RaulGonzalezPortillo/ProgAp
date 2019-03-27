#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (void)
{
  int numtemps, *listatemps, i;
  printf ("Cuantas temepraturas quieres?\n");
  scanf ("%d", &numtemps);
  listatemps = (int*) malloc (sizeof (int) * numtemps);
  for (i = 0; i < numtemps; i ++)
    {
      printf ("Dame la temperatura [%d]: ", i + 1);
      scanf ("%d", &listatemps [i]);
    }
  for (i = 0; i < numtemps; i ++)
    {
      printf ("La temperatura #%d fue de: %d°\n", i + 1, listatemps [i]);
    }
  free (listatemps);
}
