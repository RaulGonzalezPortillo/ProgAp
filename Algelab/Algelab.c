#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void Logo (void);
void Encabezado (void);
void AnimacionSalida (void);
void Dormir (void);
void RepasarTeoria (void);
void AbrirArchivoTeoria (char *Nombre);
void ContestarPregunta (void);
void Calculadora (void);
void MultiplicarPorEscalar (int *Matriz[], int R, int C, int Escalar);
void LimpiarMatrices (int R, int **Matriz[]);
void ImprimirMatricesDeEntrada (int *Matriz1[], int R1, int C1, int *Matriz2[], int R2, int C2);
void PresioneEnterParaContinuar (void);
void SumaDeMatrices (int *Matriz1[], int R1, int C1, int *Matriz2[], int R2, int C2);
int ProductoPunto (int *Matriz1[], int R1, int C1, int *Matriz2[], int R2, int C2);
void TrazaDeUnaMatriz (int *Matriz[], int R, int C);

int main (void)
{
  int Opcion;
  srand(time(NULL));
  system ("clear");
  printf ("\n");
  printf ("Bienvenido a");
  Logo ();
  PresioneEnterParaContinuar ();
  do
  {
    Encabezado ();
    printf ("Elija una opción:\n\n");
    Dormir ();
    printf ("1.- Ir a la calculadora algebráica\n");
    Dormir ();
    printf ("2.- Repasar teoría\n");
    Dormir ();
    printf ("3.- Contestar una pregunta tipo exámen\n");
    Dormir ();
    printf ("4.- Salir del programa\n\n");
    scanf ("%d", &Opcion);
    switch (Opcion)
    {
      case 1:
      Calculadora ();
      break;
      case 2:
      RepasarTeoria ();
      break;
      case 3:
      ContestarPregunta ();
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
  system ("sleep 0.05");
}

void RepasarTeoria (void)
{
  char Nombre [100];
  while (1)
  {
    Encabezado ();
    printf ("Temas disponibles:\n\n");
    printf ("1.- Operaciones elementales (OperacionesElementales)\n");
    printf ("2.- Sistemas equivalentes (SistemasEquivalentes)\n");
    printf ("3.- Matriz del sistema (MatrizDelSistema)\n");
    printf ("\n");
    printf ("Ingrese el nombre del archivo que desea abrir, escriba 'Salir' para volver\n\n");
    __fpurge (stdin);
    gets (Nombre);
    printf ("\n");
    if (strcmp (Nombre, "Salir") == 0)
      return;
    AbrirArchivoTeoria (Nombre);
  }
}

void AbrirArchivoTeoria (char *Nombre)
{
  FILE *Archivo;
  char Impresor [400], TempNombre [100];
  strcpy (TempNombre, "Teoría/");
  strcat (TempNombre, Nombre);
  strcat (TempNombre, ".txt");
  Archivo = fopen (TempNombre, "rt");
  if (Archivo == NULL)
  {
    printf ("No se encontró el archivo\n\n");
    PresioneEnterParaContinuar ();
    return;
  }
  else
  {
    Encabezado ();
    while (fgets (Impresor, 398, Archivo) != NULL)
    {
      Impresor [strlen (Impresor) - 1] = '\0';
      puts (Impresor);
    }
    printf ("\n");
    PresioneEnterParaContinuar ();
    return;
  }
}

void ContestarPregunta (void)
{
  FILE *Archivo;
  char TempNombre [100], TempNombre2 [100], Impresor [400], Respuesta, RespuestaUsuario;
  int R = rand () % 4 + 1;
  strcpy (TempNombre, "Preguntas/");
  sprintf (TempNombre2, "%d", R);
  strcat (TempNombre, TempNombre2);
  strcat (TempNombre, ".txt");
  Archivo = fopen (TempNombre, "rt");
  Encabezado ();
  fscanf (Archivo, "%c", &Respuesta);
  while (fgets (Impresor, 398, Archivo) != NULL)
  {
    Impresor [strlen (Impresor) - 1] = '\0';
    puts (Impresor);
  }
  printf ("\n");
  printf ("Introduzca la respuesta:\n\n");
  __fpurge (stdin);
  scanf ("%c", &RespuestaUsuario);
  printf ("\n");
  if (Respuesta == RespuestaUsuario)
    printf ("¡Respuesta correcta!\n\n");
  else
    printf ("Respuesta incorrecta\n\n");
  PresioneEnterParaContinuar ();
}

void Calculadora (void)
{
  FILE *Historial;
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
    printf ("1.- Introducir una matriz o un vector\n");
    Dormir ();
    printf ("2.- Multiplicar a la matriz A por un escalar\n");
    Dormir ();
    printf ("3.- Multiplicar a la matriz B por un escalar\n");
    Dormir ();
    printf ("4.- Sumar a la matriz A con la matriz B\n");
    Dormir ();
    printf ("5.- Producto punto de vectores\n");
    Dormir ();
    printf ("6.- Comprobar la ortogonalidad entre dos vectores\n");
    Dormir ();
    printf ("7.- Traza de la matriz A\n");
    Dormir ();
    printf ("8.- Traza de la matriz B\n");
    Dormir ();
    printf ("9.- Borrar matrices ingresadas\n");
    Dormir ();
    printf ("10.- Volver\n\n");
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
        PresioneEnterParaContinuar ();
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
        PresioneEnterParaContinuar ();
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
        PresioneEnterParaContinuar ();
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
        PresioneEnterParaContinuar ();
      }
      else
      if (Matriz1 != NULL && Matriz2 != NULL)
      {
        printf ("INFO: Ya ha guardado el límite máximo de matrices\n\n");
        PresioneEnterParaContinuar ();
      }
      break;
      case 2:
      Encabezado ();
      if (Matriz1 == NULL)
      {
        printf ("INFO: No tiene una Matriz A guardada\n\n");
        PresioneEnterParaContinuar ();
      }
      else
      {
        printf ("Ingrese el escalar por el cual multiplicar a la matriz: ");
        scanf ("%d", &Escalar);
        printf ("\n");
        MultiplicarPorEscalar (Matriz1, R1, C1, Escalar);
      }
      break;
      case 3:
      Encabezado ();
      if (Matriz2 == NULL)
      {
        printf ("INFO: No tiene una Matriz B guardada\n\n");
        PresioneEnterParaContinuar ();
      }
      else
      {
        printf ("Ingrese el escalar por el cual multiplicar a la matriz: ");
        scanf ("%d", &Escalar);
        printf ("\n");
        MultiplicarPorEscalar (Matriz2, R2, C2, Escalar);
      }
      break;
      case 4:
      Encabezado ();
      if (Matriz1 == NULL || Matriz2 == NULL)
      {
        printf ("INFO: Necesita guardar dos matrices para utilizar esta función\n\n");
        PresioneEnterParaContinuar ();
      }
      else
      {
        if (R1 != R2 || C1 != C2)
        {
          printf ("INFO: Las matrices A y B deben ser del mismo orden para utilizar esta función\n\n");
          PresioneEnterParaContinuar ();
        }
        else
        SumaDeMatrices (Matriz1, R1, C1, Matriz2, R2, C2);
      }
      break;
      case 5:
      Encabezado ();
      if (Matriz1 == NULL || Matriz2 == NULL)
      {
        printf ("INFO: Necesita guardar dos vectores para utilizar esta función\n\n");
        PresioneEnterParaContinuar ();
      }
      else
      if (R1 != 1 || R2 != 1 || C1 != C2)
      {
        printf ("INFO: Necesita guardar dos vectores con la misma cantidad de elementos para utilizar esta función\n\n");
        PresioneEnterParaContinuar ();
      }
      else
      ProductoPunto (Matriz1, R1, C1, Matriz2, R2, C2);
      break;
      case 6:
      Encabezado ();
      if (Matriz1 == NULL || Matriz2 == NULL)
      {
        printf ("INFO: Necesita guardar dos vectores para utilizar esta función\n\n");
        PresioneEnterParaContinuar ();
      }
      else
      if (R1 != 1 || R2 != 1 || C1 != C2)
      {
        printf ("INFO: Necesita guardar dos vectores con la misma cantidad de elementos para utilizar esta función\n\n");
        PresioneEnterParaContinuar ();
      }
      else
      {
        Historial = fopen ("Historial.txt", "at");
        if ((ProductoPunto (Matriz1, R1, C1, Matriz2, R2, C2)) == 0)
        {
          Encabezado ();
          printf ("Los vectores son ortogonales\n\n");
          fprintf (Historial, "Los vectores son ortogonales\n\n");
        }
        else
        {
          Encabezado ();
          printf ("Los vectores no son ortogonales\n\n");
          fprintf (Historial, "Los vectores no son ortogonales\n\n\n");
        }
        PresioneEnterParaContinuar ();
        fclose (Historial);
      }
      break;
      case 7:
      Encabezado ();
      if (Matriz1 == NULL)
      {
        printf ("INFO: No tiene una Matriz A guardada\n\n");
        PresioneEnterParaContinuar ();
      }
      else
      {
        if (R1 != C1)
        {
          printf ("INFO: Necesita guardar una matriz cuadrada para utilizar esta función\n\n");
          PresioneEnterParaContinuar ();
        }
        else
        {
          TrazaDeUnaMatriz (Matriz1, R1, C1);
        }
      }
      break;
      case 8:
      Encabezado ();
      if (Matriz2 == NULL)
      {
        printf ("INFO: No tiene una Matriz B guardada\n\n");
        PresioneEnterParaContinuar ();
      }
      else
      {
        if (R2 != C2)
        {
          printf ("INFO: Necesita guardar una matriz cuadrada para utilizar esta función\n\n");
          PresioneEnterParaContinuar ();
        }
        else
        {
          TrazaDeUnaMatriz (Matriz2, R2, C2);
        }
      }
      break;
      case 9:
      printf ("\n");
      printf ("Liberando memoria...\n\n");
      system ("sleep 0.75");
      if (Matriz1 != NULL)
      LimpiarMatrices (R1, &Matriz1);
      if (Matriz2 != NULL)
      LimpiarMatrices (R2, &Matriz2);
      break;
      case 10:
      printf ("\n");
      printf ("Liberando memoria...\n\n");
      system ("sleep 0.75");
      if (Matriz1 != NULL)
      LimpiarMatrices (R1, &Matriz1);
      if (Matriz2 != NULL)
      LimpiarMatrices (R2, &Matriz2);
      return;
      break;
      default:
      break;
    }
  }
}

