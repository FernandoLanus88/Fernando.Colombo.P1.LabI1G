#ifndef DESTINOS_H_INCLUDED
#define DESTINOS_H_INCLUDED




typedef struct
{
    int id; // comienza en 20000
    char descripcion[25];
    int precio;
} eDestino;



/** \brief Obtiene el destino mediante mostrar destinos y lo imprime en pantalla
 *
 * \param obtiene los destinos
 * \param obtiene tamaño del vector
 * \return 0 si es NULL  / 1 OK
 *
 */
int imprimirDestinos(eDestino destinos[],  int tam_dest);


/** \brief Brinda a imprimir destinos la informacion para mostrar en pantalla
 *
 * \param Obtiene los destinos ingresados / Hardcodeados
 * \return void
 *
 */
 void mostrarDestinos(eDestino x);



/** \brief Valida que el ID ingresado se corresponda con un ID de destino y trae la descripcion
 *
 * \param solicita el numero a verificar
 * \param obtiene tamaño del vector
 * \param obtiene ID de destino
 * \param almacena la descripcion del destino

 * \return 0 si es NULL / -1 si el numero no cumple los filtros mencionados en el brief / 1 OK
 *
 */
int cargarDescripcionDestino(eDestino destinos[], int tam_dest, int idDestino, char descDestino[]);


#endif // DESTINOS_H_INCLUDED
