// gestion del juego

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "jugar_partida_normal.h"

int jugar_partida(int modo, int *lifes){

 int establecer_nivel(); //PROTOTIPO

  if(modo==0){ //MODO NORMAL DE JUEGO
  
  int oportunidades=*lifes;
  char codigo[4];
  int indice1, indice2, error;
  srand(time(NULL));
  printf("Se va a jugar una partida en dificultad normal\n");

	//GENERAMOS EL CODIGO SECRETO
    do{
     error=0;
     for(indice1=0; indice1<4; indice1++){
     *(codigo+indice1) = '0'+(rand() % (':'-'0'));//NUMEROS ALEATORIOS ENTRE 0 Y 9
     }
     //COMPROBAMOS QUE NO HAYA DOS ELEMENTOS IGUALES EN EL CODIGO SECRETO
     for(indice1=0; indice1<4; indice1++){
     for(indice2=0; indice2<4; indice2++){
     if(indice1==indice2){
     continue;
     }
     else if(codigo[indice1]==codigo[indice2]){
     //	  printf("\nLas letras de las posiciones %i y %i son iguales\n\n", indice1+1, indice2 +1);
     error=1;
     break;
     }
     }
     if(error==1)break;
     }
     }while(error==1);

  partida_normal(oportunidades, codigo);
  return 0;
  }
  
  else{ //PARTIDA DE PRUEBA 
  
  char codigo_p[4]="1234";  
  int oportunidades=100;
  printf("Se va a jugar una partida de prueba\n");
  partida_normal(oportunidades, codigo_p);  
  }
	return 0;
}

int establecer_nivel(int error, int *lifes){

  int modo=error;
  printf("Nivel actual: %i\n", *lifes);
  while(modo==1){
  printf("Elige nuevo nivel [1..100]:");
  scanf(" %i", lifes);
  if(*lifes>=1 && *lifes<=100){
  printf("\nNivel seleccionado: %i\n", *lifes);
  modo=0;
  }
  else{
  printf("\nNivel seleccionado no válido\n");
  modo=1; 
 }
}
	return 0;
}

int listar_historial(){
	FILE *txt;
	char c;
	txt=fopen("partidas.txt","r");
	if( txt == NULL) {
		printf("No puedo leer el fichero del historial\n");
		return 0;
	}
	    while((c=fgetc(txt))!=EOF){ //Comparamos con fin de fichero.
        printf("%c",c);
    }
    fclose(txt);
	return 0;
	}

