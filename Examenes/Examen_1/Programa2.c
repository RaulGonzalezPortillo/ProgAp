#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct def_Documento
{
  char Nombre[100];
  int ID, Paginas, Estado, PaginasImpresas; //Estado 1 = Pendiente, Estado 2 = Imprimiendo
  struct def_Documento *Sig;
} TipoDocumento;

void Inserta (TipoDocumento **Inicio, int *SiguienteID);
void Imprime (TipoDocumento *Inicio);
void Eliminar (TipoDocumento **Inicio, int IDAEliminar);
void Avanzar (TipoDocumento **Inicio);
void Guardar (TipoDocumento *Inicio, int SiguienteID);
void Leer (TipoDocumento **Inicio, int *SiguienteID);

void Leer (TipoDocumento **Inicio, int *SiguienteID)
{
  int i;
  FILE *Archivo;
  char Nombre [100], Enter;
  TipoDocumento *Temp, *Temp2;
  Temp = (TipoDocumento *) malloc (sizeof (TipoDocumento));
  Temp2 = (TipoDocumento *) malloc (sizeof (TipoDocumento));

  printf ("Escriba el nombre con el que guardó su archivo:\n\n");
  __fpurge (stdin);
  gets (Nombre);
  Archivo = fopen (Nombre, "rt");
  fscanf (Archivo, "%d\n", SiguienteID);
  Temp = Inicio;
  for (i = 0; i < (*SiguienteID) ; i++)
    {
      fgets (Temp2 -> Nombre, 100, Archivo);
      fscanf (Archivo, "%d\n", &Temp2 -> ID);
      fscanf (Archivo, "%d\n", &Temp2 -> Paginas);
      fscanf (Archivo, "%d\n", &Temp2 -> Estado);
      fscanf (Archivo, "%d\n", &Temp2 -> PaginasImpresas);
      printf ("Entra a inserta\n");


      /*if (*Inicio != NULL)
	{
	  printf ("entra if\n");
	  Temp2 = *Inicio;
	  printf ("antes del while\n");
	  while (Temp2 -> Sig != NULL)
	    Temp2 = Temp2 -> Sig;
	  printf ("paso el while\n");
	  Temp2 -> Sig = Temp;
	  printf ("paso la igualacion\n");
	}
      else
	{
	  printf ("Entra else\n");
	  *Inicio = Temp;
	  }*/
      /*
      printf ("Presione enter para continuar\n\n");
      __fpurge (stdin);
      scanf ("%c", &Enter);

      
      printf ("Sale\n");
      Temp2 = Temp2 -> Sig;*/
      Temp = Temp2;
      Temp = Temp->Sig;
    }
  fclose (Archivo);
}

int main (void)
{
  int Seleccion, SiguienteID = 1, IDAEliminar;
  char Enter;
  TipoDocumento *Inicio;
  Inicio = (TipoDocumento *) malloc (sizeof (TipoDocumento));
  Inicio = NULL;
  do
    {
      system ("clear");
      printf ("\n");
      printf ("1.- Introducir documento a la cola de impresión\n\n");
      printf ("2.- Listar trabajos en la cola de impresión\n\n");
      printf ("3.- Eliminar trabajo de la cola de impresión\n\n");
      printf ("4.- Imprimir documento\n\n");
      printf ("5.- Guardar cola en archivo\n\n");
      printf ("6.- Leer cola de archivo\n\n");
      printf ("7.- Salir\n\n");
      scanf ("%d", &Seleccion);
      printf ("\n");
      switch (Seleccion)
	{
	case 1:
	  Inserta (&Inicio, &SiguienteID);
	  break;
	case 2:
	  Imprime (Inicio);
	  break;
	case 3:
	  printf ("Introduzca el ID del elemento a eliminar\n\n");
	  scanf ("%d", &IDAEliminar);
	  printf ("\n");
	  Eliminar (&Inicio, IDAEliminar);
	  break;
	case 4:
	  Avanzar (&Inicio);
	  break;
	case 5:
	  Guardar (Inicio, SiguienteID);
	  break;
	case 6:
	  Leer (&Inicio, &SiguienteID);
	  break;
	case 7:
	  break;
	default:
	  printf ("Ha elegido una opción invalida\n\n");
	  printf ("Presione enter para continuar\n\n");
	  __fpurge (stdin);
	  scanf ("%c", &Enter);
	  break;
	}
    }
  while (Seleccion != 7);
  printf ("\n");
}

