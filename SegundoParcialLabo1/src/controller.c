/*
 * controller.c
 *
 *  Created on: 21 jun. 2022
 *      Author: Dana
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "controller.h"
#include "servicios.h"
#include "parser.h"
#include "extras.h"
#include "utn.h"

int controller_loadFromText(LinkedList* pArrayServicios)
{
	int retorno = -1;
	char path[20];
	FILE* pFile;

	getString(path, 20, "\nIngrese el nombre del archivo que desea abrir", "\nEl dato ingresado no es valido");
	strcat(path,".csv");
	fflush(stdin);

	if(pArrayServicios!=NULL)
	{
		if(path!=NULL)
		{
			if(ll_len(pArrayServicios) > 0)
			{
				ll_clear(pArrayServicios);
			}

			pFile = fopen(path, "r");

			if(pFile!=NULL)
			{
				if(parser_ServiceFromText(pFile, pArrayServicios)==0)
				{
					retorno = 0;
				}
			}
			fclose(pFile);
		}
	}
	return retorno;
}

int controller_ListServicios(LinkedList* pArrayListServicios)
{
	int retorno = -1;
	eServicios* unServicio;

	printf("||==========================================================================================||\n");
	for(int i=0; i<ll_len(pArrayListServicios); i++)
	{
		unServicio = (eServicios*) ll_get(pArrayListServicios, i);
		Servicios_print(unServicio);
		retorno = 0;
	}
	printf("||==========================================================================================||\n");

	return retorno;
}

int controller_asignarTotales(LinkedList* pArrayServicios)
{
	int retorno = -1;

	if(pArrayServicios!=NULL)
	{
		ll_map(pArrayServicios, Servicios_asignarTotales);
		retorno = 0;
	}

	return retorno;
}

LinkedList* controller_filter(LinkedList* pArrayServicios)
{
	int tipoAFiltrar;

	LinkedList* pListaFiltrada = NULL;

	if(pArrayServicios!=NULL)
	{
		if(utn_getNumber(&tipoAFiltrar, "\nSeleccione un tipo a filtrar (1-MINORISTA 2- MAYORISTA 3-EXPORTAR)", "El tipo ingresado no es valido(1-MAYORISTA 2- MINORISTA 3-EXPORTAR)", 1, 3)==0)
		{
			switch(tipoAFiltrar)
			{
			case 1:
				pListaFiltrada = ll_filter(pArrayServicios, Servicios_filtrarMinorista);
			break;
			case 2:
				pListaFiltrada = ll_filter(pArrayServicios, Servicios_filtrarMayorista);
			break;
			case 3:
				pListaFiltrada = ll_filter(pArrayServicios, Servicios_filtrarExportar);
			break;
			}
		}
	}
	return pListaFiltrada;
}

int controller_sortServicio(LinkedList* pArrayServicios)
{
	int retorno = -1;
	if(pArrayServicios!=NULL)
	{
		printf("\nAguarde un segundo por favor...\n");
		ll_sort(pArrayServicios, Servicios_sortByDescripcion, 1);
		retorno = 0;

	}

	return retorno;
}

int controller_saveAsText(char* path, LinkedList* pArrayServicios)
{
	int retorno = -1;
	{
		eServicios* unServicio;
		FILE* pFile;

		int retorno = -1;

		int id;
		char descripcion[TAM_DESCRIPCION];
		int tipo;
		float precioUnitario;
		int cantidad;
		float totalServicio;

		int len;

		if(pArrayServicios!=NULL && path!=NULL)
		{
			pFile = fopen(path, "w");
			if(pFile!=NULL)
			{
				len = ll_len(pArrayServicios);
				if(len>0)
				{
					fprintf(pFile, "id_servicio, descripcion, tipo, precioUnitario, cantidad, totalServicio \n");
					for(int i = 0; i<len; i++)
					{
						unServicio = (eServicios*) ll_get(pArrayServicios,i);
						if(unServicio!=NULL)
						{
							if(Servicios_getId(unServicio, &id)==0)
							{
								if(Servicios_getDescripcion(unServicio, descripcion)==0)
								{
									if(Servicios_getTipo(unServicio, &tipo)==0)
									{
										if(Servicios_getPrecioUnitario(unServicio, &precioUnitario)==0)
										{
											if(Servicios_getCantidad(unServicio, &cantidad)==0)
											{
												if(Servicios_getTotalServicio(unServicio, &totalServicio)==0)
												{
													fprintf(pFile, "%d, %s, %d, %.2f, %d, %.2f \n", id, descripcion, tipo, precioUnitario, cantidad, totalServicio);
													retorno = 0;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}

		fclose(pFile);
		return retorno;
	}

	return retorno;
}
