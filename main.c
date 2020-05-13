#include <stdio.h>
#include <stdlib.h>
#define TAM 100
#include "funciones.h"
#include <string.h>

int main()
{
    char seguir = 's';
    char salir;

    eNotebook lista[TAM];
    eMarca marcas[4] = {{1, "Compaq"}, {2,"Asus"},{3, "Acer"}, {4, "HP"}};
    eTipo tipos [4] = {{1, "Gamer"}, {2,"Disenio"},{3, "Ultrabook"}, {4, "Normal"}};
    eServicio Servicios[4] = {{20000, "Bateria", 250}, {20001,"Antivirus", 300},{20002, "Actualizacion", 400 }, {20003, "Fuente", 600}};
     eTrabajo trabajos[TAM];

    inicializar(lista, TAM);
     inicializar(trabajos, TAM);

    do
    {

        switch (menu())
        {

        case 1:
            altaNotebook(lista,TAM);

            break;
        case 2:

            modificarNotebook(lista, TAM, marcas, 4, tipos, 4);



            break;
        case 3:
            bajaNotebook(lista, TAM, marcas, 4, tipos, 4);

            break;
        case 4:
            mostrarNotebooks(lista, TAM, marcas, 4, tipos, 4);

            break;
        case 5:
            printf("***LISTA DE MARCAS***\n\n");
            printf("1: COMPAQ\n");
            printf("2: ASUS\n");
            printf("3: ACER\n");
            printf("4: HP\n");

                break;
        case 6:
            printf("***LISTA DE TIPOS***\n\n");
            printf("1: GAMER\n");
            printf("2: DISENIO\n");
            printf("3: ULTRABOOK\n");
            printf("4: NORMALITA\n");


            break;
        case 7:
            printf("***LISTA DE SERVICIOS***\n\n");
            printf("20000: BATERIA = 250$\n");
            printf("20001: ANTIVIRUS = 300$\n");
            printf("20002: ACTUALIZACION = 400$\n");
            printf("20003: FUENTE = 600$\n");


            break;

            case 8:

                printf("No llegue a hacerlo por cuestiones de tiempo \n");


            break;

             case 9:

                  printf("No llegue a hacerlo por cuestiones de tiempo \n");



            break;

        case 10:
            printf("confirma salir? : ");
            scanf("%c", &salir);

            if(salir == 's')
            {
                seguir = 'n';
            }

            break;

        default:
            printf("OPCION NO VALIDA\n\n");
        }

    }
    while (seguir =='s');




    return 0;
}
