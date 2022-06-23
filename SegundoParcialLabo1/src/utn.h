/*
 * utn.h
 *
 *  Created on: 21 jun. 2022
 *      Author: Dana
 */

#ifndef UTN_H_
#define UTN_H_

/**
 * Obtiene un string
 * @param arrayRecibido El string a obtener
 * @param textoAMostrar Texto que indica al usuario lo que debe ingresar
 */
int getString(char cadena[], int longitud, char mensaje [], char mensajeError[]);
/**
 * Pide al usuario un dato a traves de string y cambia el ultimo bit de '\n' a '\0'
 * @param cadena cadena a obtener
 * @param longitud largo de la cadena
 * @return devuelve -1 si hubo un error 0 si es correcto
 */
int myGets(char *cadena, int longitud);
/**
 * Pide un texto al usuario, lo almacena como cadena, valida y convierte el texto a numero y lo devuelve como int
 * @param pResultado Entero a devolver
 * @return devuelve -1 si hubo un error 0 si es correcto
 */
int getInt(int* pResultado);
/**
 * Recorre el string y valida que todos los caracteres sean numericos
 * @param cadena string a recorrer
 * @return devuelve -1 si hubo un error 0 si es correcto
 */
int esNumerica(char* cadena);
/**
 * Pide un entero al usuario, lo valida y lo devuelve
 * @param pResultado entero a devolver
 * @param mensaje indica al usuario lo que debe ingresar
 * @param mensajeError indica que hubo un error
 * @param minimo maximo valor que puede tomar el caracter del string
 * @param maximo minimo valor que puede tomar el caracter del string
 * @return devuelve -1 si hubo un error 0 si es correcto
 */
int utn_getNumber(int *pResultado, char mensaje[], char mensajeError[], int minimo, int maximo);
/**
 * Obtiene un numero flotante
 * @param pResultado donde se almacena el numero flotante
 * @return devuelve -1 si hubo un error 0 si es correcto
 */
int getFloat(float *pResultado);
/**
 * Pide un numero flotante al usuario, lo valida y lo devuelve
 * @param pResultado flotante a devolver
 * @param mensaje indica al usuario lo que debe ingresar
 * @param mensajeError indica que hubo un error
 * @param minimo maximo valor que puede tomar el caracter del string
 * @param maximo minimo valor que puede tomar el caracter del string
 * @return devuelve -1 si hubo un error 0 si es correcto
 */
int utn_getFloat(float *pResultado, char *mensaje, char *mensajeError, float minimo, float maximo);
/**
 * Obtiene una cadena de caracteres, la verifica y la devuelve
 * @param cadena cadena a verificar
 * @param mensaje indica al usuario lo que debe ingresar
 * @param mensajeError indica si hubo error
 * @return devuelve -1 si hubo un error 0 si es correcto
 */
int utn_getName(char* cadena, char* mensaje, char* mensajeError);
/**
 * Pasa el primer caracter de la cadena a mayus y transforma el resto en minus
 * @param cadena cadena a modificar
 */
void utn_corregirMayus(char* cadena);
/**
 * Toma una cadena y los caracteres q encuentre dentro de la mism los pasa a mayus
 * @param cadena cadena a analizar
 */
void utn_caracteresAMayus(char* cadena);

#endif /* UTN_H_ */
