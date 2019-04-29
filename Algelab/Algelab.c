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
      printf ("1.- Ir a la calculadora algebráica\n");
      printf ("2.- Repasar teoría\n");
      printf ("3.- Contestar una pregunta\n");
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
  int Opcion;
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
      printf ("1.- Introducir una matriz\n");
      printf ("2.- Multiplicar matriz por un escalar\n");
      printf ("3.- Volver\n\n");
      scanf ("%d", &Opcion);
      switch (Opcion)
	{
	case 1:
	  break;
	case 2:
	  break;
	case 3:
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
