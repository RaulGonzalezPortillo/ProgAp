#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ObtenerInformacionImagen (int *TamanoX, int *TamanoY, char NombreImagen[]);
void Negativo (int TamanoX, int TamanoY, int *Matriz[], int *NuevaMatriz []);
void Ecualizacion (int TamanoX, int TamanoY, int *Matriz[], int *NuevaMatriz []);
void Reducir (int NuevoTamanoX, int NuevoTamanoY, int *Matriz[], int *NuevaMatriz []);
void Ampliar (int TamanoX, int TamanoY, int *Matriz[], int *NuevaMatriz[]);
void GuardarImagen (int NuevoTamanoX, int NuevoTamanoY, int *NuevaMatriz[], char NombreNuevo[]);
void LimpiarArreglos (int TamanoY, int NuevoTamanoY, int *Matriz[], int *NuevaMatriz[]);

int main (void)
{
  //Declaramos las variables a utilizar
  //Las variables con el prefijo Nuevo son las que hacen referencia a la imágen tras ser procesada
  int **Matriz;
  int **NuevaMatriz;
  int Seleccion, TamanoX, TamanoY, x, y, NuevoTamanoX, NuevoTamanoY;
  char Enter, NombreImagen[100], NombreNuevo[100];
  FILE *Archivo;

  //Imprimimos un arte sencillo para recibir al usuario
  system ("clear");
  printf ("\n");
  printf ("t4GMQQQQQQQQQ004((4(44(44C4(<<..444MQQ(.      _____ _____ _____     _           \n");
  printf ("<<<<4Q4QQQQ[((4`  ...´ ~4~ <4..`444GQQQ,     |  _  |   __|     |___| |_ ___ ___ \n");
  printf ("(44444(QG4(4.   .44((44..   ..               |   __|  |  | | | |_ -|   | . | . |\n");
  printf ("44M((C(QQG4.  ´pp(((.<~~   ..  44444QQQQQ4   |__|  |_____|_|_|_|___|_|_|___|  _|\n");
  printf (".   _jWpQ[4 ´('´´        ....     4QQQQQQQQQ                               |_|  \n");
  printf ("(((4QQQQQ((44([t(4. . 444.... .   4MQQQQQQQQQ,\n");
  printf ("QQQQQQQQQ4444(tQGpGpQ4444.~.<.    4QQQQQQQQQQ4.\n");
  printf ("QQQMQ(44`   44pQQQ44444  ...      jQQQQQQQQQQQQQ4\n");
  printf ("QQQQQpp(,     GQQ$(44C  ...      .<QQQQQQQQQQQQQC\n");
  printf ("QQQQQMMQQ$(44((4((4C.   ..     ..(4QQQQ0QQQQQQQQ(\n");
  printf ("044C`````````<<((444....       4jQQQQM0QM[(44QQQ4\n");
  printf ("[(p.<44<<´. . ´4(((4.   ..    44QQMM44((((4((pQQ(\n");
  printf ("$44((´``....,((((4444..       ((((C444444C44(Q$4\n");
  printf ("t4QQQ44((<(4444((4<<  ..      .~~  ..C44<44(4(4\n");
  printf ("(44QQQQQQpt(((44.C  .       .          .44(tC,\n\n");
  //Imprimimos los créditos
  printf ("Elaboró:\n\n");
  printf ("Raúl González Portillo\n\n");
  printf ("Presione enter para continuar...\n\n");
  scanf ("%c", &Enter); //A lo largo del programa, utilizaremos este scanf para hacer pausas del tipo "Presione enter para continuar..."
  //Imprimimos los objetivos del programa
  system ("clear");
  printf ("\n");
  printf ("Este programa se creó para reforzar conocimientos sobre Archivos binarios y asignación dinámica de memoria\n\n");
  printf ("Con el podrá:\n\n");
  printf ("- Obtener el negativo de una imágen\n");
  printf ("- Ecualizar una imágen\n");
  printf ("- Reducir una imágen (a la mitad de su tamaño en cada eje)\n");
  printf ("- Ampliar una imágen (al doble de su tamaño en cada eje)\n\n");
  printf ("Presione enter para continuar...\n\n");
  scanf ("%c", &Enter);
  //Comienza el programa
  ObtenerInformacionImagen (&TamanoX, &TamanoY, NombreImagen); //Obtenemos las dimensiones y el nombre de la imágen a procesar
  Matriz = (int **) malloc (TamanoY*sizeof(int *)); //Definimos cuantos renglones tendrá la matriz
  for (y = 0; y < TamanoY; y++)
  {
    Matriz [y] = (int *) malloc (TamanoX*sizeof(int)); //Definimos cuantas columnas tendrá cada renglón
  }
  Archivo = fopen (NombreImagen, "rb"); //Abrimos la imágen como un archivo binario
  fseek (Archivo, 15L, SEEK_SET); //Nos movemos 15 bytes para saltar los metadatos
  for (y = 0; y < TamanoY; y++) //Recorremos los renglones de la matriz
  {
    for (x = 0; x < TamanoX; x++) //Recorremos las columnas de la matriz
    {
      fread (&Matriz[y][x], 1, 1, Archivo); //Leemos un byte por cada dato, ya que son de tipo unsigned char
    }
  }
  fclose (Archivo); //Cerramos la imagen
  //Imprimimos el menú principal
  system ("clear");
  printf ("\n");
  printf ("Menú principal\n\n");
  printf ("1.- Negativo de la imágen\n");
  printf ("2.- Ecualización de la imágen\n");
  printf ("3.- Reducción de la imágen\n");
  printf ("4.- Ampliación de la imágen\n\n");
  scanf ("%d", &Seleccion);
  printf ("\n");
  //Hacemos un switch en base a la selección del usuario
  switch (Seleccion)
  {
    case 1:
    NuevoTamanoX = TamanoX; //Por cada caso se determinan las dimensiones de la nueva imágen
    NuevoTamanoY = TamanoY;
    NuevaMatriz = (int **) malloc (TamanoY*sizeof(int *)); //Por cada caso se asigna memoria a la nueva matriz en base a las nuevas dimensiones
    for (y = 0; y < TamanoY; y++)
    {
      NuevaMatriz [y] = (int *) malloc (TamanoX*sizeof(int));
    }
    Negativo (TamanoX, TamanoY, Matriz, NuevaMatriz); //Por cada caso se llama a la funcion que haga el procesamiento como tal
    break;
    case 2:
    NuevoTamanoX = TamanoX;
    NuevoTamanoY = TamanoY;
    NuevaMatriz = (int **) malloc (TamanoY*sizeof(int *));
    for (y = 0; y < TamanoY; y++)
    {
      NuevaMatriz [y] = (int *) malloc (TamanoX*sizeof(int));
    }
    Ecualizacion (TamanoX, TamanoY, Matriz, NuevaMatriz);
    break;
    case 3:
    NuevoTamanoX = TamanoX / 2;
    NuevoTamanoY = TamanoY / 2;
    NuevaMatriz = (int **) malloc (NuevoTamanoY*sizeof(int *));
    for (y = 0; y < NuevoTamanoY; y++)
    {
      NuevaMatriz [y] = (int *) malloc (NuevoTamanoX*sizeof(int));
    }
    Reducir (NuevoTamanoX, NuevoTamanoY, Matriz, NuevaMatriz);
    break;
    case 4:
    NuevoTamanoX = TamanoX * 2;
    NuevoTamanoY = TamanoY * 2;
    NuevaMatriz = (int **) malloc (NuevoTamanoY*sizeof(int *));
    for (y = 0; y < NuevoTamanoY; y++)
    {
      NuevaMatriz [y] = (int *) malloc (NuevoTamanoX*sizeof(int));
    }
    Ampliar (TamanoX, TamanoY, Matriz, NuevaMatriz);
    break;
    default:
    system ("clear");
    printf ("\nHa elegido una opción invalida, saliendo del programa...\n\n");
    exit (3);
    break;
  }
  //Una vez terminado el procesamiento se muestra la interfaz de guardado
  system ("clear");
  printf ("\n");
  printf ("Imagen procesada, indique el nombre con el que se guardará\n\n");
  __fpurge (stdin);
  gets (NombreNuevo); //Leemos el nombre con el que se guardará la imágen
  printf ("\n");
  GuardarImagen (NuevoTamanoX, NuevoTamanoY, NuevaMatriz, NombreNuevo); //Llamamos a la función encargada de crear el archivo con la nueva imágen
  LimpiarArreglos (TamanoX, NuevoTamanoX, Matriz, NuevaMatriz); //Llamamos a la función encargada de liberar la memoria utilizada durante el programa
}

