/*
 ============================================================================
 Name        : 2parcial_laboratorio.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "controller.h"
#include "auxiliares.h"
#include "menus.h"


int main(void) {
	setbuf(stdout,NULL);

	LinkedList* listaMovies=ll_newLinkedList();
	verificarNULL(listaMovies);
	LinkedList* listaFiltrada=ll_newLinkedList();
	verificarNULL(listaFiltrada);

	int banderaGenero=0;
	int banderaRating=0;
	char path[30];
	char salir;
	do{

		switch(menu()){
		case 1:
			if(controller_PedirArchivo(path)==1){
				controller_cargarArchivoTexto(path, listaMovies);
			}
			break;
		case 2:
			if(ll_isEmpty(listaMovies)==0){
				controller_listaLista(listaMovies);
			}else{
				printf("Primero carge un achivo csv (1).\n");
			}

			break;
		case 3:
			if(ll_isEmpty(listaMovies)==0){
				;
				if(controller_asignarRating(listaMovies)==0){
					printf("Se cargaron los ratings exitosamente.\n");
					banderaRating=1;
				}else{
					printf("Hubo un error en la validacion NULL.\n");
				}
			}else{
				printf("Primero carge un achivo csv (1).\n");
			}
			break;
		case 4:
			if(ll_isEmpty(listaMovies)==0){
				if(controller_asignarGenero(listaMovies)==0){
					printf("Se cargaron los generos exitosamente.\n");
					banderaGenero=1;
				}else{
					printf("Hubo un error en la validacion NULL.\n");
				}
			}else{
				printf("Primero carge un achivo csv (1).\n");
			}
			break;
		case 5:
			if(banderaGenero==1){
				controller_filtrarGenero(listaMovies, listaFiltrada);
			}else{
				printf("primero asigne los generos (4)\n");
			}
			break;
		case 6:
			if(banderaGenero==1 && banderaRating==1){
				if(controller_ordenarLista(listaMovies)==0){
					printf("Se ordeno la lista con exito.\n");
				}else{
					printf("Hubo un error el la validacion NULL.\n");
				}
			}else{
				printf("primero asigne los generos y rating (3)(4)\n");
			}
			break;
		case 7:
			if(controller_VerificarCsv(path)==0){
				if(controller_guardarArchivoTexto(path, listaMovies)==0){
					printf("Se guardo el archivo csv con exito.\n");
				}else{
					printf("Hubo en error en la validacion NULL.\n");
				}
			}
			break;

		case 8:
			if(!cerrar(&salir)){
				printf("Hubo un problema con la validacion.\n");
			}else{
				controller_limpiarElementos(listaMovies);
				ll_deleteLinkedList(listaMovies);
				controller_limpiarElementos(listaFiltrada);
				ll_deleteLinkedList(listaFiltrada);
			}
			break;
		}
		system("pause");
		system("cls");
	}while(salir!='s');
	return EXIT_SUCCESS;
}
