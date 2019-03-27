#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Nodo
{
  int Num;
  struct Nodo *Izq, *Der;
};

void Inserta (struct Nodo **Raiz, int Insertador)
{
  struct Nodo *Avanza, *Nuevo;
  Avanza = *Raiz;
  if ((Nuevo = (struct Nodo *) malloc (sizeof (struct Nodo))) == NULL)
    {
      printf ("No hay memoria\n");
      exit (1);
    }
  Nuevo -> Num = Insertador;
  Nuevo -> Izq = NULL;
  Nuevo -> Der = NULL;
  while (Avanza != NULL)
    {
      if (Insertador > Avanza -> Num) //Muevete a la derecha
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
      if (Insertador <= Avanza -> Num) //Muevete a la izquierda
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
  //Avanza = Nuevo;
  //*Raiz = Avanza;
}

void Imprime (struct Nodo *Impresor)
{
  if (Impresor != NULL)
    {
      Imprime (Impresor -> Izq);
      printf ("%d\n", Impresor -> Num);
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
  int Insertador;
  struct Nodo *Raiz;
  Raiz = NULL;
  system ("clear");
  printf ("\n");
  printf ("Teclea enteros, seguido por un cáracter no numérico para terminar:\n\n");
  while (scanf ("%d", &Insertador) == 1)
    {
      Inserta (&Raiz, Insertador);
      system ("clear");
      printf ("\n");
      printf ("Numeros impresos en orden:\n\n");
      Imprime (Raiz);
      printf ("\n");
    }
  Borra (Raiz);
}
