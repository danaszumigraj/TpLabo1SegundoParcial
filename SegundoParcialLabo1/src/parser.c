/*
 * parser.c
 *
 *  Created on: 21 jun. 2022
 *      Author: Dana
 */
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "controller.h"
#include "servicios.h"
#include "parser.h"
#include "extras.h"

int parser_ServiceFromText(FILE* pFile, LinkedList* pArrayServicios)
{
	int retorno = -1;
	int r;

	char id_servicio[TAM_DATO];
	char descripcion[TAM_DATO];
	char tipo[TAM_DATO];
	char precioUnitario[TAM_DATO];
	char cantidad[TAM_DATO];
	char totalServicio[TAM_DATO];

	eServicios* unServicio;

	if(pFile!=NULL && pArrayServicios!=NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id_servicio, descripcion, tipo, precioUnitario, cantidad, totalServicio);

		while(!feof(pFile))
		{
			r= fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id_servicio, descripcion, tipo, precioUnitario, cantidad, totalServicio);
			if(r==6)
			{
				unServicio = Servicios_newParametros(id_servicio, descripcion, tipo, precioUnitario, cantidad, totalServicio);
				if(unServicio!=NULL)
				{
					if(ll_add(pArrayServicios, unServicio)==0)
					{
						retorno = 0;
					}
				}
			}
		}
	}
	fclose(pFile);

	return retorno;
}
