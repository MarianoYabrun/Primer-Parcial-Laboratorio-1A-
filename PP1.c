#include <stdio.h>
#include <stdlib.h>
#include "PP1.h"

int menu()
{
    int opcion;

    printf("\n\n***Gestion de lista notebooks***\n\n");
    printf("1) ALTA NOTEBOOK\n");
    printf("2) MODIFICAR \n");
    printf("3) BAJA \n");
    printf("4) LISTAR NOTEBOOKS\n");
    printf("5) LISTAR TIPOS\n");
    printf("6) LISTAR SERVICIOS\n");

    printf("7) LISTAR TRABAJOS \n");
    printf("8) SALIR\n");

    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);


    return opcion;
}


void inicializar(eNotebook vec[], int tam)
{

    for(int i=0; i<tam; i++)
    {

        vec[i].isEmpty = 1;

    }

}

int buscarLibre( eNotebook vec[], int tam)
{

    int indice = -1;

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty ==1)
        {
            indice =i;
            break;
        }

    }

    return indice;
}


int altaNotebook( eNotebook vec[], int tam)
{

    int indice = buscarLibre(vec, tam);

    eNotebook auxNotebook;
    int todoOk;

    if(indice == -1)
    {
        printf("Sistema completo \n\n");
        todoOk =0;

    }
    else
    {

        printf("Ingrese id: \n");
        fflush(stdin);
        scanf("%d", &auxNotebook.id);

        printf("\n Ingrese Modelo: ");
        fflush(stdin);
        gets(auxNotebook.modelo);

        printf("\n Ingrese id de la Marca: ");
        fflush(stdin);
        scanf("%d",&auxNotebooko.idMarca);

        printf("\n Ingrese tipo: ");
        fflush(stdin);
        scanf("%d",&auxNotebook.idTipo);

        printf("\n Ingrese el Precio: ");
        fflush(stdin);
        canf("%2.f", &auxNotebook.precio );

        auxNotebook.isEmpty =0;

        vec[indice] = auxEmpleado;
        todoOk =1;
    }
    return todoOk;
}
