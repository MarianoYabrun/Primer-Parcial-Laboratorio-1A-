
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"


int menu()
{
    int opcion;

    printf("\n\n***Gestion de lista notebooks***\n\n");
    printf("1) ALTA NOTEBOOK\n");
    printf("2) MODIFICAR \n");
    printf("3) BAJA \n");
    printf("4) LISTAR NOTEBOOKS\n");
    printf("5) LISTAR MARCAS\n");
    printf("6) LISTAR TIPOS\n");
    printf("7) LISTAR SERVICIOS\n");
    printf("8) ALTA TRABAJOS \n");
    printf("9) LISTAR TRABAJOS\n");
    printf("10) SALIR \n");

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

        printf("Ingrese id: ");
        fflush(stdin);
        scanf("%d", &auxNotebook.id);

        printf("\n Ingrese Modelo: ");
        fflush(stdin);
        gets(auxNotebook.modelo);

        printf("\n Ingrese id de la Marca: ");
        fflush(stdin);
        scanf("%d",&auxNotebook.idMarca);

        printf("\n Ingrese id del tipo: ");
        fflush(stdin);
        scanf("%d",&auxNotebook.idTipo);

        printf("\n Ingrese el Precio: ");
        fflush(stdin);
        scanf("%f", &auxNotebook.precio );

        auxNotebook.isEmpty =0;

        vec[indice] = auxNotebook;
        todoOk =1;
    }
    return todoOk;
}

int cargarDescripcionMarca(char descripcion[], int id, eMarca marcas[], int tamM)
{
    int todoOk = 0;

    for(int i =0; i<tamM; i++)
    {
        if(marcas[i].id == id)
        {
            strcpy(descripcion, marcas[i].descripcionMarca);
            todoOk =1;
        }
    }
    return todoOk;
}

int cargarDescripcionTipo(char descripcion[], int id, eTipo tipos[], int tamT)
{
    int todoOk = 0;

    for(int i =0; i<tamT; i++)
    {
        if(tipos[i].id == id)
        {
            strcpy(descripcion, tipos[i].descripcionTipo);
            todoOk =1;
        }
    }
    return todoOk;
}




void mostrarNotebook(eNotebook x, eMarca marcas[], int tamM, eTipo tipos[], int tamT)
{

char descripcionMarca[20];
char descripcionTipo[20];

cargarDescripcionMarca(descripcionMarca, x.idMarca, marcas, 4 );
cargarDescripcionTipo(descripcionTipo, x.idTipo, tipos, 4);

    printf("\n\n%4d ", x.id);
    printf(" %4s  ", x.modelo);
    printf("%4s", descripcionMarca );
    printf("%4s", descripcionTipo);
    printf(" %.2f   ", x.precio);



}

void mostrarNotebooks(eNotebook vec[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT)
{

    printf("\n\n**** LISTADO DE NOTEBOOKS****\n\n");
    printf("ID  MODELO  MARCA TIPO  PRECIO   \n");

    int flag =0;

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 0)
        {
            mostrarNotebook(vec[i], marcas, 4, tipos, 4);
            flag =1;
        }

        if( vec[i].isEmpty ==1 && flag == 0)
        {
            printf("\n No hay Notebooks cargadas\n");
        }

    }

}


void bajaNotebook(eNotebook vec[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT)
{
    int id;
    int indice;
    char confirmar;
    system("cls");
    printf("***BAJA NOTEBOOK***");
    printf("ingrese id: ");
    scanf("%d", &id);

    indice = buscarNotebook(id, vec, 4);

    if(indice ==-1)
    {

        printf("no hay un Notebook cuyo id sea %d", id);
    }
    else
    {
        mostrarNotebook(vec[indice], marcas, 4, tipos, 4);

        printf("confirma la baja de esta notebook? s/n:  ");
        fflush(stdin);
        scanf("%c", &confirmar);

        if(confirmar == 's')
        {
            vec[indice].isEmpty = 1;

            printf("BAJA EXITOSA");
        }
        else
        {
            printf("Se ha cancelado la operacion");
        }

    }

}

    int buscarNotebook(int id,eNotebook vec[], int tam)
{
    int indice = -1;

    for(int i=0; i<tam; i++)

    {
        if(vec[i].id == id && vec[i].isEmpty == 0)
        {
            indice =i;
            break;
        }

    }
    return indice;
}


void modificarNotebook(eNotebook vec[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT)
{

    int id;
    int opcion;
    int indice;
    system("cls");

    printf("***** Modificar Notebook*****\n\n");
    printf("Ingrese id de la Notebook que quiera modificar: ");
    scanf("%d", &id);

    indice = buscarNotebook(id, vec, 4);

    if(indice == -1)
    {

        printf("No existe una notebook con ese ID");
    }
    else
    {

        mostrarNotebook(vec[indice], marcas, 4, tipos, 4);

        printf("Que dato desea modificar? \n\n");
        printf("1- Modificar Precio\n");
        printf("2- Modificar Tipo\n");

        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            printf("Ingrese el nuevo Precio: ");
          scanf("%f", &vec[indice].precio);
            break;

        case 2:

            printf("1: GAMER\n");
            printf("2: DISENIO\n");
            printf("3: ULTRABOOK\n");
            printf("4: NORMALITA\n");
            printf("Ingrese el nuevo id del tipo que desea: ");
            scanf("%d", &vec[indice].idTipo);

            break;

        default:
            printf("OPCION NO VALIDA\n\n");


        }
    }
}


/* NO LLEGUE POR EL TIEMPO


int altaTrabajo( eTrabajo vec[], int tam)
{

    int indice = buscarLibre(vec, tam);

    eTrabajo auxTrabajo;
    int todoOk;

    if(indice == -1)
    {
        printf("Sistema completo \n\n");
        todoOk =0;

    }
    else
    {



    return todoOk;
}
*/
