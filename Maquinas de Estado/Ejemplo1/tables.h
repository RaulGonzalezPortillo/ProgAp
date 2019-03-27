/************************************************************************
 *									*
 * Archivo:	tables.h						*
 * Descripcion: Tablas para la maquina de estados y funciones externas	*
 *		Aqui se definen todos las tablas que se utilizan	*
 *		en el programa						*
 *									*
 ************************************************************************/

/*************** ARCHIVOS DE INCLUSION ***************/ 
#include "local.h"
#include <stdio.h>


/*************** FUNCIONES EXTERNAS *********************
 * En esta seccion se declaran los encabezados de 	*
 * todas las funciones que se utilizan en las     	*
 * tablas del programa. Todas las funciones deben 	*
 * ser de tipo entero y no deben recibir parametros	*
 ********************************************************/ 
extern int Msg_EdoA(void);
extern int Msg_EdoB(void);
extern int Msg_SalA(void);
extern int Msg_SalB(void);
extern int nul(void);

/******************** TABLAS ********************
 * En esta seccion se declaran las tablas	*
 * que se van a usar en el programa		*
 ************************************************/ 
 
/*************** TABLA DE ACCION ***************/  
ACTION_TAB action_table[]={
        /*etype     accion     bandera   sigEdo. */    
    { ENTRADA_A,  Msg_EdoA,  	-1,	ESTADO_A},
    { ENTRADA_B,  Msg_EdoB,	-1,	ESTADO_B},
    { ASTERISCO,  nul,  	-1,	INICIO},
    { ENTRADA_a,  Msg_SalA,	-1,	INICIO},
    { ASTERISCO,  nul,  	-1,	ESTADO_A},
    { ENTRADA_b,  Msg_SalB,	-1,	INICIO},
    { ASTERISCO,  nul,  	-1,     ESTADO_B}, 
};

/*************** TABLA AUXILIAR ***************/  
    AUX_TAB aux_table[]={        
/*    accion       bandera           sigEdo */
    { nul,         0,                0},
};

/*************** TABLA DE ESTADOS ***************/  
STATE_TAB state_table[]={
   /*estado      inicio   fin */
    {INICIO,       0,      2},
    {ESTADO_A,     3,      4},
    {ESTADO_B,     5,      6},
};


    
        

        
    
        
    
        
    
        
    
        
    
        
    
        
    
        
    
        
    
        
    
        
    
    
        
