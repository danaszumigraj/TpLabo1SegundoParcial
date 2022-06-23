/*
 * utn.c
 *
 *  Created on: 21 jun. 2022
 *      Author: Dana
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"

int getString(char cadena[], int longitud, char mensaje [], char mensajeError[])
{
	int retorno = -1;
	char cadenaAux[longitud];

	if(cadena!=NULL && longitud > 0)
	{
		printf(mensaje);
		if(myGets(cadenaAux, longitud)==0)
		{
			strcpy(cadena, cadenaAux);
			retorno = 0;

		}
		else
		{
			printf(mensajeError);
		}
	}
	return retorno;
}
int myGets(char *cadena, int longitud)
{
	int retorno = -1;

	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		if (fgets(cadena, longitud, stdin))
		{
			cadena[strlen(cadena)-1] = '\0';
		}
		retorno = 0;
	}

	return retorno;
}

int getInt(int* pResultado)
{
int retorno=-1;
char buffer[64];
if(pResultado != NULL)
{
	if(myGets(buffer,sizeof(buffer))==0 && esNumerica(buffer))
	{
		*pResultado = atoi(buffer);
		retorno = 0;
	}
}
return retorno;
}

int esNumerica(char* cadena)
{
int i=0;
int retorno = 1;
if(cadena != NULL && strlen(cadena) > 0)
{
	while(cadena[i] != '\0')
	{
		if(cadena[i] < '0' || cadena[i] > '9' )
		{
			retorno = 0;
			break;
		}
		i++;
	}
}
return retorno;
}



int utn_getNumber(int *pResultado, char mensaje[], char mensajeError[], int minimo, int maximo)
{
	int bufferInt;
	int retorno = -1;

	while (retorno != 0)
	{
		printf("%s", mensaje);
		if (getInt(&bufferInt) == 0)
		{
			if (bufferInt >= minimo && bufferInt <= maximo)
			{
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
		}
		printf("%s", mensajeError);
	}
	return retorno;
}



int getFloat(float *pResultado)
{
	int retorno = -1;
	char buffer[64];

	if (pResultado != NULL)
	{
		if (myGets(buffer, sizeof(buffer)) == 0 && esNumerica(buffer))
		{
			*pResultado = atof(buffer);
			retorno = 0;
		}
	}
	return retorno;
}

int utn_getFloat(float *pResultado, char *mensaje, char *mensajeError, float minimo, float maximo)
{
	float bufferFloat;
	int retorno = -1;

	while (retorno != 0)
	{
		printf("%s", mensaje);
		if (getFloat(&bufferFloat) == 0)
		{
			if (bufferFloat >= minimo && bufferFloat <= maximo)
			{
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
		}
		printf("%s", mensajeError);
	}
	return retorno;
}

int utn_getName(char* cadena, char* mensaje, char* mensajeError)
{
	int retorno = 1;

	while(retorno != 0)
	{
		printf(mensaje);
		fflush(stdin);
		gets(cadena);
		for (int i = 0; i < strlen(cadena); i++)
		{
			if(isalpha(cadena[i]) == 0 && isspace(cadena[i]) == 0 && cadena[i] != 'ñ')
			{
				retorno = 1;
				printf(mensajeError);
				break;
			}
			retorno = 0;
		}
	}

	utn_corregirMayus(cadena);

	return retorno;
}

void utn_corregirMayus(char* cadena)
{
	strlwr(cadena);

	cadena[0] = toupper(cadena[0]);

	for(int i = 0; i < strlen(cadena); i++)
	{
		if (cadena[i] == ' ')
		{
			cadena[i + 1] = toupper(cadena[i + 1]);
		}
	}
}

void utn_caracteresAMayus(char* cadena)
{
	for(int i = 0; i < strlen(cadena); i++)
	{
		if(isalpha(cadena[i]))
		{
			cadena[i]=toupper(cadena[i]);
		}
	}
}
