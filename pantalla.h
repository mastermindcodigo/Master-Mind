// Parte que recoge las funciones 

#include <stdio.h>
#include <stdlib.h>
#include "gestion_juego.h"

void pantalla(){
  
int asteriscos; 
int linea_aste;
  system("clear");
  printf("\n");
  for(asteriscos=0; asteriscos<=8; asteriscos++){
   
    if(asteriscos<=3 || asteriscos>=5 ){
      printf("\t\t");
      for(linea_aste=0; linea_aste<81; linea_aste++){
	printf("*");
      }
    }
    else if(asteriscos==4){
      printf("\t\t");
      for(linea_aste=0; linea_aste<67; linea_aste++){
	if(linea_aste==33){
	  printf("  MASTER MIND  ");
	}
	else{
	  printf("*");
	}
      }
    }
    printf("\n");
  }
}

int confirmar(char opcion){

  opcion = tolower(opcion);
  switch(opcion){
    
  case 's':{
    return 1;
  }
  case 'n':{
    return 0;
  }
  default: {
    return -1;
  }
  }
}

void menu(){

char accion;
int error;
int dificultad;
int *lives;
int x=100;
lives=&x;

#define JUGAR '1'
#define PROBAR '2'
#define NIVEL '3'
#define LISTAR '4'
#define SALIR '0'

//do{
do{
error=0;
fprintf(stdout," 1) Jugar partida \n 2) Jugar partida de prueba \n 3) Establecer nivel de dificultad \n 4) Listar historial de partidas \n 0)Salir\n \nSiguiente operacion?: ");
  fscanf(stdin," %c",&accion);  
  

 switch (accion) {

 case SALIR: { //salir

  do{
  printf("\nEsta seguro de que desea salir? (s/n):");
  scanf(" %c", &accion);

  while(tolower(accion) != 's' && tolower(accion) != 'n'){
    printf("\nLa respuesta no es correcta, introduzca (s/n):");
      scanf(" %c", &accion);
  }
  }while(tolower(accion) == 'n');
   break;
 }

  case JUGAR : {
    fprintf(stdout," \nHas seleccionado Jugar partida\n\n");
    dificultad=0;
    jugar_partida(dificultad, lives); //MODO NORMAL DE JUEGO
    break;
  }
  case PROBAR: {
    fprintf(stdout," \nHas seleccionado Jugar partida de prueba\n\n");
    dificultad=1;
    jugar_partida(dificultad, lives);
    break;
  }
  case NIVEL: {
    fprintf(stdout," \nHas seleccionado establecer nivel de dificultad\n\n");
    error=1;
    lives=&x;
    establecer_nivel(error, lives); //MODIFICAMOS EL NUMERO DE OPORTUNIDADES Y VOLVEMOS A LANZAR EL MENU DE OPCIONES
    
    break;
  }
  case LISTAR: {
    fprintf(stdout,"\nHas seleccionado listar historial de partidas\n\n");
    break;
  }
  default : {
    fprintf(stdout," \nOpcion no valida\n\n");
    error=1;
    break;
  }
 }
  }while (error == 1 );

  
  /*printf("\nEsta seguro de que desea salir? (s/n):");
  scanf(" %c", &accion);

  while(tolower(accion) != 's' && tolower(accion) != 'n'){
    printf("\nLa respuesta no es correcta, introduzca (s/n):");
      scanf(" %c", &accion);
  }
  }while(tolower(accion) == 'n');*/
 

  return ;
}





