/*
 * otros.c
 *
 *  Created on: 25 abr. 2022
 *      Author: Jony
 */

#include "auxiliares.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int cerrar(char* pSalir){
	int todoOk=0;
	if(pSalir!=NULL){
		system("cls");
		printf("ATENCION.\nEsta por salir del programa.\nPara confirmar presione (s): ");
		fflush(stdin);
		scanf("%c", pSalir);

		*pSalir=tolower(*pSalir);
		todoOk=1;
	}
	return todoOk;
}
int numeroRandom(int numMin, int numMax){

	int numero;
	int max=numMax;
	int min=numMin;
	numero=rand() % (max-min+1)+min;
	return numero;
}
float decimalRandom(int numMin, int numMax){

	float numero;
	int min=numMin*100;
	int max=numMax*100;
	numero=(float)(rand() % (max-min+1)+min)/100;
	return numero;
}
void verificarNULL(void* puntero){
	if(puntero==NULL){
		printf("Hubo un error al crear un espacio en la momoria dinamica.\n");
		system("pause");
		exit(1);
	}
}