void MultiplicarPorEscalar (int *Matriz[], int R, int C, int Escalar)
{
  FILE *Historial;
  int Resultado, i, j;
  ImprimirMatricesDeEntrada (Matriz, R, C, NULL, 0, 0);
  Historial = fopen ("Historial.txt", "at");
  fprintf (Historial, "Procedimiento: Multiplicar por escalar (%d)\n\n", Escalar);
  printf ("El resultado es:\n\n");
  fprintf (Historial, "Matriz resultante:\n\n");
  for (i = 0; i < R; i++)
  {
    printf ("(");
    fprintf (Historial, "(");
    for (j = 0; j < C; j++)
    {
      Resultado = Matriz [i][j] * Escalar;
      printf ("\t%d", Resultado);
      fprintf (Historial, "\t%d", Resultado);
    }
    printf ("\t)\n");
    fprintf (Historial, "\t)\n");
  }
  printf ("\n");
  fprintf (Historial, "\n\n");
  PresioneEnterParaContinuar ();
  fclose (Historial);
}

void LimpiarMatrices (int R, int **Matriz[])
{
  int **TempMatriz;
  TempMatriz = *Matriz;
  int i;
  for (i = 0; i < R; i++)
  {
    free (TempMatriz[i]);
  }
  free (TempMatriz);
  *Matriz = NULL;
}

