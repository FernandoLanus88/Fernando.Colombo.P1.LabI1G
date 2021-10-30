#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "destinos.h"






int imprimirDestinos(eDestino destinos[],  int tam_dest)
{
    int todoOk=0;

    if(destinos !=NULL && tam_dest > 0)
    {
        system("cls");
        printf("             ***DESTINOS***                        \n");
        printf("-------------------------------------------------------------\n");
        printf("   Id           Destino         Precio           \n");
        printf("-------------------------------------------------------------\n");
        for(int i =0; i<tam_dest; i++)
        {
                mostrarDestinos(destinos[i]);
        }
        todoOk=1;

    }
    return todoOk;
}


void mostrarDestinos(eDestino x)
{

    printf(" %5d         %-9s         %d\n\n\n",
           x.id,
           x.descripcion,
           x.precio
           );
}


int cargarDescripcionDestino(eDestino destinos[], int tam_dest, int idDestino, char descDestino[])
{

    int todoOk = 0;
    int flag = 1;
    if (destinos != NULL && tam_dest > 0 && descDestino != NULL)
    {
        todoOk = 1;
        for (int i = 0; i < tam_dest; i++)
        {
            if (destinos[i].id == idDestino)
            {
                strcpy(descDestino, destinos[i].descripcion);
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

