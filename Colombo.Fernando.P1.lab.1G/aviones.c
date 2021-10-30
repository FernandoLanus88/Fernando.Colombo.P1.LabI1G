#include "aerolinea.h"
#include "tipo.h"
#include "aviones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validaciones.h"
#include "vuelos.h"
#include "piloto.h"



int menu()
{
    char opcion;
    system("cls");
    printf("     ***    MENU DE OPCIONES   ***   \n\n");
    printf("Z- Alta Piloto\n");
    printf("A- Alta Avion\n");
    printf("B- Modificar Avion\n");
    printf("C- Baja Avion\n");
    printf("D- Listar Aviones\n");
    printf("E- Listar Aerolineas\n");
    printf("F- Listar Tipos\n");
    printf("G- Listar Destinos\n");
    printf("H- Alta Vuelo\n");
    printf("I- Listar Vuelos\n");
    printf("J- Salir\n\n");
    printf("Ingrese Opcion: ");
    fflush(stdin);
    scanf("%c",&opcion);
    opcion = toupper(opcion);

    return opcion;
}


int menuModificacion()
{
    int opcion;
    system("cls");

    printf("1- Modificar Tipo\n");
    printf("2- Modificar Capacidad\n");
    printf("3- Salir\n\n");
    printf("Ingrese Opcion: ");
    scanf("%d",&opcion);

    return opcion;
}



int altaAvion(eAvion lista[],eAerolinea aerolineas[], eTipo tipos[], ePiloto piloto[], int tam, int tam_ae, int tam_tipo)
{
    int todoOk =-1;
    int indice=-1;
    eAvion auxAvion;
    char auxiliar[100];
    char continuar='n';


    if(lista !=NULL && tam>0 && aerolineas !=NULL && tipos !=NULL  && piloto !=NULL  && tam_ae>0 && tam_tipo>0)
    {
        system("cls");
        printf("     ***ALTA AVION***   \n");

            for(int i =0; i<tam ; i++)
            {
                if(lista[i].isEmpty)
                {
                    indice = i;
                    break;
                }
            }

            if(indice == -1)
            {
                printf("Limite alcanzado, borre algun registro si desea ingresar uno nuevo\n");
                todoOk=1;
            }
        else
        {

            printf("Confirma registrar una nueva aeronave?. Ingrese 's' para continuar: ");
            fflush(stdin);
            scanf("%c", &continuar);
            continuar = tolower(continuar);
            if(continuar== 's')
            {
            printf("Ingrese Id del Avion:  ");
            fflush(stdin);
            gets(auxiliar);
            while(validarEntero(auxiliar, lista, tam))
            {
            printf("Reingrese Id del Avion:  ");
            fflush(stdin);
            gets(auxiliar);
            }
            auxAvion.id = atoi(auxiliar);



            printf("Ingrese Id de un piloto dado de Alta:  ");
            fflush(stdin);
            gets(auxiliar);
            while(validarIdPiloto(auxiliar, piloto, tam))
            {
            printf("Reingrese Id del Piloto:  ");
            fflush(stdin);
            gets(auxiliar);
            }
            auxAvion.idPiloto = atoi(auxiliar);



            imprimirAerolineas(aerolineas,tam_ae);

            printf("Ingrese Id de la Aerolinea:  ");
            fflush(stdin);
            gets(auxiliar);
            while( validarAerolinea(auxiliar, aerolineas, tam_ae))
            {
            printf("Error. El numero no coincide con ningun id de aerolinea, reingrese:  ");
            fflush(stdin);
            gets(auxiliar);
            }
            auxAvion.idAerolinea = atoi(auxiliar);


            imprimirTipo(tipos,tam_tipo);

            printf("Ingrese Id correspondiente al Tipo de Aeronave:  ");
            fflush(stdin);
            gets(auxiliar);
             while( validarTipo(auxiliar, tipos, tam_tipo))
            {
            printf("Error. El numero no coincide con ningun tipo reingrese id:  ");
            fflush(stdin);
            gets(auxiliar);
            }
            auxAvion.idTipo = atoi(auxiliar);



            printf("\nIngrese Capacidad del avion: 10 a 300 pasajeros: ");
            fflush(stdin);
            gets(auxiliar);
            while(validarCantidadPasajeros(auxiliar))
            {
                printf("Error. Capacidad incorrecta, reingrese:  ");
                fflush(stdin);
                gets(auxiliar);
            }
            auxAvion.capacidad = atoi(auxiliar);
            auxAvion.isEmpty = 0;
            lista[indice] = auxAvion;

            todoOk=0;

            }

        }
    }

    return todoOk;
}



