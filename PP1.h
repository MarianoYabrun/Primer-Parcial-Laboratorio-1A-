#ifndef PP1_H_INCLUDED
#define PP1_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;

} eFecha;

typedef struct
{
    int id;
    char descripcion[20];



}eMarca;

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
   char modelo[20];
   int idMarca;
   int idTipo;
   float precio;
   int isEmpty;

}eNotebook;

typedef struct
{
    int id;
    int idNotebook;
    int idServicio;
    eFecha fecha;

}eTrabajo;


int menu();
void inicializar(eNotebook vec[], int tam);
int buscarLibre( eNotebook vec[], int tam);
int altaNotebook( eNotebook vec[], int tam);


#endif // PP1_H_INCLUDED

