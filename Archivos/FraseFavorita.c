#include <stdio.h>

int main (void)
{
  FILE *Archivo;
  char Frase [200];
  Archivo = fopen ("algo.txt", "wt");
  printf ("Dame tu frase favorita: \n");
  gets (Frase);
  fprintf (Archivo, "Tu frase favorita es:\n%s\n", Frase);
  fclose (Archivo);
}
