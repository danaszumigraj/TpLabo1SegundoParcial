/*
 * servicios.h
 *
 *  Created on: 21 jun. 2022
 *      Author: Dana
 */

#ifndef SERVICIOS_H_
#define SERVICIOS_H_

#define TAM_DESCRIPCION 50

typedef struct
{
	int id_servicio;
	char descripcion[TAM_DESCRIPCION];
	int tipo;
	float precioUnitario;
	int cantidad;
	float totalServicio;

}eServicios;

#endif /* SERVICIOS_H_ */

/**
 * genera un nuevo servicio en memoria
 */
eServicios* Servicios_new();
/**
 * asigna los valores de cada dato al nuevo servicio en memoria
 * \param idStr
 * \param descripcionStr
 * \param tipoStr
 * \param precioUnitarioStr
 * \param cantidadStr
 * \param totalServicioStr
 */
eServicios* Servicios_newParametros(char* idStr, char* descripcionStr, char* tipoStr, char* precioUnitarioStr, char* cantidadStr, char* totalServicioStr);
/**
 * asigna un id a un servicio
 * \param this el servicio
 * \param idAux id a asignar
 */
int Servicios_setId(eServicios* this, int idAux);
/**
 * Obtiene un id a partir de un servicio
 * \param this el servicio
 * \param idAux el puntero donde se guarda el id
 */
int Servicios_getId(eServicios* this, int* idAux);
/**
 * asigna una descipcion a un servicio
 * \param this el servicio
 * \param descripcionAux descripcion a asignar
 * \return int 0 si esta ok -1 si hay problema
 */
int Servicios_setDescripcion(eServicios* this, char* descripcionAux);
/**
 * obtiene una descripcion a partir de un servicio
 * \param this el servicio
 * \param descipcionAux es donde se guarda la descripcion obtenida
 * \return int 0 si esta ok -1 si hay problema
 */
int Servicios_getDescripcion(eServicios* this, char* descripcionAux);
/**
 * asigna un tipo a un servicio
 * \param this el servicio
 * \param tipoAux el tipo a asignar
 * \return int 0 si esta ok -1 si hay problema
 */
int Servicios_setTipo(eServicios* this, int tipoAux);
/**
 * Obtiene un tipo a partir de un servicio
 * \param this el servicio
 * \tipoAux puntero donde se guarda el tipo obtenido
 * \return int 0 si esta ok -1 si hay problema
 */
int Servicios_getTipo(eServicios* this, int* tipoAux);
/**
 * Asigna un precio unitario a un servicio
 * \param this el servicio
 * \param precioUnitarioAux el precio a asignar
 * \return int 0 si esta ok -1 si hay problema
 */
int Servicios_setPrecioUnitario(eServicios* this, float precioUnitarioAux);
/**
 * Obtiene un precio unitario a partir de un servicio
 * \param this el servicio
 * \param precioUnitarioAux puntero donde se guarda el precio
 * \return int 0 si esta ok -1 si hay problema
 */
int Servicios_getPrecioUnitario(eServicios* this, float* precioUnitarioAux);
/**
 * asigna una cantidad a un servicio
 * \param this el servicio
 * \param cantidadAux cantidad a asignar
 * \return int 0 si esta ok -1 si hay problema
 */
int Servicios_setCantidad(eServicios* this, int cantidadAux);
/**
 * obtiene una cantidad a partir de un servicio
 * \param this el servicio
 * \param cantidadAux puntero donde se guarda la cantidad obtenida
 * \return int 0 si esta ok -1 si hay problema
 */
int Servicios_getCantidad(eServicios* this, int* cantidadAux);
/**
 * asigna un total por el servicio en un servicio
 * \param this el servicio
 * \total servicio dato a asignar
 * \return int 0 si esta ok -1 si hay problema
 */
int Servicios_setTotalServicio(eServicios* this, float totalServicioAux);
/**
 * obtiene un total por el servicio a partir de un servicio
 * \param this el servicio
 * \totalServicioAux puntero donde se guarda el total
 * \return int 0 si esta ok -1 si hay problema
 */
int Servicios_getTotalServicio(eServicios* this, float* totalServicioAux);
/**
 * imprime un servicio
 * \param this el servicio a imprimir
 * \return int 0 si esta ok -1 si hay problema
 */
void Servicios_print(eServicios* this);
/**
 * indica si el servicio dado es del tipo deseado
 * \param this el servicio
 * \return int 0 si esta ok -1 si hay problema
 */
int Servicios_filtrarMinorista(void* this);
/**
 * indica si el servicio dado es del tipo deseado
 * \param this el servicio
 * \return int 0 si esta ok -1 si hay problema
 */
int Servicios_filtrarMayorista(void* this);
/**
 * indica si el servicio dado es del tipo deseado
 * \param this el servicio
 * \return int 0 si esta ok -1 si hay problema
 */
int Servicios_filtrarExportar(void* this);
/**
 * calcula el total por el servicio a un servicio
 * \param this el servicio
 * \return int 0 si esta ok -1 si hay problema
 */
void Servicios_asignarTotales(void* this);
/**
 * compara dos servicios por su descipcion
 * \param this el servicio
 * \return int devuelve la comparacion
 */
int Servicios_sortByDescripcion(void* primerServicio, void* segundoServicio);

