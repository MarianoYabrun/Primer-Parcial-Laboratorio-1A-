#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;

}eFecha;


typedef struct
{

    int id;
    char descripcion[10];

}eMarca;

typedef struct
{

    int id;
    char modelo[20];
    int idMarca;
    int idTipo;
    int idCliente;
    float precio;
    int isEmpty;


}eNotebook;

typedef struct
{
    int id;
    char descripcion[20];


}eTipo;


typedef struct
{

    int id;
    char descripcion[25];
    float precio;


}eServicio;


typedef struct
{
    int id;
    int  idNotebook;
    int idServicio;
    eFecha fecha;
    int isEmpty;


}eTrabajo;

typedef struct
{
    int id;
    char nombre[20];
    char sexo;


}eCliente;

#endif // FUNCIONES_H_INCLUDED

int menu();
int buscarLibre( eNotebook vec[], int tam);
int altaNotebook( int id, eNotebook vec[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente clientes[], int tamC);
void inicializarNotebooks(eNotebook vec[], int tam);
int cargarDescripcionMarca(char descripcion[], int id, eMarca marcas[], int tamH);
int cargarDescripcionTipo(char descripcion[], int id, eTipo tipos[], int tamH);
void mostrarNotebook(eNotebook x, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente clientes[], int tamC );
void mostrarNotebooks(eNotebook vec[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente clientes[], int tamC);
void ordenarNotebooks(eNotebook vec[], int tam);
int buscarNotebook(int id,eNotebook vec[], int tam);
void bajaNotebook(eNotebook vec[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT,eCliente clientes[], int tamC);
void modificarNotebook (eNotebook vec[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente clientes[], int tamC );
void mostrarTipos(eTipo tipos[], int tamT);
void mostrarMarcas(eMarca marcas[], int tamM);
void mostrarServicios(eServicio servicios[], int tamS);
int altaTrabajo( int idT, eTrabajo vec[], int tamTR, eNotebook lista[], int tam, eServicio servicios[], int tamS, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente clientes[], int tamC);
int buscarLibreTrabajo( eTrabajo vec[], int tam);
void inicializarTrabajos(eTrabajo vec[], int tam);
 void mostrarTrabajos(eTrabajo vec[], int tam, eNotebook lista[], int tamL, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eServicio servicios[], int tamS, eCliente clientes[], int tamC );
int cargarDescripcionServicio(char descripcion[], int id, eServicio servicios[], int tamS);
void mostrarClientes(eCliente clientes[], int tamC);
int cargarDescripcionCliente(char nombre[], int id, eCliente clientes[], int tamC);
int menuInformes();
void informar(eNotebook vec[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente clientes[], int tamC);
void mostrarNotebooksTipo(eNotebook vec[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente clientes[], int tamC );
void mostrarNotebooksMarca(eNotebook vec[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente clientes[], int tamC );
void mostrarNotebooksXMarca(eNotebook vec[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente clientes[], int tamC);
void contarNotebooks(eNotebook vec[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente clientes[], int tamC);
void mostrarNotebookBarata(eNotebook vec[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente clientes[], int tamC);
