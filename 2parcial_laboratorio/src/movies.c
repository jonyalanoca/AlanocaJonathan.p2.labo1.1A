#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "auxiliares.h"
#include "movies.h"
eMovies* movies_nuevo(void){
	eMovies* aux=(eMovies*)malloc(sizeof(eMovies));
	verificarNULL(aux);
	return aux;
}
eMovies* movies_nuevoParametros(char* strId, char* strTitulo, char* strGenero, char* strRating){
	eMovies* aux=movies_nuevo();
	if(strId!=NULL &&strTitulo!=NULL && strGenero!=NULL && strRating!=NULL){
		movies_setId(aux,atoi(strId));
		movies_setTitulo(aux,strTitulo);
		movies_setGenero(aux,strGenero);
		movies_setRating(aux,atof(strRating));
	}
	return  aux;
}

int movies_setId(eMovies* pEstructura, int id){
	int todoOk=-1;
	if(pEstructura!=NULL && id>0){
		pEstructura->id=id;
		todoOk=0;
	}
	return todoOk;
}
int movies_setTitulo(eMovies* pEstructura, char* titulo){
	int todoOk=-1;
	if(pEstructura!=NULL && titulo!=NULL){
		strcpy(pEstructura->titulo,titulo);
		todoOk=0;
	}
	return todoOk;
}
int movies_setGenero(eMovies* pEstructura, char* genero){
	int todoOk=-1;
	if(pEstructura!=NULL && genero!=NULL){
		strcpy(pEstructura->genero,genero);
		todoOk=0;
	}
	return todoOk;
}


int movies_setRating(eMovies* pEstructura, float rating){
	int todoOk=-1;
	if(pEstructura!=NULL && rating>=0){
		pEstructura->rating=rating;
		todoOk=0;
	}
	return todoOk;
}
int movies_getId(eMovies* pEstructura,int* id){
	int todoOk=-1;
	if(pEstructura!=NULL && id!=NULL){
		*id=pEstructura->id;
		todoOk=0;
	}
	return todoOk;
}
int movies_getTitulo(eMovies* pEstructura, char* titulo){
	int todoOk=-1;
	if(pEstructura!=NULL && titulo!=NULL){
		strcpy(titulo,pEstructura->titulo);
		todoOk=0;
	}
	return todoOk;
}
int movies_getGenero(eMovies* pEstructura, char* genero){
	int todoOk=-1;
	if(pEstructura!=NULL && genero!=NULL){
		strcpy(genero,pEstructura->genero);
		todoOk=0;
	}
	return todoOk;
}
int movies_getRating(eMovies* pEstructura, float* rating){
	int todoOk=-1;
	if(pEstructura!=NULL && rating!=NULL){
		*rating=pEstructura->rating;
		todoOk=0;
	}
	return todoOk;
}

/*fin seter y geters*/

void movies_mostrar(eMovies* pEstructura){
	int auxId;
	char auxTitulo[30];
	char auxGenero[30];
	float auxRating;
	movies_getId(pEstructura,&auxId);
	movies_getTitulo(pEstructura,auxTitulo);
	movies_getGenero(pEstructura,auxGenero);
	movies_getRating(pEstructura,&auxRating);
	printf("%4d %-30s %-15s %.1f\n",auxId,auxTitulo,auxGenero,auxRating);
}




void* movies_asignarRating(void* pEstructura){
	float numero;
	if(pEstructura!=NULL){
		numero=decimalRandom(1,10);
		movies_setRating(pEstructura, numero);
	}
	return pEstructura;
}
void* movies_asignarGenero(void* pEstructura){
	int numero;
	char generos[4][20]={"Drama","Comedia","Accion","Terror"};
	if(pEstructura!=NULL){
		numero=numeroRandom(0,3);
		movies_setGenero(pEstructura, generos[numero]);
	}
	return pEstructura;
}


int movies_filtrarDrama(void* pEstructura){
	int resultado=0;
	if(pEstructura!=NULL){
		if(strcmp(((eMovies*)pEstructura)->genero,"Drama")==0){
			resultado=1;
		}
	}
	return resultado;
}
int movies_filtrarComedia(void* pEstructura){
	int resultado=0;
	if(pEstructura!=NULL){
		if(strcmp(((eMovies*)pEstructura)->genero,"Comedia")==0){
			resultado=1;
		}
	}
	return resultado;
}
int movies_filtrarTerror(void* pEstructura){
	int resultado=0;
	if(pEstructura!=NULL){
		if(strcmp(((eMovies*)pEstructura)->genero,"Terror")==0){
			resultado=1;
		}
	}
	return resultado;
}
int movies_filtrarAccion(void* pEstructura){
	int resultado=0;
	if(pEstructura!=NULL){
		if(strcmp(((eMovies*)pEstructura)->genero,"Accion")==0){
			resultado=1;
		}
	}
	return resultado;
}



int movies_compararPorGenero(void* pEstructura1, void* pEstructura2){
	int auxReturn=0;
	if(pEstructura1!=NULL && pEstructura2!=NULL){
		auxReturn=strcmp(((eMovies*)pEstructura1)->genero, ((eMovies*)pEstructura2)->genero);
		if(auxReturn==0){
			if(((eMovies*)pEstructura1)->rating>((eMovies*)pEstructura2)->rating)
			{
			 auxReturn= 1;
			}
			if(((eMovies*)pEstructura1)->rating<((eMovies*)pEstructura2)->rating)
			{
			 auxReturn= -1;
			}
		}
	}
	return auxReturn;
}
