/*
 * controller.h
 *
 *  Created on: 21 jun. 2022
 *      Author: Dana
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#define TAM_DESCRIPCION 50

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 * \param path char* ubicacion del archivo
 * \param pArrayListPassenger LinkedList* lista de pasajeros
 * \return int 0 si esta ok y -1 si hay problema
 *
 */
int controller_loadFromText(LinkedList* pArrayServicios);

int controller_ListServicios(LinkedList* pArrayListServicios);

int controller_sortServicio(LinkedList* pArrayListServicios);

int controller_saveAsText(char* path, LinkedList* pArrayListServicios);

LinkedList* controller_filter(LinkedList* pArrayServicios);
int controller_asignarTotales(LinkedList* pArrayServicios);


#endif /* CONTROLLER_H_ */