void ImprimirMatricesDeEntrada (int *Matriz1[], int R1, int C1, int *Matriz2[], int R2, int C2)
{
  int i, j;
  FILE *Historial;
  Historial = fopen ("Historial.txt", "at");
  if (Matriz2 == NULL)
  {
    fprintf (Historial, "Entrada:\n\n");
  }
  else
  fprintf (Historial, "Entrada A:\n\n");
  for (i = 0; i < R1; i++)
  {
    fprintf (Historial, "(");
    for (j = 0; j < C1; j++)
    {
      fprintf (Historial, "\t%d", Matriz1 [i][j]);
    }
    fprintf (Historial, "\t)\n");
  }
  fprintf (Historial, "\n");
  if (Matriz2 != NULL)
  {
    fprintf (Historial, "Entrada B:\n\n");
    for (i = 0; i < R2; i++)
    {
      fprintf (Historial, "(");
      for (j = 0; j < C2; j++)
      {
        fprintf (Historial, "\t%d", Matriz2 [i][j]);
      }
      fprintf (Historial, "\t)\n");
    }
    fprintf (Historial, "\n");
  }
  fclose (Historial);
}

void PresioneEnterParaContinuar (void)
{
  printf ("Presione Enter para continuar...\n\n");
  __fpurge (stdin);
  getchar ();
}

