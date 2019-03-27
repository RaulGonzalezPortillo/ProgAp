#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void CalcularEspacios (char Linea [], int *Espacios);
void CalcularPalabras (char Linea [], int *Palabras);
void TiposDeLetras (char Linea [], int *Letras, int *Mayusculas, int *Minusculas);

int main (void)
{
  FILE *Archivo;
  char Nombre [200], Linea[200];
  int Palabras = 0, Letras = 0, Mayusculas = 0, Minusculas = 0, Espacios = 0;
  system ("clear");
  printf ("\n");
  printf ("Especifique el nombre de un archivo para analizarlo:\n\n");
  gets (Nombre);
  printf ("\n");
  Archivo = fopen (Nombre, "rt");
  if (Archivo == NULL)
    {
      printf ("No se pudo abrir el archivo, saliendo...\n\n");
      exit (0);
    }
  else
    {
      while ((fgets (Linea, 200, Archivo)) != NULL)
	{
	  CalcularEspacios (Linea, &Espacios);
	  CalcularPalabras (Linea, &Palabras);
	  TiposDeLetras (Linea, &Letras, &Mayusculas, &Minusculas);
	}
      system ("clear");
      printf ("\n");
      printf ("Se encontraron:\n\n");
      printf ("%d Espacios\n\n", Espacios);
      printf ("%d Palabras\n\n", Palabras);
      printf ("%d Letras\n\n", Letras);
      printf ("%d Mayusculas\n\n", Mayusculas);
      printf ("%d Minusculas\n\n", Minusculas);
    }
}

void CalcularEspacios (char Linea [], int *Espacios)
{
  int i;
  for (i = 0; Linea [i] != '\0'; i++)
    {
      if (Linea [i] == ' ')
	{
	  (*Espacios)++;
	}
    }
}

void CalcularPalabras (char Linea [], int *Palabras)
{
  int i;
  if ((Linea [0] >= 'A' && Linea [0] <= 'Z') || (Linea [0] >= 'a' && Linea [0] <= 'z'))
    {
      (*Palabras)++;
    }
  for (i = 0; Linea [i] != '\0'; i++)
    {
      if (Linea [i] == ' ' && ((Linea [i + 1] >= 'A' && Linea [i + 1] <= 'Z') || (Linea [i + 1] >= 'a' && Linea [i + 1] <= 'z')))
	{
	  (*Palabras)++;
	}
    }
}

void TiposDeLetras (char Linea [], int *Letras, int *Mayusculas, int *Minusculas)
{
  int i;
  for (i = 0; Linea [i] != '\0'; i++)
    {
      if ((Linea [i] >= 'A' && Linea [i] <= 'Z') || (Linea [i] >= 'a' && Linea [i] <= 'z'))
	{
	  (*Letras)++;
	}
      if (Linea [i] >= 'A' && Linea [i] <= 'Z')
	{
	  (*Mayusculas)++;
	}
      if (Linea [i] >= 'a' && Linea [i] <= 'z')
	{
	  (*Minusculas)++;
	}
    }
}
