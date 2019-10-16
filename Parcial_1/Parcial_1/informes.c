#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "informes.h"
#include "instrumento.h"
#include "musico.h"
#include "orquesta.h"


/** \brief Lista los elementos del array de musicos e instrumento vinculado
* \param arrayA Musico Array de Musico
* \param arrayB Instrumento Array de Instrumento
* \param sizeI int Tamaño del arrayA
* \param sizeJ int Tamaño del arrayB
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) Ok
*
*/
int Informes_listarMusicos(Musico arrayA[], Instrumento arrayB[], int sizeI, int sizeJ)
{
    int retorno=-1;
    int i;
    int j;
    int flag=-1;
    if(arrayA!=NULL && sizeI>=0 && arrayB!=NULL && sizeJ>=0)
    {
        for(i=0;i<sizeI;i++)                                                                            //Obtengo la posicion de la primer entidad
        {
            if(arrayA[i].isEmpty!=1)
            {
                if(Instrumento_buscarID(arrayB,sizeJ,arrayA[i].idInst,&j)==-1)                           //Obtengo la posicion de la 2da entidad buscando por el campo en comun
                    j=-1;

                printf("\nID: %d   Nombre: %s  Apellido: %s    Edad: %d    ", arrayA[i].idUnico,arrayA[i].nombre,arrayA[i].apellido,arrayA[i].edad);
                if(j==-1)
                    printf("    ID instrumento desconocido");
                else
                {
                    printf("     Nombre instrumento: %s     Tipo instrumento: ",arrayB[j].nombre);
                    if(arrayB[j].tipo==1)
                        printf("Cuerdas");
                    else if(arrayB[j].tipo==2)
                        printf("Viento-madera");
                    else if(arrayB[j].tipo==3)
                        printf("Viento-metal");
                    else if(arrayB[j].tipo==4)
                        printf("Percusion");
                    else
                        printf("Desconocido");
                }
                flag=0;
            }
        }
        if(flag==-1)
            printf("\nNo se encontraron musicos");
        retorno=0;
    }
    return retorno;
}

//A listar orquesta de un lugar en particular ingresado por el usuario, imprimir ID orquesta, nombre, tipo y lugar
/** \brief Solicita un lugar y lista las orquestas correspondientes a ese lugar
* \param array Orquesta Array de Orquesta
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int Informes_a_listarOrqPorLugar(Orquesta array[], int size)
{
    int retorno=-1;
    int i;
    char criterio[TEXT_SIZE];
    int flag=-1;
    if(array!=NULL && size>=0)
    {
        if(utn_getTexto("\nLugar: ","\nError",1,TEXT_SIZE,1,criterio)==0)
        {
            for(i=0;i<size;i++)
            {
                if(array[i].isEmpty!=1 && strcmp(array[i].lugar,criterio)==0)
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
                    flag=0;
                }
            }
            if(flag==-1)
                printf("\nNo se han encontrado orquestas para el lugar indicado");
        }
        retorno=0;
    }
    return retorno;
}


//B Listar musico: menores de 25 años, mostrar id, nombre apellido, edad, nombre instrumento, nombre orquesta

/** \brief Lista los musicos menores de 25 años con informacion de arrays vinculados
* \param arrayA Musico Array de Musico
* \param arrayB Orquesta Array de Orquesta
* \param arrayC Instrumento Array de Instrumento
* \param sizeI int Tamaño del arrayA
* \param sizeJ int Tamaño del arrayB
* \param sizeK int Tamaño del arrayC
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) Ok
*
*/
int Informes_b_listarMusicosEdad(Musico arrayA[], Orquesta arrayB[], Instrumento arrayC[], int sizeI, int sizeJ, int sizeK)
{
    int retorno=-1;
    int i;
    int j;
    int k;
    int flag=-1;
    if(arrayA!=NULL && sizeI>=0 && arrayB!=NULL && sizeJ>=0 && arrayC!=NULL && sizeK>=0)
    {
        printf("\nMusicos menores de 25:");
        for(i=0;i<sizeI;i++)                                                                            //Obtengo la posicion de la primer entidad
        {
            if(arrayA[i].isEmpty!=1 && arrayA[i].edad<25)
            {
                if(Orquesta_buscarID(arrayB,sizeJ,arrayA[i].idOrq,&j)==-1)
                    j=-1;
                if(Instrumento_buscarID(arrayC,sizeK,arrayA[i].idInst,&k)==-1)
                    k=-1;
                printf("\n ID: %d   Nombre: %s  Apellido: %s    Edad: %d  ",
                       arrayA[i].idUnico,arrayA[i].nombre,arrayA[i].apellido,arrayA[i].edad);
                if(k==-1)
                    printf("    Instrumento desconocido");
                else
                    printf("    Nombre instrumento: %s",arrayC[k].nombre);
                if(j==-1)
                    printf("    Orquesta desconocida");
                else
                    printf("    Nombre orquesta: %s",arrayB[j].nombre);
                flag=0;
            }
        }
        if(flag==-1)
            printf("\nNo se encontraron musicos menores de 25");
        retorno=0;
    }
    return retorno;
}

