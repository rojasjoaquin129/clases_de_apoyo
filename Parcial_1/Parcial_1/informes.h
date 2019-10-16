#include "instrumento.h"
#include "musico.h"
#include "orquesta.h"

#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

int Informes_listarMusicos(Musico arrayA[], Instrumento arrayB[], int sizeI, int sizeJ);

int Informes_a_listarOrqPorLugar(Orquesta array[], int size);
int Informes_b_listarMusicosEdad(Musico arrayA[], Orquesta arrayB[], Instrumento arrayC[], int sizeI, int sizeJ, int sizeK);
int Informes_c_listarOrqCantMusico(Orquesta arrayA[], Musico arrayB[], int sizeI, int sizeJ);
int Informes_d_listarInstPorOrq(Musico arrayA[], Instrumento arrayB[], int sizeI, int sizeJ);
int Informes_e_listarOrqCompleta(Orquesta arrayA[], Musico arrayB[], Instrumento arrayC[], int sizeI, int sizeJ, int sizek);
int Informes_f_orqMinMusicos(Orquesta arrayA[], Musico arrayB[], int sizeI, int sizeJ);
int Informes_g_promedioInstOrq(Orquesta arrayA[], Instrumento arrayB[], int sizeI, int sizeJ);
int Informes_h_listarMusicosExcViento(Musico arrayA[], Instrumento arrayB[], int sizeI, int sizeJ);
int Informes_OrquestaLugar(Orquesta ArrayOrquesta[],int tamanioOrquesta, char lugar[]);
int Informes_OrquestaPorLugar(Orquesta arrayOrquesta[], int tamanioOrquesta);
#endif // INFORMES_H_INCLUDED
