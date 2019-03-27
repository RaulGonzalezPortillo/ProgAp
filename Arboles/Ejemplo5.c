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
}

void Imprime (struct Nodo *Impresor)
{
  if (Impresor != NULL)
    {
      Imprime (Impresor -> Izq);
      printf ("%d\n\n", Impresor -> Num);
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

void Reemplazar(struct Nodo **Raiz, struct Nodo **Temp)
{
  if ((*Raiz)->Der == NULL)
  {
    (*Temp)->Num = (*Raiz)->Num;
    *Temp = *Raiz;
    *Raiz = (*Raiz)->Izq;
  }
  else
    Reemplazar(&(*Raiz)->Der, Temp);
}

void Borrar(struct Nodo **Raiz, int Borrador)
{
  struct Nodo *Temp;
  if (*Raiz == NULL)
    return;
  if ((*Raiz)->Num < Borrador)
    Borrar(&(*Raiz)->Der, Borrador);
  else
    if ((*Raiz)->Num > Borrador)
      Borrar(&(*Raiz)->Izq, Borrador);
    else
      if ((*Raiz)->Num == Borrador)
	{
	  Temp = *Raiz;
	  if ((*Raiz)->Izq == NULL)
	    *Raiz = (*Raiz)->Der;
	  else if ((*Raiz)->Der == NULL)
	    *Raiz = (*Raiz)->Izq;
	  else
	    Reemplazar(&(*Raiz)->Izq, &Temp);
	  free(Temp);
	}
}

int main (void)
{
  int Insertador, Seleccion, Borrador;
  char Enter;
  struct Nodo *Raiz;
  Raiz = NULL;
  do
    {
      system ("clear");
      printf ("\n");
      printf ("Menú principal:\n\n\n");
      printf ("1.- Insertar\n\n");
      printf ("2.- Borrar\n\n");
      printf ("3.- Imprimir\n\n");
      printf ("4.- Salir\n\n\n");
      scanf ("%d", &Seleccion);
      printf ("\n");
      switch (Seleccion)
	{
	case 1:
	  system ("clear");
	  printf ("\n");
	  printf ("Inserte el número: ");
	  scanf ("%d", &Insertador);
	  printf ("\n");
	  Inserta (&Raiz, Insertador);
	  break;
	case 2:
	  system ("clear");
	  printf ("\n");
	  printf ("Inserte el número a borrar: ");
	  scanf ("%d", &Borrador);
	  printf ("\n");
	  Borrar (&Raiz, Borrador);
	  break;
	case 3:
	  system ("clear");
	  printf ("\n");
	  printf ("Numeros impresos en orden:\n\n\n");
	  Imprime (Raiz);
	  printf ("\n");
	  printf ("Presione enter para continuar...\n\n");
	  __fpurge (stdin);
	  scanf ("%c", &Enter);
	  printf ("\n");
	  break;
	case 4:
	  system ("clear");
	  Borra (Raiz);
	  break;
	default:
	  break;
	}
    }
  while (Seleccion != 4);
}
