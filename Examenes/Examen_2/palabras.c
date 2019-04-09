#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Nodo
{
  int Frecuencia;
  char Palabra [30];
  struct Nodo *Izq, *Der;
};

void Insertar (struct Nodo **Raiz, char Insertador [30]);
void ImprimirOrden (struct Nodo *Raiz);
void ImprimirPreOrden (struct Nodo *Raiz);
void ImprimirPosOrden (struct Nodo *Raiz);
void Borrar (struct Nodo *Raiz);

int main (void)
{
  FILE *Archivo;
  int Salir, Seleccion, Nodos, Hojas, Altura, i;
  char NombreDeArchivo [100], Insertador [30], Letra, Enter;
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
      while ((fscanf (Archivo, "%c", &Letra)) == 1)
	{
	  if (Letra != ' ' && Letra != '\n' && Letra != '\0')
	    {
	      i = 0;
	      while (Letra != ' ' && Letra != '\n' && Letra != '\0')
		{
		  Insertador [i] = Letra;
		  fscanf (Archivo, "%c", &Letra);
		  i++;
		}
	      Insertador [i] = '\0';
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
	  printf ("2.- Imprimir en pre orden\n\n");
	  printf ("3.- Imprimir en post orden\n\n");
	  printf ("4.- Salir\n\n\n");
	  __fpurge (stdin);
	  scanf ("%d", &Seleccion);
	  printf ("\n");
	  switch (Seleccion)
	    {
	    case 1:
	      system ("clear");
	      printf ("\n");
	      ImprimirOrden (Raiz);
	      printf ("\n");
	      printf ("Presione Enter para continuar...\n\n");
	      __fpurge (stdin);
	      scanf ("%c", &Enter);
	      printf ("\n");
	      break;
	    case 2:
	      system ("clear");
	      printf ("\n");
	      ImprimirPreOrden (Raiz);
	      printf ("\n");
	      printf ("Presione enter para continuar...\n\n");
	      __fpurge (stdin);
	      scanf ("%c", &Enter);
	      printf ("\n");
	      break;
	    case 3:
	      system ("clear");
	      printf ("\n");
	      ImprimirPosOrden (Raiz);
	      printf ("\n");
	      printf ("Presione enter para continuar...\n\n");
	      __fpurge (stdin);
	      scanf ("%c", &Enter);
	      printf ("\n");
	      break;
	    case 4:
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

void Insertar (struct Nodo **Raiz, char Insertador [30])
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
  strcpy (Nuevo -> Palabra, Insertador);
  Nuevo -> Frecuencia = 1;
  Nuevo -> Izq = NULL;
  Nuevo -> Der = NULL;
  while (Avanza != NULL)
    {
      if ((strcmp (Insertador, Avanza -> Palabra)) > 0) //Muevete a la derecha
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
      if ((strcmp (Insertador, Avanza -> Palabra)) == 0)
	{
	  (Avanza -> Frecuencia)++;
	  return;
	}
      if ((strcmp (Insertador, Avanza -> Palabra)) <= 0) //Muevete a la izquierda
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

void ImprimirOrden (struct Nodo *Raiz)
{
  if (Raiz != NULL)
    {
      ImprimirOrden (Raiz -> Izq);
      puts (Raiz -> Palabra);
      printf ("Frecuencia:%d\n\n", Raiz -> Frecuencia);
      ImprimirOrden (Raiz -> Der);
    }
}

void ImprimirPreOrden (struct Nodo *Raiz)
{
  if (Raiz != NULL)
    {
      puts (Raiz -> Palabra);
      printf ("Frecuencia:%d\n\n", Raiz -> Frecuencia);
      ImprimirPreOrden (Raiz -> Izq);
      ImprimirPreOrden (Raiz -> Der);
    }
}

void ImprimirPosOrden (struct Nodo *Raiz)
{
  if (Raiz != NULL)
    {
      ImprimirPosOrden (Raiz -> Izq);
      ImprimirPosOrden (Raiz -> Der);
      puts (Raiz -> Palabra);
      printf ("Frecuencia:%d\n\n", Raiz -> Frecuencia);
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