//C Listar orquestas con menos de 6 musicos, imprime ID orquesta, nombre, tipo y lugar
/** \brief Lista las orquestas con menos de 6 musicos
* \param arrayA Orquesta Array de Orquesta
* \param arrayB Musico Array de Musico
* \param sizeI int Tamaño del arrayA
* \param sizeJ int Tamaño del arrayB
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) Ok
*
*/
int Informes_c_listarOrqCantMusico(Orquesta arrayA[], Musico arrayB[], int sizeI, int sizeJ)
{
    int retorno=-1;
    int i;
    int j;
    int contador=0;
    int flag=-1;
    if(arrayA!=NULL && sizeI>=0 && arrayB!=NULL && sizeJ>=0)
    {
        printf("\nOrquestas con menos de 6 musicos:");
        for(i=0;i<sizeI;i++)
        {
            if(arrayA[i].isEmpty!=1)
            {
                for(j=0,contador=0;j<sizeJ;j++)
                {
                    if(arrayB[j].isEmpty!=1 && arrayA[i].idUnico==arrayB[j].idOrq)     //Busco todas las veces que aparece ese id
                    {
                        contador++;
                    }
                }
                if (contador<6)
                {
                    printf("\n ID: %d   Nombre: %s  Lugar: %s   Tipo: ",
                           arrayA[i].idUnico,arrayA[i].nombre,arrayA[i].lugar);
                    if(arrayA[i].tipo==1)
                        printf("Sinfonica");
                    else if(arrayA[i].tipo==2)
                        printf("Filarmonica");
                    else if(arrayA[i].tipo==3)
                        printf("Camara");
                    else
                        printf("Desconocido");
                    flag=0;
                }
            }
        }
        if(flag==-1)
            printf("\nNo se encontraron orquestas con menos de 6 musicos");
        retorno=0;
    }
    return retorno;
}

//D
/** \brief Solicita un ID de orquesta y lista sus intrumentos
* \param arrayA Musico Array de Musico
* \param arrayB Instrumento Array de Instrumento
* \param sizeI int Tamaño del arrayA
* \param sizeJ int Tamaño del arrayB
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) Ok
*
*/
int Informes_d_listarInstPorOrq(Musico arrayA[], Instrumento arrayB[], int sizeI, int sizeJ)
{
    int retorno=-1;
    int i;
    int j;
    int criterio;
    int flag=-1;
    if(arrayA!=NULL && sizeI>=0 && arrayB!=NULL && sizeJ>=0)
    {
        if(utn_getUnsignedInt("\nID orquesta: ","\nError",1,sizeof(int),1,&criterio)==0)
        {
            printf("\nInstrumentos de la orquesta:");
            for(i=0;i<sizeI;i++)
            {
                if(arrayA[i].isEmpty!=1 && arrayA[i].idOrq==criterio)
                {
                    if(Instrumento_buscarID(arrayB,sizeJ,arrayA[i].idInst,&j)==0)
                    {
                        printf("\nNombre: %s  Tipo: ",arrayB[j].nombre);
                        if(arrayB[j].tipo==1)
                            printf("Cuerdas");
                        else if(arrayB[j].tipo==2)
                            printf("Viento-madera");
                        else if(arrayB[j].tipo==3)
                            printf("Viento-metal");
                        else if(arrayB[j].tipo==4)
                            printf("Percusion");
                        else
                            printf("Desconocido");
                    }
                    else
                        printf("\nTipo de instrumento desconocido");

                    printf("  Nombre musico: %s",arrayA[i].nombre);
                    flag=0;
                }
            }
            if(flag==-1)
                printf("\nLa orquesta no tiene instrumentos ingresados");
        }
        retorno=0;
    }
    return retorno;
}

