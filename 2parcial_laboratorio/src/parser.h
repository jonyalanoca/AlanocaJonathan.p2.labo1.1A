/*
 * parser.h
 *
 *  Created on: 14 jun. 2022
 *      Author: Jony
 */
#include "LinkedList.h"
#ifndef PARSER_H_
#define PARSER_H_



#endif /* PARSER_H_ */

/// @fn int parser_cargarTexto(FILE*, LinkedList*)
/// @brief carga los datos a una estructura desde un archivo csv
///
/// @param pFile
/// @param listaCPU
/// @return retorna -1: si falla la validacion NULL.
///			retorna  0:si salio todo bien
int parser_cargarTexto(FILE* pFile, LinkedList* listaCPU);
