#include <stdio.h>
#include <stdlib.h>
#include <funciones.c>
#include <string.h>
#include "funciones.h"
#define CANT 5

void main()
{
    char seguir = 's';
    int opcion = 0;
    EMovie unaPelicula;
    EMovie array_Peliculas[CANT];

    hardcode_array(array_Peliculas);

    while(seguir == 's')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Mostrar pelicula\n");
        printf("3- Generar pagina web\n");
        printf("4- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            system("cls");
            cargarArray_Peliculas(array_Peliculas,CANT);
            break;
        case 2:
            system("cls");
            break;
        case 3:
            system("cls");
            break;
        case 4:
            system("cls");
            seguir = 'n';
            break;
        }
    }
}
