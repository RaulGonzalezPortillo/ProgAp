#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Logo (void);
void Encabezado (void);
void AnimacionSalida (void);
void Dormir (void);
void Calculadora (void);
void AnimacionVolver (void);

int main (void)
{
  int Opcion;
  system ("clear");
  printf ("\n");
  printf ("Bienvenido a");
  Logo ();
  printf ("Presione Enter para continuar...\n\n");
  getchar ();
  do
    {
      Encabezado ();
      printf ("Elija una opción:\n\n");
      Dormir ();
      printf ("1.- Ir a la calculadora algebráica\n");
      Dormir ();
      printf ("2.- Repasar teoría\n");
      Dormir ();
      printf ("3.- Contestar una pregunta\n");
      Dormir ();
      printf ("4.- Salir del programa\n\n");
      scanf ("%d", &Opcion);
      switch (Opcion)
	{
	case 1:
	  Calculadora ();
	  break;
	case 2:
	  break;
	case 3:
	  break;
	case 4:
	  AnimacionSalida ();
	  break;
	default:
	  break;
	}
    }
  while (Opcion != 4);
}

void Logo (void)
{
  printf ("\n\n");
  printf ("\t      _/_/    _/                      _/            _/       \n");
  Dormir ();
  printf ("\t   _/    _/  _/    _/_/_/    _/_/    _/    _/_/_/  _/_/_/    \n");
  Dormir ();
  printf ("\t  _/_/_/_/  _/  _/    _/  _/_/_/_/  _/  _/    _/  _/    _/   \n");
  Dormir ();
  printf ("\t _/    _/  _/  _/    _/  _/        _/  _/    _/  _/    _/    \n");
  Dormir ();
  printf ("\t_/    _/  _/    _/_/_/    _/_/_/  _/    _/_/_/  _/_/_/       \n");
  Dormir ();
  printf ("\t                   _/                                        \n");
  Dormir ();
  printf ("\t              _/_/                                           \n\n");
  Dormir ();
  printf ("Desarrollado por:\n");
  Dormir ();
  printf ("•Raúl González Portillo\n\n");
}

void Encabezado (void)
{
  system ("clear");
  printf ("\n");
  printf (" /` | _  _ | _ |_ \n");
  printf ("/--`|(_|(/_|(_||_)\n");
  printf ("      _|          \n");
  printf ("_______________________________________________________________________________\n\n");
}

void AnimacionSalida (void)
{
  Dormir ();
  Encabezado ();
  printf ("Elija una opción:\n\n");
  printf ("1.- Ir a la calculadora algebráica\n");
  printf ("2.- Repasar teoría\n");
  printf ("3.- Contestar una pregunta\n");
  printf ("4.- Salir del programa\n\n");
  Dormir ();
  Encabezado ();
  printf ("Elija una opción:\n\n");
  printf ("1.- Ir a la calculadora algebráica\n");
  printf ("2.- Repasar teoría\n");
  printf ("3.- Contestar una pregunta\n");
  Dormir ();
  Encabezado ();
  printf ("Elija una opción:\n\n");
  printf ("1.- Ir a la calculadora algebráica\n");
  printf ("2.- Repasar teoría\n");
  Dormir ();
  Encabezado ();
  printf ("Elija una opción:\n\n");
  printf ("1.- Ir a la calculadora algebráica\n");
  Dormir ();
  Encabezado ();
  printf ("Elija una opción:\n\n");
  Dormir ();
  Encabezado ();
  Dormir ();
  system ("clear");
}

void Dormir (void)
{
  system ("sleep 0.06");
}

