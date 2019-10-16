#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "instrumento.h"

//***************************************************************
//Init
/** \brief Indica que todas las posiciones del array estan vacias inicializando el campo isEmpty en TRUE
* \param array Instrumento Array de Instrumento
* \param size int Array length
* \return int Return (-1) si Error [tamaño invalido o NULL pointer] - (0) si Ok
*
*/
int Instrumento_inicializar(Instrumento array[], int size)
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>=0;size--)
        {
            array[size].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Buscar
/** \brief Busca el primer lugar vacio en un array
* \param array Instrumento Array de Instrumento
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [tamaño invalido o NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int Instrumento_buscarEmpty(Instrumento array[], int size, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array Instrumento Array de Instrumento
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [tamaño invalido o NULL pointer] - (0) si encuentra el valor buscado
*
*/
int Instrumento_buscarID(Instrumento array[], int size, int valosBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idUnico==valosBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array Instrumento Array de Instrumento
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int Instrumento_alta(Instrumento array[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(Instrumento_buscarEmpty(array,size,&posicion)==-1)                          //cambiar Tipo
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            if( utn_getTexto("\nNombre: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre) == 0  &&
                utn_getUnsignedInt("\nTipo: ","\nError",1,sizeof(int),1,&array[posicion].tipo) == 0)
            {
                (*contadorID)++;
                array[posicion].idUnico=*contadorID;
                array[posicion].isEmpty=0;

                printf("\nID: %d",array[posicion].idUnico);
                retorno=0;
            }
            else
            {
                printf("\nAlta no exitosa");
            }
        }
    }
    return retorno;
}

//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array Instrumento Array de Instrumento
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int Instrumento_listar(Instrumento array[], int size)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
            {
                printf("\n ID: %d   Nombre: %s  Tipo: ",
                       array[i].idUnico,array[i].nombre);
                if(array[i].tipo==1)
                    printf("Cuerdas");
                else if(array[i].tipo==2)
                    printf("Viento-madera");
                else if(array[i].tipo==3)
                    printf("Viento-metal");
                else if(array[i].tipo==4)
                    printf("Percusion");
                else
                    printf("Desconocido");
            }
        }
        retorno=0;
    }
    return retorno;
}
