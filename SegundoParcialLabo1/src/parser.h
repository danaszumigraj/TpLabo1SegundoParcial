/*
 * parser.h
 *
 *  Created on: 21 jun. 2022
 *      Author: Dana
 */

#ifndef PARSER_H_
#define PARSER_H_

#define TAM_DATO 50
/** \brief Parsea los datos los datos de los servicios desde el archivo data.csv (modo texto).
 *
 * \param path char* ubicacion del archivo
 * \param pArrayServicios LinkedList* lista de servicios
 * \return int
 *
 */
int parser_ServiceFromText(FILE* pFile, LinkedList* pArrayServicios);

#endif /* PARSER_H_ */
