/****************************************************************
 *								*
 * Archivo:	state_mach1.c					*
 * Descripcion: Codigo Fuente para implementar el programa	*
 *		de maquina de estados.			 	*
 *								*
 ****************************************************************/
//Coment

/*************** ARCHIVOS DE INCLUSION ***************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tables.h"
#include <time.h>


/*************** VARIABLES GLOBALES ***************/
EVENT event;
int state;
char buf[BUFFER];
char Parametro[10],NumCuenta[20],Bitacora[100];
// Parametro -> Copia argumento de terminal "-c" para verificar si es admin o no para CargarBase.
char Usuario[100],Password[100], NewPassword[100]; //NewPassword -> Utilizada para cambiar la contraseña.
int Opcion=0,Login=0,Leido=0,Dinero;
// Opcion -> Switch Menú Admin. // Login -> Permite Entrar al usuario e identificar si es la primera ejecución.
// Leido-> Verifica si la carga de archivo se hizo, para no cargar más elementos en las lista dinámica.
long long int Saldo,Cuenta;
TipoLista *Inicio=NULL;
//Las demás variables globales son utilizadas a lo largo del programa.

/*************** PROTOTIPOS DE FUNCION ***************/
void initialise(void);
void getevent(void);

int Creditos (void);
int CargarBase (void);
int Login_Cajero (void);
int Registro (void);
int Imprimir (void);
int GuardarUsuarios (void);
int SolicitarInfo_BuscarCoincidencia_SesionIniciada (void);
int MsgIngresarDinero (void);
int MsgRetirarDinero (void);
int MostrarSaldo_MsgMenu (void);
int MostrarHistorial_MsgMenu (void);
int MsgCambiarPassword (void);
int MsgSalir_LimpiarLista (void);
int Msg_Espera (void);
int MsgMenu (void);
int SumarDinero_ActualizarHistorial_MsgMenu (void);
int PedirCantidad_SaldoSuficiente (void);
int PedirPassword (void);
int VolverAPedirPassword_Coinciden (void);
int SesionFallida (void);
int MsgSaldoInsuficiente_MsgMenu (void);
int MsgRetiroExitoso_RestarSaldo_ActualizarHistorial_MsgMenu (void);
int MsgErrorCambioPassword_MsgMenu (void);
int MsgPasswordCambiada_ActualizarPassword_MsgMenu (void);
int Borrar_Lista(void);
int ActualizarRegistro (void);
int ActualizarCuentaHabiente(void);
int nul(void);


/*************** FUNCION PRINCIPAL ***************/
int main(int argc, char **argv)
{
  int actx, auxx, outcome;
  system("clear");
  if(argc!=1 && argc!=2)
    {
      printf("Insertó parámetros de más, intente de nuevo.\n");
      exit(0);
    }
  else
    {
      if(argc==1)
	{
	  Creditos();
	  system("clear");
	  CargarBase();
	  initialise();

	  while (1) {    /* loop infinito para la MFE */
	    CargarBase();
	    getevent(); // leer el evento

	    for ((actx = state_table[state].start);(action_table[actx].event != event.etype) && (actx < state_table[state].end);actx++)
	      ;
	    outcome = (*(action_table[actx].action))();
	    if(action_table[actx].moreacts == -1)
	      state = action_table[actx].nextstate;
	    else {
	      auxx = action_table[actx].moreacts + outcome;
	      while (auxx != -1){
		outcome = (*(aux_table[auxx].action))();
		if (aux_table[auxx].moreacts == -1 ){
		  state = aux_table[auxx].nextstate;
		  auxx = -1;
		}
		else
		  auxx = aux_table[auxx].moreacts + outcome;

	      }
	    }
	  }
	}
      if(argc==2 && (strcmp(argv[1],"-c"))==0)
	{
	  strcpy(Parametro,argv[1]);
	  CargarBase();
	  do
	    {
	      system("clear");
	      printf("Bienvenido al módulo de administrador\n");
	      printf("Menú:\n");
	      printf("1.- Dar de alta cuentahabientes\n");
	      printf("2.- Salir y Guardar Cambios\n");
	      printf("Ingrese la opción que desea realizar\n ");
	      scanf(" %d", &Opcion);
	      system("clear");
	      switch(Opcion)
		{
		case 1:
		  Registro();
		  break;
		case 2:
		  GuardarUsuarios();
		  printf("Se han guardado los datos correctamente\n");
		  printf("Saliendo del programa...\n");
		  Borrar_Lista();
		  exit(0);
		  break;
		default:
		  printf("Opción Inválida\n");
		  break;
		}
	      printf("Presione Enter para continuar...\n");
	      __fpurge(stdin);
	      getchar();		  
	    }while(Opcion!=2);
	}
      else
	{
	  printf("Opción inválida, intente de nuevo.\n");
	  printf("Modo Admin: $./practica3.c -c.\n");
	  exit(0);
	}
    }
}

