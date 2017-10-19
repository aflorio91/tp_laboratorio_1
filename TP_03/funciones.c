#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void hardcode_array(EMovie unArray[])
{
    for (int i=0; i<CANT; i++)
    {
        array_Peliculas[i].codigo = 0;
    }
}
void request_Pelicula(EMovie unaPelicula)
{
    int auxiliarcodigo;
    char auxiliarTitulo[50];
    char auxiliarGenero[50];
    char auxiliarDescripcion[50];
    char auxiliarLink[50];

    printf("\n***CARGAR DATOS DE PELICULA***\n");
    printf("\nIngresar codigo de pelicula: ");
    scanf("%d",&codigo);
    unaPelicula.codigo = auxiliarcodigo;
    printf("\nIngresar titulo: ");
    gets(auxiliarTitulo);
    strcpy(unaPelicula.titulo, auxiliarTitulo);
    printf("\nIngresar genero: ");
    gets(auxiliarGenero);
    strcpy(unaPelicula.genero, auxiliarGenero);
    printf("\nIngresar duracion: ");
    scanf("%d",&unaPelicula.duracion);
    printf("\nIngresar breve descripcion: ");
    gets(auxiliarDescripcion);
    strcpy(unaPelicula.descripcion, auxiliarDescripcion);
    printf("\nIngresar puntaje: ");
    scanf("%d",&unaPelicula.puntaje);
    printf("\nIngresar link de imagen: ");
    gets(auxiliarLink);
    strcpy(unaPelicula.linkImagen, auxiliarLink);
}
void show_pelicula(EMovie unaPelicula)
{
    printf("\nTitulo: %s",unaPelicula.titulo);
    printf("\nGenero: %s",unaPelicula.genero);
    printf("\nDuracion: %d",unaPelicula.duracion);
    printf("\nDescripcion: %s",unaPelicula.descripcion);
    printf("\nPuntaje: %d",unaPelicula.puntaje);
    printf("\nLink imagen: %s",unaPelicula.linkImagen);
    printf("\nCodigo: %d",unaPelicula.codigo);
}
void cargarArray_Peliculas(EMovie unArraydePeliculas[], int CANT)
{
    printf("\n***AGREGAR PELICULAS***\n");
    char seguir = 's';

    while(seguir == 's')
    {
        for (int i=0; i<CANT; i++)
        {
            if (unArraydePeliculas[i].codigo == 0)
            {
                request_Pelicula(unArraydePeliculas[i]);
                break;
            }else
            {
                printf("\nNo hay espacio en el array...");
                seguir = 'n';
                break;
            }
        }
        printf("\nContinuar cargando peliculas? (s/n): ");
        scanf("%c",&seguir);
    }
}










