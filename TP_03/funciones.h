#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "funciones.c"

typedef struct
{
    int codigo;
    char titulo[50];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];
}EMovie;

void hardcode_array(EMovie unArray[]);
void request_Pelicula(EMovie unaPelicula);
void show_pelicula(EMovie unaPelicula);
void cargarArray_Peliculas(EMovie unArraydePeliculas[], int CANT);
#endif // FUNCIONES_H_INCLUDED
