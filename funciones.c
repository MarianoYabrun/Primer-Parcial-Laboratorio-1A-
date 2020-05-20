
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int menu()
{
    int opcion;


    printf("\n\n***MENU DE OPCIONES***\n\n");
    printf("1) ALTA NOTEBOOK\n");
    printf("2) MODIFICAR NOTEBOOK \n");
    printf("3) BAJA NOTEBOOK \n");
    printf("4) LISTADO NOTEBOOKS\n");
    printf("5) LISTADO MARCAS\n");
    printf("6) LISTADO TIPOS\n");
    printf("7) LISTADO SERVICIOS\n");
    printf("8) MOSTRAR CLIENTES\n");
    printf("9) ALTA TRABAJO\n");
    printf("10) LISTADO TRABAJOS\n");
    printf("11) INFORMES\n");
    printf("12) SALIR\n");

    printf("\nIngrese una opcion: ");
    scanf("%d", &opcion);

    return opcion;
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


int buscarLibreTrabajo( eTrabajo vec[], int tam)
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


void inicializarNotebooks(eNotebook vec[], int tam)
{

    for(int i=0; i<tam; i++)
    {

        vec[i].isEmpty = 1;

    }

}

void inicializarTrabajos(eTrabajo vec[], int tam)
{

    for(int i=0; i<tam; i++)
    {

        vec[i].isEmpty = 1;

    }

}



int altaNotebook( int id, eNotebook vec[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente clientes[], int tamC)
{
    system("cls");
    int indice = buscarLibre(vec, tam);
    eNotebook aux;
    int todoOk;

    if(indice == -1)
    {
        printf("Sistema completo \n\n");
        todoOk =0;

    }
    else
    {
        aux.id = id;

        printf("\n**ALTA NOTEBOOK**\n");

        printf("\n Ingrese Modelo: ");
        fflush(stdin);
        gets(aux.modelo);

        system("cls");

        mostrarMarcas(marcas, tamM);
        printf("\n Ingrese id de la marca : ");
        fflush(stdin);
        scanf("%d", &aux.idMarca);
        system("cls");


        while(aux.idMarca != 1000 && aux.idMarca != 1001 && aux.idMarca != 1002 && aux.idMarca != 1003 )
        {
            mostrarMarcas(marcas, tamM);
            printf("\n El id que ingresaste no existe, Reingrese el id de la marca : ");
            fflush(stdin);
            scanf("%d", &aux.idMarca);
            system("cls");


        }
        mostrarTipos(tipos, tamT);
        printf("\n Ingrese id del Tipo : ");
        fflush(stdin);
        scanf("%d", &aux.idTipo);
        system("cls");


        while(aux.idTipo != 5000 && aux.idTipo != 5001 && aux.idTipo != 5002 && aux.idTipo != 5003 )
        {
            mostrarTipos(tipos, tamT);
            printf("\n El id que ingresaste no existe, Reingrese id del Tipo : ");
            fflush(stdin);
            scanf("%d", &aux.idTipo);
            system("cls");

        }

        mostrarClientes(clientes, tamC);
        printf("\n\nIngrese un ID del cliente correspondiente:  ");
        scanf("%d", &aux.idCliente);

        while(aux.idCliente < 1 || aux.idCliente > 4)
        {
            printf("\n\nEl id ingresado no pertenece a ningun cliente en sistema, reingrese ID del cliente:  ");
            scanf("%d", &aux.idCliente);
        }

        system("cls");

        printf("\n Ingrese precio: ");
        fflush(stdin);
        scanf("%f", &aux.precio);
        while(aux.precio < 1)
        {
            printf("\n El precio debe ser mayor a 0, Reingrese: ");
            fflush(stdin);
            scanf("%f", &aux.precio);

        }

        system("cls");

        aux.isEmpty =0;

        vec[indice] = aux;
        todoOk =1;
    }
    return todoOk;
}

int cargarDescripcionMarca(char descripcion[], int id, eMarca marcas[], int tamH)
{
    int todoOk = 0;

    for(int i =0; i<tamH; i++)
    {
        if(marcas[i].id == id)
        {
            strcpy(descripcion, marcas[i].descripcion);
            todoOk =1;
        }
    }
    return todoOk;
}

int cargarDescripcionTipo(char descripcion[], int id, eTipo tipos[], int tamH)
{
    int todoOk = 0;

    for(int i =0; i<tamH; i++)
    {
        if(tipos[i].id == id)
        {
            strcpy(descripcion, tipos[i].descripcion);
            todoOk =1;
        }
    }
    return todoOk;
}


void mostrarNotebook(eNotebook x, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente clientes[], int tamC)
{

    char descripcionMarca[20];
    char descripcionTipo[20];
    char nombreC[10];
    cargarDescripcionMarca(descripcionMarca, x.idMarca, marcas, tamM );
    cargarDescripcionTipo(descripcionTipo, x.idTipo, tipos, tamT );
    cargarDescripcionCliente(nombreC, x.idCliente, clientes, tamC);

    printf("%d ", x.id);
    printf("  %s  ", x.modelo);
    printf("  %s  ", descripcionMarca );
    printf("  %s  ", descripcionTipo);
    printf("  %.2f  ", x.precio);
    printf(" %d ", x.idCliente);
    printf("%s  \n", nombreC);

}


void mostrarNotebooks(eNotebook vec[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente clientes[], int tamC )
{

    printf("\n\n**** LISTADO DE NOTEBOOKS****\n\n");
    printf("ID  MODELO   MARCA    TIPO       PRECIO        IDC  NOMBRE   \n\n");

    int flag =0;

    ordenarNotebooks(vec, tam);

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 0)
        {
            mostrarNotebook(vec[i], marcas, tamM, tipos, tamT, clientes, tamC);
            flag =1;
        }

        if( vec[i].isEmpty ==1 && flag == 0)
        {
            printf("\n No hay Notebooks cargadas\n");
            break;
        }

    }

}

void ordenarNotebooks(eNotebook vec[], int tam)
{
    eNotebook aux;

    for(int i=0; i<tam-1; i++)
    {

        for(int j=i+1; j<tam; j++)
        {

            if(vec[i].isEmpty == 0 && vec[j].isEmpty == 0 && vec[i].idMarca > vec[j].idMarca)
            {

                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;


            }
            else if(vec[i].isEmpty == 0 && vec[j].isEmpty == 0 && vec[i].idMarca == vec[j].idMarca && vec[i].precio > vec[j].precio)
            {

                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;

            }
        }
    }
}

void bajaNotebook(eNotebook vec[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente clientes[], int tamC)
{
    system("cls");
    int id;
    int indice;
    char confirmar;
    system("cls");
    printf("***BAJA NOTEBOOK***");

    mostrarNotebooks(vec, tam, marcas, tamM, tipos, tamT, clientes, tamC);

    printf("\nIngrese id de la notebook que quiera eliminar del sistema: ");

    scanf("%d", &id);

    indice = buscarNotebook(id, vec, tam);

    if(indice ==-1)
    {
        printf("\nNo hay Notebook cuyo id sea %d", id);
    }
    else
    {
        printf("\n\n");
        mostrarNotebook(vec[indice], marcas, tamM, tipos, tamT, clientes, tamC);

        printf("\nConfirma la baja de esta Notebook? presione 's' para confirmar o cualquier otra tecla para cancelar :  ");
        fflush(stdin);
        scanf("%c", &confirmar);

        if(confirmar == 's')
        {
            vec[indice].isEmpty = 1;
            printf("\n\nBAJA EXITOSA\n\n");
        }
        else
        {
            printf("\nSe ha cancelado la operacion\n");
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

void modificarNotebook (eNotebook vec[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente clientes[], int tamC )
{

    int id;
    int opcion;
    int indice;
    system("cls");

    printf("***MODIFICAR NOTEBOOK***\n\n");

    mostrarNotebooks(vec, tam, marcas, tamM, tipos, tamT, clientes, tamC);
    printf("Ingrese id de la notebook que quiera modificar: ");
    scanf("%d", &id);

    indice = buscarNotebook(id, vec, tam);

    if(indice == -1)
    {
        printf("\nNo existe una notebook con ese ID\n");
    }
    else
    {
        printf("\n\n");

        mostrarNotebook(vec[indice],marcas,tamM, tipos, tamT, clientes, tamC );


        printf("\n1- Modificar Tipo\n");
        printf("2- Modificar Precio\n");
        printf("3- Salir\n");
        printf("\nQue dato desea modificar? \n\n");
        scanf("%d", &opcion);



        switch(opcion)
        {
        case 1:

            mostrarTipos(tipos, tamT);
            printf("\nIngrese nuevo id del Tipo: ");
            fflush(stdin);
            scanf("%d", &vec[indice].idTipo);

            while(vec[indice].idTipo != 5000 && vec[indice].idTipo != 5001 && vec[indice].idTipo != 5002 && vec[indice].idTipo != 5003 )
            {
                mostrarTipos(tipos, tamT);
                printf("\n El id que ingresaste no existe, Reingrese id del Tipo : ");
                fflush(stdin);
                scanf("%d", &vec[indice].idTipo);
            }

            break;


        case 2:

            printf("\nIngrese nuevo precio: ");
            fflush(stdin);
            scanf("%f", &vec[indice].precio);
            while(vec[indice].precio < 1)
            {
                printf("\nEl precio debe ser igual o mayor a 1, reingrese: ");
                fflush(stdin);
                scanf("%f", &vec[indice].precio);

            }
            break;


        case 3:
            break;

        default:
            printf("\nOPCION NO VALIDA\n\n");
            break;
        }
    }
}

void mostrarTipos(eTipo tipos[], int tamT)
{
    printf("\nID  DESCRIPCION\n\n");

    for(int i=0; i<tamT; i++)
    {

        printf("%d  ", tipos[i].id);
        printf(" %s\n", tipos[i].descripcion);


    }
}

void mostrarMarcas(eMarca marcas[], int tamM)
{
    printf("\nID  DESCRIPCION\n\n");

    for(int i=0; i<tamM; i++)
    {

        printf("%d  ", marcas[i].id);
        printf(" %s\n", marcas[i].descripcion);


    }
}

void mostrarServicios(eServicio servicios[], int tamS)
{
    printf("\nID  DESCRIPCION   PRECIO\n\n");

    for(int i=0; i<tamS; i++)
    {

        printf("%d  ", servicios[i].id);
        printf(" %s  ", servicios[i].descripcion);
        printf(" %.2f $ \n", servicios[i].precio);


    }
}

int altaTrabajo(int id, eTrabajo vec[], int tamTR, eNotebook lista[], int tam, eServicio servicios[], int tamS, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente clientes[], int tamC)
{
    system("cls");
    eTrabajo aux;
    int idN;
    int idS;
    int indice;
    int todoOk =0;
    int ind = buscarLibreTrabajo(vec, tamTR);
    printf("\n\n***ALTA TRABAJO***\n\n");

    mostrarNotebooks(lista, tam, marcas, tamM, tipos, tamT, clientes, tamC);
    printf("\nIngrese el ID de la notebook que desea seleccionar para el trabajo: ");
    scanf("%d", &idN);
    indice = buscarNotebook(idN, lista, tam);

    while( indice == -1)
    {
        printf("\nEste id no corresponde a ninguna notebook, reingrese id: ");
        scanf("%d", &idN);
        indice = buscarNotebook(idN, lista, tam);

    }

    system("cls");

    aux.idNotebook = idN;

    mostrarServicios(servicios, tamS);
    printf("\nIngrese el id del servicio que desea contratar :  ");
    scanf("%d", &idS);

    while(idS != 20000 && idS != 20001 && idS != 20002 && idS != 20003 )
    {
        printf("\nEl id que ingreso no corresponde a ningun servicio. Reingrese : ");
        scanf("%d", &idS);

    }
    system("cls");

    aux.idServicio = idS;


    printf("\nIngrese el dia asignado para el trabajo: ");
    scanf("%d", &aux.fecha.dia);
    while(aux.fecha.dia < 0 || aux.fecha.dia > 31)
    {
        printf("\n El dia ingresado no es valido, Reingrese: ");
        scanf("%d", &aux.fecha.dia);

    }
    printf("\nIngrese el mes asignado para el trabajo: ");
    scanf("%d", &aux.fecha.mes);
    while(aux.fecha.mes < 1 || aux.fecha.mes > 12 )
    {
        printf("\n El mes ingresado no es valido, Reingrese: ");
        scanf("%d", &aux.fecha.mes);


    }
    printf("\nIngrese el anio asignado para el trabajo: ");
    scanf("%d", &aux.fecha.anio);
    while(aux.fecha.anio < 2020)
    {
        printf("\n El anio ingresado debe ser el anio actual o posterior, Reingrese: ");
        scanf("%d", &aux.fecha.anio);

    }

    aux.id = id;
    aux.isEmpty = 0;
    vec[ind] = aux;

    todoOk =1;

    return todoOk;

}

void mostrarTrabajos(eTrabajo vec[], int tam, eNotebook lista[], int tamL, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eServicio servicios[], int tamS, eCliente clientes[], int tamC )
{

    printf("\n\n**** LISTADO DE TRABAJOS****\n\n");
    printf(" ID   SERVICIO PRECIO   FECHA      IDN    MODELO   MARCA   TIPO    PRECIO  IDC  NOMBRE  \n\n");

    int flag =0;

    char descripcionServicio [20];

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 0)
        {
            printf("%d ", vec[i].id);

            int idS = vec[i].idServicio;
            cargarDescripcionServicio(descripcionServicio,idS, servicios, tamS );
            printf("%s", descripcionServicio);

            printf("  %d/", vec[i].fecha.dia);
            printf(" %d/", vec[i].fecha.mes);
            printf(" %d  ", vec[i].fecha.anio);

            int idN = vec[i].idNotebook;
            int indice = buscarNotebook(idN, lista, tamL);
            mostrarNotebook(lista[indice], marcas, tamM, tipos, tamT, clientes, tamC);
            flag =1;
        }

        if ( vec[i].isEmpty ==1 && flag == 0)
        {
            printf("\nNo hay trabajos cargados\n\n");
            break;
        }

    }

}

int cargarDescripcionServicio(char descripcion[], int id, eServicio servicios[], int tamS)
{
    int todoOk = 0;

    for(int i =0; i<tamS; i++)
    {
        if(servicios[i].id == id)
        {
            strcpy(descripcion, servicios[i].descripcion);
            todoOk =1;
        }
    }
    return todoOk;
}


void mostrarClientes(eCliente clientes[], int tamC)
{
    printf("\nID  NOMBRE  SEXO \n\n");

    for(int i=0; i<tamC; i++)
    {
        printf("%d  ", clientes[i].id);
        printf(" %4s   ", clientes[i].nombre);
        printf("  %4c\n", clientes[i].sexo);
    }
}
int cargarDescripcionCliente(char nombre[], int id, eCliente clientes[], int tamC)
{
    int todoOk = 0;

    for(int i =0; i<tamC; i++)
    {
        if(clientes[i].id == id)
        {
            strcpy(nombre, clientes[i].nombre);
            todoOk =1;
        }
    }
    return todoOk;
}

void informar(eNotebook vec[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente clientes[], int tamC)
{

    char seguir ='s';
    system("cls");


    do
    {

        switch (menuInformes())
        {

        case 1:
            mostrarNotebooksTipo(vec, tam, marcas, tamM, tipos, tamT, clientes, tamC);

            break;
        case 2:
            mostrarNotebooksMarca(vec, tam, marcas, tamM, tipos, tamT, clientes, tamC);

            break;

        case 3:
            mostrarNotebookBarata(vec, tam, marcas, tamM, tipos, tamT, clientes, tamC);

            break;

        case 4:
            mostrarNotebooksXMarca(vec, tam, marcas, tamM, tipos, tamT, clientes, tamC);

            break;

        case 5:
            contarNotebooks(vec, tam, marcas, tamM, tipos, tamT, clientes, tamC);

            break;

        case 6:
            printf("No llegue con el tiempo para hacer esta funcion.");

            break;


        case 7:
            seguir = 'n';
            break;

        default:
            printf("\n opcion no valida");

        }

    }
    while (seguir =='s');

}



int menuInformes()
{
    int opcion;

    system("cls");
    printf("\n\n***Gestion de informes***\n\n");
    printf("1) Mostrar las notebooks de un tipo\n");
    printf("2) Mostrar notebooks de una marca\n");
    printf("3) Mostrar la o las notebooks mas baratas\n");
    printf("4) Listar Notebooks separadas por marca\n");
    printf("5) Elegir un tipo y una marca y mostrar cuantas notebooks cumplen ambos criterios\n");
    printf("6) Mostrar la o las marcas mas elegidas por los clientes\n");
    printf("7) Salir \n\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);


    return opcion;
}





void mostrarNotebooksTipo(eNotebook vec[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente clientes[], int tamC )
{
    int idT;
    int flag =0;
    printf("\n\n");
    mostrarTipos(tipos, tamT);
    printf("\nIngrese el ID del tipo por el cual desea filtrar: ");
    scanf("%d", &idT);

    while(idT != 5000 && idT != 5001 && idT != 5002 && idT != 5003 )
    {
        mostrarTipos(tipos, tamT);
        printf("\n El id que ingresaste no existe, Reingrese id del Tipo : ");
        fflush(stdin);
        scanf("%d", &idT);
        system("cls");
    }



    printf("\n\n**** LISTADO DE NOTEBOOKS****\n\n");
    printf("ID  MODELO   MARCA    TIPO      PRECIO        IDC  NOMBRE   \n\n");


    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 0 && vec[i].idTipo == idT)
        {
            mostrarNotebook(vec[i], marcas, tamM, tipos, tamT, clientes, tamC);
            flag =1;
        }

        if( vec[i].isEmpty ==1 && flag == 0)
        {
            printf("\n No hay Notebooks de ese tipo cargadas \n");
            break;
        }

    }

    system("pause");

}

void mostrarNotebooksMarca(eNotebook vec[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente clientes[], int tamC )
{
    int idM;
    int flag =0;
    printf("\n\n");
    mostrarMarcas(marcas, tamM);
    printf("\nIngrese el ID de la Marca por la cual desea filtrar: ");
    scanf("%d", &idM);

    while(idM != 1000 && idM != 1001 && idM != 1002 && idM != 1003 )
    {
        mostrarMarcas(marcas, tamM);
        printf("\n El id que ingresaste no existe, Reingrese id de la Marca : ");
        fflush(stdin);
        scanf("%d", &idM);
        system("cls");
    }



    printf("\n\n**** LISTADO DE NOTEBOOKS****\n\n");
    printf("ID  MODELO   MARCA    TIPO      PRECIO        IDC  NOMBRE   \n\n");


    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 0 && vec[i].idMarca == idM)
        {
            mostrarNotebook(vec[i], marcas, tamM, tipos, tamT, clientes, tamC);
            flag =1;
        }

        if( vec[i].isEmpty ==1 && flag == 0)
        {
            printf("\n No hay Notebooks de la marca que selecciono. \n");
            break;
        }

    }

    system("pause");

}

 void mostrarNotebooksXMarca(eNotebook vec[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente clientes[], int tamC)
{


    int flag =0;
    eNotebook aux;

    for(int i=0; i<tam-1; i++)
    {

        for(int j=i+1; j<tam; j++)
        {

            if(vec[i].isEmpty == 0 && vec[j].isEmpty == 0 && vec[i].idMarca < vec[j].idMarca)
            {

                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;


            }

        }

    printf("\n\n**** LISTADO DE NOTEBOOKS****\n\n");
    printf("ID  MODELO   MARCA    TIPO       PRECIO        IDC  NOMBRE   \n\n");


    for(int k=0; k<tam; k++)
    {
        if(vec[k].isEmpty == 0)
        {
            mostrarNotebook(vec[k], marcas, tamM, tipos, tamT, clientes, tamC);
            flag =1;

        }

        if( vec[k].isEmpty ==1 && flag == 0)
        {
            printf("\n No hay Notebooks cargadas\n");
            break;
        }

    }
    system("pause");

}

}

void contarNotebooks(eNotebook vec[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente clientes[], int tamC)
{
    int idM;
    int idT;
    int contador =0;

    mostrarMarcas(marcas, tamM);
    printf("\nIngrese el ID de la Marca por la cual desea filtrar: ");
    scanf("%d", &idM);
    system("cls");

    while(idM != 1000 && idM != 1001 && idM != 1002 && idM != 1003 )
    {
        mostrarMarcas(marcas, tamM);
        printf("\n El id que ingresaste no existe, Reingrese id de la Marca : ");
        fflush(stdin);
        scanf("%d", &idM);
        system("cls");
    }

    printf("\n\n");
    mostrarTipos(tipos, tamT);
    printf("\nIngrese el ID del tipo por el cual desea filtrar: ");
    scanf("%d", &idT);
    system("cls");

    while(idT != 5000 && idT != 5001 && idT != 5002 && idT != 5003 )
    {
        mostrarTipos(tipos, tamT);
        printf("\n El id que ingresaste no existe, Reingrese id del Tipo : ");
        fflush(stdin);
        scanf("%d", &idT);
        system("cls");
    }

   for(int i=0;i<tam;i++)
   {
       if(vec[i].idMarca == idM && vec[i].idTipo == idT)
       {
           contador ++;
       }

   }

   printf("\n La cantidad de notebooks en el sistema de esa marca y tipo es de %d \n\n", contador);
   system("pause");

}


void mostrarNotebookBarata(eNotebook vec[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente clientes[], int tamC)
{


float precioMin;
eNotebook aux;
int flag =0;

    for(int i=0; i<tam-1; i++)
    {

        for(int j=i+1; j<tam; j++)
        {
            if(flag ==0)
            {
                precioMin = vec[i].precio;
            }


            if(vec[i].isEmpty == 0 && vec[j].isEmpty == 0 && vec[i].precio > vec[j].precio )
            {

                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
                precioMin = vec[i].precio;
                flag =1;


            }
        }

    }

    for(int k=0;k<tam;k++)
    {
        if(vec[k].precio == precioMin)
        {
            mostrarNotebook(vec[k], marcas, tamM, tipos, tamT, clientes, tamC);
        }
    }


    system("pause");

}
