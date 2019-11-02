#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    pFile = fopen(path,"r");
    int retorno=-1;
    int control;
    if(pFile != NULL)
    {
        control=parser_EmployeeFromText(pFile,pArrayListEmployee);
        if(control!=-1)
            retorno=0;
    }
    fclose(pFile);
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{

    FILE* pFileB;
    pFileB = fopen(path,"rb");
    int retorno=-1;
    int control;
    if(pFileB != NULL)
    {
        control=parser_EmployeeFromBinary(pFileB,pArrayListEmployee);
        if(control!=-1)
            retorno=0;
    }
    fclose(pFileB);

    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int i;
    int len=0;
    int auxid=0;
    int auxHorasTrabajadas=0;
    int auxSueldo=0;
    char auxNombre[4036];
    Employee* auxEmpleado;
    len=ll_len(pArrayListEmployee);
    for(i=0; i<len; i++)
    {
        auxEmpleado=(Employee*)ll_get(pArrayListEmployee,i);
        if (auxEmpleado!=NULL)
        {
            employee_getId(auxEmpleado,&auxid);
            employee_getNombre(auxEmpleado,auxNombre);
            employee_getHorasTrabajadas(auxEmpleado,&auxHorasTrabajadas);
            employee_getSueldo(auxEmpleado,&auxSueldo);
            printf("%d        %s          %d           %d    \n",auxid,auxNombre,auxHorasTrabajadas,auxSueldo );
        }

    }
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* Binario;
    Binario=fopen(path,"wb");
    int i;
    int len=ll_len(pArrayListEmployee);
    if(len!=0 && path != NULL && pArrayListEmployee !=NULL )
    {
        for (i=0; i<len; i++)
        {
            fwrite(ll_get(pArrayListEmployee,i),sizeof(Employee),1,Binario);

        }
        fclose(Binario);
    }
    return 1;
}

