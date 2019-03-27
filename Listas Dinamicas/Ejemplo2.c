#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Def_Numero
{
  int Numero;
  struct Def_Numero *Ant;
  struct Def_Numero *Sig;
} TipoNumero;

void InsertaInicio (int Numero, TipoNumero **Inicio);
void InsertaFin (int Numero, TipoNumero **Inicio);
void InsertaEnOrden (int Numero, TipoNumero **Inicio);
void ImprimirListaDesdeInicio (TipoNumero *Inicio);
void ImprimirListaDesdeFin (TipoNumero *Inicio);
void BorrarLista (TipoNumero *Inicio);

void InsertaInicio (int Numero, TipoNumero **Inicio)
{
  TipoNumero *Nuevo;
  Nuevo = (TipoNumero *) malloc (sizeof (TipoNumero));
  Nuevo -> Numero = Numero;
  Nuevo -> Ant = NULL;
  Nuevo -> Sig = *Inicio;
  if (*Inicio != NULL)
    (*Inicio) -> Ant = Nuevo;
  *Inicio = Nuevo;
}

void InsertaFin (int Numero, TipoNumero **Inicio)
{
  TipoNumero *Nuevo, *Temp;
  Nuevo = (TipoNumero *) malloc (sizeof (TipoNumero));
  Nuevo -> Numero = Numero;
  Nuevo -> Sig = NULL;
  if (*Inicio == NULL)
    {
      Nuevo -> Ant = NULL;
      *Inicio = Nuevo;
    }
  else
    {
      Temp = *Inicio;
      while (Temp -> Sig != NULL)
	{
	  Temp = Temp -> Sig;
	}
      Temp -> Sig = Nuevo;
      Nuevo -> Ant = Temp;
    }
}

void InsertaEnOrden (int Numero, TipoNumero **Inicio)
{
  TipoNumero *Nuevo, *Temp;
  Nuevo = (TipoNumero *) malloc (sizeof (TipoNumero));
  Nuevo -> Numero = Numero;
  Temp = *Inicio;
  if (Temp == NULL) //Si la lista está vacia
    {
      Nuevo -> Ant = NULL;
      Nuevo -> Sig = NULL;
      *Inicio = Nuevo;
    }
  else
    {
      
    }
}

void ImprimirListaDesdeInicio (TipoNumero *Inicio)
{
  TipoNumero *Temp;
  Temp = Inicio;
  printf ("=======================================================\n\n");
  while (Temp != NULL)
    {
      printf ("%d\n\n", Temp -> Numero);
      Temp = Temp -> Sig; 
    }
}

void ImprimirListaDesdeFin (TipoNumero *Inicio)
{
  TipoNumero *Temp;
  Temp = Inicio;
  printf ("=======================================================\n\n");
  while (Temp -> Sig != NULL)
    {
      Temp = Temp -> Sig;
    }
  while (Temp != NULL)
    {
      printf ("%d\n\n", Temp -> Numero);
      Temp = Temp -> Ant;
    }
}

void BorrarLista (TipoNumero *Inicio)
{
  TipoNumero *Temp;
  while (Inicio != NULL)
    {
      Temp = Inicio;
      Inicio = Inicio -> Sig;
      free (Temp);
    }
}

int main (void)
{
  int Eleccion, Numero;
  char Enter;
  TipoNumero *Inicio = NULL;
  do
    {
      system ("clear");
      printf ("\n");
      printf ("Eliga una opción:\n\n\n");
      printf ("1.- Insertar al principio\n\n");
      printf ("2.- Insertar al final\n\n");
      printf ("3.- Insertar en orden (No usar si se usó las opciones 1 o 2)\n\n");
      printf ("4.- Imprimir desde el inicio\n\n");
      printf ("5.- Imprimir desde el final\n\n");
      printf ("6.- Salir\n\n");
      scanf (" %d", &Eleccion);
      printf ("\n");
      switch (Eleccion)
	{
	case 1:
	  printf ("Inserte un numero:\n\n");
	  scanf (" %d", &Numero);
	  printf ("\n");
	  InsertaInicio (Numero, &Inicio);
	  break;
	case 2:
	  printf ("Inserte un numero:\n\n");
	  scanf (" %d", &Numero);
	  printf ("\n");
	  InsertaFin (Numero, &Inicio);
	  break;
	case 3:
	  printf ("Inserte un numero:\n\n");
	  scanf (" %d", &Numero);
	  printf ("\n");
	  InsertaEnOrden (Numero, &Inicio);
	  break;
	case 4:
	  ImprimirListaDesdeInicio (Inicio);
	  break;
	case 5:
	  ImprimirListaDesdeFin (Inicio);
	  break;
	case 6:
	  break;
	default:
	  printf ("Opción invalida\n\n");
	}
      printf ("Presione enter para continuar...\n\n");
      __fpurge (stdin);
      scanf ("%c", &Enter);
      printf ("\n");
    }
  while (Eleccion != 6);
  BorrarLista (Inicio);
}