void ObtenerInformacionImagen (int *TamanoX, int *TamanoY, char NombreImagen[])
{
  //Declaramos variables, en estas se guardaran metadatos que usaremos pero no enviaremos de regreso
  int Maximo;
  char ValorMagico[3], Enter;
  FILE *Archivo;
  //Imprimimos interfaz de carga de imágenes
  system ("clear");
  printf ("\n");
  printf ("Ingrese el nombre del archivo que continene la imágen:\n\n");
  gets (NombreImagen); //Leemos el nombre de la imágen
  printf ("\n");
  Archivo = fopen (NombreImagen, "rb"); //Abrimos el archivo que tenga el nombre especificado
  system ("clear");
  printf ("\n");
  if (Archivo == NULL) //Indica error si no se pudo leer el archivo
  {
    printf ("Hubo un error de lectura, puede que el archivo que especificó no exista\n\n");
    printf ("Saliendo del programa...\n\n");
    exit (0);
  }
  else
  {
    fscanf (Archivo, "%c%c %d %d %d", &ValorMagico[0], &ValorMagico[1], TamanoX, TamanoY, &Maximo); //Leemos todos los metadatos
    ValorMagico[2] = '\0';
    if (strcmp (ValorMagico, "P5") != 0) //Imprime error si el valor mágico no es P5
    {
      printf ("El archivo especificado no puede ser procesado, no tiene el formato PGM\n\n");
      printf ("Saliendo del programa...\n\n");
      fclose (Archivo);
      exit (1);
    }
    if (Maximo != 255) //Imprime error si el valor máximo de luminiscencia no es 255
    {
      printf ("El archivo especificado no puede ser procesado, el valor máximo de luminiscencia no es 255\n\n");
      printf ("Saliendo del programa...\n\n");
      fclose (Archivo);
      exit (2);
    }
    printf ("Se obtuvieron los metadatos de la imágen correctamente\n\n"); //Indicamos que no hubo errores
    printf ("Presione enter para continuar...\n\n");
    scanf ("%c", &Enter);
  }
}

