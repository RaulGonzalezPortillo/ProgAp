#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct def_empleado
{
  char  Nombre [100];
  int   Edad;
  int   Antiguedad;
  float Sueldo;
} tipoEmpleado;

void IngresarEmpleado  (int *Registrados, tipoEmpleado Empleados[]);
void ImprimirEmpleados (int *Registrados, tipoEmpleado Empleados []);
void BuscarEmpleado    (int *Registrados, tipoEmpleado Empleados []);
void BuscarAntiguedad  (int *Registrados, tipoEmpleado Empleados []);
void BaileFortnite     ();
void Dormir            ();

int main (void)
{
  tipoEmpleado Empleados [10];
  int Registrados = 0, Repeticion = 1, Seleccion;
  do { 
    system ("clear");
    printf ("\nEL BASE-DE-DATOS-DE-EMPLEADOS-TRON 3000\n\n");
    printf ("Menú principal:\n\n\n");
    printf ("1.- Registrar a un divertido empleado (Máximo 10, compre la versión premium para más) (Empleados registrados actualmente: %d)\n\n", Registrados);
    printf ("2.- Imprimir toda la información de todos los empleados\n\n");
    printf ("3.- Buscar a un empleado por su nombre\n\n");
    printf ("4.- Imprimir empleados con cierta antiguedad\n\n");
    printf ("5.- Supersalirse\n\n");
    printf ("6.- Báilame\n\n\n");
    printf ("Escoja una opción:\n\n");
    __fpurge (stdin);
    scanf ("%d", &Seleccion);
    switch (Seleccion)
      {
      case 1:
	IngresarEmpleado (&Registrados, Empleados);
	break;
      case 2:
	ImprimirEmpleados (&Registrados, Empleados);
	break;
      case 3:
	BuscarEmpleado (&Registrados, Empleados);
	break;
      case 4:
	BuscarAntiguedad (&Registrados, Empleados);
	break;
      case 5:
	printf ("\nSaliendo del programa...\n\n");
	exit (0);
	break;
      case 6:
	BaileFortnite ();
	break;
      default:
	printf ("\nHa fallado en seguir una simple instrucción.\n\n");
	printf ("Saliendo del programa...\n\n");
	exit (0);
      }
  }
  while (Repeticion = 1);
}

void IngresarEmpleado (int *Registrados, tipoEmpleado Empleados[])
{
  char Enter;
  system ("clear");
  if (*Registrados >= 10)
    {
      printf ("Págueme la licencia de Windows antes de que lo deje ingresar más de 10 empleados...\n\n");
      system ("sleep 3");
    }
  else
    {
      printf ("\nA continuación ingrese la información requerida:\n\n\n");
      printf ("Nombre del empleado: ");
      __fpurge (stdin);
      gets (Empleados [*Registrados].Nombre);
      printf ("\nEdad del empleado: ");
      __fpurge (stdin);
      scanf ("%d", &Empleados [*Registrados].Edad);
      printf ("\nAntiguedad del empleado: ");
      __fpurge (stdin);
      scanf ("%d", &Empleados [*Registrados].Antiguedad);
      printf ("\nSueldo del empleado: ");
      __fpurge (stdin);
      scanf ("%f", &Empleados [*Registrados].Sueldo);
      (*Registrados)++;
      printf ("\n\nInformación guardada con mucha pasión y éxito!");
      printf ("\n\nIngrese un caracter para continuar...\n\n");
      __fpurge (stdin);
      scanf ("%c", &Enter);
    }
}

void ImprimirEmpleados (int *Registrados, tipoEmpleado Empleados [])
{
  int i;
  char Enter;
  system ("clear");
  printf ("\nAhí le van todos los empleados:");
  system ("sleep 0.1");
  printf ("\n\n_,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,_");
  system ("sleep 0.1");
  for (i = 0; i < *Registrados; i++)
    {
      printf ("\n\nEmpleado #%d", i + 1);
      system ("sleep 0.1");
      printf ("\n\nNombre: ");
      puts (Empleados [i].Nombre);
      system ("sleep 0.1");
      printf ("\nEdad: %d", Empleados [i].Edad);
      system ("sleep 0.1"); 
      printf ("\n\nAntiguedad: %d", Empleados [i].Antiguedad);
      system ("sleep 0.1");
      printf ("\n\nSueldo: %f", Empleados [i].Sueldo);
      system ("sleep 0.1");
      printf ("\n\n_,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,_");
    }
  printf ("\n\nIngrese un caracter para continuar...\n\n");
  __fpurge (stdin);
  scanf ("%c", &Enter);
}

