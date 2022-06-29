/*
 * menus.c
 *
 *  Created on: 25 abr. 2022
 *      Author: Jony
 */
#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "validaciones.h"
int menu(void){
	int opcion;
	printf("-----------------------------------------------------------------------------\n");
	printf(" \t..[ MENU PRINCIPAL]..\n");
	printf("========================================\n\n");
	printf("  [1] CARGAR ARCHIVO DE PELICULAS\n");
	printf("  [2] IMPRIMIR LISTA.\n");
	printf("  [3] ASIGNAR RATING.\n");
	printf("  [4] ASIGNAR GENERO.\n");
	printf("  [5] FILTRAR POR GENERO.\n");
	printf("  [6] ORDENAR POR GENERO Y RATING EN FORMA DESCENDENTE.\n");
	printf("  [7] GUARDAR PELICULAS EN UN ARCHIVO DE TEXTO.\n");
	printf("-----------------------------------------------------------------------------\n");
	printf("  [8] SALIR.\n");
	printf("-----------------------------------------------------------------------------\n");

	if(!enteroEnRango("Ingrese una opciones del menu",&opcion,1,8)){
		printf("Algo ha salido mal.\n");
	}
	return opcion;
}
int menuModificar(void){
	int opcion;
	system("cls");
	printf("----------------------------------------\n");
	printf(" \t..[MENU MODIFICAR PASAJERO]..\n");
	printf("========================================\n\n");
	printf("  [1]  Modificar nombre.\n");
	printf("  [2]  Modificar apellido.\n");
	printf("  [3]  Modificar codigo de vuelo.\n");
	printf("  [4]  Modificar precio.\n");
	printf("  [5]  Modificar tipo de pasaje.\n");
	printf("  [6]  Modificar estado de vuelo.\n");
	printf("  [7]  Volver al menu principal.\n");
	printf("________________________________________\n\n");

	if(!enteroEnRango("Ingrese una opciones del menu",&opcion,1,7)){
		printf("Algo ha salido mal.\n");
	}
	return opcion;
}
int menuOrdenar(void){
	int opcion;
	system("cls");
	printf("----------------------------------------\n");
	printf(" \t..[MENU DE ORDENAMIENTO]..\n");
	printf("========================================\n\n");
	printf("  [1]  Ordenar por id.\n");
	printf("  [2]  Ordenar por Nombre.\n");
	printf("  [3]  Ordenar por Apellido.\n");
	printf("  [4]  Ordenar por precio.\n");
	printf("  [5]  Ordenar por Codigo de vuelo.\n");
	printf("  [6]  Ordenar por Tipo de pasajero.\n");
	printf("  [7]  Ordenar por Estado de vuelo.\n");
	printf("  [8]  Volver al menu principal.\n");
	printf("________________________________________\n\n");

	if(!enteroEnRango("Ingrese una opciones del menu",&opcion,1,8)){
		printf("Algo ha salido mal.\n");
	}
	return opcion;
}
int ascendenteDescendente(void){
	int opcion;
	system("cls");
	printf("----------------------------------------\n");
	printf(" \t..[TIPO DE ORDENAMIENTO]..\n");
	printf("========================================\n\n");
	printf("  [0]  Ordenar descendente.\n");
	printf("  [1]  Ordenar ascendente\n");

	printf("________________________________________\n\n");

	if(!enteroEnRango("Ingrese una opciones del menu",&opcion,0,1)){
		printf("Algo ha salido mal.\n");
	}
	printf("Estamos trabajando muy duro. Por favor, espere..\n");
	return opcion;
}


int menuFiltrar(void){
	int opcion;
	system("cls");
	printf("----------------------------------------\n");
	printf(" \t..[MENU FILTRAR]..\n");
	printf("========================================\n\n");
	printf("  [1]  FILTRAR POR DRAMA.\n");
	printf("  [2]  FILTRAR POR COMEDIA.\n");
	printf("  [3]  FILTRAR POR ACCION.\n");
	printf("  [4]  FILTRAR POR TERROR.\n");
	printf("  [5]  VOLVER AL MENU PRINCIPAL.\n");
	printf("________________________________________\n\n");

	if(!enteroEnRango("Ingrese una opciones del menu",&opcion,1,5)){
		printf("Algo ha salido mal.\n");
	}
	return opcion;
}
