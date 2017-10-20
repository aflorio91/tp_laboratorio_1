#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define CANT 5

void main()
{
    char seguir = 's';
    int opcion = 0;
    EMovie unaPelicula;
    EMovie array_Peliculas[CANT];

    hardcode_array(array_Peliculas,CANT);

    while(seguir == 's')
    {
        printf("1- Agregar peliculas\n");
        printf("2- Mostrar peliculas\n");
        printf("3- Borrar peliculas\n");
        printf("4- Generar archivo HTML\n");
        printf("5- Salir\n");
        fflush(stdin);

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            system("cls");
            cargarArray_Peliculas(array_Peliculas,CANT);
            break;
        case 2:
            system("cls");
            show_peliculas(array_Peliculas,CANT);
            break;
        case 3:
            system("cls");
            borrar_Peliculas(array_Peliculas,CANT);
            break;
        case 4:
            system("cls");
            generar_html(array_Peliculas,CANT);
            break;
        case 5:
            system("cls");
            seguir = 'n';
            break;
        }
    }
}
