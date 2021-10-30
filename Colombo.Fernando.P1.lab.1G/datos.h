#ifndef DATOS_H_INCLUDED
#define DATOS_H_INCLUDED
#define TAM_AE 5
#define TAM_DEST 4
#define TAM_TIPO 4



 eTipo tipos[TAM_TIPO] =
    {
        { 5000, "Jet" },
        { 5001, "Helice" },
        { 5002, "Planeador" },
        { 5003, "Carga" }
    };



eAerolinea aerolineas[TAM_AE] =
{
    { 1000 , "Lan" },
    { 1001 , "Iberia" },
    { 1002 , "Norwegian" },
    { 1003 , "American" },
    { 1004 , "Austral" }
};

 eDestino destinos[TAM_DEST] =
    {
        { 20000, "Calafate", 22250 },
        { 20001, "Miami", 103000},
        { 20002, "Madrid", 84400},
        { 20003, "Amsterdam", 95600}
    };



/** \brief Hardcodea una lista de Aviones con su respectivo Id / aerolinea y tipo
 *
 * \param obtiene aviones
 * \param obtiene aerolineas
 * \param obtiene tipos
 * \param obtiene tamaño
 * \return 1 si es NULL  / 0 Ok
 *
 */
int hardcodearAviones(eAvion lista[], eAerolinea aerolineas[], eTipo tipos[], int tam, int cant, int* idVuelo);




#endif // DATOS_H_INCLUDED
