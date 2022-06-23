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
 * \param pArrayServicios LinkedList* lista de servicios
 * \return int 0 si esta ok y -1 si hay problema
 */
int controller_loadFromText(LinkedList* pArrayServicios);
/**recorre el array de estructuras y lista los servicios
 * \param pArrayServicios lista de servicios
 * \return int 0 si esta ok -1 si hay problema
 */
int controller_ListServicios(LinkedList* pArrayServicios);
/**ordena los servicios por descripcion de forma ascendente
 * \param pArrayServicios lista de servicios
 * \return int 0 si esta ok -1 si hay problema
 */
int controller_sortServicio(LinkedList* pArrayServicios);
/**guarda el archivo como texto
 * \param path direccion del archivo
 * \param pArrayServicios lista de servicios
 * \return int 0 si esta ok -1 si hay problema
 */
int controller_saveAsText(char* path, LinkedList* pArrayServicios);
/**filtra segun el tipo de servicio
 * \param pArrayServicios lista de servicios
 * \return retorna la lista filtrada
 */
LinkedList* controller_filter(LinkedList* pArrayServicios);
/**asigna los totales de cada servicio
 * \param pArrayServicios lista de servicios
 * \return int 0 si esta ok -1 si hay problema
 */
int controller_asignarTotales(LinkedList* pArrayServicios);


#endif /* CONTROLLER_H_ */