void initialise(void)
{
  state = 0;
  Msg_Espera();
}

void getevent(void)
{
  char *ptmp;
  ptmp = &buf[2];

#ifdef DEBUG
  printf("wait event \n");
#endif
  __fpurge(stdin);
  gets(buf);
  switch (buf[0])
    {
    case 'I' :
      event.etype=ENTRADA_I;
      break;
    case 'i' :
      event.etype=ENTRADA_i;
      break;
    case 'R' :
      event.etype=ENTRADA_R;
      break;
    case 'C':
      event.etype=ENTRADA_C;
      break;
    case 'M':
      event.etype=ENTRADA_M;
      break;
    case 'P':
      event.etype=ENTRADA_P;
      break;
    case 'Q':
      event.etype=ENTRADA_Q;
      break;
    case '!':
      event.etype=ENTRADA_Admiracion;
      break;
    case 'd':
      event.etype=ENTRADA_d;
      break;
    case '#':
      event.etype=ENTRADA_Gato;
      break;
    case 'D':
      event.etype=ENTRADA_D;
      break;
    case '$':
      event.etype=ENTRADA_Dinero;
      break;
    case 'Z':
      event.etype=ENTRADA_Z;
      break;
    case 'p':
      event.etype=ENTRADA_p;
      break;
    default:
      event.etype=-1;
      break;

    }//switch
}// getevent


/* FUNCIONES DE IMPLEMENTACION */

int Creditos(void)
{
  system("clear");
  printf("Desarrollado por:\n");
  printf("César Mauricio Arellano Velásquez\n");
  printf("Raúl González Portillo\n");
  printf("Allan Jair Escamilla Hernández\n\n");
  printf("Presione Enter para continuar...\n");
  __fpurge(stdin);
  getchar();
  system("clear");
  printf("Objetivo principal del programa:\n");
  printf("Este programa pretende simular un cajero automático convencional,\n");
  printf("a través del método de máquinas de estados.\n");
}

int CargarBase(void)
{
  FILE *Archivo;
  TipoLista *Nuevo,*temp;
  char User[100];
  Archivo = fopen("CuentaHabiente.txt","rt");
  if(Archivo==NULL && (strcmp(Parametro,"-c"))==0)
    {
      printf("Se ha detectado que es la primera ejecución del programa\n");
      printf("Presione Enter para crear los archivo necesarios...\n");
      __fpurge(stdin);
      getchar();
      strcpy(NumCuenta,"2640812340");
      Login=1;
      Registro();
      printf("Presione Enter para continuar...\n");
      __fpurge(stdin);
      getchar();
    }
  else
    {
      if(Archivo==NULL)
	{
	  printf("Se ha detectado que es la primera ejecución del programa,\ndebido a que no existen los archivos necesarios para funcionar.\n");
	  printf("Para continuar es necesario acceder al módulo de administrador.\n");
	  printf("Saliendo del programa...\n");
	  exit(0);
	}
      else
	{
	  if(Leido==0)
	    {
	      while(fscanf(Archivo," %[^\n]", User)==1)
		{
		  Nuevo = (TipoLista *)malloc(sizeof(TipoLista));
		  strcpy(Nuevo -> Usuario, User);
		  fscanf(Archivo, " %[^\n]", Nuevo -> Password);
		  fscanf(Archivo, " %[^\n]", Nuevo -> NumCuenta);
		  fscanf(Archivo, " %lld", &Nuevo -> Saldo);
		  Nuevo -> sig = NULL;
		  if (Inicio != NULL)
		    {
		      temp = Inicio;
		      while (temp -> sig != NULL)
			temp = temp -> sig;
		      temp -> sig = Nuevo;
		    }
		  else
		    {
		      Inicio = Nuevo;
		    }
		  Cuenta = atoll(Nuevo->NumCuenta);
		  Cuenta += 1;
		  Leido=1;
		}
	      fclose(Archivo);
	    }
	}
    }
}