void Inserta (TipoDocumento **Inicio, int *SiguienteID)
{
  char Enter;
  int Error = 0;
  TipoDocumento *Nuevo, *Temp;
  Nuevo = (TipoDocumento *) malloc (sizeof (TipoDocumento));
  Temp = (TipoDocumento *) malloc (sizeof (TipoDocumento));
  Nuevo -> Sig = NULL;
  Nuevo -> ID = *SiguienteID;
  Nuevo -> Estado = 1;
  Nuevo -> PaginasImpresas = 0;
  printf ("Introduzca el nombre de su archivo:\n\n");
  __fpurge (stdin);
  if ((gets (Nuevo -> Nombre)) == 0)
    Error = 1;
  printf ("\n");
  printf ("Introduzca el número de páginas de su archivo:\n\n");
  if ((scanf ("%d", &Nuevo -> Paginas)) == 0)
    Error = 2;
  printf ("\n");
  if (Error == 1)
    printf ("Hubo un error al leer el nombre de su archivo\n\n");
  if (Error == 2)
    printf ("Hubo un error al leer el número de páginas de su archivo\n\n");
  if (Error == 0)
    {
      (*SiguienteID)++;
      if (*Inicio != NULL)
	{
	  Temp = *Inicio;
	  while (Temp -> Sig != NULL)
	    Temp = Temp -> Sig;
	  Temp -> Sig = Nuevo;
	}
      else
	*Inicio = Nuevo;
    }
  printf ("Presione enter para continuar\n\n");
  __fpurge (stdin);
  scanf ("%c", &Enter);
}


void Imprime (TipoDocumento *Inicio)
{
  int i;
  char Enter;
  TipoDocumento *Temp, *Temp2;
  Temp = (TipoDocumento *) malloc (sizeof (TipoDocumento));
  Temp2 = (TipoDocumento *) malloc (sizeof (TipoDocumento));
  Temp = Inicio;
  if (Temp == NULL)
    {
      printf ("Parece que la lista estaba vacía...");
    }
  else
    {
      while (Temp -> Sig != NULL)
	{
	  Temp = Temp -> Sig;
	}
      Temp2 = Inicio;
      while (Temp != Inicio)
	{
	  printf ("%d: ", Temp -> ID);
	  for (i = 0; i < strlen (Temp -> Nombre); i++)
	    printf ("%c", Temp -> Nombre [i]);
	  printf (", %d páginas, ", Temp -> Paginas);
	  if (Temp -> Estado == 1)
	    printf ("espera");
	  if (Temp -> Estado == 2)
	    printf ("imprimiendo, %d páginas impresas", Temp -> PaginasImpresas);
	  printf ("\n");
	  Temp2 = Inicio;
	  while (Temp2 != NULL && Temp2 -> Sig != Temp)
	    {
	      Temp2 = Temp2 -> Sig;
	    }
	  Temp = Temp2;
	}
      printf ("%d: ", Temp -> ID);
      for (i = 0; i < strlen (Temp -> Nombre); i++)
	printf ("%c", Temp -> Nombre [i]);
      printf (", %d páginas, ", Temp -> Paginas);
      if (Temp -> Estado == 1)
	printf ("espera");
      if (Temp -> Estado == 2)
	printf ("imprimiendo, %d páginas impresas", Temp -> PaginasImpresas);
    }
  printf ("\n\n");
  printf ("Presione enter para continuar\n\n");
  __fpurge (stdin);
  scanf ("%c", &Enter);
}

