// gestion del juego

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "jugar_partida_normal.h"

int jugar_partida(int modo){

 int establecer_nivel(); //PROTOTIPO

  if(modo==0){ //MODO NORMAL DE JUEGO
	
  int error=0;
  int oportunidades=establecer_nivel(error);
  printf("Se va a jugar una partida en dificultad normal\n");
  partida_normal(oportunidades);
  return 0;
  }
  
  else{ //PARTIDA DE PRUEBA 
    printf("Se va a jugar una partida de prueba\n");
  }
	return 0;
}

int establecer_nivel(int error, int *lifes){

  int vidas=*lifes;
  int modo=error;
  while(modo==1){
  printf("Nivel actual: 100\nElige nuevo nivel [1..100]:");
  scanf(" %i", lifes);
  if(*lifes>=-2147483648 && *lifes<=2147483647){
  printf("\nNivel seleccionado: %i:", *lifes);
  modo=0;
  }
  else{
  printf("Nivel seleccionado no válido");
  modo=1; 
 }
}
	return vidas;
}

int listar_historial(){}