int Login_Cajero(void)
{
  TipoLista *temp;
  temp=Inicio;
  while(temp != NULL)
    {
      if(strcmp(Usuario,temp->Usuario)==0 && strcmp(Password,temp->Password)==0)
	{
	  Saldo=temp->Saldo;
	  Login=1;
	  strcpy(NumCuenta,temp->NumCuenta);
	  Cuenta-=1;
	}
      temp = temp-> sig;
    }
}

int Registro (void)
{
  system("clear");
  TipoLista *Nuevo, *temp;
  temp=Inicio;
  Nuevo = (TipoLista *)malloc(sizeof(TipoLista));
  printf("Ingrese nombre del cuentahabiente\n");
  scanf(" %[^\n]",Nuevo->Usuario);
  printf("Ingrese contraseña del cuentahabiente\n");
  scanf(" %[^\n]",Nuevo->Password);
  Nuevo->Saldo=0;
  if(Login==1)
    {
      strcpy(Nuevo->NumCuenta,NumCuenta);
      Cuenta = atoll(Nuevo->NumCuenta);
      Login=0;
    }
  else
    sprintf(Nuevo->NumCuenta, "%lld", Cuenta);
  printf("El número de cuenta generado es: %s\n",Nuevo->NumCuenta); 
  Cuenta+=1;
  Nuevo->sig=NULL;
  if (Inicio != NULL)
    {
      temp = Inicio;
      while (temp -> sig != NULL)
	temp = temp -> sig;
      temp -> sig = Nuevo;
    }
  else
    {
      Inicio = Nuevo;
    }
}

int GuardarUsuarios (void)
{
  TipoLista *temp;
  FILE *Archivo;
  temp=Inicio;
  Archivo = fopen("CuentaHabiente.txt","wt");
  while(temp!=NULL)
    {
      fprintf(Archivo,"%s\n",temp->Usuario);
      fprintf(Archivo,"%s\n",temp->Password);
      fprintf(Archivo,"%s\n",temp->NumCuenta);
      fprintf(Archivo,"%lld\n",temp->Saldo);
      temp=temp->sig;
    }
  fclose(Archivo);
}

int SolicitarInfo_BuscarCoincidencia_SesionIniciada (void)
{
  system("clear");
  printf("Por favor ingrese sus datos para entrar a su cuenta:\n");
  printf("Usuario: ");
  scanf (" %[^\n]", Usuario);
  printf("Contraseña: ");
  scanf (" %[^\n]", Password);
  printf("Verificando...\n");
  system("sleep 0.5");
  Login_Cajero();
  system("clear");
  if(Login==1)
    {
      printf("Sesión Iniciada Exitosamente\n\n");
      system("sleep 0.6");
      return 1; 
    }
  else
    return 0;
}

int MsgIngresarDinero (void)
{
  system("clear");
  printf("Accion: Ingresar Dinero\n\n");
  printf("Ingresa Dinero con d\n");
  printf("Cancelar acción con !\n\n");
  printf("Opcion: ");
}