void BuscarEmpleado (int *Registrados, tipoEmpleado Empleados [])
{
  int i;
  char Buscador [100], Enter;
  system ("clear");
  printf ("\nPor favor ingrese el empleado a buscar:\n\n");
  __fpurge (stdin);
  gets (Buscador);
  system ("clear");
  printf ("\nEstas son las incidencias si o no raza:");
  system ("sleep 0.1");
  printf ("\n\n_,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,_");
  system ("sleep 0.1");
  for (i = 0; i < *Registrados; i ++)
    {
      if ((strcmp (Buscador, Empleados [i]. Nombre)) == 0)
	{
	  printf ("\n\nEmpleado #%d", i + 1);
	  system ("sleep 0.1");
	  printf ("\n\nNombre: ");
	  puts (Empleados [i].Nombre);
	  system ("sleep 0.1");
	  printf ("\nEdad: %d", Empleados [i].Edad);
	  system ("sleep 0.1"); 
	  printf ("\n\nAntiguedad: %d", Empleados [i].Antiguedad);
	  system ("sleep 0.1");
	  printf ("\n\nSueldo: %f", Empleados [i].Sueldo);
	  system ("sleep 0.1");
	  printf ("\n\n_,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,_");
	  system ("sleep 0.1");
	}
    }
  printf ("\n\nIngrese un caracter para continuar...\n\n");
  __fpurge (stdin);
  scanf ("%c", &Enter);
}

void BuscarAntiguedad (int *Registrados, tipoEmpleado Empleados [])
{
  int i, Buscador;
  char Enter;
  system ("clear");
  printf ("\nPor favor ingrese la antiguedad de empleado a buscar:\n\n");
  __fpurge (stdin);
  scanf ("%d", &Buscador);
  system ("clear");
  printf ("\nEstas son las incidencias si o no raza:");
  system ("sleep 0.1");
  printf ("\n\n_,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,_");
  system ("sleep 0.1");
  for (i = 0; i < *Registrados; i ++)
    {
      if (Empleados [i].Antiguedad >= Buscador)
	{
	  printf ("\n\nEmpleado #%d", i + 1);
	  system ("sleep 0.1");
	  printf ("\n\nNombre: ");
	  puts (Empleados [i].Nombre);
	  system ("sleep 0.1");
	  printf ("\nEdad: %d", Empleados [i].Edad);
	  system ("sleep 0.1"); 
	  printf ("\n\nAntiguedad: %d", Empleados [i].Antiguedad);
	  system ("sleep 0.1");
	  printf ("\n\nSueldo: %f", Empleados [i].Sueldo);
	  system ("sleep 0.1");
	  printf ("\n\n_,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,_");
	  system ("sleep 0.1");
	}
    }
  printf ("\n\nIngrese un caracter para continuar...\n\n");
  __fpurge (stdin);
  scanf ("%c", &Enter);
}