//E
/** \brief Lista las orquestas completas de acuerdo a la cantidad de instrumentos
* \param arrayA Orquesta Array de Orquesta
* \param arrayB Musico Array de Musico
* \param sizeI int Tamaño del arrayA
* \param sizeJ int Tamaño del arrayB
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) Ok
*
*/
int Informes_e_listarOrqCompleta(Orquesta arrayA[], Musico arrayB[], Instrumento arrayC[], int sizeI, int sizeJ, int sizek)
{
    int retorno=-1;
    int i;
    int j;
    int k;
    int contadorCuerda=0;
    int contadorViento=0;
    int contadorPerc=0;
    int flag=-1;
    if(arrayA!=NULL && sizeI>=0 && arrayB!=NULL && sizeJ>=0 && arrayC!=NULL && sizek>=0)
    {
        printf("\nOrquestas completas:");
        for(i=0;i<sizeI;i++)
        {
            if(arrayA[i].isEmpty!=1)
            {
                for(j=0,contadorCuerda=0, contadorViento=0, contadorPerc=0;j<sizeJ;j++)
                {
                    if(arrayB[j].isEmpty!=1 && arrayA[i].idUnico==arrayB[j].idOrq)     //Busco todas las veces que aparece ese id
                    {
                        Instrumento_buscarID(arrayC,sizek,arrayB[j].idInst,&k);
                        if(arrayC[k].tipo==1)
                            contadorCuerda++;
                        else if(arrayC[k].tipo==2 || arrayC[k].tipo==3)
                            contadorViento++;
                        else if(arrayC[k].tipo==4)
                            contadorPerc++;
                    }
                }
                if (contadorCuerda>=4 && contadorViento>=4 && contadorPerc>=1)
                {
                    printf("\n ID: %d   Nombre: %s  Lugar: %s   Tipo: ",
                           arrayA[i].idUnico,arrayA[i].nombre,arrayA[i].lugar);
                    if(arrayA[i].tipo==1)
                        printf("Sinfonica");
                    else if(arrayA[i].tipo==2)
                        printf("Filarmonica");
                    else if(arrayA[i].tipo==3)
                        printf("Camara");
                    else
                        printf("Desconocido");

                    flag=0;
                }
            }
        }
        if(flag==-1)
            printf("\nNo se encontraron orquestas completas");
        retorno=0;
    }
    return retorno;
}

//F
/** \brief Lista las orquestas con la menor cantidad de musicos
* \param arrayA Orquesta Array de Orquesta
* \param arrayB Musico Array de Musico
* \param sizeI int Tamaño del arrayA
* \param sizeJ int Tamaño del arrayB
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) Ok
*
*/
int Informes_f_orqMinMusicos(Orquesta arrayA[], Musico arrayB[], int sizeI, int sizeJ)
{
    int retorno=-1;
    int i;
    int j;
    int minContador=0;
    int contador=0;
    int iMin[sizeI];

    if(arrayA!=NULL && sizeI>=0 && arrayB!=NULL && sizeJ>=0)
    {
        for(i=0;i<sizeI;i++)
        {
            iMin[i]=-2;                        //Para marcar los lugares vacios
            if(arrayA[i].isEmpty!=1)
            {
                for(j=0,contador=0;j<sizeJ;j++)
                {
                    if(arrayB[j].isEmpty!=1 && arrayA[i].idUnico==arrayB[j].idOrq)     //Busco todas las veces que aparece ese id
                    {
                        contador++;
                    }
                }

                if(i==0)
                    minContador=contador;
                else if(contador<minContador)
                {
                    minContador=contador;
                    iMin[i-1]=-1;
                    iMin[i]=i;
                }
                else if(contador==minContador)
                    iMin[i]=i;
            }
        }

        printf("\nMenor cantidad de musicos: %d \nOrquestas: ",minContador);
        for(i--;iMin[i]!=-1 && i>=0;i--)
        {
            if(iMin[i]!=-2)                         //Salteo los vacios
            {
                printf("\n ID: %d   Nombre: %s  Lugar: %s   Tipo: ",
                       arrayA[iMin[i]].idUnico,arrayA[iMin[i]].nombre,arrayA[iMin[i]].lugar);
                if(arrayA[iMin[i]].tipo==1)
                    printf("Sinfonica");
                else if(arrayA[iMin[i]].tipo==2)
                    printf("Filarmonica");
                else if(arrayA[iMin[i]].tipo==3)
                    printf("Camara");
                else
                    printf("Desconocido");
            }
        }
        retorno=0;
    }
    return retorno;
}

//G
/** \brief Imprime por pantalla el promedio de instrumentos por orquesta
* \param arrayA Orquesta Array de Orquesta
* \param arrayB Instrumento Array de Instrumento
* \param sizeI int Tamaño del arrayA
* \param sizeJ int Tamaño del arrayB
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) Ok
*
*/
int Informes_g_promedioInstOrq(Orquesta arrayA[], Instrumento arrayB[], int sizeI, int sizeJ)
{
    int retorno=-1;
    int i;
    int contadorOrq=0;
    int contadorInst=0;
    int promedio;           //no lo pongo como float porque el compilador lo redondea, sino los contadores tmb deberian ser float

    if(arrayA!=NULL && sizeI>=0 && arrayB!=NULL && sizeJ>=0)
    {
        for(i=0;i<sizeI;i++)
        {
            if(arrayA[i].isEmpty!=1)
                contadorOrq++;
        }
        for(i=0;i<sizeJ;i++)
        {
            if(arrayB[i].isEmpty!=1)
                contadorInst++;
        }


        if(contadorOrq==0)
            printf("\nNo se han ingresado orquestas");
        else
        {
            promedio=contadorInst/contadorOrq;
            printf("\nPromedio de instrumentos por orquesta: %d",promedio);
        }

        retorno=0;
    }
    return retorno;
}


