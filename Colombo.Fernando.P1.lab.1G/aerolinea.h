#ifndef AEROLINEA_H_INCLUDED
#define AEROLINEA_H_INCLUDED



typedef struct
{
    int id; // comienza en 1000
    char descripcion[20];
} eAerolinea;



/** \brief Brinda a imprimir aerolineas la informacion para mostrar en pantalla
 *
 * \param Obtiene las aerolineas ingresadas / Hardcodeados
 * \return void
 *
 */
void mostrarAerolinea(eAerolinea x);



/** \brief Obtiene la aerolinea mediante mostrar aerolineas y lo imprime en pantalla
 *
 * \param obtiene los destinos
 * \param obtiene tamaño del vector
 * \return 0 si es NULL  / 1 OK
 *
 */
int imprimirAerolineas(eAerolinea aerolineas[],int tam_ae);




/** \brief Valida que el ID ingresado se corresponda con un ID de aerolinea y trae la descripcion
 *
 * \param solicita el numero a verificar
 * \param obtiene tamaño del vector
 * \param obtiene ID de la aerolinea
 * \param almacena la descripcion de la aerolinea

 * \return 0 si es NULL / -1 si el numero no cumple los filtros mencionados en el brief / 1 OK
 *
 */
int cargarDescripcionAerolinea( eAerolinea aerolineas[], int tam_ae, int idAerolinea, char descAerolinea[] );

#endif // AEROLINEA_H_INCLUDED
