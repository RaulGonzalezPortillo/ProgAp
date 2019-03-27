#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct def_empleado
{
  char Nombre [100];
  int Edad;
  int Antiguedad;
  float Sueldo;
} tipoEmpleado;

void IngresarEmpleado (int *Registrados, tipoEmpleado Empleados []);
void ImprimirEmpleados (int *Registrados, tipoEmpleado Empleados []);
void BuscarEmpleado (int *Registrados, tipoEmpleado Empleados []);
void BuscarAntiguedad (int *Registrados, tipoEmpleado Empleados []);
void BaileFortnite ();
void Dormir ();
void MayusculasEmpleado (int *Registrados, tipoEmpleado Empleados []);
void Mayusculas (tipoEmpleado *Convertidor);
void Exportar (int *Registrados, tipoEmpleado Empleados []);
void Importar (int *Registrados, tipoEmpleado Empleados []);

void Exportar (int *Registrados, tipoEmpleado Empleados [])
{
  char NombreDeArchivo [100];
  FILE *Archivo;
  system ("clear");
  printf ("\n¿Con que nombre quiere guardar el archivo? (Introduzca un nombre de máximo 100 caracteres, si lo desea incluya una extensión)\n\n");
  __fpurge (stdin);
  gets (NombreDeArchivo);
  Archivo = fopen (NombreDeArchivo, "wb");
  fwrite (Empleados, sizeof (tipoEmpleado), *Registrados, Archivo);
  fclose (Archivo);
}

void Importar (int *Registrados, tipoEmpleado Empleados [])
{
  int i, Error = 0, tamano;
  char NombreDeArchivo [100], Enter;
  FILE *Archivo;
  system ("clear");
  printf ("\n¿Que nombre tiene su archivo? (Introduzca un nombre de máximo 100 caracteres, incluya, si la tiene, la extensión de su archivo)\n\n");
  __fpurge (stdin);
  gets (NombreDeArchivo);
  Archivo = fopen (NombreDeArchivo, "rb");
  if (Archivo == NULL)
  {
    printf ("\nHubo un error de lectura, puede que el archivo que especificó no exista\n\n");
    Error = 1;
  }
  else
  {
    *Registrados = 0;
    fseek (Archivo, 0L, SEEK_END);
    tamano = ftell (Archivo);
    *Registrados = tamano / sizeof (tipoEmpleado);
    fseek (Archivo, 0L, SEEK_SET);
    fread (Empleados, sizeof (tipoEmpleado), *Registrados, Archivo);
    fclose (Archivo);
  }
  if (Error == 0)
  {
    printf ("\nParece que todo salió bien\n\n");
    printf ("Se han leido %d empleados y la base de datos actual se ha sobreescribido\n\n", *Registrados);
  }
  printf ("Ingrese un caracter para continuar...\n\n");
  __fpurge (stdin);
  scanf ("%c", &Enter);
}

