#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Nodo
{
  char Nombre [100];
  struct Nodo *Izq, *Der;
};

void Inserta (struct Nodo **Raiz, char Insertador[])
{
  struct Nodo *Avanza, *Nuevo;
  Avanza = *Raiz;
  if ((Nuevo = (struct Nodo *) malloc (sizeof (struct Nodo))) == NULL)
    {
      printf ("No hay memoria\n");
      exit (1);
    }
  strcpy (Nuevo -> Nombre, Insertador);
  Nuevo -> Izq = NULL;
  Nuevo -> Der = NULL;
  while (Avanza != NULL)
    {
      if (strcmp (Insertador, Avanza -> Nombre) > 0)
	{
	  if (Avanza -> Der != NULL)
	    {
	      Avanza = Avanza -> Der;
	    }
	  else
	  {
	    Avanza -> Der = Nuevo;
	    return;
	  }
	}
      if (strcmp (Insertador, Avanza -> Nombre) <= 0)
	{
	  if (Avanza -> Izq != NULL)
	    {
	      Avanza = Avanza -> Izq;
	    }
	  else
	    {
	      Avanza -> Izq = Nuevo;
	      return;
	    }
	}
    }
  *Raiz = Nuevo;
}

void Imprime (struct Nodo *Impresor)
{
  if (Impresor != NULL)
    {
      Imprime (Impresor -> Izq);
      puts (Impresor -> Nombre);
      Imprime (Impresor -> Der);
    }
}

void Borra (struct Nodo *Borrador)
{
  if (Borrador != NULL)
    {
      Borra (Borrador -> Izq);
      Borra (Borrador -> Der);
      free (Borrador);
    }
}

int main (void)
{
  char Insertador[100];
  struct Nodo *Raiz;
  Raiz = NULL;
  system ("clear");
  printf ("\n");
  printf ("Ingrese nombres, ingrese 'iniciar' para terminar\n\n");
  do
  {
    __fpurge (stdin);
    gets (Insertador);
    if (strcmp (Insertador, "iniciar") != 0)
    {
      Inserta (&Raiz, Insertador);
    }
    system ("clear");
    printf ("\n");
    printf ("Nombres impresos en orden:\n\n");
    Imprime (Raiz);
    printf ("\n");
    if (strcmp (Insertador, "iniciar") != 0)
    {
      printf ("Continúe insertando nombres:\n\n");
    }
  }
  while (strcmp (Insertador, "iniciar") != 0);
  Borra (Raiz);
}
