#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

/**@brief
 * Inicializa en 0 los 20 lista[#].estado
 * @param array de personas
 * @return void
 */     
void set_Estado(EPersona lista[]);

/**@brief
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[]);

/**@brief
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], int dni);

/**@brief
 * Carga el array con 5 datos de nombre, edad, dni y estado
 * @param un array de EPersona
 * @return void
 */
void load_Array(EPersona lista[]);

/**@brief
 * Se piden nombre, edad y dni por pantalla y se cargan en una parte del array cuyo estado sea 0
 * @param un array de EPersona
 * @return VOID
 */
void agregar_Persona(EPersona lista[]);

/**@brief
 * Imprime la lista
 * @param Array de personas
 */
void imprimir_Lista(EPersona lista[]);

/**@brief
 * Elimina a una persona del Array
 * @param array de personas
 * @return void
 */
void borrar_Persona(EPersona lista[]);

/**@brief
 * Imprime lista ordenada por nombre
 * @param array de personas
 * @return void
 */
void imprimir_Lista_ordenada(EPersona lista[]);

/**@brief
 * Imprimir "grafico" de edades
 * @param array de personas
 * @return void
 */
void imprimirEdades(EPersona lista[]);

#endif // FUNCIONES_H_INCLUDED
