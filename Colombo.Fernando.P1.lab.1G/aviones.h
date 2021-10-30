#include "vuelos.h"
#ifndef AVIONES_H_INCLUDED
#define AVIONES_H_INCLUDED
#include "tipo.h"
#include "piloto.h"
#include "aerolinea.h"



typedef struct
{
    int id;
    int idAerolinea;  // validar
    int idTipo; // validar
    int capacidad;  //cantidad de pasajeros entre 10 y 300
    int idPiloto;
    int isEmpty;  //1 vacio  // 0 ocupado
} eAvion;


int mostrarAvionesTipo( eAvion lista[], int tam, eTipo tipos[], int tam_tipo );












/** \brief  Despliega menu principal
 *
 * \param
 * \param
 * \return Opcion seleccionada por el usuario
 *
 */
int menu();





/** \brief  Despliega el submenu de modificaciones
 *
 * \param
 * \param
 * \return Opcion seleccionada por el usuario
 *
 */
int menuModificacion();





/** \brief Da de alta un avion con la informacion de   / aerolineas / tipos /  y da de alta el ID de la aeronave validando cada campo.
 *
 * \param Utiliza aerolineas tipos y y asigna ID para dar de alta la aeronave.
 * \param Obtiene los tamaños de los vectores
 * \return -1 si es NULL o no cumple los requisitos de alta /  0 OK
 *
 */
int altaAvion(eAvion lista[],eAerolinea aerolineas[], eTipo tipos[], ePiloto piloto[] ,int tam, int tam_ae, int tam_tipo);





/** \brief Da de baja un avion con la informacion de  aviones / aerolineas / tipos /  y da baja logica al ID de la aeronave informando al usuario, modifica el flag en caso de no quedar aeronaves para bloquear funciones del menu
 *
 * \param Utiliza aviones aerolineas tipos  y da baja logica al ID
 * \param Obtiene los tamaños de los vectores
 * \return 0 si es NULL o no cumple los requisitos de alta /  1 OK
 *
 */
int bajaAvion(eAvion lista[], eAerolinea aerolineas[], eTipo tipos[], ePiloto piloto[] ,int tam, int tam_ae, int tam_tipo, int* flag);





/** \brief Modifica un avion con la informacion de aviones / aerolineas / tipos /  validando cada campo.
 *
 * \param Obtiene informacion de aviones aerolineas y tipos
 * \param Obtiene los tamaños de los vectores
 * \return 0 si es NULL o no cumple los requisitos de alta /  1 OK
 *
 */
int modificarAvion(eAvion lista[], eAerolinea aerolineas[], eTipo tipos[],ePiloto piloto[] ,int tam, int tam_ae, int tam_tipo );






/** \brief Obtiene la informacion de los aviones / aerolineas y los ordena por Id de aerolinea y capacidad de la aeronave
 *
 * \param obtiene los valores necesarios de cada vector para poder realizar la comparacion
 * \param obtiene tamaño de los vectores
 * \return -1 si es NULL  / 0 Ok
 *
 */
int clasificarAviones(eAvion lista[], eAerolinea aerolineas[], int tam,  int tam_ae);






/** \brief Obtiene la informacion de los aviones / aerolineas / tipos  mediante mostrar avion y verifica que no tenga baja logica
 *
 * \param obtiene los valores necesarios de cada vector para poder desplegar la lista de aviones
 * \param obtiene tamaño de los vectores
 * \return 0 si es NULL  / 1 Ok
 *
 */
int imprimirAvion(eAvion lista[], eAerolinea aerolineas[], eTipo tipos[], ePiloto piloto[],int tam, int tam_ae, int tam_tipo);






/** \brief Obtiene la informacion de la aeronave / aviones / destinos / fehas mediante mostrar vuelos y verifica que sean existentes
 *
 * \param obtiene los valores necesarios de cada vector para poder desplegar la lista de vuelos
 * \param obtiene tamaño
 * \param obtiene id ingresado por el usuario
 * \return -1 si es NULL  / Posicion del Id de la aeronave
 *
 */
int buscarAeronaveId(eAvion lista[], int tam, int id);





/** \brief Valida que el ID ingresado se corresponda con un ID de aeronave y trae la descripcion
 *
 * \param solicita el numero a verificar
 * \param obtiene tamaño del vector
 * \param obtiene ID de aeronave
 * \param almacena la descripcion del avion

 * \return 0 si es NULL / -1 si el numero no cumple los filtros mencionados en el brief / 1 OK
 *
 */
int cargarDescripcionAvion( eAvion lista[],int tam, int idAvion, int* descAvion);






/** \brief Obtiene los aviones ingresados teniendo en cuenta aviones / aerolineas / tipos asi como la descripcion de aerolinea y tipo y se los entrega a imprimir avion
 *
 * \param Obtiene los vectores
 * \param Obtiene los tamaños
 * \return void
 *
 */
void mostrarAvion(eAvion avion, eAerolinea aerolineas[], eTipo tipos[], ePiloto piloto[] ,int tam_ae, int tam_tipo, int tam);



#endif // AVIONES_H_INCLUDED








