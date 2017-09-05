#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <conio.h>

int main()
{
    char seguir='s';
    int opcion=0;
    EPersona array_Personas[20];
    
    set_Estado(array_Personas);
    load_Array(array_Personas);//carga 5 datos de personas cualesquiera al array de personas vacío

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                agregar_Persona(array_Personas);
                break;
            case 2:
                borrar_Persona(array_Personas);
                break;
            case 3:
                imprimir_Lista_ordenada(array_Personas);
                break;
            case 4:
                imprimirEdades(array_Personas);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