void Negativo (int TamanoX, int TamanoY, int *Matriz[], int *NuevaMatriz[])
{
  int x, y; //Declaramos incrementadores
  for (y = 0; y < TamanoY; y++) //Recorremos los renglones del arreglo
  {
    for (x = 0; x < TamanoX; x++) //Recorremos las columnas del arreglo
    {
      NuevaMatriz[y][x] = 255 - (Matriz[y][x]); //Por cada elemento aplica la ecuación y = x - 1
    }
  }
}

void Ecualizacion (int TamanoX, int TamanoY, int *Matriz[], int *NuevaMatriz [])
{
  //Declaramos incrementadores, variables para guardar los puntos y los elementos de la recta
  int x, y, Minimo, Maximo;
  double m, b;
  Minimo = Matriz [0][0]; //Asignamos el valor del primer elemento del arreglo tanto a mínimo como a máximo para inicializarlos
  Maximo = Matriz [0][0];
  for (y = 0; y < TamanoY; y++) //Recorremos renglones del arreglo
  {
    for (x = 0; x < TamanoX; x++) //Recorremos columnas del arreglo
    {
      if (Matriz[y][x] < Minimo) //Obtenemos el punto mínimo de x (luminiscencia original)
      {
        Minimo = Matriz[y][x];
      }
      if (Matriz[y][x] > Maximo) //Obtenemos el punto máximo de x
      {
        Maximo = Matriz[y][x];
      }
    }
  }
  m = 255 / (Maximo - Minimo); //La pendiente será el cambio de y (luminiscencia nueva) entre el cambio de x
  b = 255 - m*Maximo; //Despejamos la b de la ecuación y = mx + b e insertamos los valores de un punto
  for (y = 0; y < TamanoY; y++) //Recorremos renglones
  {
    for (x = 0; x < TamanoX; x++) //Recorremos columnas
    {
      NuevaMatriz[y][x] = Matriz[y][x]*m; //Aplicamos y = mx + b a cada elemento y lo guardamos en la nueva matriz
      NuevaMatriz[y][x] += b;
    }
  }
}

