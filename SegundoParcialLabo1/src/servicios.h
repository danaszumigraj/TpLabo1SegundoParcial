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

eServicios* Servicios_new();

eServicios* Servicios_newParametros(char* idStr, char* descripcionStr, char* tipoStr, char* precioUnitarioStr, char* cantidadStr, char* totalServicioStr);

int Servicios_setId(eServicios* this, int idAux);

int Servicios_getId(eServicios* this, int* idAux);

int Servicios_setDescripcion(eServicios* this, char* descripcionAux);

int Servicios_getDescripcion(eServicios* this, char* descripcionAux);

int Servicios_setTipo(eServicios* this, int tipoAux);

int Servicios_getTipo(eServicios* this, int* tipoAux);

int Servicios_setPrecioUnitario(eServicios* this, float precioUnitarioAux);

int Servicios_getPrecioUnitario(eServicios* this, float* precioUnitarioAux);

int Servicios_setCantidad(eServicios* this, int cantidadAux);

int Servicios_getCantidad(eServicios* this, int* cantidadAux);

int Servicios_setTotalServicio(eServicios* this, float totalServicioAux);

int Servicios_getTotalServicio(eServicios* this, float* totalServicioAux);

void Servicios_print(eServicios* this);

int Servicios_filtrarMinorista(void* this);

int Servicios_filtrarMayorista(void* this);

int Servicios_filtrarExportar(void* this);

void Servicios_asignarTotales(void* this);

int Servicios_sortByDescripcion(void* primerServicio, void* segundoServicio);