//H
/** \brief Lista los musicos excepto aquellos que toquen instrumentos de viento, ordenados por apellido
* \param arrayA Musico Array de Musico
* \param arrayB Instrumento Array de Instrumento
* \param sizeI int Tamaño del arrayA
* \param sizeJ int Tamaño del arrayB
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) Ok
*
*/
int Informes_h_listarMusicosExcViento(Musico arrayA[], Instrumento arrayB[], int sizeI, int sizeJ)
{
    int retorno=-1;
    int i;
    int j;
    int flag=-1;
    if(arrayA!=NULL && sizeI>=0 && arrayB!=NULL && sizeJ>=0)
    {
        Musico_ordenarPorApelldio(arrayA,sizeI);
        for(i=0;i<sizeI;i++)                                                                            // posicion de la primer entidad
        {
            if(arrayA[i].isEmpty!=1)
            {
                if(Instrumento_buscarID(arrayB,sizeJ,arrayA[i].idInst,&j)==-1)                           //Obtengo la posicion de la 2da entidad buscando por el campo en comun
                    j=-1;
                if(arrayB[j].tipo!=2 && arrayB[j].tipo!=3)
                {
                    printf("\nNombre: %s  Apellido: %s    Edad: %d    ", arrayA[i].nombre,arrayA[i].apellido,arrayA[i].edad);
                    if(j==-1)
                        printf("    ID instrumento desconocido");
                    else
                    {
                        printf("     Nombre instrumento: %s     Tipo instrumento: ",arrayB[j].nombre);
                        if(arrayB[j].tipo==1)
                            printf("Cuerdas");
                        else if(arrayB[j].tipo==2)
                            printf("Viento-madera");
                        else if(arrayB[j].tipo==3)
                            printf("Viento-metal");
                        else if(arrayB[j].tipo==4)
                            printf("Percusion");
                        else
                            printf("Desconocido");
                    }
                    flag=0;
                }
            }
        }
        if(flag==-1)
            printf("\nNo se encontraron musicos de instrumentos que no sean de viento");
        retorno=0;
    }
    return retorno;
}




int Informes_OrquestaLugar(Orquesta ArrayOrquesta[],int tamanioOrquesta, char lugar[]){
    int retorno = -1;
    int i;

    if(ArrayOrquesta != NULL && tamanioOrquesta > 0 && lugar != NULL){
        printf("LUGAR: %s", lugar);
        for(i=0;i<tamanioOrquesta;i++){
            if(ArrayOrquesta[i].isEmpty==0&&strncmp(ArrayOrquesta[i].lugar,lugar,20)==0){
                retorno = 0;
                printf("\n %s  ",ArrayOrquesta[i].nombre);
                if(ArrayOrquesta[i].tipo == 1){
                    printf("Sinfonica");
                }else if(ArrayOrquesta[i].tipo == 2){
                    printf("Filarmonica");
                }else if(ArrayOrquesta[i].tipo == 3){
                    printf("Camara");
                }
            }

        }
         if(retorno == -1){
                printf("\n No se encontro el lugar indicado");
            }

    }
    return retorno;
}

int Informes_OrquestaPorLugar(Orquesta arrayOrquesta[], int tamanioOrquesta){
    int retorno = -1;
    int i;
    int j;
    Lugar auxListaLugares[50];
    if(arrayOrquesta != NULL && tamanioOrquesta > 0){
        for(i = 0; i<50;i++){//Inicilizar lista auxiliar, tendria que estar en la estructura Lugar
            auxListaLugares[i].idLugar = -1;
            //strcpy(auxListaLugares[i].nombreLugar,);

        }
        for(i = 0; i<tamanioOrquesta;i++){ // Carga la lista de estructura de lugar
            for(j=0;j<50;j++){
                if(strncmp(arrayOrquesta[i].lugar,auxListaLugares[j].nombreLugar,20)!=0 && auxListaLugares[j].idLugar == -1){
                    strcpy(auxListaLugares[j].nombreLugar,arrayOrquesta[i].lugar);
                    auxListaLugares[j].idLugar=auxListaLugares[j].idLugar+1;
                    break;
                }
            }
        }

        for(i = 0; i < 50; i++){
            retorno = 0;
            printf("Array de lugares: id -- %d, nombre %s",auxListaLugares[i].idLugar,auxListaLugares[i].nombreLugar);
            if(auxListaLugares[i].idLugar != -1 ){
                Informes_OrquestaLugar(arrayOrquesta,tamanioOrquesta, auxListaLugares[i].nombreLugar);
            }

        }

    }

    return retorno;
}


