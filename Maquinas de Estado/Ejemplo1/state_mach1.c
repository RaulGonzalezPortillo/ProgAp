/****************************************************************
 *								*
 * Archivo:	state_mach1.c					*
 * Descripcion: Codigo Fuente para implementar el programa	*
 *		de maquina de estados.			 	*
 *								*
 ****************************************************************/

/*************** ARCHIVOS DE INCLUSION ***************/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tables.h"


/*************** VARIABLES GLOBALES ***************/ 
EVENT event;
int state;
char buf[BUFFER];

/*************** PROTOTIPOS DE FUNCION ***************/ 
void initialise(void); //Debe de existir
void getevent(void); //Debe de existir

int Msg_EdoA(void);
int Msg_EdoB(void);
int Msg_SalA(void);
int Msg_SalB(void);

int nul(void); //Debe de existir


/*************** FUNCION PRINCIPAL ***************/ 
int main(int argc, char **argv)
{
    int actx, auxx, outcome;

    initialise();
    
    while (1) {    /* loop infinito para la MFE */
        getevent();

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
        
    } /* while(1) */
}

void initialise(void) //Aquí colocamos la información que necesitemos
{
    state = 0;
}


void getevent(void)
{
    char *ptmp;
    ptmp = &buf[2];
    
#ifdef DEBUG
    printf("wait event \n");
#endif
    gets(buf);
         switch (buf[0])
             {
	     case 'A' :
	       event.etype=ENTRADA_A;
	       break;
	     case 'B' :
	       event.etype=ENTRADA_B;
	       break;
	     case 'a' :
	       event.etype=ENTRADA_a;
	       break;
	     case 'b' :
	       event.etype=ENTRADA_b;
	       break;
	     default:
	       event.etype=-1;
	       break;
                     
             }//switch
}// getevent
 

/* FUNCIONES DE IMPLEMENTACION */

int Msg_EdoA(void)
{
  printf ("Hola amigos estamos en A\n\n");
}//funcion1

int Msg_EdoB(void)
{
  printf ("Hola amigos estamos en B\n\n");
}//funcion2

int Msg_SalA(void)
{
  printf ("Hola amigos salimos de A\n\n");
}//funcion3

int Msg_SalB(void)
{
  printf ("Hola amigos salimos de B\n\n");
}//funcion4

int nul(void)
{
  printf ("Pues nada xD!...\n\n");
}//nul
