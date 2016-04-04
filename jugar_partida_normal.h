//MODO DE JUEGO NORMAL

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void partida_normal(int oportunidades, char codigo[4]){
  
  void escrituratxt(int iteraciones, float puntuacion) { //Oye moi, esto se supone que lo hice para despues de meter en el txt los datos de la partida, guardase el numero de veces que te pidio el numero y la nota que te da el programa. lo llamaría desde void felicitaciones y void derrota, pero me da error al compilar. mira a ver si ves que hago mal pls. Tambien tengo unos warnings en los fprintf, a ver si tu sabes porque son...
	
    FILE *txt1;
    txt1=fopen("partidas.txt","a+"); //ESCRITURA EN FICHERO DE LAS APUESTAS Y ACIERTOS.
    fprintf(txt1,"Intentos: %i\n",iteraciones);
    //fprintf(txt1,"\n");
    fprintf(txt1,"Puntos: %.2f\n",puntuacion);
    //fprintf(txt1,"\n");
    fclose(txt1);
  } 

  void felicitaciones(int intentos, char codigo[4], int indice1){
  
    float puntos;
    
    if(intentos<=3)puntos=10;
    else if(intentos>=12)puntos=0;
    else if(intentos>3 && intentos<12)puntos=10-10*(intentos - 3)/9.;

    printf("\n\nHa descubierto el codigo secreto (");

    for(indice1=0; indice1<4; indice1++){
      printf("%c", codigo[indice1]);
    }
    if(intentos!=1){
      printf(") en %i intentos\nHa obtenido %.2f puntos\n\n", intentos, puntos);
      escrituratxt(intentos, puntos);
    }
    else{ 
      printf(") en %i intento\nHa obtenido %.2f puntos\n\n", intentos, puntos);
      escrituratxt(intentos, puntos);
    }
  }

  void derrota(char codigo[4], int indice1, int intentos){
    
    float puntos=0;

    printf("\n\nNO ha descubierto el codigo secreto (");

    for(indice1=0; indice1<4; indice1++){
      printf("%c", codigo[indice1]);
    }
    if(intentos!=1){
      printf(") tras %i intentos\nHa obtenido %.2f puntos\n\n", intentos, puntos);
      escrituratxt(intentos, puntos);
    }
    else{
      printf(") tras %i intento\nHa obtenido %.2f puntos\n\n", intentos, puntos);
      escrituratxt(intentos, puntos);
    }
  }

  srand(time(NULL));
  //char codigo[4];
  char apuesta[4];
  char apuesta_c[4];
  char apuesta_final[4];
  int indice1, indice2, error, a, b, perder;
  int ganar=0;
  int intentos=0;
  int contimpresion=0; //CONTADOR AUX PARA NUMERO DE VALORES DISTINTOS DE _ 
  FILE *txt;

  //GENERAMOS LOS CUATRO NUMEROS ALEATORIOS
  /*do{
    error=0;
    for(indice1=0; indice1<4; indice1++){
    *(codigo+indice1) = '0'+(rand() % (':'-'0'));//NUMEROS ALEATORIOS ENTRE 0 Y 9
    }
    //COMPROBAMOS QUE NO HAYA DOS ELEMENTOS IGUALES EN EL CODIGO SECRETO
    for(indice1=0; indice1<5; indice1++){
    for(indice2=0; indice2<5; indice2++){
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
    }while(error==1);*/
  /* for(indice=0; indice<4; indice++){
     printf(" %i", *(codigo+indice));
     }*/

  txt=fopen("partidas.txt","a+"); //GUARDADO EN FICHERO DEL CODIGO SECRETO Y COLOCACIÓN DE GUIONES.
  fprintf(txt,"------------\n");
  fprintf(txt, "El codigo secreto es:");
  for(indice1=0; indice1<4; indice1++){
    fprintf(txt,"%c",codigo[indice1]);
  }
  fprintf(txt,"\n");
  fclose(txt);

  //YA TENEMOS CREADO EL CODIGO SECRETO
  do{
    ganar=0;
    perder=0;
    do{
      do{
	error=0;
	
	printf("\nEscriba un número de 4 dígitos diferentes + ENTER:");
	scanf(" %s", apuesta);
	printf("\n");
      
	while(strlen(apuesta)!=4){
	
	  printf("\nLa longitud de la apuesta es incorrecta\n");
	  printf("\nEscriba un número de 4 dígitos diferentes + ENTER:");
	  scanf(" %s", apuesta);
	  printf("\n");
	}

	for(indice1=0; indice1<4; indice1++){
	  if(apuesta[indice1]>='0'  && apuesta[indice1]<='9') continue;
	  else{
	    error=1;
	    printf("La apuesta solo debe contener dígitos\n");
	    break;
	  }
	}
      }while(error==1);

      error=0;
  
      for(indice1=0; indice1<4; indice1++){
	for(indice2=0; indice2<4; indice2++){
	  if(indice1==indice2)continue;
	  if(apuesta[indice2]==apuesta[indice1]){
	    //  printf("\nLos digitos de la apuesta deben ser diferentes\n");
	    error=1;
	    break;
	  }
	  if(error==1)break;
	}
      }
      if(error==1)printf("\nLos digitos de la apuesta deben ser diferentes\n");
    }while(error==1);

    /*PASAMOS LA BATERÍA DE PRUEBAS PARA SABER SI EL CODIGO INTRODUCIDO ES CORRECTO*/
  
    //AHORA MIRAMOS LOS ELEMENTOS DEL CODIGO QUE SE ACERTARON O NO 
    printf("El codigo secreto es: ");
    for(indice1=0; indice1<4; indice1++){
      printf("%c", codigo[indice1]);
    }
  
    printf("\nSu apuesta es: <");
    for(indice1=0; indice1<4; indice1++){
      printf("%c", apuesta[indice1]);
    }
    printf(">  <");
 

    for(indice1=0; indice1<4; indice1++){
      a=0;
      b=0;
      for(indice2=0; indice2<4; indice2++){
	if(apuesta[indice1]==codigo[indice2]){
	  if(indice1==indice2){
	    a=1; // printf("*");
	    // break;
	  }
	  else{
	    b=1;// printf("|");
	    //  break;
	  }
	}
	else{
	  //	break;
	}
      }
      if(a==1){
	apuesta_c[indice1]='*'; //printf("*");
      }
      else{
	if(b==1)apuesta_c[indice1]='|';//printf("|");
	else apuesta_c[indice1]='_';//printf("_");
      }
    }

    for(indice1=0; indice1<4; indice1++){ //IMPRESION DE LOS CARACTERES DE SALIDA.
      if(apuesta_c[indice1]=='*'){
	printf("%c", apuesta_c[indice1]);
	apuesta_final[contimpresion]='*';
	contimpresion++;
      } }
		
    for(indice1=0; indice1<4; indice1++) {
      if(apuesta_c[indice1]=='|')	{
	printf("%c", apuesta_c[indice1]);
	apuesta_final[contimpresion]='|';
	contimpresion++;
      } }
		
    for(indice1=0; indice1<(4-contimpresion); indice1++) {
      printf("_");
      apuesta_final[indice1+contimpresion]='_';
    }
    contimpresion=0; //Ponemos contador a 0 para la siguiente ejecución de la impresión de salida.
    printf(">"); //ACABAMOS DE COMPROBAR LA APUESTA CON EL CODIGO
    oportunidades--;    //QUITAMOS UN INTENTO
    printf(" Quedan %i", oportunidades); 
    intentos++;
    
    txt=fopen("partidas.txt","a+"); //ESCRITURA EN FICHERO DE LAS APUESTAS Y ACIERTOS.
    for(indice1=0; indice1<4; indice1++){
      fprintf(txt,"%c", apuesta[indice1]);
    }
    fprintf(txt,"  <");
    for(indice1=0; indice1<4; indice1++){
      fprintf(txt, "%c", apuesta_final[indice1]);
    }
    fprintf(txt,">  \n");
    fclose(txt);

    /* for(indice1=0; indice1<4; indice1++){
       printf("%c", apuesta_c[indice1]);
       }
       printf(">"); //ACABAMOS DE COMPROBAR LA APUESTA CON EL CODIGO
  
       //QUITAMOS UN INTENTO
       oportunidades--;
       printf("%i", oportunidades);
       intentos++;*/
    
    if(oportunidades==0)perder=1; //PIERDE LA PARTIDA

    for(indice1=0; indice1<4; indice1++){ //COMPROBAMOS SI TODOS SON ASTERISCOS*
      if(apuesta_c[indice1]=='*')ganar=ganar+1;
    }
    
  }while(ganar!=4 && perder!=1);

  if(perder==1)derrota(codigo, indice1, intentos); //PIERDE
  else felicitaciones(intentos, codigo, indice1); //GANA

  return ;
  
}




/*int main(){
  
  partida_normal();
  return 0;
  }*/
