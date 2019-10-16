#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "orquesta.h"
#include "instrumento.h"
#include "musico.h"
#include "informes.h"


#define QTY_ORQ 50
#define QTY_INST 20
#define QTY_MUSICO 100

int cargarDatos(Instrumento arrayInst[], Musico arrayMusico[], Orquesta arrayOrq[], int *contadorIdOrq, int *contadorIdInst, int *contadorIdMusico);


int main()
{
    int contadorIdOrq=0;
    int contadorIdInst=0;
    int contadorIdMusico=0;
    int flagOrq=0;
    int flagMusico=0;
    //int flagInst=0;
    int opcion;
    char opcionB;

    Orquesta arrayOrq[QTY_ORQ];
    Orquesta_inicializar(arrayOrq,QTY_ORQ);

    Instrumento arrayInst[QTY_INST];
    Instrumento_inicializar(arrayInst,QTY_INST);

    Musico arrayMusico[QTY_MUSICO];
    Musico_inicializar(arrayMusico,QTY_MUSICO);

    cargarDatos(arrayInst, arrayMusico, arrayOrq, &contadorIdOrq, &contadorIdInst, &contadorIdMusico);

    do
    {

        cargarDatos(arrayInst, arrayMusico, arrayOrq, &contadorIdOrq, &contadorIdInst, &contadorIdMusico);
        if(utn_getUnsignedInt("\n\n1) Agregar orquesta \n2) Eliminar Orquesta \n3) Imprimir orquestas \n4) Agregar musico \n5) Modificar musico \n6) Eliminar musico \n7) Imprimir musicos\n8) Agregar instrumento\n9) Imprimir instrumentos\n10) Informes\n11) Salir\n",                   //cambiar
                                "\nError",1,3,1,&opcion)!=0)
            opcion=11;   //salir
        else
        {
            switch(opcion)
            {
                case 1: //Alta orquesta
                    if(Orquesta_alta(arrayOrq,QTY_ORQ,&contadorIdOrq)==0)
                        flagOrq=1;
                    break;

                case 2: //Baja orquesta
                    if(flagOrq==0)
                    {
                        printf("\nAun no se ha dado de alta ninguna orquesta");
                    }
                    else
                        Orquesta_baja(arrayOrq,QTY_ORQ,arrayMusico,QTY_MUSICO);
                    break;

                case 3: //Listar orquesta
                    Orquesta_listar(arrayOrq,QTY_ORQ);
                    break;

                case 4: //Alta musico
                    if(Musico_alta(arrayMusico,QTY_MUSICO,&contadorIdMusico)==0)
                        flagMusico=1;
                    break;

                case 5: //Modificar musico
                    if(flagMusico==0)
                    {
                        printf("\nAun no se ha dado de alta ningun musico");
                    }
                    else
                        Musico_modificar(arrayMusico,QTY_MUSICO);
                    break;

                case 6: //Baja musico
                    if(flagMusico==0)
                    {
                        printf("\nAun no se ha dado de alta ningun musico");
                    }
                    else
                        Musico_baja(arrayMusico,QTY_MUSICO);
                    break;

                case 7: //Listar musicos
                    Informes_listarMusicos(arrayMusico, arrayInst, QTY_MUSICO, QTY_INST);
                    break;

                case 8: // Alta instrumento
                    Instrumento_alta(arrayInst,QTY_INST,&contadorIdInst);
                    break;

                case 9: //Listar instrumento
                    Instrumento_listar(arrayInst,QTY_INST);
                    break;
                case 12:
                    //Informes_OrquestaLugar(arrayOrq,QTY_ORQ,"Lugar5");
                    Informes_OrquestaPorLugar(arrayOrq, QTY_ORQ);
                    break;

                case 10://Informes
                    do
                    {
                        if(utn_getLetra("\n\nInformes:\nA) Orquestas correspondientes a un lugar\nB) Musicos menores de 25\nC) Orquestas con menos de 6 musicos\nD) Instrumentos de una orquesta\nE) Orquestas completas\nF) Orquestas con la menor cantidad de musicos\nG) Promedio de instrumentos por orquesta\nH) Musicos excepto aquellos que toquen instrumentos de viento\nS) Volver\n",                   //cambiar
                                          "\nM      \nError",1,&opcionB)!=0)
                            opcionB='S';   //salir
                        else
                        {
                            switch(opcionB)
                            {
                                case 'A':
                                    Informes_a_listarOrqPorLugar(arrayOrq, QTY_ORQ);
                                    break;

                                case 'B':
                                    Informes_b_listarMusicosEdad(arrayMusico, arrayOrq, arrayInst, QTY_MUSICO, QTY_ORQ, QTY_INST);
                                    break;

                                case 'C':
                                    Informes_c_listarOrqCantMusico(arrayOrq, arrayMusico, QTY_ORQ, QTY_MUSICO);
                                    break;

                                case 'D':
                                    Informes_d_listarInstPorOrq(arrayMusico, arrayInst, QTY_MUSICO, QTY_INST);
                                    break;

                                case 'E':
                                    Informes_e_listarOrqCompleta(arrayOrq, arrayMusico, arrayInst, QTY_ORQ, QTY_MUSICO, QTY_INST);
                                    break;

                                case 'F':
                                    Informes_f_orqMinMusicos(arrayOrq, arrayMusico, QTY_ORQ, QTY_MUSICO);
                                    break;

                                case 'G':
                                    Informes_g_promedioInstOrq(arrayOrq, arrayInst, QTY_ORQ, QTY_INST);
                                    break;

                                case 'H':
                                    Informes_h_listarMusicosExcViento(arrayMusico, arrayInst, QTY_MUSICO, QTY_INST);
                                    break;


                                case 'S'://Salir
                                    break;
                                default:
                                    printf("\nOpcion no valida");
                            }
                        }
                    }while(opcionB!='S');
                    break;
                case 11:
                    break;
                default:
                    printf("\nOpcion no valida");
            }
        }
    }while(opcion!=11);
    return 0;
}


