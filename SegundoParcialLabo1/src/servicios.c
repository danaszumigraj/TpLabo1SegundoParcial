/*
 * servicios.c
 *
 *  Created on: 21 jun. 2022
 *      Author: Dana
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "controller.h"
#include "servicios.h"
#include "parser.h"
#include "extras.h"

eServicios* Servicios_new(void)
{
	eServicios* unServicio;
	unServicio = (eServicios*) malloc (sizeof(eServicios));

	return unServicio;
}

eServicios* Servicios_newParametros(char* idStr, char* descripcionStr, char* tipoStr, char* precioUnitarioStr, char* cantidadStr, char* totalServicioStr)
{
	eServicios* unServicio;
	unServicio = Servicios_new();
	int validacion = -1;

	if(unServicio!=NULL)
	{
		if(Servicios_setId(unServicio, atoi(idStr))==0)
		{
			if(Servicios_setDescripcion(unServicio, descripcionStr)==0)
			{
				if(Servicios_setTipo(unServicio, atoi(tipoStr))==0)
				{
					if(Servicios_setPrecioUnitario(unServicio, atof(precioUnitarioStr))==0)
					{
						if(Servicios_setCantidad(unServicio, atoi(cantidadStr))==0)
						{
							if(Servicios_setTotalServicio(unServicio, atof(totalServicioStr))==0)
							{
								validacion = 0;
							}
						}
					}
				}
			}
		}
	}

	if(validacion != 0)
	{
		unServicio = NULL;
	}

	return unServicio;
}

int Servicios_setId(eServicios* this, int idAux)
{
	int retorno = -1;
	if(this!=NULL && idAux>0)
	{
		this->id_servicio = idAux;
		retorno = 0;

	}

	return retorno;
}

int Servicios_getId(eServicios* this, int* idAux)
{
	int retorno = -1;
	if(this!=NULL && idAux!=NULL)
	{
		*idAux = this->id_servicio;
		retorno = 0;
	}

	return retorno;
}

int Servicios_setDescripcion(eServicios* this, char* descripcionAux)
{
	int retorno = -1;
	if(this!=NULL && descripcionAux!=NULL)
	{
		strcpy(this->descripcion, descripcionAux);
		retorno = 0;
	}

	return retorno;
}

int Servicios_getDescripcion(eServicios* this, char* descripcionAux)
{
	int retorno = -1;
	if(this!=NULL && descripcionAux!=NULL)
	{
		strcpy(descripcionAux, this->descripcion);
		retorno = 0;
	}

	return retorno;
}

int Servicios_setTipo(eServicios* this, int tipoAux)
{
	int retorno = -1;
	if(this!=NULL && tipoAux >=1 && tipoAux<=3)
	{
		this->tipo = tipoAux;
		retorno = 0;
	}

	return retorno;
}

int Servicios_getTipo(eServicios* this, int* tipoAux)
{
	int retorno = -1;
	if(this!=NULL && tipoAux!=NULL)
	{
		*tipoAux = this->tipo;
		retorno = 0;
	}

	return retorno;
}

int Servicios_setPrecioUnitario(eServicios* this, float precioUnitarioAux)
{
	int retorno = -1;
	if(this!=NULL && precioUnitarioAux > 0)
	{
		this->precioUnitario = precioUnitarioAux;
		retorno = 0;
	}

	return retorno;
}

int Servicios_getPrecioUnitario(eServicios* this, float* precioUnitarioAux)
{
	int retorno = -1;
	if(this!=NULL && precioUnitarioAux!=NULL)
	{
		*precioUnitarioAux = this->precioUnitario;
		retorno = 0;
	}

	return retorno;
}

int Servicios_setCantidad(eServicios* this, int cantidadAux)
{
	int retorno = -1;
	if(this!=NULL && cantidadAux>0)
	{
		this->cantidad = cantidadAux;
		retorno = 0;
	}

	return retorno;
}

int Servicios_getCantidad(eServicios* this, int* cantidadAux)
{
	int retorno = -1;
	if(this!=NULL && cantidadAux!=NULL)
	{
		*cantidadAux = this->cantidad;
		retorno = 0;
	}

	return retorno;
}

int Servicios_setTotalServicio(eServicios* this, float totalServicioAux)
{
	int retorno = -1;
	if(this!=NULL && totalServicioAux>=0)
	{
		this->totalServicio = totalServicioAux;
		retorno = 0;
	}

	return retorno;
}

int Servicios_getTotalServicio(eServicios* this, float* totalServicioAux)
{
	int retorno = -1;
	if(this!=NULL && totalServicioAux!=NULL)
	{
		*totalServicioAux = this->totalServicio;
		retorno = 0;
	}

	return retorno;
}

void Servicios_print(eServicios* this)
{
	char tipoAux[20];
	if(this!=NULL)
	{
		switch(this->tipo)
		{
		case 1:
			strcpy(tipoAux, "MINORISTA");
		break;
		case 2:
			strcpy(tipoAux, "MAYORISTA");
		break;
		case 3:
			strcpy(tipoAux, "EXPORTAR");
		break;
		}

		printf("|| %-6d || %-23s || %-15s || %-9.2f || %5d || %10.2f ||\n", this->id_servicio, this->descripcion, tipoAux, this->precioUnitario, this->cantidad, this->totalServicio);
	}
}

int Servicios_filtrarMinorista(void* this)
{
	int retorno = -1;
	int tipoAux;

	if(this!=NULL)
	{
		if(Servicios_getTipo(this, &tipoAux)==0)
		{
			if(tipoAux == 1)
			{
				retorno = 0;
			}
		}
	}

	return retorno;
}

int Servicios_filtrarMayorista(void* this)
{
	int retorno = -1;
	int tipoAux;

	if(this!=NULL)
	{
		if(Servicios_getTipo(this, &tipoAux)==0)
		{
			if(tipoAux == 2)
			{
				retorno = 0;
			}
		}
	}

	return retorno;
}

int Servicios_filtrarExportar(void* this)
{
	int retorno = -1;
	int tipoAux;

	if(this!=NULL)
	{
		if(Servicios_getTipo(this, &tipoAux)==0)
		{
			if(tipoAux == 3)
			{
				retorno = 0;
			}
		}
	}

	return retorno;
}

void Servicios_asignarTotales(void* this)
{
	int cantidadAux;
	float precioUnitarioAux;
	float totalServicioAux;
	if(this!=NULL)
	{
		if(Servicios_getPrecioUnitario(this, &precioUnitarioAux)==0)
		{
			if(Servicios_getCantidad(this, &cantidadAux)==0)
			{
				totalServicioAux = precioUnitarioAux * cantidadAux;
				Servicios_setTotalServicio(this, totalServicioAux);
			}
		}
	}

}

int Servicios_sortByDescripcion(void* primerServicio, void* segundoServicio)
{
	int retorno = -1;

	eServicios* pPrimerServicio;
	eServicios* pSegundoServicio;

	char primerDescripcion[TAM_DESCRIPCION];
	char segundaDescripcion[TAM_DESCRIPCION];

	pPrimerServicio = (eServicios*) primerServicio;
	pSegundoServicio = (eServicios*) segundoServicio;

	if(primerServicio!=NULL && segundoServicio!=NULL)
	{
		if(Servicios_getDescripcion(pPrimerServicio, primerDescripcion)==0)
		{
			if(Servicios_getDescripcion(pSegundoServicio, segundaDescripcion)==0)
			{
				retorno = strcmp(primerDescripcion, segundaDescripcion);
			}
		}
	}
	return retorno;
}
