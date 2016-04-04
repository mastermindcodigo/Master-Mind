//menús
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestion_juego.h"


#define JUGAR '1'
#define PROBAR '2'
#define NIVEL '3'
#define LISTAR '4'
#define SALIR '0'
#define GUARDAR '5'
#define IDIOMA '6'

int  menu_nguardar(int *lives, int *ocasion){

  char accion;
  char opcion[1];
  int error;
  int dificultad;

fprintf(stdout," 1) Jugar partida \n 2) Jugar partida de prueba \n 3) Establecer nivel de dificultad \n 4) Listar historial de partidas \n 6) Establecer idioma \n 0) Salir\n \nSiguiente operacion?: ");

fscanf(stdin," %s", opcion);
if(strlen(opcion)!=1)opcion[0]=7;

switch (opcion[0]) {

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
error=1;
ocasion++;
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
establecer_nivel(error, lives); //MODIFICAMOS EL NUMERO DE OPORTUNIDADES Y VOLVEMOS A LANZAR EL MENU DE OPCIONES
    
break;
}
 case LISTAR: {
fprintf(stdout,"\nHas seleccionado listar historial de partidas\n\n");
listar_historial();
break;
}
 case IDIOMA: {

}
 default : {
fprintf(stdout," \nOpcion no valida\n\n");
error=1;
break;
}
}

return error;
}

int menu_guardar(int *lives, int *ocasion){

 char accion;
  char opcion[1];
  int error;
  int dificultad;

fprintf(stdout," 1) Jugar partida \n 2) Jugar partida de prueba \n 3) Establecer nivel de dificultad \n 4) Listar historial de partidas \n 5) Guardar partida \n 6) Establecer idioma \n 0)Salir\n \nSiguiente operacion?: ");

fscanf(stdin," %s", opcion);
if(strlen(opcion)!=1)opcion[0]=7;

switch (opcion[0]) {

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
error=1;
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
establecer_nivel(error, lives); //MODIFICAMOS EL NUMERO DE OPORTUNIDADES Y VOLVEMOS A LANZAR EL MENU DE OPCIONES

break;
}
 case LISTAR: {
fprintf(stdout,"\nHas seleccionado listar historial de partidas\n\n");
listar_historial();
break;
}
 case GUARDAR: {

}
 case IDIOMA: {

}
 default : {
fprintf(stdout," \nOpcion no valida\n\n");
error=1;
break;
}
}

return error;
}