void Reducir (int NuevoTamanoX, int NuevoTamanoY, int *Matriz[], int *NuevaMatriz[])
{
  int x1, x2, y1, y2; //Declaramos un par de incrementadores por cada eje, ya que el incremento no será el mismo
  y1 = 0; //Inicializamos los valores de los renglones
  y2 = 0;
  while (y2 < NuevoTamanoY) //Recorremos renglones
  {
    x1 = 0;
    x2 = 0;
    while (x2 < NuevoTamanoX) //Recorremos columnas
    {
      NuevaMatriz[y2][x2] = Matriz[y1][x1]; //Guardamos en la nueva matriz
      x1 += 2; //Avanzamos dos columnas en la imagen original (Para saltarnos uno de cada 2 pixeles)
      x2 ++; //Avanzamos una columna en la nueva imagen
    }
    y1 += 2; //Repetimos el paso anterior pero con los renglones de ambas matrices
    y2++;
  }
}

void Ampliar (int TamanoX, int TamanoY, int *Matriz[], int *NuevaMatriz[])
{
  int x1, y1, x2, y2; //Declaramos dos incrementadores para cada eje para hacer incrementos diferentes
  y2 = 0; //Iniciamos el valor de los renglones en la nueva matriz
  for (y1 = 0; y1 < TamanoY; y1++) //Recorremos renglones
  {
    x2 = 0; //Inicializamos columnas en la nueva matriz
    for (x1 = 0; x1 < TamanoX; x1++) //Recorremos columnas
    {
      NuevaMatriz[y2][x2] = Matriz[y1][x1]; //Copiamos el valor que hay en la matriz original
      NuevaMatriz[y2+1][x2] = Matriz[y1][x1]; //Tanto al valor que le corresponde * 2 en cada eje
      NuevaMatriz[y2][x2+1] = Matriz[y1][x1]; //Así como a sus tres pixeles adyacentes
      NuevaMatriz[y2+1][x2+1] = Matriz[y1][x1];
      x2+=2; //Avanzamos dos columnas en la nueva matriz
    }
    y2+=2; //Avanzamos dos renglones en la nueva matriz
  }
}

void GuardarImagen (int NuevoTamanoX, int NuevoTamanoY, int *NuevaMatriz[], char NombreNuevo[])
{
  char Enter;
  int x, y; //Declaramos incrementadores
  FILE *Archivo; //Declaramos un archivo para crear la nueva imagen
  Archivo = fopen (NombreNuevo, "wb"); //Abrimos la nueva imagen con el nombre que nos dieron
  fprintf (Archivo, "P5 %d %d 255 ", NuevoTamanoX, NuevoTamanoY); //Imprimimos metadatos
  for (y = 0; y < NuevoTamanoY; y++) //Recorremos renglones
  {
    for (x = 0; x < NuevoTamanoX; x++) //Recorremos columnas
    {
      fwrite (&NuevaMatriz[y][x], 1, 1, Archivo); //Escribimos el valor que tengamos en el byte que sigue del archivo
    }
  }
  fclose (Archivo);
  system ("clear");
  printf ("\n");
  printf ("Se ha guardado con éxito su nueva imágen...\n\n"); //indicamos que no hubo errores
  printf ("Presione enter para salir...\n\n");
  __fpurge (stdin);
  scanf ("%c", &Enter);
}

void LimpiarArreglos (int TamanoY, int NuevoTamanoY, int *Matriz[], int *NuevaMatriz[])
{
  int x, y;
  printf ("Limpiando y saliendo...\n\n\n");
  for (y = 0; y < TamanoY; y++)
  {
    free (Matriz[y]);
  }
  free (Matriz);
  for (y = 0; y < NuevoTamanoY; y++)
  {
    free (NuevaMatriz[y]);
  }
  free (NuevaMatriz);
}