void Calculadora (void)
{
  int **Matriz1, **Matriz2;
  int Opcion, R1, C1, R2, C2, r, c, i, Escalar;
  char Matriz;
  Matriz1 = NULL;
  Matriz2 = NULL;
  while (1)
    {
      Encabezado ();
      if (Matriz1 == NULL && Matriz2 == NULL)
	printf ("INFO: Actualmente se tienen 0 matrices guardadas\n\n");
      if (Matriz1 != NULL && Matriz2 == NULL)
	printf ("INFO: Actualmente se tiene 1 matriz guardada\n\n");
      if (Matriz2 != NULL)
	printf ("INFO: Actualmente se tienen 2 matrices guardadas\n\n");
      Dormir ();
      printf ("1.- Introducir una matriz\n");
      Dormir ();
      printf ("2.- Multiplicar a la matriz A por un escalar\n");
      Dormir ();
      printf ("3.- Multiplicar a la matriz B por un escalar\n");
      Dormir ();
      printf ("4.- Volver\n\n");
      scanf ("%d", &Opcion);
      switch (Opcion)
	{
	case 1:
	  Encabezado ();
	  if (Matriz1 == NULL)
	    {
	      printf ("INFO: Está guardando información en la Matriz A...\n\n");
	      printf ("Ingrese el número de renglones:\n\n");
	      scanf ("%d", &R1);
	      printf ("\n");
	      printf ("Ingrese el número de columnas:\n\n");
	      scanf ("%d", &C1);
	      Matriz1 = (int **) malloc (R1 * sizeof(int *));
	      for (i = 0; i < R1; i++)
		Matriz1[i] = (int *) malloc (C1 * sizeof(int));
	      printf ("\n");
	      printf ("INFO: Se asignó memoria correctamente.\n\n");
	      printf ("Presione Enter para continuar...\n\n");
	      __fpurge (stdin);
	      getchar ();
	      Encabezado ();
	      for (r = 0; r < R1; r++)
		{
		  for (c = 0; c < C1; c++)
		    {
		      printf ("Ingrese el elemento de la posición %d, %d: ", r + 1, c + 1);
		      scanf ("%d", &Matriz1[r][c]);
		      printf ("\n");
		    }
		}
	      printf ("Presione Enter para continuar...\n\n");
	      __fpurge (stdin);
	      getchar ();
	    }
	  else
	    if (Matriz1 != NULL && Matriz2 == NULL)
	      {
	        printf ("INFO: Está guardando información en la Matriz B...\n\n");
		printf ("Ingrese el número de renglones:\n\n");
		scanf ("%d", &R2);
		printf ("\n");
		printf ("Ingrese el número de columnas:\n\n");
		scanf ("%d", &C2);
		Matriz2 = (int **) malloc (R2 * sizeof(int *));
		for (i = 0; i < R2; i++)
		  Matriz2[i] = (int *) malloc (C2 * sizeof(int));
		printf ("\n");
		printf ("INFO: Se asignó memoria correctamente.\n\n");
		printf ("Presione Enter para continuar...\n\n");
		__fpurge (stdin);
		getchar ();
		Encabezado ();
		for (r = 0; r < R2; r++)
		  {
		    for (c = 0; c < C2; c++)
		      {
			printf ("Ingrese el elemento de la posición %d, %d: ", r + 1, c + 1);
			scanf ("%d", &Matriz2[r][c]);
			printf ("\n");
		      }
		  }
		printf ("Presione Enter para continuar...\n\n");
		__fpurge (stdin);
		getchar ();
	      }
	    else
	      if (Matriz1 != NULL && Matriz2 != NULL)
		{
		  printf ("INFO: Ya ha guardado el límite máximo de matrices\n\n");
		  printf ("Presione Enter para continuar...\n\n");
		  __fpurge (stdin);
		  getchar ();
		}
	  break;
	case 2:
	  Encabezado ();
	  if (Matriz1 == NULL)
	    {
	      printf ("INFO: No tiene una Matriz A guardada\n\n");
	      printf ("Presione Enter para continuar...\n\n");
	      __fpurge (stdin);
	      getchar ();
	    }
	  else
	    {
	      printf ("Ingrese el escalar por el cual multiplicar a la matriz: ");
	      scanf ("%d", &Escalar);
	      MultiplicarPorEscalar (Matriz1);
	    }
	  break;
	case 4:
	  AnimacionVolver ();
	  return;
	  break;
	default:
	  break;
	}
    }
}

void AnimacionVolver (void)
{
  Dormir ();
  Encabezado ();
  Dormir ();
  system ("clear");
}

void MultiplicarPorEscalar (int **Matriz, int Escalar)
{
  
}