int cargarDatos(Instrumento arrayInst[], Musico arrayMusico[], Orquesta arrayOrq[], int *contadorIdOrq, int *contadorIdInst, int *contadorIdMusico)
{
    int i=0;
//instrumento
    (*contadorIdInst)++;
    arrayInst[i].isEmpty=0;
    arrayInst[i].idUnico=*contadorIdInst;
    arrayInst[i].tipo=1;
    strcpy(arrayInst[i].nombre,"Inst1");
    (*contadorIdInst)++;
    i++;

    arrayInst[i].isEmpty=0;
    arrayInst[i].idUnico=*contadorIdInst;
    arrayInst[i].tipo=2;
    strcpy(arrayInst[i].nombre,"Inst2");
    (*contadorIdInst)++;
    i++;

    arrayInst[i].isEmpty=0;
    arrayInst[i].idUnico=*contadorIdInst;
    arrayInst[i].tipo=2;
    strcpy(arrayInst[i].nombre,"Inst3");
    (*contadorIdInst)++;
    i++;

    arrayInst[i].isEmpty=0;
    arrayInst[i].idUnico=*contadorIdInst;
    arrayInst[i].tipo=3;
    strcpy(arrayInst[i].nombre,"Inst4");
    (*contadorIdInst)++;
    i++;

    //(*contadorIdInst)++;                        //En el pizarron pusieron id 6????
    arrayInst[i].isEmpty=0;
    arrayInst[i].idUnico=*contadorIdInst;
    arrayInst[i].tipo=4;
    strcpy(arrayInst[i].nombre,"Inst5");

    i=0;
//musico
    (*contadorIdMusico)++;
    arrayMusico[i].isEmpty=0;
    arrayMusico[i].idUnico=*contadorIdMusico;
    arrayMusico[i].edad=30;
    arrayMusico[i].idOrq=1;
    arrayMusico[i].idInst=2;
    strcpy(arrayMusico[i].nombre,"Mus1");
    strcpy(arrayMusico[i].apellido,"AMus1");
    (*contadorIdMusico)++;
    i++;

    arrayMusico[i].isEmpty=0;
    arrayMusico[i].idUnico=*contadorIdMusico;
    arrayMusico[i].edad=20;
    arrayMusico[i].idOrq=2;
    arrayMusico[i].idInst=5;                    //idInst 5 no existe???
    strcpy(arrayMusico[i].nombre,"Mus2");
    strcpy(arrayMusico[i].apellido,"AMus2");
    (*contadorIdMusico)++;
    i++;

    arrayMusico[i].isEmpty=0;
    arrayMusico[i].idUnico=*contadorIdMusico;
    arrayMusico[i].edad=25;
    arrayMusico[i].idOrq=4;
    arrayMusico[i].idInst=2;
    strcpy(arrayMusico[i].nombre,"Mus3");
    strcpy(arrayMusico[i].apellido,"AMus3");
    (*contadorIdMusico)++;
    i++;

    arrayMusico[i].isEmpty=0;
    arrayMusico[i].idUnico=*contadorIdMusico;
    arrayMusico[i].edad=27;
    arrayMusico[i].idOrq=4;
    arrayMusico[i].idInst=1;
    strcpy(arrayMusico[i].nombre,"Mus4");
    strcpy(arrayMusico[i].apellido,"AMus4");
    (*contadorIdMusico)++;
    i++;

    arrayMusico[i].isEmpty=0;
    arrayMusico[i].idUnico=*contadorIdMusico;
    arrayMusico[i].edad=22;
    arrayMusico[i].idOrq=1;
    arrayMusico[i].idInst=3;
    strcpy(arrayMusico[i].nombre,"Mus5");
    strcpy(arrayMusico[i].apellido,"AMus5");
    (*contadorIdMusico)++;
    i++;

    arrayMusico[i].isEmpty=0;
    arrayMusico[i].idUnico=*contadorIdMusico;
    arrayMusico[i].edad=35;
    arrayMusico[i].idOrq=3;
    arrayMusico[i].idInst=4;
    strcpy(arrayMusico[i].nombre,"Mus6");
    strcpy(arrayMusico[i].apellido,"AMus6");

    i=0;
//orquesta
    (*contadorIdOrq)++;
    arrayOrq[i].isEmpty=0;
    arrayOrq[i].idUnico=*contadorIdOrq;
    arrayOrq[i].tipo=1;
    strcpy(arrayOrq[i].nombre,"Orquesta1");
    strcpy(arrayOrq[i].lugar,"Lugar1");
    (*contadorIdOrq)++;
    i++;
    //orquesta
    arrayOrq[i].isEmpty=0;
    arrayOrq[i].idUnico=*contadorIdOrq;
    arrayOrq[i].tipo=2;
    strcpy(arrayOrq[i].nombre,"Orquesta2");
    strcpy(arrayOrq[i].lugar,"Lugar1");
    (*contadorIdOrq)++;
    i++;
    //orquesta
    arrayOrq[i].isEmpty=0;
    arrayOrq[i].idUnico=*contadorIdOrq;
    arrayOrq[i].tipo=3;
    strcpy(arrayOrq[i].nombre,"Orquesta3");
    strcpy(arrayOrq[i].lugar,"Lugar2");
    (*contadorIdOrq)++;
    i++;
    //orquesta
    arrayOrq[i].isEmpty=0;
    arrayOrq[i].idUnico=*contadorIdOrq;
    arrayOrq[i].tipo=2;
    strcpy(arrayOrq[i].nombre,"Orquesta4");
    strcpy(arrayOrq[i].lugar,"Lugar3");

    return 0;
}