int bajaAvion(eAvion lista[], eAerolinea aerolineas[], eTipo tipos[], ePiloto piloto[] ,int tam, int tam_ae, int tam_tipo, int* flag)
{
     int todoOk =0;
     int indice;
     int id;
     char confirma;
     int contador=0;
     char advertencia='n';


    if(lista != NULL && tam>0 && aerolineas != NULL && tipos != NULL && flag!= NULL && tam_ae >0 && tam_tipo >0 && piloto != NULL)
    {
        system("cls");
        printf("   *** BAJA AERONAVE ***  \n\n");

            printf("-------------------------------------------------------------\n");
            printf("  Id        Aerolinea             Tipo        Capacidad          Piloto          \n");
            printf("-------------------------------------------------------------\n");

             for(int i =0; i<tam; i++)
        {
            if(!lista[i].isEmpty)
            {
                mostrarAvion(lista[i], aerolineas, tipos, piloto,tam_ae, tam_tipo, tam);

            }
        }

                printf("Ingrese Id de la aeronave a dar de baja / ingrese 0 para cancelar: ");
                scanf("%d", &id);
                indice = buscarAeronaveId(lista, tam, id);


        if(indice == -1)
        {
            printf("Cancelado por el Usuario / ID inexistente\n");
        }
        else
        {

            printf("-------------------------------------------------------------\n");
            printf("  Id        Aerolinea             Tipo        Capacidad          Piloto          \n");
            printf("-------------------------------------------------------------\n");
            mostrarAvion(lista[indice], aerolineas, tipos, piloto,tam_ae, tam_tipo, tam);

            printf("Confirma baja? ingrese s para confirmar, cualquier otra tecla para cancelar: \n");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                    for(int i =0; i<tam; i++)
                    {
                        if(lista[i].isEmpty)
                        {
                            contador++;
                        }
                    }
                if(contador == (tam-1))
                {
                    printf("ADVERTENCIA: No quedara ninguna aeronave registrada en sistema, no podra realizar ninguna visualizacion y se cancelaran los vuelos por falta de aeronaves.\n");
                    fflush(stdin);
                    printf("Ingrese 's' para confirmar: ");
                    fflush(stdin);
                    scanf("%c", &advertencia);
                    advertencia = tolower(advertencia);

                        if(advertencia=='s')
                        {
                            *flag=1;
                            printf("Baja Exitosa\n\n\n");
                                lista[indice].isEmpty = 1;
                        }
                        else
                        {
                            printf("Baja cancelada por el usuario\n");
                        }

                }
                else
                {
                lista[indice].isEmpty = 1;
                }

                todoOk=1;
            }
            else
            {
                printf("Baja cancelada por el usuario\n");
            }

        }
    }
    return todoOk;
}



int modificarAvion(eAvion lista[], eAerolinea aerolineas[], eTipo tipos[], ePiloto piloto[] ,int tam, int tam_ae, int tam_tipo )
{
     int todoOk =0;
     int indice;
     int id;
     char confirma;
     char auxiliar[100];
     char seguir = 's';



    if(lista != NULL && tam>0 && aerolineas != NULL && tipos != NULL && tam_ae >0 && tam_tipo >0)
    {
        system("cls");
        printf("   *** MODIFICACION DE AERONAVE ***  \n\n");

            printf("-------------------------------------------------------------\n");
            printf("  Id        Aerolinea             Tipo        Capacidad          Piloto          \n");
            printf("-------------------------------------------------------------\n");

             for(int i =0; i<tam; i++)
        {
            if(!lista[i].isEmpty)
            {
                mostrarAvion(lista[i], aerolineas, tipos, piloto ,tam_ae, tam_tipo, tam);

            }
        }
                printf("Ingrese Id de la aeronave a modificar / ingrese 0 para cancelar: ");
                scanf("%d", &id);
                indice = buscarAeronaveId(lista, tam, id);



        if(indice == -1)
        {
            printf("Cancelado por el Usuario / ID inexistente\n");
        }
        else
        {
            printf("-------------------------------------------------------------\n");
            printf("  Id        Aerolinea             Tipo        Capacidad          Piloto          \n");
            printf("-------------------------------------------------------------\n");
            mostrarAvion(lista[indice], aerolineas, tipos, piloto ,tam_ae, tam_tipo, tam);

            printf("Va a modificar este registro? ingrese s para desplegar el submenu, cualquier otra tecla para cancelar: \n\n");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
            if(confirma == 's')
            {
                   system("cls");
                   mostrarAvion(lista[indice], aerolineas,  tipos, piloto, tam_ae, tam_tipo, tam);

              do
              {
                switch(menuModificacion())
                {

            case 1:

            imprimirTipo(tipos,tam_tipo);
            printf("Su Aeronave actual: ID   %d\n\n", lista[indice].idTipo);

            printf("Ingrese Id correspondiente al nuevo tipo de Aeronave:  ");
            fflush(stdin);
            gets(auxiliar);
             while( validarTipo(auxiliar, tipos, tam_tipo))
            {
            printf("Error. El numero no coincide con ningun tipo reingrese id:  ");
            fflush(stdin);
            gets(auxiliar);
            }
            lista[indice].idTipo = atoi(auxiliar);
            printf("Modifacion Exitosa.\n");
            system("pause");
            break;


            case 2:
            printf("Su capacidad actual:   %d\n\n", lista[indice].capacidad);

            printf("Ingrese Capacidad del avion: 10 a 300 pasajeros: ");
            fflush(stdin);
            gets(auxiliar);
            while(validarCantidadPasajeros(auxiliar))
            {
                printf("Error. Capacidad incorrecta, reingrese:  ");
                fflush(stdin);
                gets(auxiliar);
            }
            lista[indice].capacidad = atoi(auxiliar);
            printf("Modifacion Exitosa.\n");
            system("pause");
            break;


            case 3:
            printf("Ha seleccionado salir\n");
            seguir = 'n';
            break;

            default:
            printf("Opcion Invalida\n");
            fflush(stdin);
            system("pause");
                }

              }while(seguir == 's');

                todoOk=1;
            }
            else
            {
                printf("Modificacion cancelada por el usuario\n");
            }
        }
    }
    return todoOk;
}







