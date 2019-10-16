#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "orquesta.h"
#include "musico.h"


/*
Funciones:
    Alta
    Baja elimina tmb musico
    Imprimir

*/

//***************************************************************
//Init
/** \brief Indica que todas las posiciones del array estan vacias inicializando el campo isEmpty en TRUE
* \param array Orquesta Array de Orquesta
* \param size int Array length
* \return int Return (-1) si Error [tamaño invalido o NULL pointer] - (0) si Ok
*
*/
int Orquesta_inicializar(Orquesta array[], int size)
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
* \param array Orquesta Array de Orquesta
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [tamaño invalido o NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int Orquesta_buscarEmpty(Orquesta array[], int size, int* posicion)
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
* \param array Orquesta Array de Orquesta
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [tamaño invalido o NULL pointer] - (0) si encuentra el valor buscado
*
*/
int Orquesta_buscarID(Orquesta array[], int size, int valosBuscado, int* posicion)
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
* \param array Orquesta Array de Orquesta
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int Orquesta_alta(Orquesta array[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(Orquesta_buscarEmpty(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            if( utn_getTexto("\nNombre: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre) == 0  &&
                utn_getTexto("\nLugar: ","\nError",1,TEXT_SIZE,1,array[posicion].lugar) ==0 &&
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
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array Orquesta Array de Orquesta
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int Orquesta_baja(Orquesta array[], int sizeArray, Musico arrayMusico[], int sizeMusico)
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        Orquesta_listar(array,sizeArray);
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,&id);
        if(Orquesta_buscarID(array,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idUnico=0;
            array[posicion].tipo=0;
            strcpy(array[posicion].nombre,"");
            strcpy(array[posicion].lugar,"");

            Musico_bajaValorRepetidoInt(arrayMusico,sizeMusico,id);

            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array Orquesta Array de Orquesta
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int Orquesta_listar(Orquesta array[], int size)
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
                printf("\n ID: %d   Nombre: %s  Lugar: %s   Tipo: ",
                       array[i].idUnico,array[i].nombre,array[i].lugar);
                if(array[i].tipo==1)
                    printf("Sinfonica");
                else if(array[i].tipo==2)
                    printf("Filarmonica");
                else if(array[i].tipo==3)
                    printf("Camara");
                else
                    printf("Desconocido");
            }
        }
        retorno=0;
    }
    return retorno;
}
