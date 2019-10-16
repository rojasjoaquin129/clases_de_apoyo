#ifndef MUSICO_H_INCLUDED
#define MUSICO_H_INCLUDED

#define TEXT_SIZE 20

typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    char nombre[TEXT_SIZE];
    char apellido[TEXT_SIZE];
    int edad;
    int idOrq;
    int idInst;

}Musico;


#endif // MUSICO_H_INCLUDED

int Musico_inicializar(Musico array[], int size);
int Musico_buscarEmpty(Musico array[], int size, int* posicion);
int Musico_buscarID(Musico array[], int size, int valosBuscado, int* posicion);
int Musico_buscarOrq(Musico array[], int size, int valosBuscado, int* posicion);
int Musico_buscarInst(Musico array[], int size, int valosBuscado, int* posicion);

int Musico_alta(Musico array[], int size, int* contadorID);
int Musico_baja(Musico array[], int sizeArray);
int Musico_bajaValorRepetidoInt(Musico array[], int sizeArray, int valorBuscado);
int Musico_modificar(Musico array[], int sizeArray);
int Musico_listar(Musico array[], int size);
int Musico_ordenarPorApelldio(Musico array[],int size);



