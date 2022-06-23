/*
 ============================================================================
 Name        : SegundoParcialLabo1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "controller.h"
#include "servicios.h"
#include "parser.h"
#include "extras.h"
#include "utn.h"

int main(void)
{
	int opcionMenu = 0;
	int opcionLista = 0;

	int flagLista = 0;
	int flagGuardado = 0;
	int flagListaFiltrada = 0;

	LinkedList* listaServicios = ll_newLinkedList();
	LinkedList* listaFiltrada = ll_newLinkedList();

	setbuf(stdout,NULL);

	do
	{
		opcionMenu = mostrarMenu(opcionMenu);
		fflush(stdin);

		switch(opcionMenu)
		{
		//CARGAR ARCHIVO
		case 1:
			if(controller_loadFromText(listaServicios)==0)
			{
				printf("\nLista cargada con exito");
				flagLista = 1;
			}
			else
			{
				printf("\nHubo un error al intentar cargar la lista");
			}
		break;
		//IMPRIMIR LISTA
		case 2:
			if(flagLista == 1 && flagListaFiltrada == 0)
			{
				controller_ListServicios(listaServicios);
			}
			else if(flagLista == 1 && flagListaFiltrada == 1)
			{
				utn_getNumber(&opcionLista, "\nQue lista desea imprimir? \n1-Lista completa \n2- Lista filtrada", "\nEl numero ingresado no es valido, intente nuevamente \n1-Lista completa \n2- Lista filtrada", 1, 2);
				switch(opcionLista)
				{
				case 1:
					controller_ListServicios(listaServicios);
				break;
				case 2:
					controller_ListServicios(listaFiltrada);
				break;
				}
			}

			else
			{
				printf("\nPor favor cargue una lista antes de imprimir");
			}
		break;
		//ASIGNAR TOTALES
		case 3:
			if(flagLista == 1)
			{
				if(controller_asignarTotales(listaServicios)==0)
				{
					printf("\nSe asignaron totales con exito");
				}
				else
				{
					printf("\nHubo un error al intentar asignar totales");
				}
			}
			else
			{
				printf("\nPor favor cargue una lista antes de asignar totales");
			}

		break;
		//FILTRAR POR TIPO
		case 4:
			if(flagLista == 1)
			{
				listaFiltrada = controller_filter(listaServicios);
				if(listaFiltrada!=NULL)
				{
					printf("\nLa lista fue filtrada con exito");
					flagListaFiltrada = 1;
				}
				else
				{
					printf("\nHubo un error al intentar filtrar la lista");
				}
			}
			else
			{
				printf("\nPor favor cargue una lista antes de filtrar por tipo");
			}

		break;
		//MOSTRAR SERVICIOS
		case 5:
			if(flagLista == 1)
			{
				if(controller_sortServicio(listaServicios)==0)
				{
					printf("\nLista ordenada con exito\n");
					controller_ListServicios(listaServicios);
				}
				else
				{
					printf("\nHubo un error al intentar ordenar la lista");
				}
			}
			else
			{
				printf("\nPor favor cargue una lista antes de mostrar los servicios");
			}

		break;
		//GUARDAR SERVICIOS
		case 6:
			if(flagLista == 1)
			{
				if(controller_saveAsText("data.csv", listaServicios)==0)
				{
					printf("\nLista principal guardada con exito");
				}
				if(flagListaFiltrada == 1)
				{
					if(controller_saveAsText("data2.csv", listaFiltrada)==0)
					{
						printf("\nLista filtrada guardada con exito");
					}

				}
				flagGuardado =1;
			}
			else
			{
				printf("\nPor favor cargue una lista antes de guardar");
			}

		break;
		case 7:
			if(flagGuardado==1)
			{
				printf("\nVuelva pronto!!!");
			}
			else
			{
				printf("\nPor favor guarde los cambios antes de salir");
			}
		break;
		default:
			printf("\nOpcion no valida");
		break;
		}

	}while(opcionMenu!=7);


}