void SumaDeMatrices (int *Matriz1[], int R1, int C1, int *Matriz2[], int R2, int C2)
{
  FILE *Historial;
  int Resultado, i, j;
  ImprimirMatricesDeEntrada (Matriz1, R1, C1, Matriz2, R2, C2);
  Historial = fopen ("Historial.txt", "at");
  fprintf (Historial, "Procedimiento: Suma de matrices\n\n");
  printf ("El resultado es:\n\n");
  fprintf (Historial, "Matriz resultante:\n\n");
  for (i = 0; i < R1; i++)
  {
    printf ("(");
    fprintf (Historial, "(");
    for (j = 0; j < C1; j++)
    {
      Resultado = Matriz1 [i][j] + Matriz2 [i][j];
      printf ("\t%d", Resultado);
      fprintf (Historial, "\t%d", Resultado);
    }
    printf ("\t)\n");
    fprintf (Historial, "\t)\n");
  }
  printf ("\n");
  fprintf (Historial, "\n\n");
  PresioneEnterParaContinuar ();
  fclose (Historial);
}

int ProductoPunto (int *Matriz1[], int R1, int C1, int *Matriz2[], int R2, int C2)
{
  FILE *Historial;
  int Resultado = 0, i;
  ImprimirMatricesDeEntrada (Matriz1, R1, C1, Matriz2, R2, C2);
  Historial = fopen ("Historial.txt", "at");
  fprintf (Historial, "Procedimiento: Producto punto de vectores\n\n");
  printf ("El resultado del producto punto es:\n\n");
  fprintf (Historial, "Escalar resultante:\n\n");
  for (i = 0; i < C1; i++)
  Resultado += (Matriz1 [0][i] * Matriz2 [0][i]);
  printf ("%d\n\n", Resultado);
  fprintf (Historial, "%d\n\n\n", Resultado);
  PresioneEnterParaContinuar ();
  fclose (Historial);
  return Resultado;
}

void TrazaDeUnaMatriz (int *Matriz[], int R, int C)
{
  FILE *Historial;
  int Resultado, i;
  ImprimirMatricesDeEntrada (Matriz, R, C, NULL, 0, 0);
  Historial = fopen ("Historial.txt", "at");
  fprintf (Historial, "Procedimiento: Traza de una matriz\n\n");
  printf ("El resultado es:\n\n");
  fprintf (Historial, "Escalar resultante:\n\n");
  for (i = 0; i < R; i++)
  {
    Resultado += Matriz [i][i];
  }
  printf ("%d\n\n", Resultado);
  fprintf (Historial, "%d\n\n\n", Resultado);
  PresioneEnterParaContinuar ();
  fclose (Historial);
}