void BaileFortnite ()
{
  int Repetir = 0;
    do
      {
	system ("clear");
	printf ("⠀⠀⠀⠀⣀⣤\n");
	printf ("⠀⠀⠀⠀⣿⠿⣶\n");
	printf ("⠀⠀⠀⠀⣿⣿⣀\n");
	printf ("⠀⠀⠀⣶⣶⣿⠿⠛⣶\n");
	printf ("⠤⣀⠛⣿⣿⣿⣿⣿⣿⣭⣿⣤\n");
	printf ("⠒⠀⠀⠀⠉⣿⣿⣿⣿⠀⠀⠉⣀\n");
	printf ("⠀⠤⣤⣤⣀⣿⣿⣿⣿⣀⠀⠀⣿\n");
	printf ("⠀⠀⠛⣿⣿⣿⣿⣿⣿⣿⣭⣶⠉\n");
	printf ("⠀⠀⠀⠤⣿⣿⣿⣿⣿⣿⣿\n");
	printf ("⠀⠀⠀⣭⣿⣿⣿⠀⣿⣿⣿\n");
	printf ("⠀⠀⠀⣉⣿⣿⠿⠀⠿⣿⣿\n");
	printf ("⠀⠀⠀⠀⣿⣿⠀⠀⠀⣿⣿⣤\n");
	printf ("⠀⠀⠀⣀⣿⣿⠀⠀⠀⣿⣿⣿\n");
	printf ("⠀⠀⠀⣿⣿⣿⠀⠀⠀⣿⣿⣿\n");
	printf ("⠀⠀⠀⣿⣿⠛⠀⠀⠀⠉⣿⣿\n");
	printf ("⠀⠀⠀⠉⣿⠀⠀⠀⠀⠀⠛⣿\n");
	printf ("⠀⠀⠀⠀⣿⠀⠀⠀⠀⠀⠀⣿⣿\n");
	printf ("⠀⠀⠀⠀⣛⠀⠀⠀⠀⠀⠀⠛⠿⠿⠿\n");
	printf ("⠀⠀⠀⠛⠛\n");
	Dormir ();
	system ("clear");
	printf ("⠀⠀⠀⣀⣶⣀\n");
	printf ("⠀⠀⠀⠒⣛⣭\n");
	printf ("⠀⠀⠀⣀⠿⣿⣶\n");
	printf ("⠀⣤⣿⠤⣭⣿⣿\n");
	printf ("⣤⣿⣿⣿⠛⣿⣿⠀⣀\n");
	printf ("⠀⣀⠤⣿⣿⣶⣤⣒⣛\n");
	printf ("⠉⠀⣀⣿⣿⣿⣿⣭⠉\n");
	printf ("⠀⠀⣭⣿⣿⠿⠿⣿\n");
	printf ("⠀⣶⣿⣿⠛⠀⣿⣿\n");
	printf ("⣤⣿⣿⠉⠤⣿⣿⠿\n");
	printf ("⣿⣿⠛⠀⠿⣿⣿\n");
	printf ("⣿⣿⣤⠀⣿⣿⠿\n");
	printf ("⠀⣿⣿⣶⠀⣿⣿⣶\n");
	printf ("⠀⠀⠛⣿⠀⠿⣿⣿\n");
	printf ("⠀⠀⠀⣉⣿⠀⣿⣿\n");
	printf ("⠀⠶⣶⠿⠛⠀⠉⣿\n");
	printf ("⠀⠀⠀⠀⠀⠀⣀⣿\n");
	printf ("⠀⠀⠀⠀⠀⣶⣿⠿\n");
	Dormir ();
	system ("clear");
	printf ("⠀⠀⠀⠀⠀⠀⠀⠀⣤⣿⣿⠶⠀⠀⣀⣀\n");
	printf ("⠀⠀⠀⠀⠀⠀⣀⣀⣤⣤⣶⣿⣿⣿⣿⣿⣿\n");
	printf ("⠀⠀⣀⣶⣤⣤⠿⠶⠿⠿⠿⣿⣿⣿⣉⣿⣿\n");
	printf ("⠿⣉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠛⣤⣿⣿⣿⣀\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⣿⣿⣿⣿⣶⣤\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣤⣿⣿⣿⣿⠿⣛⣿\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⠛⣿⣿⣿⣿\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣶⣿⣿⠿⠀⣿⣿⣿⠛\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⠀⠀⣿⣿⣿\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠿⠿⣿⠀⠀⣿⣶\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠛⠀⠀⣿⣿⣶\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⣿⣿⠤\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠿⣿\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣀\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣶⣿\n");
	Dormir ();
	system ("clear");
	printf ("⠀⠀⣀\n");
	printf ("⠀⠿⣿⣿⣀\n");
	printf ("⠀⠉⣿⣿⣀\n");
	printf ("⠀⠀⠛⣿⣭⣀⣀⣤\n");
	printf ("⠀⠀⣿⣿⣿⣿⣿⠛⠿⣶⣀\n");
	printf ("⠀⣿⣿⣿⣿⣿⣿⠀⠀⠀⣉⣶\n");
	printf ("⠀⠀⠉⣿⣿⣿⣿⣀⠀⠀⣿⠉\n");
	printf ("⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿\n");
	printf ("⠀⣀⣿⣿⣿⣿⣿⣿⣿⣿⠿\n");
	printf ("⠀⣿⣿⣿⠿⠉⣿⣿⣿⣿\n");
	printf ("⠀⣿⣿⠿⠀⠀⣿⣿⣿⣿\n");
	printf ("⣶⣿⣿⠀⠀⠀⠀⣿⣿⣿\n");
	printf ("⠛⣿⣿⣀⠀⠀⠀⣿⣿⣿⣿⣶⣀\n");
	printf ("⠀⣿⣿⠉⠀⠀⠀⠉⠉⠉⠛⠛⠿⣿⣶\n");
	printf ("⠀⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣿\n");
	printf ("⠀⠀⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉\n");
	printf ("⣀⣶⣿⠛\n");
	Dormir ();
	system ("clear");
	printf ("⠀⠀⠀⠀⠀⠀⠀⠀⣤⣿⣿⠶⠀⠀⣀⣀\n");
	printf ("⠀⠀⠀⠀⠀⠀⣀⣀⣤⣤⣶⣿⣿⣿⣿⣿⣿\n");
	printf ("⠀⠀⣀⣶⣤⣤⠿⠶⠿⠿⠿⣿⣿⣿⣉⣿⣿\n");
	printf ("⠿⣉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠛⣤⣿⣿⣿⣀\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⣿⣿⣿⣿⣶⣤\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣤⣿⣿⣿⣿⠿⣛⣿\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⠛⣿⣿⣿⣿\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣶⣿⣿⠿⠀⣿⣿⣿⠛\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⠀⠀⣿⣿⣿\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠿⠿⣿⠀⠀⣿⣶\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠛⠀⠀⣿⣿⣶\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⣿⣿⠤\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠿⣿\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣀\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣶⣿\n");
	Dormir ();
	system ("clear");
	printf ("⠀⠀⣀\n");
	printf ("⠀⠿⣿⣿⣀\n");
	printf ("⠀⠉⣿⣿⣀\n");
	printf ("⠀⠀⠛⣿⣭⣀⣀⣤\n");
	printf ("⠀⠀⣿⣿⣿⣿⣿⠛⠿⣶⣀\n");
	printf ("⠀⣿⣿⣿⣿⣿⣿⠀⠀⠀⣉⣶\n");
	printf ("⠀⠀⠉⣿⣿⣿⣿⣀⠀⠀⣿⠉\n");
	printf ("⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿\n");
	printf ("⠀⣀⣿⣿⣿⣿⣿⣿⣿⣿⠿\n");
	printf ("⠀⣿⣿⣿⠿⠉⣿⣿⣿⣿\n");
	printf ("⠀⣿⣿⠿⠀⠀⣿⣿⣿⣿\n");
	printf ("⣶⣿⣿⠀⠀⠀⠀⣿⣿⣿\n");
	printf ("⠛⣿⣿⣀⠀⠀⠀⣿⣿⣿⣿⣶⣀\n");
	printf ("⠀⣿⣿⠉⠀⠀⠀⠉⠉⠉⠛⠛⠿⣿⣶\n");
	printf ("⠀⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣿\n");
	printf ("⠀⠀⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉\n");
	printf ("⣀⣶⣿⠛\n");
	Dormir ();
	system ("clear");
	printf ("⠀⠀⠀⠀⠀⠀⠀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf ("⠀⠀⠀⠀⠀⠀⣿⣿⣿⣤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣤⣤⣿\n");
	printf ("⠀⠀⠀⠀⠀⠀⠉⣿⣿⣿⣶⣿⣿⣿⣶⣶⣤⣶⣶⠶⠛⠉⠉\n");
	printf ("⠀⠀⠀⠀⠀⠀⣤⣿⠿⣿⣿⣿⣿⣿⠀⠀⠉⠀⠀⠀⠀⠀⠀\n");
	printf ("⠛⣿⣤⣤⣀⣤⠿⠉⠀⠉⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf ("⠀⠉⠉⠉⠉⠉⠀⠀⠀⠀⠉⣿⣿⣿⣀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣶⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⠛⠀⠀⠀⠀⠀⠀⠀\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣛⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⣶⣿⣿⠛⠿⣿⣿⣿⣶⣤⠀⠀⠀⠀⠀⠀\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⣿⠛⠉⠀⠀⠀⠛⠿⣿⣿⣶⣀⠀⠀⠀⠀\n");
	printf ("⠀⠀⠀⠀⠀⠀⣿⣀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⠿⣶⣤⠀⠀\n");
	printf ("⠀⠀⠀⠀⠀⠛⠿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣿⣿⠿⠀\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠛⠉⠉⠀\n");
	Dormir ();
	system ("clear");
	printf ("⠀⠀⠀⠀⠀⠀⣤⣶⣶\n");
	printf ("⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣀⣀\n");
	printf ("⠀⠀⠀⠀⠀⣀⣶⣿⣿⣿⣿⣿⣿\n");
	printf ("⣤⣶⣀⠿⠶⣿⣿⣿⠿⣿⣿⣿⣿\n");
	printf ("⠉⠿⣿⣿⠿⠛⠉⠀⣿⣿⣿⣿⣿\n");
	printf ("⠀⠀⠉⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣤⣤\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⣤⣶⣿⣿⣿⣿⣿⣿\n");
	printf ("⠀⠀⠀⠀⠀⣀⣿⣿⣿⣿⣿⠿⣿⣿⣿⣿\n");
	printf ("⠀⠀⠀⠀⣀⣿⣿⣿⠿⠉⠀⠀⣿⣿⣿⣿\n");
	printf ("⠀⠀⠀⠀⣿⣿⠿⠉⠀⠀⠀⠀⠿⣿⣿⠛\n");
	printf ("⠀⠀⠀⠀⠛⣿⣿⣀⠀⠀⠀⠀⠀⣿⣿⣀\n");
	printf ("⠀⠀⠀⠀⠀⣿⣿⣿⠀⠀⠀⠀⠀⠿⣿⣿\n");
	printf ("⠀⠀⠀⠀⠀⠉⣿⣿⠀⠀⠀⠀⠀⠀⠉⣿\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⣿⠀⠀⠀⠀⠀⠀⣀⣿\n");
	printf ("⠀⠀⠀⠀⠀⠀⣀⣿⣿\n");
	printf ("⠀⠀⠀⠀⠤⣿⠿⠿⠿\n");
	Dormir ();
	system ("clear");
	printf ("⠀⠀⠀⠀⣀\n");
	printf ("⠀⠀⣶⣿⠿⠀⠀⠀⣀⠀⣤⣤\n");
	printf ("⠀⣶⣿⠀⠀⠀⠀⣿⣿⣿⠛⠛⠿⣤⣀\n");
	printf ("⣶⣿⣤⣤⣤⣤⣤⣿⣿⣿⣀⣤⣶⣭⣿⣶⣀\n");
	printf ("⠉⠉⠉⠛⠛⠿⣿⣿⣿⣿⣿⣿⣿⠛⠛⠿⠿\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⠿\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⠿⣿⣿⣿⣿\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⠀⣭⣿⣿⣿⣿⣿\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⣤⣿⣿⣿⣿⣿⣿\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⠿\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⠿\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⠉⣿⣿⣿⣿\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⠀⠉⣿⣿⣿⣿\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⣿⠛⠿⣿⣤\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣿⠀⠀⠀⣿⣿⣤\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠀⠀⠀⣶⣿⠛⠉\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⠀⣤⣿⣿⠀⠀⠉\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉\n");
	Dormir ();
	system ("clear");
	printf ("⠀⠀⠀⠀⠀⠀⣶⣿⣶\n");
	printf ("⠀⠀⠀⣤⣤⣤⣿⣿⣿\n");
	printf ("⠀⠀⣶⣿⣿⣿⣿⣿⣿⣿⣶\n");
	printf ("⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
	printf ("⠀⠀⣿⣉⣿⣿⣿⣿⣉⠉⣿⣶\n");
	printf ("⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⠿⣿\n");
	printf ("⠀⣤⣿⣿⣿⣿⣿⣿⣿⠿⠀⣿⣶\n");
	printf ("⣤⣿⠿⣿⣿⣿⣿⣿⠿⠀⠀⣿⣿⣤\n");
	printf ("⠉⠉⠀⣿⣿⣿⣿⣿⠀⠀⠒⠛⠿⠿⠿\n");
	printf ("⠀⠀⠀⠉⣿⣿⣿⠀⠀⠀⠀⠀⠀⠉\n");
	printf ("⠀⠀⠀⣿⣿⣿⣿⣿⣶\n");
	printf ("⠀⠀⠀⠀⣿⠉⠿⣿⣿\n");
	printf ("⠀⠀⠀⠀⣿⣤⠀⠛⣿⣿\n");
	printf ("⠀⠀⠀⠀⣶⣿⠀⠀⠀⣿⣶\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⠀⠀⣭⣿⣿\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⠀⣤⣿⣿⠉\n");
	Dormir ();
	system ("clear");
	printf ("⠀⠀⠀⠀⠀⣀⣀⠀⣶⣿⣿⠶\n");
	printf ("⣶⣿⠿⣿⣿⣿⣿⣿⣿⣿⣿⣤⣤\n");
	printf ("⠀⠉⠶⣶⣀⣿⣿⣿⣿⣿⣿⣿⠿⣿⣤⣀\n");
	printf ("⠀⠀⠀⣿⣿⠿⠉⣿⣿⣿⣿⣭⠀⠶⠿⠿\n");
	printf ("⠀⠀⠛⠛⠿⠀⠀⣿⣿⣿⣉⠿⣿⠶\n");
	printf ("⠀⠀⠀⠀⠀⣤⣶⣿⣿⣿⣿⣿\n");
	printf ("⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⠒\n");
	printf ("⠀⠀⠀⠀⣀⣿⣿⣿⣿⣿⣿⣿\n");
	printf ("⠀⠀⠀⠀⠀⣿⣿⣿⠛⣭⣭⠉\n");
	printf ("⠀⠀⠀⠀⠀⣿⣿⣭⣤⣿⠛\n");
	printf ("⠀⠀⠀⠀⠀⠛⠿⣿⣿⣿⣭\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⣿⣿⠉⠛⠿⣶⣤\n");
	printf ("⠀⠀⠀⠀⠀⠀⣀⣿⠀⠀⣶⣶⠿⠿⠿\n");
	printf ("⠀⠀⠀⠀⠀⠀⣿⠛\n");
	printf ("⠀⠀⠀⠀⠀⠀⣭⣶\n");
	Dormir ();
	system ("clear");
	printf ("⠀⠀⠀⠀⠀⠀⣶⣿⣶\n");
	printf ("⠀⠀⠀⣤⣤⣤⣿⣿⣿\n");
	printf ("⠀⠀⣶⣿⣿⣿⣿⣿⣿⣿⣶\n");
	printf ("⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
	printf ("⠀⠀⣿⣉⣿⣿⣿⣿⣉⠉⣿⣶\n");
	printf ("⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⠿⣿\n");
	printf ("⠀⣤⣿⣿⣿⣿⣿⣿⣿⠿⠀⣿⣶\n");
	printf ("⣤⣿⠿⣿⣿⣿⣿⣿⠿⠀⠀⣿⣿⣤\n");
	printf ("⠉⠉⠀⣿⣿⣿⣿⣿⠀⠀⠒⠛⠿⠿⠿\n");
	printf ("⠀⠀⠀⠉⣿⣿⣿⠀⠀⠀⠀⠀⠀⠉\n");
	printf ("⠀⠀⠀⣿⣿⣿⣿⣿⣶\n");
	printf ("⠀⠀⠀⠀⣿⠉⠿⣿⣿\n");
	printf ("⠀⠀⠀⠀⣿⣤⠀⠛⣿⣿\n");
	printf ("⠀⠀⠀⠀⣶⣿⠀⠀⠀⣿⣶\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⠀⠀⣭⣿⣿\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⠀⣤⣿⣿⠉\n");
	Dormir ();
	system ("clear");
	printf ("⠀⠀⠀⠀⠀⣀⣀⠀⣶⣿⣿⠶\n");
	printf ("⣶⣿⠿⣿⣿⣿⣿⣿⣿⣿⣿⣤⣤\n");
	printf ("⠀⠉⠶⣶⣀⣿⣿⣿⣿⣿⣿⣿⠿⣿⣤⣀\n");
	printf ("⠀⠀⠀⣿⣿⠿⠉⣿⣿⣿⣿⣭⠀⠶⠿⠿\n");
	printf ("⠀⠀⠛⠛⠿⠀⠀⣿⣿⣿⣉⠿⣿⠶\n");
	printf ("⠀⠀⠀⠀⠀⣤⣶⣿⣿⣿⣿⣿\n");
	printf ("⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⠒\n");
	printf ("⠀⠀⠀⠀⣀⣿⣿⣿⣿⣿⣿⣿\n");
	printf ("⠀⠀⠀⠀⠀⣿⣿⣿⠛⣭⣭⠉\n");
	printf ("⠀⠀⠀⠀⠀⣿⣿⣭⣤⣿⠛\n");
	printf ("⠀⠀⠀⠀⠀⠛⠿⣿⣿⣿⣭\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⣿⣿⠉⠛⠿⣶⣤\n");
	printf ("⠀⠀⠀⠀⠀⠀⣀⣿⠀⠀⣶⣶⠿⠿⠿\n");
	printf ("⠀⠀⠀⠀⠀⠀⣿⠛\n");
	printf ("⠀⠀⠀⠀⠀⠀⣭⣶\n");
	Dormir ();
	system ("clear");
	printf ("⠀⠀⠀⠀⠀⠀⠀⠀⠀⣤⣤\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿\n");
	printf ("⠀⠀⣶⠀⠀⣀⣤⣶⣤⣉⣿⣿⣤⣀\n");
	printf ("⠤⣤⣿⣤⣿⠿⠿⣿⣿⣿⣿⣿⣿⣿⣿⣀\n");
	printf ("⠀⠛⠿⠀⠀⠀⠀⠉⣿⣿⣿⣿⣿⠉⠛⠿⣿⣤\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⠀⠿⣿⣿⣿⠛⠀⠀⠀⣶⠿\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⠀⣀⣿⣿⣿⣿⣤⠀⣿⠿\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⣶⣿⣿⣿⣿⣿⣿⣿⣿\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⠿⣿⣿⣿⣿⣿⠿⠉⠉\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⠉⣿⣿⣿⣿⠿\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⠉\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⠀⣛⣿⣭⣶⣀\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⠉⠛⣿\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⠀⠀⣿⣿\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣉⠀⣶⠿\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⠀⣶⣿⠿\n");
	printf ("⠀⠀⠀⠀⠀⠀⠀⠛⠿⠛⠀⠀⠀\n");
	system ("sleep 0.5");
	Dormir ();
	system ("clear");
	printf ("⠀⠀⠀⣶⣿⣶\n");
	printf ("⠀⠀⠀⣿⣿⣿⣀\n");
	printf ("⠀⣀⣿⣿⣿⣿⣿⣿\n");
	printf ("⣶⣿⠛⣭⣿⣿⣿⣿\n");
	printf ("⠛⠛⠛⣿⣿⣿⣿⠿\n");
	printf ("⠀⠀⠀⠀⣿⣿⣿\n");
	printf ("⠀⠀⣀⣭⣿⣿⣿⣿⣀\n");
	printf ("⠀⠤⣿⣿⣿⣿⣿⣿⠉\n");
	printf ("⠀⣿⣿⣿⣿⣿⣿⠉\n");
	printf ("⣿⣿⣿⣿⣿⣿\n");
	printf ("⣿⣿⣶⣿⣿\n");
	printf ("⠉⠛⣿⣿⣶⣤\n");
	printf ("⠀⠀⠉⠿⣿⣿⣤\n");
	printf ("⠀⠀⣀⣤⣿⣿⣿\n");
	printf ("⠀⠒⠿⠛⠉⠿⣿\n");
	printf ("⠀⠀⠀⠀⠀⣀⣿⣿\n");
	printf ("⠀⠀⠀⠀⣶⠿⠿⠛\n");
	system ("sleep 1.5");
      }
    while (Repetir == 0);
}

void Dormir ()
{
  system ("sleep 0.4");
}
