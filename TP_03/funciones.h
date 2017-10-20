#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
typedef struct
{
    int codigo;
    char titulo[50];
    char genero[20];
    int duracion;
    char descripcion[50];
    float puntaje;
    char linkImagen[50];
}EMovie;
/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 */
int esSoloLetras(char str[]);
/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 */
int esNumerico(char str[]);
/**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 */
int esAlfaNumerico(char str[]);
/**
 * \brief carga datos de unas peliculas al array de estructuras EMovie
 * \param array de estructuras EMovie
 * \param tamaño del array
 * \return void
 */
void hardcode_array(EMovie array_Peliculas[], int CANT);
/**
 * \brief pide los datos de una pelicula por pantalla para ser ingresados por teclado
 * \param estructura EMovie
 * \return void
 */
void request_Pelicula(EMovie unaPelicula);
/**
 * \brief Muestra el contenido del array por pantalla
 * \param array de estructuras EMovie
 * \param tamaño del array
 * \return void
 */
void show_peliculas(EMovie unArraydePeliculas[],int CANT);
/**
 * \brief carga los datos de una pelicula al array
 * \param array de estructuras EMovie
 * \param tamaño del array
 * \return void
 */
void cargarArray_Peliculas(EMovie unArraydePeliculas[], int CANT);
/**
 * \brief desabilita una pelicula convirtiendo su codigo en cero
 * \param array de estructuras EMovie
 * \param tamaño del array
 * \return void
 */
void borrar_Peliculas(EMovie unArraydePeliculas[], int CANT);

void generar_html(EMovie unArraydePeliculas[], int CANT );
#endif // FUNCIONES_H_INCLUDED
