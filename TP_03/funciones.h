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
int esSoloLetras(char str[]);
int esNumerico(char str[]);
int esAlfaNumerico(char str[]);
void hardcode_array(EMovie array_Peliculas[], int CANT);
void request_Pelicula(EMovie unaPelicula);
void show_peliculas(EMovie unArraydePeliculas[],int CANT);
void cargarArray_Peliculas(EMovie unArraydePeliculas[], int CANT);
void borrar_Peliculas(EMovie unArraydePeliculas[], int CANT);
#endif // FUNCIONES_H_INCLUDED
