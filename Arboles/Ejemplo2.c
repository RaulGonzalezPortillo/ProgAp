#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Nodo
{
  int Num;
  struct Nodo *Izq, *Der;
};

void Inserta (struct Nodo *Raiz, struct Nodo *Elemento)
{
  struct Nodo *Avanza;
  printf ("Entrando a inserción\n");
  Avanza = Raiz;
  if (Avanza != NULL)
    {
      if (Elemento -> Num > Avanza -> Num) //Muevete a la derecha
	{
	  if (Avanza -> Der != NULL)
	    {
	      Inserta (Avanza -> Der, Elemento);
	    }
	  else
	    {
	      Avanza -> Der = Elemento;
	      return;
	    }
	}
      if (Elemento -> Num <= Avanza -> Num) //Muevete a la izquierda
	{
	  if (Avanza -> Izq != NULL)
	    {
	      Inserta (Avanza -> Izq, Elemento);
	    }
	  else
	    {
	      Avanza -> Izq = Elemento;
	      return;
	    }
	}
    }
  printf ("Saliendo de la inserción\n");
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
  struct Nodo *Raiz, *Temp;
  Raiz = NULL;
  system ("clear");
  printf ("\n");
  printf ("Teclea enteros, seguido por un cáracter no numérico para terminar:\n\n");
  while (scanf ("%d", &Insertador) == 1)
    {
      Temp = (struct Nodo *) malloc (sizeof (struct Nodo));
      Temp -> Der = NULL;
      Temp -> Izq = NULL;
      Temp -> Num = Insertador;
      if (Raiz == NULL)
	{
	  Raiz = Temp;
	}
      else
	{
	  Inserta (Raiz, Temp);
	}
      system ("clear");
      printf ("\n");
      printf ("Numeros impresos en orden: \n\n");
      Imprime (Raiz);
      printf ("\n");
    }
  Borra (Raiz);
}
