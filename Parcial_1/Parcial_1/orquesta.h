#include "musico.h"
#ifndef ORQUESTA_H_INCLUDED
#define ORQUESTA_H_INCLUDED

#define TEXT_SIZE 20

typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    char nombre[TEXT_SIZE];
    char lugar[TEXT_SIZE];
    int tipo;

}Orquesta;

#endif // ORQUESTA_H_INCLUDED

int Orquesta_inicializar(Orquesta array[], int size);
int Orquesta_buscarEmpty(Orquesta array[], int size, int* posicion);
int Orquesta_buscarID(Orquesta array[], int size, int valosBuscado, int* posicion);
int Orquesta_alta(Orquesta array[], int size, int* contadorID);
int Orquesta_baja(Orquesta array[], int sizeArray, Musico arrayMusico[], int sizeMusico);
int Orquesta_listar(Orquesta array[], int size);



