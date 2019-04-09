#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Nodo
{
  char Letra;
  struct Nodo *Izq, *Der;
};

void Insertar (struct Nodo **Raiz, int Insertador);
void Imprimir (struct Nodo *Raiz);
void NumeroDeNodos (struct Nodo *Raiz, int *Nodos);
void ObtenerAltura (struct Nodo *Raiz, int TempAltura, int *Altura);
void NumeroDeHojas (struct Nodo *Raiz, int *Hojas);
void Borrar (struct Nodo *Raiz);

int main (void)
{
  FILE *Archivo;
  int Salir, Seleccion, Nodos, Hojas, Altura;
  char NombreDeArchivo [100], Insertador, Enter;
  struct Nodo *Raiz;
  Raiz = NULL;
  system ("clear");
  printf ("\n");
  printf ("Introduzca el nombre del archivo con el que generará el árbol:\n\n");
  __fpurge (stdin);
  gets (NombreDeArchivo);
  printf ("\n");
  Archivo = fopen (NombreDeArchivo, "rt");
  if (Archivo == NULL)
    {
      system ("clear");
      printf ("\n");
      printf ("No se pudo abrir el archivo, saliendo...\n\n");
    }
  else
    {
      while ((fscanf (Archivo, "%c", &Insertador)) == 1)
	{
	  if ((Insertador >= 'a' && Insertador <= 'z') || (Insertador >= 'A' && Insertador <= 'Z'))
	    {
	      Insertar (&Raiz, Insertador);
	    }
	}
      system ("clear");
      printf ("\n");
      printf ("Se ha creado el árbol de manera exitosa, presione Enter para continuar:\n\n");
      __fpurge (stdin);
      scanf ("%c", &Enter);
      do
	{
	  system ("clear");
	  printf ("\n");
	  printf ("Menú principal:\n\n\n");
	  printf ("1.- Imprimir en orden\n\n");
	  printf ("2.- Número de nodos\n\n");
	  printf ("3.- Altura del árbol\n\n");
	  printf ("4.- Número de hojas\n\n");
	  printf ("5.- Salir\n\n\n");
	  __fpurge (stdin);
	  scanf ("%d", &Seleccion);
	  printf ("\n");
	  switch (Seleccion)
	    {
	    case 1:
	      system ("clear");
	      printf ("\n");
	      Imprimir (Raiz);
	      printf ("\n\n");
	      printf ("Presione Enter para continuar...\n\n");
	      __fpurge (stdin);
	      scanf ("%c", &Enter);
	      printf ("\n");
	      break;
	    case 2:
	      Nodos = 0;
	      NumeroDeNodos (Raiz, &Nodos);
	      system ("clear");
	      printf ("\n");
	      printf ("El número de nodos es: %d\n\n", Nodos);
	      printf ("Presione enter para continuar...\n\n");
	      __fpurge (stdin);
	      scanf ("%c", &Enter);
	      printf ("\n");
	      break;
	    case 3:
	      Altura = 0;
	      ObtenerAltura (Raiz, 1, &Altura);
	      system ("clear");
	      printf ("\n");
	      printf ("La altura del árbol es: %d\n\n", Altura);
	      printf ("Presione enter para continuar...\n\n");
	      __fpurge (stdin);
	      scanf ("%c", &Enter);
	      printf ("\n");
	      break;
	    case 4:
	      Hojas = 0;
	      NumeroDeHojas (Raiz, &Hojas);
	      system ("clear");
	      printf ("\n");
	      printf ("El número de hojas es: %d\n\n", Hojas);
	      printf ("Presione enter para continuar...\n\n");
	      __fpurge (stdin);
	      scanf ("%c", &Enter);
	      printf ("\n");
	      break;
	    case 5:
	      Salir = 1;
	      system ("clear");
	      printf ("\n");
	      printf ("Borrando el árbol binario...\n\n");
	      Borrar (Raiz);
	      printf ("Correcto...\n\n");
	      break;
	    default:
	      system ("clear");
	      printf ("\n");
	      printf ("Ha introducido una opción inválida...\n\n");
	      printf ("Presione Enter para continuar...\n\n");
	      __fpurge (stdin);
	      scanf ("%c", &Enter);
	      printf ("\n");
	      break;
	    }
	}
      while (Salir != 1);
    }
}

void Insertar (struct Nodo **Raiz, int Insertador)
{
  struct Nodo *Avanza, *Nuevo;
  Avanza = *Raiz;
  if ((Nuevo = (struct Nodo *) malloc (sizeof (struct Nodo))) == NULL)
    {
      system ("clear");
      printf ("\n");
      printf ("Error fatal: no hay memoria\n\n");
      exit (1);
    }
  Nuevo -> Letra = Insertador;
  Nuevo -> Izq = NULL;
  Nuevo -> Der = NULL;
  while (Avanza != NULL)
    {
      if (Insertador > Avanza -> Letra) //Muevete a la derecha
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
      if (Insertador <= Avanza -> Letra) //Muevete a la izquierda
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

void Imprimir (struct Nodo *Raiz)
{
  if (Raiz != NULL)
    {
      Imprimir (Raiz -> Izq);
      printf ("%c\n\n", Raiz -> Letra);
      Imprimir (Raiz -> Der);
    }
}

void NumeroDeNodos (struct Nodo *Raiz, int *Nodos)
{
  if (Raiz != NULL)
    {
      NumeroDeNodos (Raiz -> Izq, Nodos);
      (*Nodos)++;
      NumeroDeNodos (Raiz -> Der, Nodos);
    }
}

void ObtenerAltura (struct Nodo *Raiz, int TempAltura, int *Altura)
{
  if (Raiz -> Izq != NULL)
    {
      ObtenerAltura (Raiz -> Izq, TempAltura + 1, Altura);
    }
  if (Raiz -> Der != NULL)
    {
      ObtenerAltura (Raiz -> Der, TempAltura + 1, Altura);
    }
  if (Raiz -> Izq == NULL && Raiz -> Der == NULL && TempAltura > *Altura)
    {
      *Altura = TempAltura;
    }
  
}

void NumeroDeHojas (struct Nodo *Raiz, int *Hojas)
{
  if (Raiz != NULL)
    {
      NumeroDeHojas (Raiz -> Der, Hojas);
      if ((Raiz -> Izq == NULL) && (Raiz -> Der == NULL))
	{
	  (*Hojas)++;
	}
      NumeroDeNodos (Raiz -> Izq, Hojas);
    }
}

void Borrar (struct Nodo *Raiz)
{
  if (Raiz != NULL)
    {
      Borrar (Raiz -> Izq);
      Borrar (Raiz -> Der);
      free (Raiz);
    }
}

