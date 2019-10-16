#ifndef INSTRUMENTO_H_INCLUDED
#define INSTRUMENTO_H_INCLUDED

#define TEXT_SIZE 20

typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    char nombre[TEXT_SIZE];
    int tipo;
}Instrumento;

typedef struct{
    int idLugar;
    char nombreLugar[TEXT_SIZE];
}Lugar;

#endif // INSTRUMENTO_H_INCLUDED

int Instrumento_inicializar(Instrumento array[], int size);
int Instrumento_buscarEmpty(Instrumento array[], int size, int* posicion);
int Instrumento_buscarID(Instrumento array[], int size, int valosBuscado, int* posicion);
int Instrumento_alta(Instrumento array[], int size, int* contadorID);
int Instrumento_listar(Instrumento array[], int size);

