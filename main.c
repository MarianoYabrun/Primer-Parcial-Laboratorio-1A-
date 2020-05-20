#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 100
#define TAMH 4
#include "funciones.h"

int main()
{
    int id = 8000;
    int idT = 3000;
    char seguir = 's';
    char salir;
    int flag =0;
    eNotebook lista[TAM];
    eMarca marcas[TAMH] = {{1000, "Compaq"},{1001, "Asus"},{1002, "Acer"},{1003, "HP"}};
    eTipo tipos[TAMH]  = {{5000, "Gamer" },{5001, "Disenio"},{5002, "Ultrabook"},{5003, "Normal"}};
    eServicio servicios[TAMH] = {{20000, "Bateria", 250},{20001, "Antivirus", 300},{20002, "Actualizacion", 400},{20003, "Fuente",600}};
    eTrabajo trabajos[TAM];
    eCliente clientes  [TAMH] ={{1, "Esteban", 'm'},{2, "Maria", 'v'},{3, "Juan", 'm'},{4, "Victoria", 'f'}};

    inicializarNotebooks(lista, TAM);
    inicializarTrabajos(trabajos, TAM);

    do
    {

        switch (menu())
        {

        case 1:
            if(altaNotebook( id, lista, TAM, marcas, TAMH, tipos, TAMH, clientes, TAMH) == 1)
            {
                id++;
                flag =1;

            }
            break;
        case 2:
            if(flag == 0)
            {
                printf("\n\nNo dio de alta ninguna notebook\n\n ");
                system("pause");
                system("cls");
            }
            else
            {
                modificarNotebook (lista, TAM, marcas, TAMH, tipos, TAMH, clientes, TAMH );
                system("cls");
            }


            break;
        case 3:

            if(flag == 0)
            {
                printf("\n\nNo dio de alta ninguna notebook \n\n");
                system("pause");
                system("cls");

            }
            else
            {
                bajaNotebook(lista, TAM, marcas, TAMH, tipos, TAMH, clientes, TAMH);
                system("pause");
                 system("cls");
            }

            break;
        case 4:

            if(flag == 0)
            {
                printf("\n\nNo dio de alta ninguna notebook \n\n");
                system("pause");
                system("cls");
            }
            else
            {

                mostrarNotebooks(lista, TAM, marcas, TAMH, tipos, TAMH, clientes, TAMH);
                system("pause");
                system("cls");
            }


            break;
        case 5:
            mostrarMarcas(marcas, TAMH);
            system("pause");
            system("cls");

            break;
        case 6:
            mostrarTipos(tipos, TAMH);
            system("pause");
            system("cls");

            break;
        case 7:
            mostrarServicios(servicios, TAMH);
            system("pause");
            system("cls");
            break;

        case 8:

            mostrarClientes(clientes, TAMH);
            system("pause");
            system("cls");


            break;
        case 9:

            if(flag == 0)
            {
                printf("\n\nNo dio de alta ninguna notebook\n\n");
                system("pause");
                system("cls");


            }
            else
            {



                if(altaTrabajo( idT, trabajos, TAM,lista, TAM, servicios, TAMH, marcas, TAMH, tipos,  TAMH, clientes, TAMH)== 1)
                {

                    idT ++;

                }

            }
             break;

        case 10:
            mostrarTrabajos(trabajos, TAM, lista, TAM, marcas, TAMH, tipos, TAMH, servicios, TAMH, clientes, TAMH);
            system("pause");
            system("cls");


            break;

        case 11:
                    informar(lista, TAM, marcas, TAMH, tipos, TAMH, clientes, TAMH);


            break;


        case 12:
            printf("\nConfirma salir? : ");
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
