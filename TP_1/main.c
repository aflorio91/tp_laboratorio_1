#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion;
    int A,B;

    while(seguir=='s')
    {
        printf("********************");
        printf("\n1- Ingresar 1er operando (A=x)\n");
        printf("2- Ingresar 2do operando (B=y)\n");
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");
        printf("********************\n");
        fflush(stdin);

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            printf("\nIngrese valor de A: ");
            scanf("%d",&A);
            printf("\nA: %d\n",A);
            break;
        case 2:
            printf("\nIngrese valor de B: ");
            scanf("%d",&B);
            printf("\nB: %d\n",B);
            break;
        case 3:
            printf("\nsuma: %d", suma(A, B));
            break;
        case 4:
            printf("\nresta: %d",resta(A, B));
            break;
        case 5:
            printf("\ndivision: %d",division(A, B));
            break;
        case 6:
            printf("\nmultiplicacion: %d",multiplicar(A, B));
            break;
        case 7:
            printf("\nfactorial: %d",factorizar(A));
            break;
        case 8:
            printf("\nsuma: %d", suma(A, B));
            printf("\nresta: %d",resta(A, B));
            printf("\ndivision: %d",division(A, B));
            printf("\nmultiplicacion: %d",multiplicar(A, B));
            printf("\nfactorial: %d\n",factorizar(A));
            break;
        case 9:
            seguir = 'n';
            break;
        }

    }
    return 0;
}
