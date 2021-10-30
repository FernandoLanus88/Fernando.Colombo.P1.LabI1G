#include "aerolinea.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>






void mostrarAerolinea(eAerolinea x)
{

    printf(" %d         %-5s   \n\n\n",
           x.id,
           x.descripcion
           );
}



int imprimirAerolineas(eAerolinea aerolineas[],int tam_ae)
{
    int todoOk=0;

    if(aerolineas !=NULL && tam_ae > 0)
    {
        system("cls");
        printf("             ***Lista de Aerolineas***                        \n");
        printf("-------------------------------------------------------------\n");
        printf(" Id           Nombre           \n");
        printf("-------------------------------------------------------------\n");
        for(int i =0; i<tam_ae; i++)
        {
                mostrarAerolinea(aerolineas[i]);
        }
        todoOk=1;

    }
    return todoOk;
}



int cargarDescripcionAerolinea( eAerolinea aerolineas[], int tam_ae, int idAerolinea, char descAerolinea[] )//los ultimos 2 son la comparacion
{

    int todoOk = 0;
    int flag = 1;
    if (aerolineas != NULL && tam_ae > 0 && descAerolinea != NULL)
    {
        todoOk = 1;
        for (int i = 0; i < tam_ae; i++)
        {
            if (aerolineas[i].id == idAerolinea)
            {
                strcpy(descAerolinea, aerolineas[i].descripcion);
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            todoOk = -1;
            printf("Error. Id invalido");
        }
    }
    return todoOk;
}


