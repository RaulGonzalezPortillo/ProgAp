#include <stdio.h>
#include <string.h>

void Contar (char Frase [], char Letras []);

int main (void)
{
  char Frase [100], Letras [26] = "abcdefghijklmnopqrstuvwxyz";
  printf ("Ingrese una frase: ");
  gets (Frase);
  Contar (Frase, Letras);
}

void Contar (char Frase [], char Letras [])
{
  int i, j, temp;
  printf ("Letras en la frase:\n");
  for (i = 0; i < 26; i ++)
    {
      temp = 0;
      for (j = 0; j < (strlen (Frase)); j ++)
	{
	  if (Letras [i] == Frase [j])
	    {
	      temp++;
	    }
	  if (Letras [i] == (Frase [j] + 32))
	    {
	      temp++;
	    }
	}
      if (temp != 0)
	{
	  printf ("Letra %c: %d\n", Letras [i], temp);
	}
    }
}
