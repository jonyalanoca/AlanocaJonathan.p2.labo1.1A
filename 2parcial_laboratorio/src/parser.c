#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "movies.h"
int parser_cargarTexto(FILE* pFile, LinkedList* listaCPU){
	int todoOk=-1;
	char matriz[4][100];
	int cant;
	eMovies* auxEstructura=NULL;
	if(pFile!=NULL && listaCPU!=NULL){

		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",matriz[0],matriz[1],matriz[2],matriz[3]);
		while(!feof(pFile)){
			cant=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",matriz[0],matriz[1],matriz[2],matriz[3]);
			//printf("aca: %s\n", matriz[3]);
			//printf("%s %s %s %s\n",matriz[0],matriz[1],matriz[2],matriz[3]);
			if(cant<4){
				break;
			}
			auxEstructura=movies_nuevoParametros(matriz[0],matriz[1],matriz[2],matriz[3]);
			ll_add(listaCPU, auxEstructura);
		}
		todoOk=0;
	}
	return todoOk;
}
