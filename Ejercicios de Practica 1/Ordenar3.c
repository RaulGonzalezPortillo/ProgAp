#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void OrdenarFrase (char *Frase, char *FraseInvertida);

int main ()
{
  system ("clear");
  char Frase [100], FraseInvertida [100];
  printf ("Introduzca una frase a continuación con una longitud máxima de 100 caractéres:\n");
  gets (Frase);
  OrdenarFrase (Frase, FraseInvertida);
  printf ("La frase invertida es: \n");
  puts (FraseInvertida);
}

void OrdenarFrase (char *Frase, char *FraseInvertida)
{
  int i, j = 0;
  for (i = (strlen (Frase) - 1); i >= 0; i --)
    {
      *(FraseInvertida + j) = *(Frase + i);
      j++;
    }
  *(FraseInvertida + j) = '\0';
}