int MsgRetirarDinero (void)
{
  system("clear");
  printf("Accion: Retirar Dinero\n\n");
  printf("Retirar Dinero con D\n");
  printf("Cancelar acción con #\n\n");
  printf("Opcion: ");
}

int MostrarSaldo_MsgMenu (void)
{
  system("clear");
  printf("Accion: Mostrar Saldo\n\n");
  printf("Su saldo actual es de: $%lld\n",Saldo);
  printf("Presione Enter para continuar...\n");
  __fpurge(stdin);
  getchar();
  MsgMenu();
}

int MostrarHistorial_MsgMenu (void)
{
  FILE *Archivo;
  char Temp[100];
  system("clear");
  strcpy(Temp,"Cliente_");
  strcat(Temp,NumCuenta);
  strcat(Temp,".txt");
  printf("Accion: Mostrar Movimientos.\n\n");
  printf("Historial de Movimientos:\n");
  Archivo = fopen(Temp,"rd");
  while(fgets(Temp,99,Archivo)!=NULL)
    {
      Temp[strlen(Temp)-1]='\0';
      puts(Temp);
    }
  fclose(Archivo);
  printf("Presione Enter para continuar...\n");
  __fpurge(stdin);
  getchar();
  MsgMenu();
}

int MsgCambiarPassword (void)
{
  system("clear");
  printf("Accion: Cambiar Contraseña\n\n");
  printf("Cambiar Contraseña con Z\n");
  printf("Cancelar Acción con $\n");
  printf("Opción: ");
}

int MsgSalir_LimpiarLista (void)
{
  printf("\nSaliendo del Menú...\n");
  system("sleep 1");
  GuardarUsuarios();
  Borrar_Lista();
  Leido=0;
  Login=0;
  Msg_Espera();
}

int Msg_Espera (void)
{
  system("clear");
  printf("Bienvenido a Cromit Inc.\n");
  printf("Por favor ingrese I para continuar\n");
}

int MsgMenu (void)
{
  system("clear");
  printf("Bienvenido %s al menú de acciones:\n\n",Usuario);
  printf("1.- Ingresar dinero, ingrese i\n");
  printf("2.- Retirar dinero, ingrese R\n");
  printf("3.- Mostrar Saldo, ingrese C\n");
  printf("4.- Mostrar historial, ingrese M\n");
  printf("5.- Cambiar Contraseña, ingrese P\n");
  printf("6.- Salir del menú, ingrese Q\n\n");
  printf("Opcion: ");
}

int SumarDinero_ActualizarHistorial_MsgMenu (void)
{
  TipoLista *temp;
  time_t rawtime;
  char SaldoActual[100];
  struct tm *timeinfo;
  time(&rawtime);
  timeinfo = localtime(&rawtime);
  system("clear");
  temp=Inicio;
  printf("Ingresa el monto a ingresar: ");
  scanf(" %d",&Dinero);
  while(temp!=NULL)
    {
      if((strcmp(Usuario,temp->Usuario))==0)
	{
	  temp->Saldo+=Dinero;	  
	  Saldo=temp->Saldo;
	  strftime(Bitacora,200,"Fecha/Hora: %d/%m/%Y - %H:%M:%S",timeinfo);
	  strcat(Bitacora,", Movimiento: Ingresar Dinero, Monto Ingresado: ");
	  sprintf(SaldoActual,"%d",Dinero);
          strcat(Bitacora,SaldoActual);
          strcat(Bitacora,", Saldo Actual: ");
          sprintf(SaldoActual,"%lld",temp->Saldo);
          strcat(Bitacora,SaldoActual);
	}
      temp=temp->sig;
    }
  ActualizarRegistro();
  MsgMenu();
}