int main (void)
{
  tipoEmpleado Empleados [10];
  int Registrados = 0, Repeticion = 1, Seleccion;
  do {
    system ("clear");
    printf ("\nEL BASE-DE-DATOS-DE-EMPLEADOS-TRON 3000\n\n");
    printf ("Menú principal:\n\n\n");
    printf ("1.- Registrar a un divertido empleado (Máximo 10, compre la versión premium para más) (Empleados registrados actualmente: %d)\n", Registrados);
    printf ("2.- Imprimir toda la información de todos los empleados\n");
    printf ("3.- Buscar a un empleado por su nombre\n");
    printf ("4.- Imprimir empleados con cierta antiguedad\n");
    printf ("5.- Supersalirse\n");
    printf ("6.- Báilame\n");
    printf ("7.- Buscar y convertir a MAYUSCULAS a un empleado\n");
    printf ("8.- Exportar la lista actual de empleados a un archivo\n");
    printf ("9.- Importar una lista de empleados\n\n\n");
    printf ("Escoja una opción:\n\n");
    __fpurge (stdin);
    scanf ("%d", &Seleccion);
    printf ("\n");
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
	printf ("Saliendo del programa...\n\n");
	exit (0);
	break;
      case 6:
	BaileFortnite ();
	break;
      case 7:
	MayusculasEmpleado (&Registrados, Empleados);
	break;
      case 8:
	Exportar (&Registrados, Empleados);
	break;
  case 9:
  Importar (&Registrados, Empleados);
  break;
      default:
	printf ("Ha fallado en seguir una simple instrucción.\n\n");
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
  printf ("\n");
  if (*Registrados >= 10)
    {
      printf ("Págueme la licencia de Windows antes de que lo deje ingresar más de 10 empleados...\n\n");
      printf ("Ingrese un caracter para continuar...\n\n");
      __fpurge (stdin);
      scanf ("%c", &Enter);
    }
  else
    {
      printf ("A continuación ingrese la información requerida:\n\n\n");
      printf ("Nombre del empleado: ");
      __fpurge (stdin);
      gets (Empleados [*Registrados].Nombre);
      printf ("\nEdad del empleado: ");
      __fpurge (stdin);
      scanf ("%d", &Empleados [*Registrados].Edad);
      printf ("\nAntiguedad del empleado: ");
      __fpurge (stdin);
      scanf ("%d", &Empleados [*Registrados].Antiguedad);
      printf ("\nSueldo del empleado: $");
      __fpurge (stdin);
      scanf ("%f", &Empleados [*Registrados].Sueldo);
      (*Registrados)++;
      printf ("\n\nInformación guardada con mucha pasión y éxito!\n\n");
      printf ("Ingrese un caracter para continuar...\n\n");
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
  system ("sleep 0.032");
  printf ("\n\n_____________________________________________________________");
  system ("sleep 0.032");
  for (i = 0; i < *Registrados; i++)
    {
      printf ("\n\nEmpleado #%d", i + 1);
      system ("sleep 0.032");
      printf ("\n\nNombre: ");
      puts (Empleados [i].Nombre);
      system ("sleep 0.032");
      printf ("\nEdad: %d", Empleados [i].Edad);
      system ("sleep 0.032");
      printf ("\n\nAntiguedad: %d", Empleados [i].Antiguedad);
      system ("sleep 0.032");
      printf ("\n\nSueldo: $%.2f", Empleados [i].Sueldo);
      system ("sleep 0.032");
      printf ("\n\n_____________________________________________________________");
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
  system ("sleep 0.032");
  printf ("\n\n_____________________________________________________________");
  system ("sleep 0.032");
  for (i = 0; i < *Registrados; i ++)
    {
      if ((strcmp (Buscador, Empleados [i]. Nombre)) == 0)
	{
	  printf ("\n\nEmpleado #%d", i + 1);
	  system ("sleep 0.032");
	  printf ("\n\nNombre: ");
	  puts (Empleados [i].Nombre);
	  system ("sleep 0.032");
	  printf ("\nEdad: %d", Empleados [i].Edad);
	  system ("sleep 0.032");
	  printf ("\n\nAntiguedad: %d", Empleados [i].Antiguedad);
	  system ("sleep 0.032");
	  printf ("\n\nSueldo: %f", Empleados [i].Sueldo);
	  system ("sleep 0.032");
	  printf ("\n\n_____________________________________________________________");
	  system ("sleep 0.032");
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
  system ("sleep 0.032");
  printf ("\n\n_____________________________________________________________");
  system ("sleep 0.032");
  for (i = 0; i < *Registrados; i ++)
    {
      if (Empleados [i].Antiguedad >= Buscador)
	{
	  printf ("\n\nEmpleado #%d", i + 1);
	  system ("sleep 0.032");
	  printf ("\n\nNombre: ");
	  puts (Empleados [i].Nombre);
	  system ("sleep 0.032");
	  printf ("\nEdad: %d", Empleados [i].Edad);
	  system ("sleep 0.032");
	  printf ("\n\nAntiguedad: %d", Empleados [i].Antiguedad);
	  system ("sleep 0.032");
	  printf ("\n\nSueldo: %f", Empleados [i].Sueldo);
	  system ("sleep 0.032");
	  printf ("\n\n_____________________________________________________________");
	  system ("sleep 0.032");
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

void MayusculasEmpleado (int *Registrados, tipoEmpleado Empleados[])
{
  int i, Proceso;
  char Buscador [100], Enter;
  system ("clear");
  printf ("\nPor favor ingrese el nombre del empleado a buscar:\n\n");
  __fpurge (stdin);
  gets (Buscador);
  system ("clear");
  for (i = 0; i < *Registrados; i++)
    {
      if ((strcmp (Buscador, Empleados [i].Nombre)) == 0)
	{
	  Mayusculas (&Empleados [i]);
	  Proceso = 1;
	}
    }
  if (Proceso == 1)
    {
      printf ("\nSe convirtió el nombre a mayúsculas exitosamente\n\n");
    }
  else
    printf ("\nSe ha fracasado una vez más en la vida");
  printf ("\n\nIngrese un caracter para continuar...\n\n");
  __fpurge (stdin);
  scanf ("%c", &Enter);
}

void Mayusculas (tipoEmpleado *Convertidor)
{
  int i;
  for (i = 0; i < strlen (Convertidor->Nombre); i ++)
    {
      if (Convertidor->Nombre [i] >= 97 && Convertidor->Nombre [i] <= 122)
      {
        Convertidor->Nombre [i] -= 32;
      }
    }
}