void Eliminar (TipoDocumento **Inicio, int IDAEliminar)
{
  char Enter;
  TipoDocumento *Temp, *Temp2, *TempAnt, *TempSig;
  Temp = (TipoDocumento *) malloc (sizeof (TipoDocumento));
  Temp2 = (TipoDocumento *) malloc (sizeof (TipoDocumento));
  TempAnt = (TipoDocumento *) malloc (sizeof (TipoDocumento));
  TempSig = (TipoDocumento *) malloc (sizeof (TipoDocumento));
  Temp = *Inicio;
  if (Temp == NULL)
    {
      printf ("Parece que la lista estaba vacía...\n\n");
    }
  else
    {
      while (Temp != NULL && Temp -> ID != IDAEliminar)
	{
	  Temp = Temp -> Sig;
	}
      if (Temp == NULL)
	{
	  printf ("No se encontró el elemento en la lista...\n\n");
	}
      else
	{
	  TempAnt = *Inicio;
	  TempSig = *Inicio;
	  while (TempAnt != NULL && TempAnt -> Sig != Temp) //Recorremos hasta dejar a TempAnt un lugar antes de Temp
	    {
	      TempAnt = TempAnt -> Sig; //Si TempAnt se va al NULL, Temp esta en el principio
	    }
	  while (TempSig != NULL && Temp -> Sig != TempSig) //Recorremos hasta dejar a TempSig un lugar despues de Temp
	    {
	      TempSig = TempSig -> Sig; //Si TempSig se va al NULL, Temp esta en el final
	    }
	  if (TempAnt == NULL && TempSig != NULL) //Temp esta al principio, borramos el principio
	    {
	      *Inicio = (*Inicio) -> Sig;
	      free (Temp);
	    }
	  if (TempSig == NULL && TempAnt != NULL) //Temp esta al final, borramos el final
	    {
	      TempAnt -> Sig = NULL;
	      free (Temp);
	    }
	  if (TempAnt == NULL && TempSig == NULL) //Solo hay un elemento en la lista, así que borramos la lista
	    {
	      *Inicio = NULL;
	      free (Temp);
	    }
	  if (TempAnt != NULL && TempSig != NULL) //Temp esta en medio de la lista, borramos temp
	    {
	      TempAnt -> Sig = TempSig;
	      free (Temp);
	    }
	}
    }
  printf ("Presione enter para continuar\n\n");
  __fpurge (stdin);
  scanf ("%c", &Enter);
}

void Avanzar (TipoDocumento **Inicio)
{
  int i, Imprimiendo = 0, Elimino = 0;
  char Enter;
  TipoDocumento *Temp, *TempSig;
  Temp = (TipoDocumento *) malloc (sizeof (TipoDocumento));
  TempSig = (TipoDocumento *) malloc (sizeof (TipoDocumento));
  Temp = *Inicio;
  while (Temp != NULL)
    {
      TempSig = Temp -> Sig;
      if (Temp -> Estado == 2)
	{
	  if (Temp -> PaginasImpresas == Temp -> Paginas)
	    {
	      Eliminar (Inicio, Temp -> ID);
	      Elimino = 1;
	    }
	  else
	    {
	      (Temp -> PaginasImpresas)++;
	    }
	  Imprimiendo = 1;
	}
      if (Temp -> Estado == 1 && Imprimiendo == 0)
	{
	  Temp -> Estado = 2;
	  Imprimiendo = 1;
	}	
      Temp = TempSig;
    }
  if (Elimino == 0)
    {
      printf ("Presione enter para continuar\n\n");
      __fpurge (stdin);
      scanf ("%c", &Enter);
    }
}

void Guardar (TipoDocumento *Inicio, int SiguienteID)
{
  int i;
  FILE *Archivo;
  char Nombre [100];
  TipoDocumento *Temp;
  Temp = (TipoDocumento *) malloc (sizeof (TipoDocumento));
  printf ("Escoja un nombre para su nuevo archivo:\n\n");
  __fpurge (stdin);
  gets (Nombre);
  Archivo = fopen (Nombre, "wt");
  fprintf (Archivo, "%d\n", SiguienteID);
  Temp = Inicio;
  for (i = 0; i < SiguienteID - 1; i++)
    {
      fputs (Temp -> Nombre, Archivo);
      fprintf (Archivo, "\n");
      fprintf (Archivo, "%d\n", Temp -> ID);
      fprintf (Archivo, "%d\n", Temp -> Paginas);
      fprintf (Archivo, "%d\n", Temp -> Estado);
      fprintf (Archivo, "%d\n", Temp -> PaginasImpresas);
      Temp = Temp -> Sig;
    }
  fclose (Archivo);
}
