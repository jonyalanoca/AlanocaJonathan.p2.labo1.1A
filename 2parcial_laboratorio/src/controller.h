/*
 * controller.h
 *
 *  Created on: 21 jun. 2022
 *      Author: Jony
 */
#include "LinkedList.h"
#ifndef CONTROLLER_H_
#define CONTROLLER_H_



#endif /* CONTROLLER_H_ */
/// @fn int controller_cargarArchivoTexto(char*, LinkedList*)
/// @brief abre un puntero a file en modo lectura y lo mantiene abierto hasta que se logre cargar los datos del archivo csv a un linkedlist
///
/// @param path
/// @param llLista
/// @return retorna -1: si falla la validacion NULL.
///			retorna  0:si salio todo bien
int controller_cargarArchivoTexto(char* path, LinkedList* llLista);
/// @fn int controller_listaLista(LinkedList*)
/// @brief muestra las estructuras del linked list en forma enculumnada y ordenada
///
/// @param llLista
/// @return retorna -1: si falla la validacion NULL.
///			retorna  0:si salio todo bien
int controller_listaLista( LinkedList* llLista);
/// @fn int controller_guardarArchivoTexto(char*, LinkedList*)
/// @brief guarda los registros del linkedlist en un archivo csv(si no existe lo crea) separados por coma
///
/// @param path
/// @param llLista
/// @return retorna -1: si falla la validacion NULL.
///			retorna  0:si salio todo bien
int controller_guardarArchivoTexto(char* path, LinkedList* llLista);
/// @fn int controller_limpiarElementos(LinkedList*)
/// @brief recorre el linked list y elimina todos los elementos de la memoria dinamica.
///
/// @param llLista
/// @return  retorna -1: si falla la validacion NULL.
///			retorna  0:si salio todo bien
int controller_limpiarElementos(LinkedList* llLista);

/// @fn int controller_asignarDuracion(LinkedList*)
/// @brief usa la funcion ll_map para asignar el valor duracion ea una estructura void
///
/// @param llLista
/// @return retorna -1: si falla la validacion NULL.
///			retorna  0:si salio todo bien
int controller_asignarRating( LinkedList* llLista);
/// @fn int controller_asignarGenero(LinkedList*)
/// @brief usa la funcion ll_map para asignar el valor Genero ea una estructura void
///
/// @param llLista
/// @return retorna -1: si falla la validacion NULL.
///			retorna  0:si salio todo bien
int controller_asignarGenero( LinkedList* llLista);
/// @fn int controller_filtrarGenero(LinkedList*, LinkedList*)
/// @brief crea un nuevo linkedlist filtrandolo con el criterio devuelto por el puntero a funcion. El nuevo linked list es guardado en listaFiltrada
///
/// @param llLista
/// @param listaFiltrada
/// @return  retorna -1: si falla la validacion NULL.
///			retorna  0:si salio todo bien
int controller_filtrarGenero(LinkedList* llLista , LinkedList* listaFiltrada);
/// @fn int controller_ordenarLista(LinkedList*)
/// @brief ordena la lista, usa ll_sort que lo ordena bajo el criterio de un puntero a funcion
///
/// @param llLista
/// @return retorna -1: si falla la validacion NULL.
///			retorna  0:si salio todo bien
int controller_ordenarLista(LinkedList* llLista);


/// @fn int controller_PedirArchivo(char*)
/// @brief pide una cadena de carcteres y verifica si es un  archivo csv existente
///
/// @param strArchivo
/// @return retorna -1: si falla la validacion NULL.
///			retorna  0:sno se encontro el archivo
/// 		retorna 1: si todo salio bien
int controller_PedirArchivo(char* strArchivo);
/// @fn int controller_VerificarCsv(char*)
/// @brief pide una cadena de caracteres y verifica si se ingreso nombre con la extencion .csv
///
/// @param strArchivo
/// @return retorna -1: si falla la validacion NULL.
///			retorna  0:si salio todo bien
int controller_VerificarCsv(char* strArchivo);
