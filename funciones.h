
typedef struct
{
    int dia;
    int mes;
    int anio;

} eFecha;

typedef struct
{
    int id;
    char descripcionMarca[20];



}eMarca;

typedef struct
{
    int id;
    char descripcionTipo[20];


}eTipo;

typedef struct
{

int id;
char descripcionServicio[25];
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
int cargarDescripcionMarca(char descripcion[], int id, eMarca marcas[], int tamM);
void mostrarNotebook(eNotebook x, eMarca marcas[], int tamM, eTipo tipos[], int tamT);
void mostrarNotebooks(eNotebook vec[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT);
int cargarDescripcionTipo(char descripcion[], int id, eTipo tipos[], int tamT);
int buscarNotebook(int id,eNotebook vec[], int tam);
void bajaNotebook(eNotebook vec[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT);
void modificarNotebook(eNotebook vec[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT);