int PedirCantidad_SaldoSuficiente (void)
{
  TipoLista *temp;
  time_t rawtime;
  char SaldoActual[100];
  struct tm *timeinfo;
  time(&rawtime);
  timeinfo = localtime(&rawtime);
  temp=Inicio;
  system("clear");
  printf("Ingresa el monto a retirar: ");
  scanf(" %d",&Dinero);
  while(temp!=NULL)
    {
      if((strcmp(Usuario,temp->Usuario))==0)
	{
	  if(temp->Saldo >=Dinero)
	    {
	      temp->Saldo-=Dinero;
	      Saldo=temp->Saldo;
	      strftime(Bitacora,200,"Fecha/Hora: %d/%m/%Y - %H:%M:%S",timeinfo);
	      strcat(Bitacora,", Movimiento: Retirar Dinero, Monto retirado: ");
	      sprintf(SaldoActual,"%d",Dinero);
	      strcat(Bitacora,SaldoActual);
	      strcat(Bitacora,", Saldo Actual: ");
	      sprintf(SaldoActual,"%lld",temp->Saldo);
	      strcat(Bitacora,SaldoActual);
	      return 3;
	    }
	  else
	    return 2;

    
	}
      temp=temp->sig;
    }
}

int PedirPassword (void)
{
  system("clear");
  printf("Ingrese la nueva contraseña\n");
  scanf(" %[^\n]",NewPassword);
  system("clear");
  printf("Accion: Comprobando Contraseña\n\n");
  printf("Comprobar Contraseña con p\n");
  printf("Opción: ");
}

int VolverAPedirPassword_Coinciden (void)
{
  system("clear");
  char Comprobar[100];
  printf("Ingrese de nuevo la contraseña\n");
  scanf(" %[^\n]",Comprobar);
  if((strcmp(NewPassword,Comprobar))==0)
    {
      return 5;
    }
  else
    return 4;
}

int SesionFallida (void)
{
  printf("Usuario y/o contraseña son incorrectos\n");
  printf("Intente de nuevo\n");
  printf("Presione Enter para continuar...\n");
  __fpurge(stdin);
  getchar();
  Msg_Espera();
}

int MsgSaldoInsuficiente_MsgMenu (void)
{
  system("clear");
  printf("La operación falló, no hay saldo suficiente\n");
  printf("Intente de nuevo\n");
  printf("Presione Enter para continuar...\n");
  __fpurge(stdin);
  getchar();
  MsgMenu();
}

int MsgRetiroExitoso_RestarSaldo_ActualizarHistorial_MsgMenu (void)
{
  system("clear");
  printf("Retiro Éxitoso\n");
  printf("Presione Enter para continuar...\n");
  __fpurge(stdin);
  getchar();
  ActualizarRegistro();
  MsgMenu();

}

int MsgErrorCambioPassword_MsgMenu (void)
{
  system("clear");
  printf("Error, contraseñas no coinciden\n");
  printf("Intente nuevamente\n");
  printf("Presione Enter para continuar...\n");
  __fpurge(stdin);
  getchar();
  MsgMenu();
}

int MsgPasswordCambiada_ActualizarPassword_MsgMenu (void)
{
  system("clear");
  TipoLista *temp;
  temp = Inicio;
  while(temp!=NULL)
    {
      if((strcmp(Usuario,temp->Usuario))==0)
	strcpy(temp->Password,NewPassword);
      temp=temp->sig;
    }
  GuardarUsuarios();
  printf("La contraseña se modificó éxitosamente.\n");
  printf("Presione Enter para continuar...\n");
  __fpurge(stdin);
  getchar();
  MsgMenu();
}


int ActualizarRegistro (void)
{
  FILE *Archivo;
  char Temp[100];
  strcpy(Temp,"Cliente_");
  strcat(Temp,NumCuenta);
  strcat(Temp,".txt");
  Archivo = fopen(Temp,"at");
  fprintf(Archivo, "%s\n", Bitacora);
  fclose(Archivo);
}

int Borrar_Lista(void)
{
  TipoLista *temp;
  temp=Inicio;
  while(temp!=NULL)
    {
      Inicio=Inicio->sig;
      free(temp);
      temp=Inicio;
    }
}

int nul(void)
{
  printf("Opcion Inválida\n");
}

