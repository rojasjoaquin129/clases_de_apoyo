#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    int flag=0;
    int control;
    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* listaEmpleadosBinario =ll_newLinkedList();
    printf( "\n Menu:\n"
            "1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
            "2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n"
            "3. Alta de empleado\n"
            "4. Modificar datos de empleado\n"
            "5. Baja de empleado\n"
            "6. Listar empleados\n"
            "7. Ordenar empleados\n"
            "8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
            "9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n"
            "10. Salir\n");
    do{
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                if(flag==0){
                control=controller_loadFromText("data.csv",listaEmpleados);
                    if (control!=-1){
                        printf("DATOS GUARDADOS CON EXITO\n");
                        flag=1;
                    } else {
                     printf("ERROR, LOS DATOS NO SE PUEDEN GUARDAR\n");
                    }
                }
                else{
                    printf("ERROR, YA SE CARGARON LOS DATOS \n");
                }
                break;
            case 2:

                        controller_saveAsBinary("data2.csv",listaEmpleados);
                        controller_loadFromBinary("data2.csv",listaEmpleadosBinario);


                break;

            case 6:
                    if(flag==1)
                        controller_ListEmployee(listaEmpleadosBinario);
                    else
                            printf("no se puede mostrar");
                 //controller_ListEmployee(listaEmpleados);
                break;
            case 7:
                 controller_ListEmployee(listaEmpleados);
                 //controller_ListEmployee(listaEmpleados);
                break;

        }
    }while(option != 10);
    return 0;
}
