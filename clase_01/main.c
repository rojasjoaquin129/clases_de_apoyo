#include <stdio.h>
#include <stdlib.h>

int main(void) {
int dinero=0;

char tipo;
int mayor=0;
int acumulador=0;
int cantidad=0;
int contador=1;
float promedio=0;
int promerDolar=1;
	while(contador<5){
		printf("ingrese moneda a acumular\n");
		fflush(stdin);
		scanf("%s",&tipo);
		printf("ingrese el %d cantidad de %d \n",contador,tipo);
		scanf("%d",&dinero);
		if(tipo=='d'){
			if(promerDolar==1){
				mayor=dinero;
				promerDolar=0;
			}else{
				if(dinero>mayor){
					mayor=dinero;
				}
			}

		}
		if(dinero>0)
        {
            acumulador=acumulador+dinero;
            cantidad=cantidad+1;
        }
	contador++;
	}
	promedio=acumulador/cantidad;
	if(promerDolar==1)
	{
		printf("no ingresaste dolares ");
		}else{
			printf("el numero mayor es %d y el promedio de los positivos es %f ",mayor,promedio);

					}

	return 0;
}
