/*
 * movies.h
 *
 *  Created on: 21 jun. 2022
 *      Author: Jony
 */

#ifndef MOVIES_H_
#define MOVIES_H_

typedef struct{
	int id;
	char titulo[50];
	char genero[30];
	float rating;
}eMovies;

#endif /* MOVIES_H_ */
/// @fn eMovies movies_nuevo*(void)
/// @brief	crear una estructura en la memoria dinamica
///
/// @return retorna un puntero a la estructura eMovies vacio
eMovies* movies_nuevo(void);
/// @fn eMovies movies_nuevoParametros*(char*, char*, char*, char*)
/// @brief crear una estructura en la memoria dinamica y lo carga con los valores pasados por parametros
///
/// @param strId
/// @param strTitulo
/// @param strGenero
/// @param strDuracion
/// @return retorna un puntero a estructura eMovies cargado
eMovies* movies_nuevoParametros(char* strId, char* strTitulo, char* strGenero, char* strDuracion);
/// @fn int movies_setId(eMovies*, int)
/// @brief carga el valor  de id en la estructructura
///
/// @param pEstructura
/// @param id
/// @return/// @return retorna -1: si falla la validacion NULL.
///			retorna  0:si salio todo bien
int movies_setId(eMovies* pEstructura, int id);
/// @fn int movies_setTitulo(eMovies*, char*)
/// @brief carga el valor de genero en la estructura
///
/// @param pEstructura
/// @param genero
/// @return retorna -1: si falla la validacion NULL.
///			retorna  0:si salio todo bien
int movies_setTitulo(eMovies* pEstructura, char* titulo);
/// @fn int movies_setGenero(eMovies*, char*)
/// @brief carga el valor de titulo en la estructura
///
/// @param pEstructura
/// @param titulo
/// @return retorna -1: si falla la validacion NULL.
///			retorna  0:si salio todo bien
int movies_setGenero(eMovies* pEstructura, char* genero);
/// @fn int movies_setDuracion(eMovies*, int)
/// @brief carga el valor de duracion en la estructura
///
/// @param pEstructura
/// @param duracion
/// @return retorna -1: si falla la validacion NULL.
///			retorna  0:si salio todo bien
int movies_setRating(eMovies* pEstructura, float rating);
/// @fn int movies_getId(eMovies*, int*)
/// @brief obtiene el valor id de la estructura  y se lo asigna  al puntero id
///
/// @param pEstructura
/// @param id
/// @return  retorna -1: si falla la validacion NULL.
///			retorna  0:si salio todo bien
int movies_getId(eMovies* pEstructura,int* id);
/// @fn int movies_getTitulo(eMovies*, char*)
/// @brief obtiene el valor de titulo de la estructura y se lo asigna al puntero titulo
///
/// @param pEstructura
/// @param titulo
/// @return retorna -1: si falla la validacion NULL.
///			retorna  0:si salio todo bien
int movies_getTitulo(eMovies* pEstructura, char* titulo);
/// @fn int movies_getGenero(eMovies*, char*)
/// @brief obtiene el valor genero de la estructura uy se lo asigna al puntero genero
///
/// @param pEstructura
/// @param genero
/// @return retorna -1: si falla la validacion NULL.
///			retorna  0:si salio todo bien
int movies_getGenero(eMovies* pEstructura, char* genero);
/// @fn int movies_getDuracion(eMovies*, int*)
/// @brief obtiene el valor duracion de la estructura y se lo asigna el puntero duracion
///
/// @param pEstructura
/// @param duracion
/// @return retorna -1: si falla la validacion NULL.
///			retorna  0:si salio todo bien
int movies_getRating(eMovies* pEstructura, float* rating);



/// @fn void movies_mostrar(eMovies*)
/// @brief muetra una estructura en forma enculumnada
///
/// @param pEstructura
void movies_mostrar(eMovies* pEstructura);

/// @fn void movies_asignarGenero*(void*)
/// @brief asigana el valor rating en una estructura void
///
/// @param retorna un puntero a estructura
void* movies_asignarRating(void* pEstructura);
/// @fn void movies_asignarGenero*(void*)
/// @brief asigna el valor genero en una estructura void
///
/// @param retorna un punero a estructura
void* movies_asignarGenero(void* pEstructura);

/// @fn int movies_filtrarDrama(void*)
/// @brief compara si la estructura contiene el genero adventure
///
/// @param pEstructura
/// @return   retorna 0: no contiene Drama.
/// 		 retorna 1: si ontiene Drama
int movies_filtrarDrama(void* pEstructura);
/// @fn int movies_filtrarComedia(void*)
/// @brief compara si la estructura contiene el genero Comedia
///
/// @param pEstructura
/// @return  retorna 0: no contiene Comedia.
/// 		 retorna 1: si ontiene Comedia
int movies_filtrarComedia(void* pEstructura);

/// @fn int movies_filtrarTerror(void*)
/// @brief Compara si la estructura contiene el genero Terror
///
/// @param pEstructura
/// @return  retorna 0: no contiene Terror.
/// 		 retorna 1: si ontiene Terror
int movies_filtrarTerror(void* pEstructura);

/// @fn int movies_filtrarAccion(void*)
/// @brief compara si la estructura contiene el genero Accion
///
/// @param pEstructura
/// @return  retorna 0: no contiene Accion.
/// 		 retorna 1: si ontiene Accion
int movies_filtrarAccion(void* pEstructura);




/// @fn int movies_compararPorGenero(void*, void*)
/// @brief compara los generos entre dos estructuras y retorna su resultado
///
/// @param pEstructura1
/// @param pEstructura2
/// @return	 retorna 1: Si el primero es mayor que el segundo
/// 		 retorna -1: Si el segundo es mayor que el primero
///			 retorna 0: Si son iguales o Fallo la validacion NULL.
int movies_compararPorGenero(void* pEstructura1, void* pEstructura2);
