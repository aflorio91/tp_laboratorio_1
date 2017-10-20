#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
int esSoloLetras(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}
int esNumerico(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}
int esAlfaNumerico(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
            return 0;
        i++;
    }
    return 1;
}
void hardcode_array(EMovie array_Peliculas[], int CANT) //hardcodea datos al array para facilitar el testeo
{
    int auxiliarcodigo[3] = {{1},{2},{3}};
    char auxiliarTitulo[3][50] = {{"The Room"},{"Back to the future"},{"The Langoliers"}};
    char auxiliarGenero[3][50] = {{"Drama"},{"Aventura"},{"Misterio"}};
    int auxiliarDuracion[3] = {{199},{96},{180}};
    char auxiliarDescripcion[3][50] = {{"Johnny is a successful banker..."},{"A young man is accidentally sent thirty years into the past..."},{"Most of the passengers on an airplane disappear..."}};
    float auxiliarPuntaje[3] = {{3.6},{8.5},{6.1}};
    char auxiliarLink[3][50] = {{"http://www.imdb.com/title/tt0368226/?ref_=nv_sr_1"},{"http://www.imdb.com/title/tt0088763/?ref_=nv_sr_1"},{"http://www.imdb.com/title/tt0112040/?ref_=nv_sr_1"}};

    for (int i=0; i<CANT; i++)
    {
        array_Peliculas[i].codigo = 0;
    }
    for (int j=0; j<3; j++)
    {
        array_Peliculas[j].codigo = auxiliarcodigo[j];
        strcpy(array_Peliculas[j].titulo, auxiliarTitulo[j]);
        strcpy(array_Peliculas[j].genero, auxiliarGenero[j]);
        array_Peliculas[j].duracion = auxiliarDuracion[j];
        strcpy(array_Peliculas[j].descripcion, auxiliarDescripcion[j]);
        array_Peliculas[j].puntaje = auxiliarPuntaje[j];
        strcpy(array_Peliculas[j].linkImagen, auxiliarLink[j]);
    }
}
void request_Pelicula(EMovie unaPelicula)
{
    char input[50];

    printf("\n***CARGAR DATOS DE PELICULA***\n\n");
    fflush(stdin);
    printf("\nIngresar codigo de pelicula: ");
    gets(input);
    while ( esNumerico(input) == 0 || atoi(input) <=0  )
    {
        printf("\nIngrese un valor numerico entero mayor a cero para codigo de pelicula: ");
        gets(input);
    }
    unaPelicula.codigo = atoi(input);

    fflush(stdin);
    printf("\nIngresar titulo: ");
    gets(input);
    while ( esSoloLetras(input) == 0 || strlen(input)>=50 )
    {
        printf("\nIngrese titulo valido con menos de 50 caracteres:");
        gets(input);
    }
    strcpy(unaPelicula.titulo, input);

    fflush(stdin);
    printf("\nIngresar genero: ");
    gets(input);
    while ( esSoloLetras(input) == 0 )
    {
        printf("\nIngrese genero valido:");
        gets(input);
    }
    strcpy(unaPelicula.genero, input);
    fflush(stdin);
    printf("\nIngresar duracion (minutos): ");
    gets(input);
    while ( esNumerico(input) == 0 || atoi(input) <=0  )
    {
        printf("\nIngrese un valor numerico entero mayor a cero para duracion en minutos: ");
        gets(input);
    }
    unaPelicula.duracion = atoi(input);

    fflush(stdin);
    printf("\nIngresar breve descripcion: ");
    gets(input);
    while ( esAlfaNumerico(input) == 0 || strlen(input)>=50 )
    {
        printf("\nIngrese una descripcion valida con menos de 50 caracteres: ");
        gets(input);
    }
    strcpy(unaPelicula.descripcion, input);

    fflush(stdin);
    printf("\nIngresar puntaje (se aceptan valores decimales): ");
    gets(input);
    while( esNumerico(input) == 0 || atoi(input) <0  )
    {
        printf("\nIngresar un puntaje valido:");
        gets(input);
    }
    unaPelicula.puntaje = atof(input);

    fflush(stdin);
    printf("\nIngresar link de imagen (50 caracteres max.): ");
    gets(input);
    while (esAlfaNumerico(input) == 0 || strlen(input)>=50 )
    {
        printf("\nIngresar un link de imagen valido: ");
        gets(input);
    }
    strcpy(unaPelicula.linkImagen, input);
}
void show_peliculas(EMovie unArraydePeliculas[],int CANT)
{
    printf("\n***LISTA DE PELICULAS EN ARRAY***\n\n");
    for (int i=0; i<CANT; i++)
    {
        if(unArraydePeliculas[i].codigo != 0)
        {
            fflush(stdin);
            printf("\nCodigo: %d",unArraydePeliculas[i].codigo);
            printf("\nTitulo: %s",unArraydePeliculas[i].titulo);
            printf("\nGenero: %s",unArraydePeliculas[i].genero);
            printf("\nDuracion: %d",unArraydePeliculas[i].duracion);
            printf("\nDescripcion: %s",unArraydePeliculas[i].descripcion);
            printf("\nPuntaje: %.01f",unArraydePeliculas[i].puntaje);
            printf("\nLink imagen: %s",unArraydePeliculas[i].linkImagen);
            printf("\n*************\n");
        }
    }
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
            }
            else
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
void borrar_Peliculas(EMovie unArraydePeliculas[], int CANT)
{
    int auxiliarCodigo;

    printf("\n***BORRAR PELICULAS***\n");
    printf("\nEscriba codigo de pelicula a borrar: ");
    for (int i=0; i<CANT; i++)
    {
        printf("\nCodigo: %d",unArraydePeliculas[i].codigo);
        printf("\nTitulo: %s",unArraydePeliculas[i].titulo);
        printf("\n***\n");
    }
    scanf("%d",&auxiliarCodigo);
    for (int j=0; j<CANT; j++)
    {
        if (unArraydePeliculas[j].codigo == auxiliarCodigo)
        {
            unArraydePeliculas[j].codigo = 0;
            break;
        }
    }
}









