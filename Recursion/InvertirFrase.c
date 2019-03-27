#include <stdio.h>
#include <string.h>

void Invertir (char Frase [], char FraseInvertida []);

int main (void)
{
  char Frase [200], FraseInvertida [200];
  system ("clear");
  printf ("\n");
  printf ("Ingrese una frase: ");
  gets (Frase);
  printf ("\n");
  Invertir (Frase, FraseInvertida);
  FraseInvertida [strlen(Frase)] = '\0';
  puts (FraseInvertida);
  printf ("\n");
}

void Invertir (char Frase [], char FraseInvertida [])
{
  if (*Frase != '\0')
    {
      Invertir (Frase + 1, FraseInvertida);
      FraseInvertida [strlen(Frase) - 1] = *Frase;
    }
}