int clasificarAviones(eAvion lista[], eAerolinea aerolineas[], int tam,  int tam_ae)
{

    int todoOk=-1;
    eAvion auxAvion;

    if(lista != NULL && tam>0 )
    {

      for(int i=0; i<tam-1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {

               if((lista[i].idAerolinea > lista[j].idAerolinea)

                || (lista[i].idAerolinea == lista[j].idAerolinea && lista[i].capacidad > lista[j].capacidad))
              {

                auxAvion = lista[i];
                lista[i] = lista[j];
                lista[j] = auxAvion;
               }

            }
        }
        todoOk=0;
    }
    return todoOk;
}



int imprimirAvion(eAvion lista[], eAerolinea aerolineas[], eTipo tipos[] ,ePiloto piloto[] ,  int tam, int tam_ae, int tam_tipo)
{
    int todoOk=0;
    int flag = 1;

    if(lista != NULL && tam>0 && aerolineas != NULL && tipos != NULL && tam_ae >0 && tam_tipo >0)
    {
        system("cls");
        printf("             ***Tipos de Aviones***                        \n");
        printf("--------------------------------------------------------------------------------\n");
        printf("  Id        Aerolinea             Tipo        Capacidad          Piloto          \n");
        printf("--------------------------------------------------------------------------------\n");
        for(int i =0; i<tam; i++)
        {
            if(!lista[i].isEmpty)
            {

                mostrarAvion(lista[i], aerolineas, tipos, piloto ,tam_ae, tam_tipo, tam);
                flag = 0;
            }
        }
         if (flag)
        {
            printf("No hay aeronaves para mostrar.\n");

        }
        todoOk=1;

    }
    return todoOk;
}


int buscarAeronaveId(eAvion lista[], int tam, int id)
{
        int avion =-1;
    if(lista !=NULL && tam>0)
    {
        for(int i =0; i<tam ; i++)
        {
            if(lista[i].id == id && !lista[i].isEmpty)
            {
                avion = i;
                break;
            }
        }
    }
    return avion;
}


int cargarDescripcionAvion( eAvion lista[],int tam, int idAvion, int* descAvion)
{
    int todoOk = 0;
    int flag = 1;
    if (lista != NULL && tam > 0 )
    {
        todoOk = 1;
        for (int i = 0; i < tam; i++)
        {
            if (lista[i].id == idAvion)
            {
                *descAvion = lista[i].id;
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


void mostrarAvion(eAvion avion, eAerolinea aerolineas[], eTipo tipos[], ePiloto piloto[],int tam_ae, int tam_tipo, int tam )
{
        char descAerolinea[20];
        char descTipo[20];
        char descPiloto[30];


       if( (cargarDescripcionAerolinea( aerolineas, tam_ae, avion.idAerolinea, descAerolinea)) &&
                (cargarDescripcionTipo( tipos, tam_tipo, avion.idTipo, descTipo))   && (cargarDescripcionPiloto(  piloto,  tam,  avion.idPiloto,  descPiloto)))
       {
           printf("  %3d        %-9s             %-9s         %d          %-9s\n\n\n",
           avion.id,
           descAerolinea,
           descTipo,
           avion.capacidad,
           descPiloto

           );

       }
}



