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
    char auxiliarDescripcion[3][300] = {{"Johnny is a successful banker who lives happily in a San Francisco townhouse with his fiancée, Lisa. One day, inexplicably, she gets bored with him and decides to seduce his best friend, Mark. From there, nothing will be the same again."},{"Marty McFly, a seventeen-year-old high school student, is accidentally sent thirty years into the past in a time-travelling DeLorean invented by his close friend, the maverick scientist Doc Brown."},{"Most of the passengers on an airplane disappear, and the remainder land the plane in a mysteriously barren airport."}};
    float auxiliarPuntaje[3] = {{3.6},{8.5},{6.1}};
    char auxiliarLink[3][300] = {{"https://images-na.ssl-images-amazon.com/images/M/MV5BMTg4MTU1MzgwOV5BMl5BanBnXkFtZTcwNjM1MTAwMQ@@._V1_UY268_CR12,0,182,268_AL_.jpg"},{"https://images-na.ssl-images-amazon.com/images/M/MV5BZmU0M2Y1OGUtZjIxNi00ZjBkLTg1MjgtOWIyNThiZWIwYjRiXkEyXkFqcGdeQXVyMTQxNzMzNDI@._V1_UX182_CR0,0,182,268_AL_.jpg"},{"https://images-na.ssl-images-amazon.com/images/M/MV5BNWNmNmVhZDYtM2Y1Yi00ZmNjLThlNTEtN2JiNjY4NGVhOTcyXkEyXkFqcGdeQXVyMTQxNzMzNDI@._V1_UY268_CR10,0,182,268_AL_.jpg"}};

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
    printf("\nIngresar  descripcion (300 caracteres max.): ");
    gets(input);
    while ( esAlfaNumerico(input) == 0 || strlen(input)>=300 )
    {
        printf("\nIngrese una descripcion valida con menos de 300 caracteres: ");
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
    printf("\nIngresar link de imagen (300 caracteres max.): ");
    gets(input);
    while (esAlfaNumerico(input) == 0 || strlen(input)>=300 )
    {
        printf("\nIngresar un link de imagen valido menor a 300 caracteres: ");
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
    printf("\n***AGREGAR PELICULAS AL ARRAY***\n");
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

void generar_html(EMovie unArraydePeliculas[], int CANT )
{
    FILE *fp;

    fp = fopen("index.html", "w");

    if(fp == NULL)
    {
        printf("\nNo se pudo abrir el archivo\n");
        exit(0);
    }
    else
    {
        for ( int i=0; i<CANT; i++)
        {
            if(unArraydePeliculas[i].codigo !=0)
            {
                fprintf(fp,"<article class='col-md-4 article-intro'><a href='#'>");
                fprintf(fp,"<img class='img-responsive img-rounded' src='%s'alt=''>",unArraydePeliculas[i].linkImagen);
                fprintf(fp,"</a><h3><a href='#'>%s</a></h3><ul>",unArraydePeliculas[i].titulo);
                fprintf(fp,"<li>Género:%s</li>",unArraydePeliculas[i].genero);
                fprintf(fp,"<li>Puntaje:%.01f</li>",unArraydePeliculas[i].puntaje);
                fprintf(fp,"<li>Duración:%d</li></ul>",unArraydePeliculas[i].duracion);
                fprintf(fp,"<p>%s</p></article>",unArraydePeliculas[i].descripcion);
            }
        }
        printf("\nArchivo creado con exito\n");
    }
    fclose(fp);
}
