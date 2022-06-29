/*
 * controller.c
 *
 *  Created on: 21 jun. 2022
 *      Author: Jony
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "controller.h"
#include "parser.h"
#include "movies.h"
#include "auxiliares.h"
#include "menus.h"

int controller_cargarArchivoTexto(char* path, LinkedList* llLista){
	int todoOk=-1;
	if(path!=NULL && llLista!=NULL){
		FILE* pFile=fopen(path, "r");
		if(pFile!=NULL){
			parser_cargarTexto(pFile, llLista);
			printf("Se cargo la lista con exito.\n");
		}
		fclose(pFile);
		todoOk=0;
	}
	return todoOk;
}
int controller_listaLista( LinkedList* llLista){
	int todoOk=-1;
	int len;
	if(llLista!=NULL){
		len=ll_len(llLista);
		system("cls");
		printf(" ID            TITULO                GENERO     DURACION\n");
		for(int i=0;i<len;i++){
			movies_mostrar((eMovies*)ll_get(llLista,i));
		}
		todoOk=0;
	}
	return todoOk;
}

int controller_guardarArchivoTexto(char* path, LinkedList* llLista){
	int todoOk=-1;
	eMovies* auxiliar;
	int len;
	int auxId;
	char auxTitulo[30];
	char auxGenero[30];
	float auxRating;
	if(llLista!=NULL && path!=NULL){
		FILE* pfile=fopen(path, "w");
		fprintf(pfile,"%s,%s,%s,%s\n","id","titulo", "genero", "duracion");
		len=ll_len(llLista);
		for(int i=0;i<len;i++){
			auxiliar=(eMovies*)ll_get(llLista,i);
			movies_getId(auxiliar,&auxId);
			movies_getTitulo(auxiliar,auxTitulo);
			movies_getGenero(auxiliar,auxGenero);
			movies_getRating(auxiliar,&auxRating);
			fprintf(pfile,"%d,%s,%s,%.1f\n",auxId,auxTitulo, auxGenero, auxRating);

		}
		fclose(pfile);
		todoOk=0;
	}


	return todoOk;
}

int controller_limpiarElementos(LinkedList* llLista){
	int todoOk=-1;
	int len;
	eMovies* aux;
	if(llLista!=NULL){
		len=ll_len(llLista);
		for(int i=0;i<len; i++){
			aux=(eMovies*)ll_get(llLista,i);
			free(aux);
		}
		todoOk=0;
	}
	return todoOk;
}




int controller_asignarRating( LinkedList* llLista){
	int todoOk=-1;
	if(llLista!=NULL){
		llLista=ll_map(llLista, movies_asignarRating);
		todoOk=0;
	}
	return todoOk;
}

int controller_asignarGenero( LinkedList* llLista){
	int todoOk=-1;
	if(llLista!=NULL){
		llLista=ll_map(llLista, movies_asignarGenero);
		todoOk=0;
	}
	return todoOk;
}
int controller_filtrarGenero(LinkedList* llLista , LinkedList* listaFiltrada)
{

	int todoOk=-1;
	if(llLista!=NULL && listaFiltrada!=NULL){
		ll_clear(listaFiltrada);
		switch(menuFiltrar()){
		case 1:
			listaFiltrada=ll_filter(llLista, movies_filtrarDrama);
			controller_listaLista(listaFiltrada);
			break;
		case 2:
			listaFiltrada=ll_filter(llLista, movies_filtrarComedia);
			controller_listaLista(listaFiltrada);
			break;
		case 3:
			listaFiltrada=ll_filter(llLista, movies_filtrarAccion);
			controller_listaLista(listaFiltrada);
			break;
		case 4:
			listaFiltrada=ll_filter(llLista, movies_filtrarTerror);
			controller_listaLista(listaFiltrada);
			break;
		case 5:

			break;

		}
		todoOk=0;
	}
	return todoOk;
}


int controller_ordenarLista(LinkedList* llLista){
	int todoOk=-1;
	if(llLista!=NULL){
		ll_sort(llLista, movies_compararPorGenero,0);
		todoOk=0;
	}
	return todoOk;
}
int controller_PedirArchivo(char* strArchivo){
	int todoOk=-1;
	if(strArchivo!=NULL){
		printf("Ingrese el nombre del archivo a abrir.\n");
		fflush(stdin);
		gets(strArchivo);
		FILE* pfile=fopen(strArchivo,"r");
		if(pfile==NULL){
			printf("No se encontro el archivo seleccionado. pruebe con movies.csv\n");
			todoOk=0;
		}else{
			todoOk=1;
		}
		fclose(pfile);

	}
	return todoOk;
}
int controller_VerificarCsv(char* strArchivo){
	int todoOk=-1;
	int len;
	if(strArchivo!=NULL){
		printf("Ingrese el nombre del csv a guardar.\n");
		fflush(stdin);
		gets(strArchivo);
		len=strlen(strArchivo);
		if(strArchivo[len-4]=='.' && strArchivo[len-3]=='c' &&strArchivo[len-2]=='s' && strArchivo[len-1]=='v'){
			todoOk=0;
		}else{
			printf("Debe ingresar un nomnbre .csv\n");
		}

	}
	return todoOk;
}
