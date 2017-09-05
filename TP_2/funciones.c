#include "funciones.h"
#include <stdio.h>

void set_Estado(EPersona lista[])
{
    for (int i =0;i<20;i++)
    {
        lista[i].edad = 0;
    }
}

void load_Array(EPersona lista[])
{
    char name[5][20] = {{"Eliana"},{"Ludmila"},{"Lucas"},{"Mariana"},{"Hernan"}};
    int age[5] = {{31},{33},{66},{70},{0}};
    int docs[5] = {{753},{951},{456},{852},{01}};
    int flag[20] = {{1},{1},{1},{1},{1}};

    for(int i=0; i<5; i++)
    {
        strcpy(lista[i].nombre, name[i]);
        lista[i].edad = age[i];
        lista[i].dni = docs[i];
        lista[i].estado = flag[i];
    }

}

void agregar_Persona(EPersona lista[]) //punto 1
{
    char name[20];
    int age;
    int doc;

    printf("\nIngrese NOMBRE de persona: ");
    scanf("%s",&name);
    printf("\nIngrese EDAD de persona: ");
    scanf("%d",&age);
    printf("\nIngrese DNI: ");
    scanf("%d",&doc);
    fflush(stdin);

    for(int i=0; i<20; i++)
    {
        if (lista[i].estado == 0)
        {
            strcpy(lista[i].nombre, name);
            lista[i].edad = age;
            lista[i].dni = doc;
            lista[i].estado = 1;
            break;
        }
    }
}

void imprimir_Lista(EPersona lista[])
{
    for (int i=0; i<20; i++)
    {
        if(lista[i].estado == 1)
        {
            printf("\n********");
            printf("\nNombre: %s",lista[i].nombre);
            printf("\nEdad: %d anios",lista[i].edad);
            printf("\nDNI: %d",lista[i].dni);
        }
    }
}

void borrar_Persona(EPersona lista[]) //punto 2
{
    int dni;

    printf("\nIngrese DNI de persona a borrar:");
    scanf("%d",&dni);
    for (int i=0; i<20; i++)
    {
        if(lista[i].dni == dni)
        {
            lista[i].estado = 0;
            break;
        }
    }
}

void imprimir_Lista_ordenada(EPersona lista[])// punto 3
{
    EPersona temp;

    for(int j=0; j<20; j++)
    {
        for(int k=j+1; k<20; k++)
        {
            if ( (strcmp(lista[j].nombre, lista[k].nombre) > 0 ) && lista[j].estado == 1 && lista[k].estado == 1 )
            {
                strcpy(temp.nombre, lista[j].nombre);
                temp.dni = lista[j].dni;
                temp.edad = lista[j].edad;
                temp.estado = lista[j].estado;

                strcpy(lista[j].nombre, lista[k].nombre);
                lista[j].dni = lista[k].dni;
                lista[j].edad = lista[k].edad;
                lista[j].estado = lista[k].estado;

                strcpy(lista[k].nombre, temp.nombre);
                lista[k].edad = temp.edad;
                lista[k].dni = temp.dni;
                lista[k].estado = temp.estado;
            }
        }
    }
    printf("\nLista ordenada por nombre: \n");
    for(int i=0; i<20; i++)
    {
        if (lista[i].estado == 1)
        {
            printf("Nombre:%s Edad:%d DNI:%d \n",lista[i].nombre,lista[i].edad,lista[i].dni);
        }
    }
}

void imprimirEdades(EPersona lista[])
{
    int cont1 = 0;//<18
    int cont2 = 0;//19<35
    int cont3 = 0;//35<

        for( int j=0; j<20; j++ )
        {
            if( lista[j].estado == 1 && lista[j].edad <18 )
            {
                cont1++;
            }
            else if( lista[j].estado == 1 && lista[j].edad < 35)
            {
                cont2++;
            }
            else if( lista[j].estado == 1 && lista[j].edad > 35)
            {
                cont3++;
            }
    }
    printf("\nEdades <18: %d\n19<35: %d\n35<: %d\n",cont1,cont2,cont3);
}
