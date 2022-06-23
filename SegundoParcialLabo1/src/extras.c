/*
 * extras.c
 *
 *  Created on: 21 jun. 2022
 *      Author: Dana
 */
#include <stdio.h>
#include <stdlib.h>
#include "Extras.h"

int mostrarMenu(int opcionIngresada)
{
	printf("\n-----------------Menu-----------------\n"
     "\n1. Cargar archivo."
     "\n2. Imprimir lista."
     "\n3. Asignar totales"
     "\n4. Filtrar por tipo"
     "\n5. Mostrar servicios"
     "\n6. Guardar servicios"
     "\n7. Salir"
	"\nIngrese una opcion\n");
	fflush(stdin);
	scanf("%d", &opcionIngresada);

	return opcionIngresada;

}
