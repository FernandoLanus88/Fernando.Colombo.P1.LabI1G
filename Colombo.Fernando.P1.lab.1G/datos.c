#include "aviones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "aerolinea.h"
#include "tipo.h"



int hardcodearAviones(eAvion lista[], eAerolinea aerolineas[], eTipo tipos[], int tam, int cant, int* idVuelo)
{

    int contador = -1;
    if (lista != NULL && idVuelo != NULL && tam > 0 && cant >= 0 && cant <= tam )
    {
        contador = 0;
        for (int i = 0; i < cant;  i++)
        {
            lista[i].id = *idVuelo;
            (*idVuelo)++;

            lista[i].idAerolinea = aerolineas[i].id;
            lista[i].idTipo = tipos[i].id;
            lista[i].capacidad = ((*idVuelo)++)+20;
            lista[4].idAerolinea = 1003;
            lista[4].idTipo = 5003;
            lista[i].isEmpty = 0;
            contador++;
        }
    }
    return contador;
}





